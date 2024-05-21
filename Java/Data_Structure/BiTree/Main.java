package Data_Structure.BiTree;

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
    }
}
class tree{
    node root;
    node nullNode;
    tree(){
        root=null;
        nullNode=new node(-1);
    }
    void insertNum(node currNode, int newNum){
        if(root==null){
            root=new node(newNum);
        }
        else{
            if(newNum<currNode.num){
                if(currNode.left!=null){
                    insertNum(currNode.left, newNum);
                }
                else{
                    currNode.left=new node(newNum);
                }
            }
            else if(newNum>currNode.num){
                if(currNode.right!=null){
                    insertNum(currNode.right, newNum);
                }
                else{
                    currNode.right=new node(newNum);
                }
            }
        }
    }
}