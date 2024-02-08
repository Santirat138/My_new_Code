public class Reverse_Linked_List {
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<5;i++) {
        	list.addLast(i);
        }
        list.show(list.head);
        list.setRev();
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
    node curr;
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
    void setRev() {
    	while(head!=tail) {
    		curr=head;
    		head=head.next;
    		if(tail.next!=null) {
    			curr.next=tail.next;
    			tail.next=curr;
    		}
    		else if(tail.next==null) {
    			tail.next=curr;
    			curr.next=null;
    		}
    	}		
    }
}