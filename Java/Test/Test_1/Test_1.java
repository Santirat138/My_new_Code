package Test.Test_1;


public class Test_1 {
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
        list.recursiveRemoveNum(list.head, 2);
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
        if(currNode!=head){
            if(currNode.next.num==numTarget){
                return currNode;
            }
            else{
                return recursiveFindPrevNum(currNode.next, numTarget);
            }
        }
        else{
            return nullNode;
        }
    }
    void deleteNum(node del, int numIn){
        if(del.num==numIn){
            if((del==head)&&(del!=tail)){
                head=head.next;
                del.next=null;
            }
            else if((del!=head)&&(del==tail)){
                node prev=recursiveFindPrevNum(head, tail.num);
                tail=prev;
                tail.next=null;
            }
            else if((del!=head)&&(del!=tail)){
                node prev=recursiveFindPrevNum(head, del.num);
                prev.next=del.next;
                del.next=null;
            }
        }
        else{
            deleteNum(del.next, numIn);
        }
    }
    void recursiveRemoveNum(node currNode, int numTarget){
        if(currNode!=null){
            if(currNode.num==numTarget){
                deleteNum(head, numTarget);
            }
            else{
                recursiveRemoveNum(currNode.next, numTarget);
            }
        }
        else{
            System.out.println("End.");
        }
    }
}