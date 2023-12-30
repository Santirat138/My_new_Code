package DataStruct.My_Data_Struct;
// Do sort when add new number.
public class Main{
    public static void main(String[] args){
        linkList list1=new linkList(5);
        list1.addNum(10);
        list1.addNum(25);
        list1.addNum(20);
        list1.addNum(30);
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
    	if(head!=tail) {
    		while(compNode!=null) {
    			if(newNum<compNode.num) {
					connectNode(newNode, head);
					head=newNode;
					break;
    			}
    			else if(newNum>compNode.num) {
    				if(compNode==tail) {
    					connectNode(tail, newNode);
    					tail=newNode;
    					break;
    				}
    				else {
    					if(compNode.next.num>newNum) {
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
    	else if(head==tail){
    		if(newNode.num<head.num) {
    			connectNode(newNode, head);
    			head=newNode;
    		}
    		else if(newNode.num>head.num) {
    			connectNode(tail, newNode);
    			tail=newNode;
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