package Test.Test_3;

// Find previous node.
public class Main{
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<5;i++){
            list.addLast(i);
        }
        list.showList(list.head);
        list.makeRev();
        list.showList(list.head);
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
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void addLast(int numIn){
        node newNode=new node(numIn);
        if(tail==null){
            head=newNode;
        }
        else{
            tail.next=newNode;
        }
        tail=newNode;
    }
    void showList(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            showList(currNode.next);
        }
        else{
            System.out.println("End");
        }
    }
    node findPrevNode(node nodePrev, node nodeIn){
        if((nodeIn==head)||(nodeIn==null)){
            return nullNode;
        }
        else{
            if(nodePrev.next==nodeIn){
                return nodePrev;
            }
            else{
                return findPrevNode(nodePrev.next, nodeIn);
            }
        }
    }
    void makeRev(){
        node newHead=head;
        node newTail=tail;
        node prevNode;
        do { 
            prevNode=findPrevNode(head, newTail);
            newTail.next=prevNode;
            newTail=prevNode;
            if(newHead==newTail){
                head=tail;
                tail=newHead;
                tail.next=null;
                break;
            }
        } while (prevNode!=nullNode);
    }
}