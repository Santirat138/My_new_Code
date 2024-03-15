package DataStruct.Binary_Tree.Postorder;

public class Main {
    public static void main(String[] args){
        biTree t1=new biTree();
        t1.insertNum(t1.root, 70);
        t1.insertNum(t1.root, 30);
        t1.insertNum(t1.root, 80);
        t1.insertNum(t1.root, 5);
        t1.insertNum(t1.root, 50);
        t1.insertNum(t1.root, 40);
        t1.insertNum(t1.root, 60);
        t1.postorder(t1.root);
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
    node nullNode;
    biTree(){
        root=null;
        nullNode=new node(-1);
    }
    void insertNum(node nodeIn, int newNum){
        if(nodeIn==null){
            root=new node(newNum);
        }
        else{
            if(newNum<nodeIn.num){
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
    }
    void postorder(node nodeIn){
        if(nodeIn!=null){
            postorder(nodeIn.left);
            postorder(nodeIn.right);
            System.out.printf("%d ", nodeIn.num);
        }
        else{
            System.out.println("-null-");
        }
    }
}