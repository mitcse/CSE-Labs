//
//	Copy4.java
//	Copies the contents of a input file to output file passed as argument
//
//
//	
//


import java.io.*;
import java.util.Scanner;

public class Copy4 {

	public static void main (String [] args) throws IOException, FileNotFoundException {

		File source = null;
		File dest = null;

		Scanner fs = null;
		PrintWriter pw = null;

		try {

			source = new File(args[0]);
			dest = new File(args[1]);

			fs = new Scanner(source);
			pw = new PrintWriter(dest);

			while(fs.hasNextLine()) {
				pw.println(fs.nextLine());
			}

		} 
		finally {
			fs.close();
			pw.close();
		}

	}

}