//
//
//
//
//
//
//

import java.io.*;
import java.util.*;

public class SearchLine {

	public static void main (String [] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);

		Scanner fileScanner = null;
		File file = null;

		if (args.length == 0) {
			System.out.print("\n\tEnter file name: ");
			file = new File(sc.nextLine());
		}
		else {
			file = new File(args[0]);
		}

		String searchItem = "";
		System.out.print("\n\tEnter search string: ");
		searchItem = sc.nextLine();

		String result = "";
		int occurences = 0;

		try {

			fileScanner = new Scanner(file);

			int lineNo = 0;

			while (fileScanner.hasNextLine()) {
				lineNo++;

				String str = fileScanner.nextLine();

				if (str.contains(searchItem)) {
					occurences++;
					result += "" + lineNo + ".\t" + str + "\n";
				}

			}

		}
		finally {
			fileScanner.close();
		}

		if (occurences == 0)
			System.out.println("\n\t\"" + searchItem + "\" not found in the file.\n\n");
		else
			System.out.println("\n\t\"" + searchItem + "\" found on " + occurences + " line" + ((occurences == 1)?"":"s") + ". \n\n" + result);

	}

}