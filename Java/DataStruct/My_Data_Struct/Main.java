package DataStruct.My_Data_Struct;
// Do sort when add new number.
public class Main{
    public static void main(String[] args){
        linkList list1=new linkList(5);
        list1.addNum(10);
        list1.addNum(25);
        list1.addNum(20);
        list1.addNum(30);
        list1.addNum(2);
        list1.addNum(7);
        list1.showAll();
    }
}
class node{
    int num;
    node prev;
    node next;
    node(int newNum){
        num=newNum;
        prev=null;
        next=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;

    linkList(int headNum){
        head=new node(headNum);
        tail=head;
        nullNode=new node(-1);
    }
    void connectNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void addNum(int newNum){
    	node newNode=new node(newNum);
    	node compNode=head;
    	if(newNode.num<compNode.num) {
    		connectNode(newNode ,head);
    		head=newNode;
    	}
    	else {
    		while(compNode!=null) {
    			if(compNode.next==null) {
    				connectNode(tail, newNode);
    				tail=newNode;
    				break;
    			}
    			else {
    				if(compNode.next.num>newNode.num) {
    					connectNode(newNode, compNode.next);
    					connectNode(compNode, newNode);
    					break;
    				}
    				else {
    					compNode=compNode.next;
    				}
    			}
    		}
    	}
    }
    void showAll() {
    	node currNode=head;
    	while(currNode!=null) {
    		System.out.printf("%d ", currNode.num);
    		currNode=currNode.next;
    	}
    	currNode=tail;
    	System.out.println("");
    	while(currNode!=null) {
    		System.out.printf("%d ", currNode.num);
    		currNode=currNode.prev;
    	}
    }
}