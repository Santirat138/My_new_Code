package test_1;

public class Main{
    public static void main(String[] args) {
        
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
    void insertNum(node currNode, int newNum){
        if(root==null){
            root=new node(newNum);
        }
        else{
            if(currNode.num<newNum){
                insertNum(currNode.right, newNum);
            }
            else if(currNode.num>newNum){
                insertNum(currNode.left, newNum);
            }
            else{
                System.out.println("Same number.");
            }
        }
    }
    void showPreorder(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            showPreorder(currNode.left);
            showPreorder(currNode.right);
        }
        else{
            System.out.print("null ");
        }
    }
    node findMaxLeftNode(node currNode){
        if(root==null){
            return root;
        }
        else{
            currNode=currNode.left;
            while(currNode.right!=null){
                currNode=currNode.right;
            }
            return currNode;
        }
    }
    node findMinRightNode(node currNode){
        if(root==null){
            return root;
        }
        else{
            currNode=currNode.right;
            while(currNode.left!=null){
                currNode=currNode.left;
            }
            return currNode;
        }
    }
    void deleteKey(int key) {
        root = deleteNode(root, key);
    }
    node deleteNode(node currNode, int key) {
        // Base case: if the tree is empty
        if (currNode == null){
            return currNode;
        }
    
        // Otherwise, recur down the tree
        if (key < currNode.num){
            currNode.left = deleteNode(currNode.left, key);
        }
        else if (key > currNode.num){
            currNode.right = deleteNode(currNode.right, key);
        }
        else {
            // Node with only one child or no child
            if (currNode.left == null){
                return currNode.right;
            }
            else if (currNode.right == null){
                return currNode.left;
            }
    
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            currNode.num = findMinRightNode(currNode).num;
    
            // Delete the inorder successor
            currNode.right = deleteNode(currNode.right, currNode.num);
        }
    
        return root;
    }
}