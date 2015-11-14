//
//	CopyMerge.java
//	Copies the contents of a input file to output file passed as argument
//
//
//	
//


import java.io.*;

public class CopyMerge {

	public static void main (String [] args) throws IOException, FileNotFoundException {

		File source1 = null;
		File source2 = null;
		File dest = null;

		InputStream is = null;
	    OutputStream os = null;

	    try {

	    	source1 = new File(args[0]);
	    	source2 = new File(args[1]);
	    	dest = new File(args[2]);

	        is = new FileInputStream(source1);
	        os = new FileOutputStream(dest);

	        byte[] buffer = new byte[1024];
	        int length;

	        while ((length = is.read(buffer)) > 0) {
	            os.write(buffer, 0, length);
	        }

	        is = new FileInputStream(source2);

	        int ch;

	        while ((ch = is.read()) != -1) {
	            os.write(ch);
	        }

	    } 
	    finally {
	        is.close();
	        os.close();
	    }

	}

}