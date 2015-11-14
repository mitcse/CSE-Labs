import java.util.Scanner;

class Card
{
	int rank;
	char suit[] = new char[20];;

	Card (int r, String s)
	{
		rank = r;
		suit = s.toCharArray();
	}

	int getRank()
	{
		return this.rank;
	}

	char[] getSuit()
	{
		return this.suit;
	}
}

class CardTester
{
	public static void main(String args[])
	{
		System.out.println("The full house of cards is as follows :");

		Card c1 = new Card(1, "Hearts");
		int r1 = c1.getRank();
		String s1 = new String(c1.getSuit());
		System.out.println("Card rank : " +r1 + "\t Suit : " +s1);

		Card c2 = new Card(1, "Spades");
		int r2 = c2.getRank();
		String s2 = new String(c2.getSuit());
		System.out.println("Card rank : " +r2 + "\t Suit : " +s2);

		Card c3 = new Card(2, "Diamonds");
		int r3 = c3.getRank();
		String s3 = new String(c3.getSuit());
		System.out.println("Card rank : " +r3 + "\t Suit : " +s3);

		Card c4 = new Card(2, "Hearts");
		int r4 = c4.getRank();
		String s4 = new String(c4.getSuit());
		System.out.println("Card rank : " +r4 + "\t Suit : " +s4);

		Card c5 = new Card(1, "Clubs");
		int r5 = c5.getRank();
		String s5 = new String(c5.getSuit());
		System.out.println("Card rank : " +r5 + "\t Suit : " +s5);
	}
}
