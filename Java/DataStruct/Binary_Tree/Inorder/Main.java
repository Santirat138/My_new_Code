package DataStruct.Binary_Tree.Inorder;

// Test binary tree
public class Main{
    public static void main(String[] args){
        tree t1=new tree();
        t1.insertNum(t1.root, 70);
        t1.insertNum(t1.root, 30);
        t1.insertNum(t1.root, 80);
        t1.insertNum(t1.root, 5);
        t1.insertNum(t1.root, 50);
        t1.insertNum(t1.root, 40);
        t1.insertNum(t1.root, 60);
        t1.preorder(t1.root);
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
class tree{
    node root;
    node nullNode;

    tree(){
        root=null;
        nullNode=new node(-1);
    }
    void insertNum(node nodeIn, int newNum){
        if(nodeIn==null){
            root=new node(newNum);
        }
        else if(newNum<nodeIn.num){
            if(nodeIn.left==null){
                nodeIn.left=new node(newNum);
            }
            else{
                insertNum(nodeIn.left, newNum);
            }
        }
        else if(newNum>nodeIn.num){
            if(nodeIn.right==null){
                nodeIn.right=new node(newNum);
            }
            else{
                insertNum(nodeIn.right, newNum);
            }
        }
    }
    void preorder(node nodeIn){
        if(nodeIn!=null){
            System.out.printf("Now is '%d' ", nodeIn.num);
            System.out.printf("\nGo left of node %d.\n", nodeIn.num);
            preorder(nodeIn.left);
            System.out.printf("End node left of %d. ", nodeIn.num);
            System.out.printf("Go right of node %d.\n", nodeIn.num);
            preorder(nodeIn.right);
            System.out.printf("End node right of %d\n\n", nodeIn.num);
        }
        else{
            System.out.println("-null-");
        }
    }
}