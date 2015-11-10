import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Count
{
        public static void main(String...args) throws IOException
        {
            int char_count=0, i, line_count=0, words=0, numbers=0;
            boolean isNumber=false;
            char ch;
            FileReader fr = new FileReader("file.txt");
            BufferedReader br = new BufferedReader(fr);
            String str;
            while((str=br.readLine())!=null)
            {  
                char_count+= str.length();
                for(i=0;i<str.length();i++)
                {
                    ch=str.charAt(i);
                    if(ch=='.')
                        line_count++;
                    if(ch==' ')
                        words++;
                    if(ch>47&&ch<58)
                        isNumber=true;
                    else if(isNumber)
                    {
                        isNumber=false;
                        numbers++;
                    }
                }
            }
                System.out.print("\n Number of lines in the text file : "+line_count);
                System.out.print("\n Number of words in the text file :"+words);
                System.out.print("\n Number of numbers in the text file : "+numbers);
                System.out.print("\n Number of characters in the text file :"+char_count+"\n");
        }
}
