//
//	Copy2.java
//	Copies the contents of a input file to output file passed as argument
//
//
//	
//


import java.io.*;

public class Copy2 {

	public static void main (String [] args) throws IOException {

		FileReader fin = null;
		FileWriter fout = null;

		try {

			fin = new FileReader(args[0]);
			fout = new FileWriter(args[1]);

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