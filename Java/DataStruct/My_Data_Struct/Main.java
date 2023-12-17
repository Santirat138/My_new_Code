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
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            connectNode(tail, newNode);
        }
        tail=newNode;
        connectNode(tail, head);
        amount++;
    }
    void show(){
        node currNode=head;
        int currPos=1;
        System.out.println("Head --> Tail.");
        while(currNode!=nullNode) {
    		if((currPos>amount)||(currNode==null)) {
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
        	if((currPos<1)||(currNode==null)) {
                currNode=head;
                currPos=1;
        		break;
        	}
        	else {
            	System.out.printf("%d ", currNode.num);
        		currNode=currNode.prev;
        		currPos--;
        	}
        }
        System.out.println("");
    }
    node headFindNode(node currNode, int currPos, int pos){
        if((currNode==null)||(currPos>amount)){
            return nullNode;
        }
        else{
            if(currPos==pos){
                return currNode;
            }
            else{
                return headFindNode(currNode.next, currPos+1, pos);
            }
        }
    }
    node tailFindNode(node currNode, int currPos, int pos){
        if((currNode==null)||(currPos<1)){
            return nullNode;
        }
        else{
            if(currPos==pos){
                return currNode;
            }
            else{
                return tailFindNode(currNode.prev, currPos--, pos);
            }
        }
    }
    node headFindNum(node currNode, int num){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currNode.num==num){
                return currNode;
            }
            else{
                return headFindNum(currNode.next, num);
            }
        }
    }
    node tailFindNum(node currNode, int num){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currNode.num==num){
                return currNode;
            }
            else{
                return tailFindNum(currNode.prev, num);
            }
        }
    }
    void addAtPos(int pos, int newNum){
        if(pos<=1){
            addFirst(newNum);
        }
        else if(pos>amount){
            addLast(newNum);
        }
        else{
            node currNode=headFindNode(head, 1, pos);
            node newNode=new node(newNum);
            connectNode(currNode.prev, newNode);
            connectNode(newNode, currNode);
            amount++;
        }
    }
    void deleteFirst(){
        node delNode=head;
        head=delNode.next;
        head.prev=null;
        delNode.next=null;
        amount--;
    }
    void deleteLast(){
        node delNode=tail;
        tail=delNode.prev;
        tail.next=null;
        delNode.prev=null;
        amount--;
    }
    void deleteAt(int pos){
        node currNode=headFindNode(head, 1, pos);
        if(currNode!=nullNode){
            if(currNode==head){
                deleteFirst();
            }
            else if(currNode==tail){
                deleteLast();
            }
            else{
                connectNode(currNode.prev, currNode.next);
                currNode.prev=null;
                currNode.next=null;
                amount--;
            }
        }
        else{
            System.out.println("Can't delete.");
        }
    }
    void swapNode(int pos1, int pos2){
        node node1=headFindNode(head, 1, pos1);
        
    }
}