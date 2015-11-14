//
//	CopyDir.java
//	Copy the contents of a directory recurvsively into another directory.
//
//	Created by Avikant Saini on 11/13/15
//
//	Usage java <Indir> <Outdir>
//

/*	*	
	*	Class details - File
	*
	*	File (File parent, String child)
	*		This constructor creates a new File instance from a parent abstract pathname and a child pathname string.
	*
	*	File(String pathname)
	*		This constructor creates a new File instance by converting the given pathname string into an abstract pathname.
	*
	*	public String getName()
	*		Returns the name of the file or directory denoted by this abstract pathname.
	*
	*	public boolean exists()
	*		Tests whether the file or directory denoted by this abstract pathname exists. 
	*		Returns true if and only if the file or directory denoted by this abstract pathname exists; false otherwise
	*
	*	public boolean isDirectory()
	*		Tests whether the file denoted by this abstract pathname is a directory. 
	*		Returns true if and only if the file denoted by this abstract pathname exists and is a directory; false otherwise.
	*
	*	public File[] listFiles()
	*		Returns an array of abstract pathnames denoting the files in the directory denoted by this abstract pathname.
	*
	*	public boolean mkdirs()
	*		Creates the directory named by this abstract pathname, including any necessary but nonexistent parent directories. 
	*		Returns true if and only if the directory was created, along with all necessary parent directories; false otherwise.
	*
	*
	*
	*	Class details - FileInputStream
	*
	*	FileInputStream(File file)
	*		This creates a FileInputStream by opening a connection to an actual file, the file named by the File object file in the file system.
	*
	*	FileInputStream(String name)
	*		This creates a FileInputStream by opening a connection to an actual file, the file named by the path name name in the file system.
	*
	*	public int read(int r)throws IOException{ }
	*		This method reads the specified byte of data from the InputStream. 
	*		Returns an int. Returns the next byte of data and -1 will be returned if it's end of file.
	*
	*	public int read(byte[] r) throws IOException{ }
	*		This method reads r.length bytes from the input stream into an array. 
	*		Returns the total number of bytes read. If end of file -1 will be returned.
	*
	*
	*
	*	Class details - FileInputStream
	*
	*	FileOutputStream(File file)
	*		This creates a file output stream to write to the file represented by the specified File object.
	*
	*	FileOutputStream(String name)
	*		This creates an output file stream to write to the file with the specified name.
	*
	*	public void write(int w)throws IOException{}
	*		This methods writes the specified byte to the output stream.
	*
	*	public void write(byte[] w)
	*		Writes w.length bytes from the mentioned byte array to the OutputStream.
	*
	*
	*/

import java.io.*;
import java.util.*;

public class CopyDir {

	public static void main (String [] args) {
		
		File inDir = null;
		File outDir = null;

		try {

			inDir = new File(args[0]);
			outDir = new File(args[1]);

			copyDirectory (inDir, outDir);

		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch (IOException e) {
			e.printStackTrace();
		}

	}

	static void copyDirectory (File inDir, File outDir) throws IOException, FileNotFoundException {

		// Create the directory of it does not exist (Important) Cause directory creation does not take place automatically.
		if (!outDir.exists())
			outDir.mkdirs();

		for (File inFile : inDir.listFiles()) {

			// If a directory is found inside the directory, copy this directory recursively
			if (inFile.isDirectory())
				copyDirectory(inFile, new File(outDir, inFile.getName()));
			// Else copy this file
			else
				copyFile(inFile, new File(outDir, inFile.getName()));
		}
	}

	static void copyFile (File inFile, File outFile) throws IOException {

		FileInputStream fin = new FileInputStream(inFile);
		FileOutputStream fout = new FileOutputStream(outFile);

		int ch;

		while ((ch = fin.read()) != -1)
			fout.write(ch);

	}

}