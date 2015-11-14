//
//
//
//
//
//
//

package BinarySearchTree;

import Tree.*;
import BinaryTree.*;

public class BinarySearchTree<T> extends BinaryTree {

	public BinarySearchTree () {
		super();
	}

	@Override
	public TNode build () {
		String data;
		TNode root = null;
		do {
			System.out.print("\n\tEnter data: ");
			data = sc.nextLine();
			if (!(data.length() == 0 || data.charAt(0) == '#')) {
				if (root == null)
					root = new TNode(data);
				else
					root = insertN(root, (T)data);
			}
		} while (!(data.length() == 0 || data.charAt(0) == '#'));
		return root;
	}

	public TNode insertN (TNode root, T data) {
		if (root == null)
			return (new TNode(data));
		if (data.compareTo(root.data) < 0)
			root.left = insert(root.left, data);
		else if (data.compareTo(root.data) > 0)
			root.right = insert(root.right, data);
		return root;
	}
	
}