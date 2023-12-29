package DataStruct.Test_Space.LinkList_Tree;

public class Main{
    public static void main(String[] args){
        llTree tree=new llTree();
        tree.root=new node(50);
        tree.root.left=new node(25);
        tree.root.left.left=new node(20);
        tree.root.left.right=new node(30);
        tree.root.right=new node(75);
        tree.root.right.right=new node(80);

        tree.show(tree.root);
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
class llTree{
    node root;
    node nullNode;

    llTree(){
        nullNode=new node(-1);
        root=null;
    }
    void show(node currNode){
        if(currNode==null){
            System.out.print(" NULL. ");
            return;
        }
        else{
            show(currNode.left);
            System.out.printf("%d ", currNode.num);
            show(currNode.right);
        }
    }
}