package DataStruct.Binary_Tree.Preorder;


public class Main {
    public static void main(String[] args){

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
        if(root==null){
            root=new node(newNum);
        }
        else{
            if(newNum>nodeIn.num){
                if(nodeIn.right==null){
                    nodeIn.right=new node(newNum);
                }
                else{
                    insertNum(nodeIn.right, newNum);
                }
            }
            else if(newNum<nodeIn.num){
                if(nodeIn.left==null){
                    nodeIn.left=new node(newNum);
                }
                else{
                    insertNum(nodeIn.left, newNum);
                }
            }
        }
    }
    void preorder(node currNode){
        
    }
}