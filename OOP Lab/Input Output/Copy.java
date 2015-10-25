//
//	Copy.java
//	Copies the contents of a input file to output file passed as argument
//
//
//	
//

import java.io.*;

public class Copy {

	public static void main (String [] args) throws IOException {

		FileInputStream fin = null;
		FileOutputStream fout = null;

		try {

			fin = new FileInputStream(args[0]);
			fout = new FileOutputStream(args[1]);

			int ch;

			while ((ch = fin.read()) != -1)
				fout.write(ch);

		}
		finally {

			fin.close();
			fout.close();

		}

	}

}