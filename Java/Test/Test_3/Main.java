package Test.Test_3;

public class Main{
    public static void main(String[] args){
        linkList listObj=new linkList();
        for(int i=0;i<5;i++){
            listObj.addLast(i);
        }
        System.out.printf("%d ", listObj.pop().num);
        System.out.printf("%d ", listObj.pop().num);
    }
}
class node{
    int num;
    node next;
    node(int numIn){
        num=numIn;
        next=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;
    node top;
    linkList(){
        nullNode=new node(-1);
        head=null;
        tail=null;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        else{
            tail=newNode;
        }
        head=newNode;
    }
    node pop(){
        top=head;
        if(top!=null){
            head=head.next;
            top.next=null;
            return top;
        }
        else{
            return nullNode;
        }
    }
}