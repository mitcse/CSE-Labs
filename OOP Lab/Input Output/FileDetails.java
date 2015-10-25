//
//
//
//
//
//
//

import java.io.*;
import java.util.*;

public class FileDetails {

	public static void main (String [] args) throws IOException {
		
		FileInputStream fin = null;
		Scanner fileScanner = null;

		int linesCount = 0, wordsCount = 0;
		long charactersCount = 0, digitsCount = 0, specialCharacters = 0;

		try {

			fin = new FileInputStream(new File(args[0]));
			fileScanner = new Scanner(fin);

			while (fileScanner.hasNextLine()) {

				linesCount++;
				
				String str = fileScanner.nextLine();
				StringTokenizer st = new StringTokenizer(str);

				wordsCount += st.countTokens();

				for (char ch : str.toCharArray()) {
					if (isCharacter(ch))
						charactersCount++;
					else if (isDigit(ch))
						digitsCount++;
					else if (ch != ' ')
						specialCharacters++;
				}
			}

		}
		finally {
			fin.close();
			fileScanner.close();
		}

		System.out.println(	"\n\t File name | " + args[0] +
							"\n\t     Lines | " + linesCount + 
							"\n\t     Words | " + wordsCount + 
							"\n\tCharacters | " + charactersCount + 
							"\n\t    Digits | " + digitsCount + 
							"\n\t   Special | " + specialCharacters + "\n\n");

	}

	private static boolean isCharacter (char ch) {
		return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
	}

	private static boolean isDigit (char ch) {
		return (ch >= '0' && ch <= '9');
	}

}