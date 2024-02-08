public class Remove_Duplicates_from_Sorted_List {
    public static void main(String[] args){
        linkList list=new linkList();
        list.addLast(1);
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(3);
        list.addLast(3);
        list.addLast(5);
        list.addLast(5);
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
    linkList(){
        head=null;
        tail=null;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(tail!=null){
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
    void removeDup(){
        node start=head;
        while(start!=null && start.next!=null) {
            if(start.num==start.next.num) {
                node curr=start.next;
                while(curr!=null && curr.num==start.num) {
                    curr=curr.next;
                }
                start.next=curr;
            }
            start=start.next;
        }
        
    }
}