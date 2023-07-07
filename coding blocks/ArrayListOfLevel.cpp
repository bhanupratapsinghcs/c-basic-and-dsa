// import java.util.*;
// public class Main {

// 	static Scanner scn = new Scanner(System.in);

// 	public static void main(String[] args) {
// 		Main m = new Main();
// 		BinaryTree bt1 = m.new BinaryTree();
// 		System.out.println(bt1.levelArrayList());
// 	}

// 	private class BinaryTree {
// 		private class Node {
// 			int data;
// 			Node left;
// 			Node right;
// 		}

// 		private Node root;
// 		private int size;

// 		public BinaryTree() {
// 			this.root = this.takeInput(null, false);
// 		}

// 		public Node takeInput(Node parent, boolean ilc) {

// 			int cdata = scn.nextInt();
// 			Node child = new Node();
// 			child.data = cdata;
// 			this.size++;

// 			// left
// 			boolean hlc = scn.nextBoolean();

// 			if (hlc) {
// 				child.left = this.takeInput(child, true);
// 			}

// 			// right
// 			boolean hrc = scn.nextBoolean();

// 			if (hrc) {
// 				child.right = this.takeInput(child, false);
// 			}

// 			// return
// 			return child;
// 		}
// 		private ArrayList<ArrayList<Integer>> lvlOrder(Node root) {

// 		Queue<Node> bfs = new LinkedList<>();

// 		bfs.add(root);
// 		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
// 		while(!bfs.isEmpty()) {

// 			ArrayList<Integer> currLvl = new ArrayList<>();
// 			int numNodesAtCurrLvl = bfs.size();//2

// 			for(int i = 0; i < numNodesAtCurrLvl; i++) {//0, 1
// 				Node front = bfs.poll();
// 				currLvl.add(front.data);

// 				if(front.left != null) {
// 					bfs.add(front.left);
// 				}

// 				if(front.right != null) {
// 					bfs.add(front.right);
// 				}
// 			}

// 			ans.add(currLvl);
// 		}

// 		return ans;
// 	}
// 		public ArrayList<ArrayList<Integer>> levelArrayList() {
// 			return this.lvlOrder(this.root);
// 		}
// 	}

// }
