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
    int amount;

    linkList(int headNum){
        head=new node(headNum);
        tail=head;
        nullNode=new node(-1);
        amount=1;
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
            amount++;
    	}
    	else {
    		while(compNode!=null) {
    			if(compNode.next==null) {
    				connectNode(tail, newNode);
    				tail=newNode;
                    amount++;
    				break;
    			}
    			else {
    				if(compNode.next.num>newNode.num) {
    					connectNode(newNode, compNode.next);
    					connectNode(compNode, newNode);
                        amount++;
    					break;
    				}
    				else {
    					compNode=compNode.next;
    				}
    			}
    		}
    	}
    }
    void showAtHead(node currNode){
        if(currNode==null){
            System.out.print(" End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showAtHead(currNode.next);
        }
    }
    void showAtTail(node currNode){
        if(currNode==null){
            System.out.print(" End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showAtTail(currNode.prev);
        }
    }
    void showAll(){
        showAtHead(head);
        System.out.println("");
        showAtTail(tail);
    }
}