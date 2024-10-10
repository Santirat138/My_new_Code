package test_bst;

public class Main{
    public static void main(String[] args) {
        BST bst=new BST();
        bst.addNum(bst.root, 50);
        bst.addNum(bst.root, 40);
        bst.addNum(bst.root, 45);
        bst.addNum(bst.root, 70);
        bst.addNum(bst.root, 60);
        bst.addNum(bst.root, 65);
        bst.showPostorder(bst.root);
        /* bst.showLevelorder(); */
        System.out.printf("%d", bst.tool.countHeight(bst.root));
    }
}
class node{
    int num;
    int height;
    node left;
    node right;
    node(int numIn){
        num=numIn;
        height=1;
        left=null;
        right=null;
    }
}

class toolsBox{
    void showNode(node nodeIn){
        System.out.printf("%d ", nodeIn.num);
    }
    void showStr(String strIn){
        System.out.println(strIn);
    }
    int getHeight(node nodeIn){
        if(nodeIn==null){
            return 0;
        }
        else{
            return nodeIn.height;
        }
    }
    int countHeight(node currNode){
        // Postorder (left --> right --> root)
        if(currNode==null){
            return 0;
        }
        int currHeight;
        int L_Height=countHeight(currNode.left);
        int R_Height=countHeight(currNode.right);
        if(L_Height>R_Height){
            currHeight=L_Height;
        }
        else{
            currHeight=R_Height;
        }
        return currHeight+1;
    }
}

class BST{
    node root;
    toolsBox tool;
    BST(){
        root=null;
        tool=new toolsBox();
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
    void showCurrLevel(node currNode, int levelIn){
        if(currNode==null){
            System.exit(0);
        }
        if(levelIn==0){
            tool.showNode(currNode);
        }
        else{
            showCurrLevel(currNode.left, levelIn-1);
            showCurrLevel(currNode.right, levelIn-1);
        }
    }
    void showLevelorder(){
        int treeHeight=tool.countHeight(root);
        for(int i=0;i<=treeHeight;i++){
            showCurrLevel(root, i);
        }
    }
    // Postorder (left --> right --> root)
    void showPostorder(node currNode){
        if(currNode==null){
            System.exit(0);
        }
        showPostorder(currNode.left);
        showPostorder(currNode.right);
        tool.showNode(currNode);
    }
}