//
// PrimitveReadWrite.java
//
//
//	Created by Avikant Saini on 11/9/15
//

import java.io.*;
import java.util.*;

public class PrimitveReadWrite {

	public static void main (String [] args) throws IOException {
		
		FileOutputStream fout = new FileOutputStream("Test.dat");
	    DataOutputStream dos = new DataOutputStream(fout);
	    dos.writeDouble(1812.4008);
	    dos.writeInt(666);
	    dos.writeChar('X');
	    dos.close();


	    BufferedInputStream bufferedInput = new BufferedInputStream(new FileInputStream("Test.dat"));
	    byte[] buffer = new byte[22];
	    bufferedInput.read(buffer);
	    System.out.print("\n\nRaw Read: ");
	    System.out.write(buffer);

	    // Raw Read: @?Q?kP???X


	    FileInputStream fin = new FileInputStream("Test.dat");
	    DataInputStream din = new DataInputStream(fin);
	    double d = din.readDouble();
	    int i = din.readInt();
	    char c = din.readChar();
	    System.out.println("\n\nPrimitve read: " + d + ", " + i + ", " + c);
	    din.close();

	    // Primitve read: 1812.4008, 666, X

	    // Content in the file (visible): @?Q?kP???X

	}

}