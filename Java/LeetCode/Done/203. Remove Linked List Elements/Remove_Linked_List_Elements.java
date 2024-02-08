// From Remove_Linked_List_Elements.
public class Remove_Linked_List_Elements{
    public static void main(String[] args){
    	linkList list=new linkList();
    	list.addFirst(1);
    	list.addFirst(2);
    	list.addFirst(1);
    	list.addFirst(3);
    	list.addFirst(1);
    	list.show(list.head);
    	list.removeNum(1);
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
	node nullNode=new node(-1);
	linkList(){
		head=null;
	}
	void addFirst(int newNum) {
		node newNode=new node(newNum);
		if(head!=null) {
			newNode.next=head;
		}
		else {
			tail=newNode;
		}
		head=newNode;
	}
	void show(node currNode) {
		if(currNode!=null) {
			System.out.printf("%d ", currNode.num);
			show(currNode.next);
		}
		else {
			System.out.println("End.");
		}
	}
	node findPrevNode(node target) {
		node prev=head;
		if(target!=head) {
			while(prev!=null) {
				if(prev.next==target) {
					return prev;
				}
				else {
					prev=prev.next;
				}
			}
		}
		return null;
	}
	node findNum(int numIn) {
		node currNode=head;
		while(currNode!=null) {
			if(currNode.num==numIn) {
				return currNode;
			}
			else {
				currNode=currNode.next;
			}
		}
		return null;
	}
	void deleteNum(int numIn) {
		node targetNode=findNum(numIn);
		if(targetNode==head) {
			head=head.next;
			targetNode.next=null;
		}
		else {
			node prevNode=findPrevNode(targetNode);
			if(targetNode!=tail) {
				prevNode.next=targetNode.next;
				targetNode.next=null;
			}
			else if(targetNode==tail) {
				prevNode.next=null;
			}
		}
	}
	void removeNum(int delNum) {
		node currNode=head;
		while(currNode!=null) {
			if(currNode.num==delNum) {
				deleteNum(delNum);
				currNode=head;
			}
			currNode=currNode.next;
		}
	}
}