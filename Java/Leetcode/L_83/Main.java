package Leetcode.L_83;

public class Main {
    public static void main(String[] args) {
        method2 method=new method2();
        method.addFirstNum(1);
        method.addFirstNum(1);
        method.addFirstNum(1);
        method.addFirstNum(4);
        method.addFirstNum(4);
        method.addFirstNum(4);
        method.addFirstNum(5);
        method.addFirstNum(5);
        method.addFirstNum(6);
        method.removeDup();
        method.show();
    }
}
class node{
    int num;
    node right;
    node(int numIn){
        num=numIn;
        right=null;
    }
}
class linkList{
    node head;
    linkList(){
        head=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.right=head;
        }
        head=newNode;
    }
    void showLL(){
        for(node curr=head;curr!=null;curr=curr.right){
            System.out.printf("%d ", curr.num);
        }
    }
}
class method1{
    linkList list=new linkList();
    void addFirstNum(int newNum){
        list.addFirst(newNum);
    }
    void bypassNode(node startNode, node endNode){
        startNode.right=endNode.right;
        endNode.right=null;
    }
    void removeDup(){
        node curr=list.head;
        node comp=curr.right;
        
    }
    void show(){
        list.showLL();
    }
}
class method2{
    linkList list=new linkList();
    void addFirstNum(int newNum){
        list.addFirst(newNum);
    }
    void show(){
        list.showLL();
    }
    void deleteNode(int targNum){
        node delNode;
        node currNode;
        if(list.head.num==targNum){
            delNode=list.head;
            list.head=list.head.right;
            delNode.right=null;
        }
        else{
            for(currNode=list.head;currNode.right.num!=targNum;currNode=currNode.right){}
            delNode=currNode.right;
            currNode.right=delNode.right;
            delNode.right=null;
        }
    }
    void removeDup(){
        node currNode=list.head;
        while(currNode!=null){
            if(currNode.right==null){
                break;
            }
            else{
                if(currNode.num==currNode.right.num){
                    deleteNode(currNode.num);
                    currNode=list.head;
                }
                currNode=currNode.right;
            }
        }
    }
}