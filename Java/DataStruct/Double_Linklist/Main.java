package DataStruct.Double_Linklist;

public class Main {
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<=5;i++){
            list.addFirst(i);
        }
        list.showList();
    }
}
class node{
    int num;
    node prev;
    node next;
    node(int numIn){
        num=numIn;
        prev=null;
        next=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void linkNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            linkNode(newNode, head);
        }
        else if(head==null){
            tail=newNode;
        }
        head=newNode;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(tail!=null){
            linkNode(tail, newNode);
        }
        else if(tail==null){
            head=newNode;
        }
        tail=newNode;
    }
    void showH(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showH(currNode.next);
        }
    }
    void showT(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showT(currNode.prev);
        }
    }
    void showList(){
        showH(head);
        showT(tail);
    }
    void addSort()
} 