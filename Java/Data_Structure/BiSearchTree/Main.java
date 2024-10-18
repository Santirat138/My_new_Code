package Data_Structure.BiSearchTree;

public class Main {
    public static void main(String[] args){
        BST bst=new BST();
        bst.root=bst.addNum2(bst.root, 50);
        bst.root=bst.addNum2(bst.root, 20);
        bst.root=bst.addNum2(bst.root, 80);
        bst.root=bst.addNum2(bst.root, 15);
        bst.root=bst.addNum2(bst.root, 40);
        bst.root=bst.addNum2(bst.root, 75);
        bst.root=bst.addNum2(bst.root, 35);
        bst.addNum1(45);
        bst.root=bst.deleteNum(bst.root, 45);
        bst.showLevelorder();
    }
}
//------------------- class node
class node{
    int num;
    node left;
    node right;
    int height;
    node(int numIn){
        num=numIn;
        left=null;
        right=null;
        height=1;
    }
}
//------------------- class toolsBox
class toolsBox{
    static int getHeight(node nodeIn){
        if(nodeIn==null){
            return 0;
        }
        return nodeIn.height;
    }
    static int countHeight(node nodeIn){
        if(nodeIn==null){
            return 0;
        }
        int L_Height=getHeight(nodeIn.left);
        int R_Height=getHeight(nodeIn.right);
        return Math.max(L_Height, R_Height)+1;
    }
    static void showNode(node nodeIn){
        System.out.printf("%d ", nodeIn.num);
    }
    static void showStr(String strIn){
        System.out.print(strIn);
    }
    static node findMaxLeftNode(node nodeIn){
        if(nodeIn.left!=null){
            nodeIn=nodeIn.left;
            while(nodeIn.right!=null){
                nodeIn=nodeIn.right;
            }
            return nodeIn;
        }
        return null;
    }
    static node findMinRightNode(node nodeIn){
        if(nodeIn.right!=null){
            nodeIn=nodeIn.right;
            while(nodeIn.left!=null){
                nodeIn=nodeIn.left;
            }
            return nodeIn;
        }
        return null;
    }
    static node findShortSide(node nodeIn){
        if(nodeIn==null){
            return null;
        }
        int L_Height=countHeight(nodeIn.left);
        int R_Height=countHeight(nodeIn.right);
        if(L_Height<R_Height){
            return nodeIn.left;
        }
        return nodeIn.right;
    }
}
//------------------- class BST
class BST{
    node root;
    BST(){
        root=null;
    }
    void addNum1(int newNum){
        if(root==null){
            root=new node(newNum);
        }
        else{
            node currNode=root;
            while(currNode!=null){
                if(currNode.num<newNum){
                    if(currNode.right!=null){
                        currNode=currNode.right;
                    }
                    else{
                        currNode.right=new node(newNum);
                        currNode.height=toolsBox.countHeight(currNode);
                        break;
                    }
                }
                else if(currNode.num>newNum){
                    if(currNode.left!=null){
                        currNode=currNode.left;
                    }
                    else{
                        currNode.left=new node(newNum);
                        currNode.height=toolsBox.countHeight(currNode);
                        break;
                    }
                }
            }
        }

    }
    node addNum2(node currNode, int newNum){
        if(currNode==null){
            currNode=new node(newNum);
        }
        if(currNode.num<newNum){
            currNode.right=addNum2(currNode.right, newNum);
        }
        else if(currNode.num>newNum){
            currNode.left=addNum2(currNode.left, newNum);
        }
        currNode.height=toolsBox.countHeight(currNode);
        return currNode;
    }
    void showCurrLevel(node currNode, int levelIn){
        if(currNode==null){
            return ;
        }
        if(levelIn==0){
            toolsBox.showNode(currNode);
        }
        else{
            showCurrLevel(currNode.left, levelIn-1);
            showCurrLevel(currNode.right, levelIn-1);
        }
    }
    void showLevelorder(){
        int treeHeight=toolsBox.getHeight(root);
        for(int i=0;i<=treeHeight;i++){
            showCurrLevel(root, i);
            toolsBox.showStr("\n");
        }
    }
    node deleteNum(node currNode, int targetNum){
        if(currNode==null){
            return null;
        }
        if(currNode.num<targetNum){
            currNode.right=deleteNum(currNode.right, targetNum);
        }
        else if(currNode.num>targetNum){
            currNode.left=deleteNum(currNode.left, targetNum);
        }
        else{
            if((currNode.left==null)&&(currNode.right==null)){
                return null;
            }
            else if((currNode.left!=null)&&(currNode.right!=null)){
                node temp=toolsBox.findShortSide(currNode);
                currNode.num=temp.num;
                if(temp==currNode.left){
                    int maxLeftNum=toolsBox.findMaxLeftNode(currNode).num;
                    currNode.left=deleteNum(currNode.left, maxLeftNum);
                }
                else if(temp==currNode.right){
                    int minRightNum=toolsBox.findMinRightNode(currNode).num;
                    currNode.right=deleteNum(currNode.right, minRightNum);
                }
            }
            else if(currNode.left==null){
                currNode=currNode.right;
            }
            else if(currNode.right==null){
                currNode=currNode.left;
            }
        }
        return currNode;
    }

}