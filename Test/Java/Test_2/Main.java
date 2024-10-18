package Test_2;

public class Main {
    public static void main(String[] args) {
        BST bst=new BST();
        bst.root=bst.addNum(bst.root, 50);
        bst.root=bst.addNum(bst.root, 40);
        bst.root=bst.addNum(bst.root, 45);
        bst.root=bst.addNum(bst.root, 30);
        bst.root=bst.addNum(bst.root, 60);
        bst.showPostorder(bst.root);    
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
class toolsBox{
    int countHeight(node currNode){
        if(currNode==null){
            return 0;
        }
        int L_Height=countHeight(currNode.left);
        int R_Height=countHeight(currNode.right);
        return Math.max(L_Height, R_Height)+1;
    }
}
class BST{
    node root;
    BST(){
        root=null;
    }
    node addNum(node currNode, int newNum){
        if(currNode==null){
            return new node(newNum);
        }
        if(currNode.num<newNum){
            currNode.right=addNum(currNode.right, newNum);
        }
        else if(currNode.num>newNum){
            currNode.left=addNum(currNode.left, newNum);
        }
        return currNode;
    }
    void showPostorder(node currNode){
        if(currNode!=null){
            showPostorder(currNode.left);
            showPostorder(currNode.right);
            System.out.printf("%d ", currNode.num);  
        }
    }
    
}