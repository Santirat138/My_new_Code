package LeetCode.Done.L83_Remove_Duplicates_from_Sorted_List;

public class L83_Remove_Duplicates_from_Sorted_List {
    public static void main(String[] args){
        linkList list=new linkList();
        list.addLast(0);
        list.addLast(1);
        list.addLast(1);
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(3);
        list.addLast(4);
        list.show(list.head);
        list.removeDup();
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
        if(tail==null){
            head=newNode;
        }
        else{
            tail.next=newNode;
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
    void removeDup(){
        node curr=head;
        node check;
        while((curr!=null)&&(curr.next!=null)){
            if(curr.num==curr.next.num){
                check=curr;
                while((check.num==check.next.num)&&(check.next!=null)){
                    check=check.next;
                }
                if((check!=null)&&(check.next.num!=check.num)){
                    curr.next=check.next;
                    check=check.next;
                    curr=curr.next;
                }
                else if(check.next==null){
                    curr.next=null;
                }
            }
            else if(curr.num!=curr.next.num){
                curr=curr.next;
            }
        }
    }
}