package test_bst;

public class Main {
    public static void main(String[] args) {
        BST bst=new BST();
        for(int i=1;i<=5;i++){
            bst.insertNum(bst.root, i*2);
        }
        for(int i=0;i<5;i++){
            bst.insertNum(bst.root, (i*2)+1);
        }
        bst.showLevelorder();
    }   
}
//------------------------ class node

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
//------------------------ class toolsBox
class toolsBox{
    void printNode(node nodeIn){
        System.out.printf("%d ", nodeIn.num);
    }
    void printTxt(String strIn){
        System.out.println(strIn);
    }
}
//------------------------ class BST
class BST{
    toolsBox tool;
    node root;
    BST(){
        tool=new toolsBox();
        root=null;
    }
    void insertNum(node currNode, int newNum){
        if(root==null){
            root=new node(newNum);
        }
        if(currNode.num<newNum){
            if(currNode.right!=null){
                insertNum(currNode.right, newNum);
            }
            else{
                currNode.right=new node(newNum);
            }
        }
        else if(currNode.num>newNum){
            if(currNode.left!=null){
                insertNum(currNode.left, newNum);
            }
            else{
                currNode.left=new node(newNum);
            }
        }
    }
    void showPreorder(node currNode){
        if(currNode==null){
            return null;
        }
        else{
            tool.printNode(currNode);
            showPreorder(currNode.left);
            showPreorder(currNode.right);
        }
    }
    void showInorder(node currNode){
        // Left Root Right
        if(currNode==null){
            return ;
        }
        else{
            showInorder(currNode.left);
            tool.printNode(currNode);
            showInorder(currNode.right);
        }
    }
    void showPostorder(node currNode){
        // Left Right Root
        showPostorder(currNode.left);
        showPostorder(currNode.right);
        tool.printNode(currNode);
    }
    void deleteNum(node currNode, int targetNum){
        if(currNode==null){
            return null;
        }
        if(currNode.num<targetNum){
            deleteNum(currNode.right, targetNum);
        }
        else if(currNode.num>targetNum){
            deleteNum(currNode.left, targetNum);
        }
        else if(currNode.num==targetNum){
            if((currNode.left==null)&&(currNode.right==null)){
                currNode=null;
            }
            else if((currNode.left!=null)&&(currNode.right!=null)){
                node maxLeftNode=findMaxLeftNum(currNode);
                currNode.num=maxLeftNode.num;
                deleteNum(currNode.left, maxLeftNode.num);
            }
            else if(currNode.left==null){
                currNode=currNode.right;
            }
            else if(currNode.right==null){
                currNode=currNode.left;
            }
        }
    }
    node findMaxLeftNum(node currNode){
        if(currNode==null){
            return null;
        }
        if(currNode.left!=null){
            currNode=currNode.left;
            while(currNode.right!=null){
                currNode=currNode.right;
            }
            return currNode;
        }
        return null;
    }
    int findTreeHeight(node currNode){
        if(currNode==null){
            return -1;
        }
        // Postorder(left -> right -> root)
        int leftHeight=findTreeHeight(currNode.left);
        int rightHeight=findTreeHeight(currNode.right);
        if(leftHeight<rightHeight){
            return leftHeight+1;
        }
        else{
            return rightHeight+1;
        }
    }
    void showCurrLevel(node currNode, int levelIn){
        if(currNode==null){
            tool.printTxt("null");
        }
        if(levelIn==0){
            tool.printNode(currNode);
        }
        else{
            showCurrLevel(currNode.left, levelIn-1);
            showCurrLevel(currNode.right, levelIn-1);
        }
    }
    void showLevelorder(){
        int treeHeight=findTreeHeight(root);
        for(int i=0;i<=treeHeight;i++){
            showCurrLevel(root, i);
        }
    }
}

