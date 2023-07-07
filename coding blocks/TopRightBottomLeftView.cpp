// import java.util.*;
// import java.io.*;
// public class Main {
//     public static void main(String args[]) throws Exception{
//         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//         String[] arr=br.readLine().split(" ");
//         BinaryTree bt=new BinaryTree(arr);

//         bt.bottomView();

//     }
// }

// class BinaryTree
// {
//     private class Node
//     {
//         int data;
//         Node left,right;
//         Node(int data)
//         {
//             this.data=data;
//         }
//     }
// 	private class Pair {
// 		int stickLvl;
// 		Node node;

// 		public Pair(int stickLvl, Node node) {
// 			this.stickLvl = stickLvl;
// 			this.node = node;
// 		}
// 	}

//     Node root;

//     BinaryTree(String[] arr)
//     {
//         Queue<Node> queue=new LinkedList<Node>();
//         construct(arr,0,queue);
//     }

// ----------------------- Bottom View -------------------

//     public void bottomView()
//     {
//         bottomView(this.root);
//     }

//    private void bottomView(Node root) {
// 	   Queue<Pair> bfs = new LinkedList<>();

// 		bfs.add(new Pair(0, root));

// 		Map<Integer, List<Integer>> map = new TreeMap<>();

// 		while (!bfs.isEmpty()) {

// 			Pair front = bfs.poll();

// 			int stickLvl = front.stickLvl;
// 			Node curr = front.node;

// 			List<Integer> value = map.getOrDefault(stickLvl, new ArrayList<>());
// 			value.add(curr.data);

// 			map.put(stickLvl, value);

// 			if (curr.left != null) {
// 				bfs.add(new Pair(stickLvl - 1, curr.left));
// 			}

// 			if (curr.right != null) {
// 				bfs.add(new Pair(stickLvl + 1, curr.right));
// 			}
// 		}

// 		for (List<Integer> lvl : map.values()) {
// 			// System.out.println(lvl.toString());
// 			for(int x = lvl.size()-1;x>=0;x--){
// 				if(lvl.get(x) != -1){
// 				System.out.print(lvl.get(x)+" ");// case bottom ka -> lvl.size() - 1
// 				break;}
// 			}
// 		}

// 	}

// ------------------ Top View --------------------

// public void topview()
//     {
//         verticalTraversalTop(this.root);
//     }

//    private void verticalTraversalTop(Node root) {
// 	   Queue<Pair> bfs = new LinkedList<>();

// 		bfs.add(new Pair(0, root));

// 		Map<Integer, List<Integer>> map = new TreeMap<>();

// 		while (!bfs.isEmpty()) {

// 			Pair front = bfs.poll();

// 			int stickLvl = front.stickLvl;
// 			Node curr = front.node;

// 			List<Integer> value = map.getOrDefault(stickLvl, new ArrayList<>());
// 			value.add(curr.data);

// 			map.put(stickLvl, value);

// 			if (curr.left != null) {
// 				bfs.add(new Pair(stickLvl - 1, curr.left));
// 			}

// 			if (curr.right != null) {
// 				bfs.add(new Pair(stickLvl + 1, curr.right));
// 			}
// 		}

// 		for (List<Integer> lvl : map.values()) {
// 			if(lvl.get(0) != -1)
// 			System.out.print(lvl.get(0)+" ");// case bottom ka -> lvl.size() - 1
// 		}
//    }

// ------------------ Right View ------------------

// static int maxLvl;
// public void leftView() {
// 	maxLvl =0;
// 	rightSideView(this.root, 1);
// 	return ;
// }

// private void rightSideView(Node root, int lvl) {
// 	if (root == null) {
// 		return;
// 	}

// 	if (maxLvl < lvl) {
// 		if(root.data== -1){
// 			return;
// 		}
// 		System.out.print(root.data+" ");
// 		maxLvl = lvl;
// 	}

// 	rightSideView(root.left, lvl + 1);
// 	rightSideView(root.right, lvl + 1);
// }

//  ----------------------- Left View ----------------------

// static int maxLvl;
//   	public void leftView() {
// 		maxLvl =0;
// 		rightSideView(this.root, 1);
// 		return ;
// 	}

// 	private void rightSideView(Node root, int lvl) {
// 		if (root == null) {
// 			return;
// 		}

// 		if (maxLvl < lvl) {
// 			if(root.data== -1){
// 				return;
// 			}
// 			System.out.print(root.data+" ");
// 			maxLvl = lvl;
// 		}

// 		rightSideView(root.left, lvl + 1);
// 		rightSideView(root.right, lvl + 1);
// 	}

//     private void construct(String[] arr,int ind,Queue<Node> queue)
//     {
//         if(ind>=arr.length)
//         return;
//         if(queue.size()==0)
//         {
//             Node nn=new Node(Integer.parseInt(arr[ind]));
//             this.root=nn;
//             queue.add(nn);
//         }
//         else
//         {
//             Node parent=queue.peek();
//                 if(parent.data!=-1){
//                 if(parent.left==null)
//                 {
//                     parent.left=new Node(Integer.parseInt(arr[ind]));
//                     queue.add(parent.left);
//                 }
//                 else
//                 {
//                     if(parent.right==null)
//                     {
//                     parent.right=new Node(Integer.parseInt(arr[ind]));
//                     queue.add(parent.right);
//                     queue.poll();
//                     }
//                }
//                }
//                else
//                {
//                    queue.poll();
//                    ind--;
//                }
//         }
//         construct(arr,ind+1,queue);
//     }

//     public void display()
//     {
//         display_tree(this.root);
//     }

//     private void display_tree(Node root)
//     {
//         if(root==null)
//         return;
//         String str=root.data+"";
//         if(root.left!=null)
//         {
//             str=root.left.data+" <= "+str;
//         }
//         else
//         {
//             str="END <= "+str;
//         }

//         if(root.right!=null)
//         {
//             str=str+" => "+root.right.data;
//         }
//         else
//         {
//             str=str+" => END";
//         }
//         System.out.println(str);
//         display_tree(root.left);
//         display_tree(root.right);

//     }

// }