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

			if (file.isDirectory())
				printContents(file.listFiles(), tabLength + 1);

			for (int i = 0; i < tabLength; ++i)
				System.out.print("\t");

			System.out.println(file.getName());
		}

	}

}