package LeetCode.Done.L206_Reverse_Linked_List;

public class L206_Reverse_Linked_List {
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<=5;i++){
            list.addLast(i);
        }
        list.show(list.head);
        list.makeRev();
        list.show(list.head);
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
    node newTail;
    node curr;
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head!=null)&&(tail!=null)){
            tail.next=newNode;
        }
        else{
            head=newNode;
        }
        tail=newNode;
    }
    void show(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            show(currNode.next);
        }
    }
    node findNum(node curr, int numIn){
        if(curr==null){
            return nullNode;
        }
        else{
            if(curr.num==numIn){
                return curr;
            }
            else{
                return findNum(curr.next, numIn);
            }
        }
    }
    node findPrevNum(node prev, int currNum){
        if(head.num==currNum){
            return nullNode;
        }
        else{
            if(prev.next.num==currNum){
                return prev;
            }
            else{
                return findPrevNum(prev.next, currNum);
            }
        }
    }
    void makeRev(){
        newTail=tail;
        while(head!=newTail){
            curr=findPrevNum(head, newTail.num);
            newTail.next=curr;
            curr.next=null;
            newTail=curr;
        }
        head=tail;
        tail=newTail;
    }
}