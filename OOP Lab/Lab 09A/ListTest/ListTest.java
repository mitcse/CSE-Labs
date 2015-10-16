//
//	ListTest.java
//
//	Created by Avikant Saini on 10/16/15
//

import java.util.Scanner;

class Node <GenericNode> {

	private GenericNode data;
	public Node next;

	public Node () {
		this.next = null;
	}

	public void insert (GenericNode item, Node head) {
		Node node = new Node();
		node.data = item;
		
		Node temp = head;
		while (temp.next != null)
			temp = temp.next;

		temp.next = node;
	}

	public void display (Node head) {
		Node temp = head.next;
		if (temp == null) {
			System.out.println("\n\tEMPRT LIST!");
			return;
		}
		while (temp != null) {
			System.out.print("\t" + temp.data);
			temp = temp.next;
		}
	}

}

public class ListTest {

	public static void main (String [] args) {
		
		Node <Integer> headInt = new Node<>();
		Node <Double> headDob = new Node<>();

		Node <Integer> tempInt = new Node<>();
		Node <Double> tempDob = new Node<>();		

		Scanner sc = new Scanner(System.in);
		int choice;

		do {
			System.out.print("\n\t1. Integer\n\t2. Double\n\tChoice: ");
			choice = sc.nextInt();

			if (choice < 1 || choice > 2) {
				System.out.println("\n\tINVALID CHOICE!");
				System.exit(0);
			}

			int listch;
			do {
				System.out.print("\n\t1. Insert\n\t2. Display\n\tChoice: ");
				listch = sc.nextInt();
				if (listch == 1) {
					if (choice == 1) {
						System.out.print("\n\rEnter integer: ");
						tempInt.insert(new Integer(sc.nextInt()), headInt);
					}
					else if (choice == 2) {
						System.out.print("\n\rEnter double: ");
						tempDob.insert(new Double(sc.nextDouble()), headDob);
					}
				}
				if (choice == 1) {
					System.out.print("Integer List: ");
					tempInt.display(headInt);
				}
				else if (choice == 2) {
					System.out.print("Double List: ");
					tempDob.display(headDob);
				}

			} while(listch == 1 || listch == 2);

		} while (choice == 1 || choice == 2);

	}

}