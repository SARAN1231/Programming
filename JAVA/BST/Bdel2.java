package BST;

class Node
{
   int data;
   Node left,right;    
   Node(int data)
   {
       this.data=data;
       left=null;
       right=null;
   }
}
class BSTDeletion
{
   Node root;  
   public BSTDeletion()
   {
        root=null;
   }
   public void inorder(Node node)
   {
       if(node==null)
           return;
       inorder(node.left);
       System.out.print(node.data+" ");
       inorder(node.right);
   } 
  
    public  Node  deleteNode(Node node,int data)
   {
       if(node==null) 
       return node;
       if(data>node.data)
           node.right=deleteNode(node.right,data);
       else if(data<node.data)
       {
           node.left=deleteNode(node.left,data);
       }
       else {
       if(node.left==null)    
           return node.right;
       else if(node.right==null)
           return node.left;
           node.data=minimumValue(node.left);
        node.left=deleteNode(node.left,node.data);  
        }
       return node;
   }
   public int minimumValue(Node node)
   {
       int min;
       for(min=node.data;node.right!=null;node=node.right)
       min=node.right.data;
       return min; 
   }
}
public class Bdel2{
   public static void main(String[] args)
   {   BSTDeletion tree=new BSTDeletion();
       tree.root=new Node(70);
       tree.root.left=new Node(50);
       tree.root.right=new Node(80);
       tree.root.left.left=new Node(30);
       tree.root.left.right=new Node(60);
       tree.root.right.left=new Node(75);
       tree.root.right.right=new Node(95);
       System.out.println("Inorder Traversal of a Binary Search Tree");
       tree.inorder(tree.root); 
       tree.deleteNode(tree.root,60);
       System.out.println();
       System.out.println("Inorder Traversal After deleting a Node 60");
       tree.inorder(tree.root); 
       tree.deleteNode(tree.root,50);
       System.out.println();
       System.out.println("Inorder Traversal After deleting a Node 50");
       tree.inorder(tree.root);
       tree.deleteNode(tree.root,80);
       System.out.println();
       System.out.println("Inorder Traversal After deleting a Node 80"); 
       tree.inorder(tree.root); 
   } 
}