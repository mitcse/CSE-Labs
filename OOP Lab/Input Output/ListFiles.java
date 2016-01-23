//
//
//
//
//
//
//

import java.io.*;

public class ListFiles {

	public static void main (String [] args) {
		
		File file = null;

		try {

			file = new File(args[0]);
			File paths[] = file.listFiles();

			printContents (paths, 1);

		}
		catch (Exception e) {
			e.printStackTrace();
		}

	}

	static void printContents (File [] paths, int tabLength) {
		
		for (File file: paths) {

			for (int i = 0; i < tabLength; ++i)
				System.out.print("\t");

			if (file.isDirectory()) {
				System.out.println(" > " + file.getName());
				printContents(file.listFiles(), tabLength + 1);
			}
			else 
				System.out.println(" | " + file.getName());

		}

	}

}