//
//
//
//
//
//
//

package BTTest;

import BinaryTree.*;
import Tree.*;

public class BinaryTreeTest {
	
	public static void main (String [] args) {
		
		BinaryTree tree = new BinaryTree();

		System.out.print("\n\tPreorder: ");
		BinaryTree.preorder(tree);

		System.out.print("\n\tInorder: ");
		BinaryTree.inorder(tree);

		System.out.print("\n\tPostorder: ");
		BinaryTree.postorder(tree);

	}

}