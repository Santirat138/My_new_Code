package DataStruct.Test_Space.Test_1;

public class Test_1{
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<=5;i++){
            list.addFirst(i);
        }
        list.show(list.head, true);
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
    void linkNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head==null){
            tail=newNode;
        }
        else{
            linkNode(newNode, head);
        }
        head=newNode;
    }
    void show(node currNode, boolean ticket){
        System.out.printf("%d ", currNode.num);
        if(ticket){
            if(currNode!=tail){
                show(currNode.next, true);
            }
            else if(currNode==tail){
                System.out.println("");
                show(currNode, false);
            }
        }
        else if(!ticket){
            if(currNode!=head){
                show(currNode.prev, false);
            }
            else if(currNode==head){
                System.out.print("\nEnd.");
            }
        }
    }
    void addSort(int newNum){
        
    }
}