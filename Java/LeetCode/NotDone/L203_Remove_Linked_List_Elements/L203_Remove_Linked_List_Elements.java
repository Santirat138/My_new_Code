package LeetCode.NotDone.L203_Remove_Linked_List_Elements;

public class L203_Remove_Linked_List_Elements {
    public static void main(String[] args){
        linkList list=new linkList();
        list.addLast(1);
        list.addLast(2);
        list.addLast(2);
        list.addLast(2);
        list.addLast(3);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        list.show(list.head);
        list.removeNum(4);
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
    node loopFindPrevNum(int numIn){
        node curr=findNum(head, numIn);
        node prev=head;
        if((curr!=nullNode)&&(prev!=null)&&(curr!=head)){
            while(prev!=null){
                if(prev.next==curr){
                    break;
                }
                else if((prev.next!=null)&&(prev.next!=curr)){
                    prev=prev.next;
                }
            }
        }
        else{
            prev=nullNode;
        }
        return prev;
    }
    //node recursiveFindPrevNum(){}
    void deleteNum(int numIn){
        node del=findNum(head, numIn);
        if(del!=nullNode){
            if((del==head)&&(del!=tail)){
                head=head.next;
                del.next=null;
            }
            else if((del!=head)&&(del==tail)){
                node prev=loopFindPrevNum(tail.num);
                tail=prev;
                tail.next=null;
            }
            else if((del!=head)&&(del!=tail)){
                node prev=loopFindPrevNum(del.num);
                prev.next=del.next;
                del.next=null;
            }
        }
        else{
            System.out.println("End.");
        }
    }
    void removeNum(int numIn){
        node curr=head;
        while(curr!=null){
            if(curr.num==numIn){
                deleteNum(curr.num);
                curr=head;
            }
            curr=curr.next;
        }
    }
}