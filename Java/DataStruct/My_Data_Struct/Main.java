package DataStruct.My_Data_Struct;
// DoubleCirLinkList
public class Main {
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.show();
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
    node nullNode;
    node head;
    node tail;
    int amount;

    linkList(){
        nullNode=new node(-1);
        head=null;
        tail=null;
        amount=0;
    }
    void connectNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            tail=newNode;
        }
        else{
            connectNode(newNode, head);
        }
        head=newNode;
        connectNode(tail, head);
        amount++;
    }
    void show(){
        node currNode=head;
        int currPos=1;
        System.out.println("Head --> Tail.");
        while(currNode!=nullNode) {
    		if((currPos>amount)||(currNode.next==null)) {
    			currNode=tail;
    			currPos=amount;
    			break;
    		}
    		else {
            	System.out.printf("%d ", currNode.num);
        		currNode=currNode.next;
        		currPos++;
    		}
        }
        System.out.println("\nTail --> Head.");
        while(currNode!=nullNode) {
        	if(currPos<1) {
        		break;
        	}
        	else {
            	System.out.printf("%d ", currNode.num);
        		currNode=currNode.prev;
        		currPos--;
        	}
        }
    }
}