package LeetCode.Modify_Code.M203_Remove_Linked_List_Elements;

public class L203_Remove_Linked_List_Elements {
    public static void main(String[] args){
        linkList list=new linkList();
        list.addLast(1);
        list.addLast(2);
        list.addLast(2);
        list.addLast(2);
        list.addLast(2);
        list.addLast(2);
        list.addLast(3);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        list.show(list.head);
        list.removeNum(2);
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
    node recursiveFindPrevNum(node currNode, int numTarget){
        if(head.num!=numTarget){
            if(currNode.next.num==numTarget){
                return currNode;
            }
            else if(currNode.next.num!=numTarget){
                return recursiveFindPrevNum(currNode.next, numTarget);
            }
        }
        return nullNode;
    }
    void recursiveDeleteNum(node currNode, int numIn){
        if(currNode.num==numIn){
            if((currNode==head)&&(currNode!=tail)){
                head=head.next;
                currNode.next=null;
            }
            else if((currNode!=head)&&(currNode==tail)){
                node prev=recursiveFindPrevNum(head, tail.num);
                tail=prev;
                tail.next=null;
            }
            else if((currNode!=head)&&(currNode!=tail)){
                node prev=recursiveFindPrevNum(head, currNode.num);
                prev.next=currNode.next;
                currNode.next=null;
            }
        }
        else{
            recursiveDeleteNum(currNode.next, numIn);
        }
    }
    void removeNum(int numIn){
        node curr=head;
        while(curr!=null){
            if(curr.num==numIn){
                recursiveDeleteNum(head, curr.num);
                curr=head;
            }
            curr=curr.next;
        }
    }
}