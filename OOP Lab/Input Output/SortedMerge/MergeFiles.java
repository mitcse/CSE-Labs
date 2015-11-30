package filePackage;
import java.util.*;
import java.io.*;

public class MergeFiles {
	
	Scanner r1=null;
	Scanner r2=null;
	PrintWriter w=null;
	Scanner s=null;
	boolean b1,b2;
	File c = null;

	public MergeFiles(File fa, File fb, File fc) {
		try {
			r1= new Scanner( fa );
			r2= new Scanner( fb );
			w = new PrintWriter( fc );
			c=fc;
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found .\n");
			System.exit(0);
		}
		b1=b2=true;
		System.out.println(w.checkError());
		w.write("Start");
	}
	
	public void add(String s1, String s2) {
		int c = s1.compareTo(s2);
		System.out.println("s1:"+s1+" s2:"+s2+" c:"+c);
		if(c > 0) {
			
			w.println(s2);
			b1=false;
			b2=true;
		}
		else if(c < 0) {
			w.println(s1);
			b2=false;
			b1=true;
		}
		else {
			w.println(s1);
			w.println(s2);
			b1=b2=true;
		}
	}
	
	public void merge() {
		String s1=null,s2=null;
		System.out.println("Merging?");
		while(r1.hasNextLine()&&r2.hasNextLine()) {
			if(b1) s1=r1.nextLine();	//b1 and b2 determine when to read next line.
			if(b2) s2=r2.nextLine();
			add(s1,s2);
		}
		while(r1.hasNextLine()) {
			s1=r1.nextLine();
			w.println(s1);
		}
			
		while(r2.hasNextLine()) {
			s2=r2.nextLine();
			w.println(s2);
		}
		w.println("End");
	}
	
	public void display() {
		try { s = new Scanner ( c ); }
		catch (FileNotFoundException e) {
			System.out.println("File not found .\n");
			System.exit(0);
		}
		System.out.println("Printing the new File."+s.hasNextLine());
		while (s.hasNextLine()) System.out.println(s.nextLine());
	}

	public static void extremeMerge (File in1, File in2, File out) throws FileNotFoundException {
		ArrayList<String> input = new ArrayList<>();
		Scanner sc = new Scanner(in1);
		while (sc.hasNextLine())
			input.add(sc.nextLine());
		sc = new Scanner(in2);
		while (sc.hasNextLine())
			input.add(sc.nextLine());
		Collections.sort(input);
		PrintWriter pw = new PrintWriter(out);
		for (String str : input)
			pw.println(str);
		sc.close();
		pw.close();
	}

	public static void normalMerge (File in1, File in2, File out) throws FileNotFoundException {
		Scanner sc1 = new Scanner(in1);
		Scanner sc2 = new Scanner(in2);
		PrintWriter pw = new PrintWriter(out);
		String s1 = sc1.nextLine(), s2 = sc2.nextLine();
		while ((sc1.hasNextLine()) || (sc2.hasNextLine())) {
			if (s2 == null)
				pw.println(sc1.nextLine());
			else if (s1 == null)
				pw.println(sc2.nextLine());
			else {
				if (s1.compareTo(s2) > 0) {
					pw.println(s2);
					s2 = sc2.nextLine();
				}
				else if (s1.compareTo(s2) < 0) {
					pw.println(s1);
					s1 = sc1.nextLine();
				}
				else {
					pw.println(s1);
					s1 = sc1.nextLine();
					pw.println(s2);
					s2 = sc2.nextLine();
				}
			}

		}
		sc1.close();
		sc2.close();
		pw.close();
	}	

}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			