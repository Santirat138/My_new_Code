package DataStruct.Single_Linklist;

public class Main {
    public static void main(String[] args){
        linkList list1=new linkList();
        list1.add(1);
        list1.add(2);
        list1.add(3);
        list1.show();
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
    linkList(){
        head=null;
    }
    void add(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
}