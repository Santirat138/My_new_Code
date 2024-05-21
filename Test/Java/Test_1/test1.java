// Test binary tree.
package Test_1;

public class test1 {
    public static void main(String[] args){
       tree t=new tree();
       t.insertNum(t.root, 50);
       t.insertNum(t.root, 25);
       t.insertNum(t.root, 75);
       t.insertNum(t.root, 20);
       t.insertNum(t.root, 80);
       t.preorder(t.root);
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
    tree(){
        root=null;
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
                else if(currNode.left==null){
                    currNode.left=new node(newNum);
                }
            }
            else if(newNum>currNode.num){
                if(currNode.right!=null){
                    insertNum(currNode.right, newNum);
                }
                else if(currNode.right==null){
                    currNode.right=new node(newNum);
                }
            }
        }
    }
    void preorder(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            preorder(currNode.left);
            preorder(currNode.right);
        }
    }
}