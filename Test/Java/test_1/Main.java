package test_1;
// Test bypass node.
public class Main {
    public static void main(String[] args) {
        method1 method=new method1();
        method.addFirstNum(6);
        method.addFirstNum(5);
        method.addFirstNum(4);
        method.addFirstNum(3);
        method.addFirstNum(2);
        method.addFirstNum(1);
        method.BypassNode(method.list.head, method.list.head.right.right.right);
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
    void BypassNode(node startNode, node endNode){
        startNode.right=endNode.right;
        endNode.right=null;
    }
    void show(){
        list.showLL();
    }
}