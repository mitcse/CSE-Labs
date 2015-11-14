//
//
//
//
//
//
//

package Tree;

public class TNode<T> {

	public T data;

	public TNode left;
	public TNode right;

	public TNode () {
		this.data = null;
		this.left = null;
		this.right = null;
	}

	public TNode (T data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}

	@Override
	public String toString () {
		return "" + this.data + "";
	}

}