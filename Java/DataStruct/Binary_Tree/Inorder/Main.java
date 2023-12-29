package DataStruct.Binary_Tree.Inorder;

public class Main {
    public static void main(String[] args){
        biTree tree=new biTree(50);
        tree.root.left=new node(40);
        tree.root.right=new node(60);
        tree.root.left.left=new node(20);

        tree.showInorder(tree.root);
    }
}
class node{
    int num;
    node left;
    node right;

    node(int numIn){
        num=numIn;
        left=null;
        right=null;
    }
}
class biTree{
    node root;

    biTree(int rootIn){
        root=new node(rootIn);
    }
    void showInorder(node currNode){
        if(currNode==null){
            //System.out.println("End");
            return;
        }
        else{
            showInorder(currNode.left);
            System.out.printf("%d ", currNode.num);
            showInorder(currNode.right);
        }
    }
}