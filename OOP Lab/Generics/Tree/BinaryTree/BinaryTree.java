//
//
//
//
//
//
//

package BinaryTree;

import Tree.TNode;
import java.util.Scanner;

public class BinaryTree<T> {

	public TNode<T> root;
	protected Scanner sc;

	public BinaryTree () {
		sc = new Scanner(System.in);
		root = build();
	}

	public TNode build () {
		System.out.print("\tEnter data: ");
		String data = sc.nextLine();
		if (data.length() == 0 || data.charAt(0) == '#')
			return null;
		TNode root = new TNode(data);
		System.out.print("\t Left of '" + root.data + "' : ");
		root.left = build();
		System.out.print("\tRight of '" + root.data + "' : ");
		root.right = build();
		return root;
	}

	public void insert (TNode root, T data) {
		TNode temp = new TNode(data);
		if (root == null) {
			root = temp;
			return;
		}
		int ch;
		System.out.print("\tCurrent: " + root.data + " | 1. Left " + 
			((root.left == null)?"(*)":"") + "; 2. Right " + ((root.right == null)?"(*)":"") + 
			" Choice: ");
		ch = sc.nextInt();
		if (ch == 1)
			insert(root.left, data);
		else if (ch == 2)
			insert(root.right, data);
	}

	public static void preorder (BinaryTree tree) {
		preorder(tree.root);
	}

	public static void preorder (TNode root) {
		if (root != null) {
			System.out.print("  " + root.data);
			preorder(root.left);
			preorder(root.right);
		}
	}

	public static void inorder (BinaryTree tree) {
		inorder(tree.root);
	}

	public static void inorder (TNode root) {
		if (root != null) {
			inorder(root.left);
			System.out.print("  " + root.data);
			inorder(root.right);
		}
	}

	public static void postorder (BinaryTree tree) {
		postorder(tree.root);
	}

	public static void postorder (TNode root) {
		if (root != null) {
			postorder(root.left);
			postorder(root.right);
			System.out.print("  " + root.data);
		}
	}

}