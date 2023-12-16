// cirLinkList, DoubleLinkList
public class MyLinkList {
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.show();
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
    int amount;
    node nullNode=new node(-1);
    node head;
    node tail;

    linkList(){
        amount=0;
        head=null;
        tail=null;
    }
    void connectNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            tail=newNode;
        }
        else{
            connectNode(newNode, head);
        }
        head=newNode;
        connectNode(tail, head);
        amount++;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            connectNode(tail, newNode);
        }
        tail=newNode;
        connectNode(tail, head);
        amount++;
    }
    void show(){
        node currNode=head;
        System.out.println("Head --> Tail.");
        for(int i=0;i<amount;i++){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        currNode=tail;
        System.out.println("Tail --> Head.");
        for(int i=0;i<amount;i++){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
    }
}
