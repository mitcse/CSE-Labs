//
//
//
//
//
//
//

import java.io.*;
import java.util.*;

class SearchString implements Runnable {

	String str;
	String searchItem;

	public SearchString (String str, String searchItem) {
		this.str = str;
		this.searchItem = searchItem;
	}

	public void run () {
		Scanner sc = new Scanner(str);
		while (sc.hasNextLine()) {
			String s = sc.nextLine();
			if (s.contains(searchItem))
				System.out.println("\t" + s);
		}
	}

}

public class SearchFileThreads {

	public static void main (String [] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		Scanner fileScanner = null;

		System.out.print("\n\tEnter number of threads you want: ");
		int numberOfThreads = sc.nextInt();

		SearchString sstrs[] = new SearchString[numberOfThreads];
		Thread threads[] = new Thread[numberOfThreads];

		try {

			int lineNo = 0;
			fileScanner = new Scanner(new File(args[0]));

			while (fileScanner.hasNextLine()) {
				lineNo++;
				fileScanner.nextLine();
			}

			int linesInOneThread = (int)(lineNo/numberOfThreads);

			lineNo = 0;
			int i = 0;
			fileScanner = new Scanner(new File(args[0]));

			StringBuffer sb = new StringBuffer("");

			while (fileScanner.hasNextLine()) {
				lineNo++;
				if (lineNo % linesInOneThread == 0) {
					sstrs[i] = new SearchString("" + sb, ".java");
					threads[i] = new Thread(sstrs[i]);
					threads[i].start();
					Thread.sleep(1000);
					sb = new StringBuffer("");
				}
				else
					sb.append(fileScanner.nextLine() + "\n");
			}

			try {
				for (Thread thrd: threads)
					if (thrd != null)
						thrd.join();
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}

		}
		catch (InterruptedException e) {
				e.printStackTrace();
			}
		finally {
			fileScanner.close();
		}

	}

}