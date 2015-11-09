//
//	Copy2.java
//	Copies the contents of a input file to output file passed as argument
//
//
//	
//


import java.io.*;

public class Copy3 {

	public static void main (String [] args) throws IOException, FileNotFoundException {

		File source = null;
		File dest = null;

		InputStream is = null;
	    OutputStream os = null;

	    try {

	    	source = new File(args[0]);
	    	dest = new File(args[1]);

	        is = new FileInputStream(source);
	        os = new FileOutputStream(dest);

	        byte[] buffer = new byte[1024];
	        int length;

	        while ((length = is.read(buffer)) > 0) {
	            os.write(buffer, 0, length);
	        }

	    } 
	    finally {
	        is.close();
	        os.close();
	    }

	}

}