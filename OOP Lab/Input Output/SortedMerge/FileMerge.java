import java.util.*;
import java.io.*;
import filePackage.MergeFiles;
public class FileMerge {
	public static void main(String args[]) {
		File a,b,c;
		a=b=c=null;
		PrintWriter w=null;
		try {
			a = new File(args[0]);
			b = new File(args[1]);
			c = new File(args[2]);
			MergeFiles.normalMerge(a, b, c);
		}
		catch (NullPointerException e) {
			if(args.length != 3) System.out.println("Illegal usage .");
			else System.out.println("Error : "+e);
		}
		catch (Exception e) {
			
		}
		// MergeFiles f = new MergeFiles ( a, b, c );
		// f.merge();
		// try {
		// 	w = new PrintWriter( c );
		
		// }
		// catch (FileNotFoundException e) {
		// 	System.out.println("File not found .\n");
		// 	System.exit(0);
		// }
		// w.println("Check");
		// System.out.println("Merged the files.");
		// f.display();
		//display(c);
	}
	public static void display( File c) {
		Scanner s=null;
		try { s = new Scanner ( c ); }
		catch (FileNotFoundException e) {
			System.out.println("File not found .\n");
			System.exit(0);
		}
		System.out.println("Printing the File.");
		while (s.hasNextLine()) System.out.println(s.nextLine());
	}
}
		