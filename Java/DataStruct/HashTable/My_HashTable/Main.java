package DataStruct.HashTable.My_HashTable;
public class Main{
    public static void main(String[] args){
        hashTable table=new hashTable(5);
        
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
    node head;
    node tail;
    node nullNode;
    int amount;

    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
        amount=0;
    }
    void connectNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void addAtPos(int pos, int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
            amount++;
        }
        else{
            if(pos<=1){
                // Add first
                connectNode(newNode, head);
                head=newNode;
                amount++;
            }
            else if(pos>amount){
                // Add Last
                connectNode(tail, newNode);
                tail=newNode;
                amount++;
            }
            else{
                node currNode=head;
                int currPos=1;
                while(currPos<=amount){
                    if(currPos==pos){
                        connectNode(currNode.prev, newNode);
                        connectNode(newNode, currNode);
                        amount++;
                    }
                    else{
                        currNode=currNode.next;
                        currPos++;
                    }
                }
            }
        }
    }
    void show(){
        node currNode=head;
        System.out.print("\nHead --> Tail : ");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
        currNode=tail;
        System.out.print("Tail --> Head : ");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
        System.out.println("\n");
    }
    void swapNode(node n1, node n2) {
    	int temp=n1.num;
    	n1.num=n2.num;
    	n2.num=temp;
    }
    void sortMinMax() {
    	node currNode=head;
    	node lastNode=tail;
    	while(lastNode!=head) {
    		while(currNode!=lastNode) {
    			if(currNode.num>currNode.next.num) {
    				swapNode(currNode, currNode.next);
    			}
    			currNode=currNode.next;
    		}
    		currNode=head;
    		lastNode=lastNode.prev;
    	}
    }
    void deleteNode(node nodeIn) {
    	if(nodeIn==head) {
    		head=head.next;
    		head.prev=null;
    		nodeIn.next=null;
    		amount--;
    	}
    	else if(nodeIn==tail) {
    		tail=tail.prev;
    		tail.next=null;
    		nodeIn.prev=null;
    		amount--;
    	}
    	else if(head==tail) {
    		head=null;
    		tail=null;
    		amount=0;
    	}
    	else {
    		connectNode(nodeIn.prev, nodeIn.next);
    		nodeIn.prev=null;
    		nodeIn.next=null;
    		amount--;
    	}
    }
}
class stack{
    node top;
    node nullNode;

    stack(){
        top=null;
        nullNode=new node(-1);
    }
    void push(int newNum){
        node newNode=new node(newNum);
        if(top!=null){
            newNode.next=top;
        }
        top=newNode;
    }
    node pop(){
        node temp=top;
        top=top.next;
        temp.next=null;
        return temp;
    }
    void show(){
        node currNode=top;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
}
class queue{
    node firstNode;
    node lastNode;
    node nullNode;

    queue(){
        firstNode=null;
        lastNode=null;
        nullNode=new node(-1);
    }
    void enqueue(int newNum){
        node newNode=new node(newNum);
        if((firstNode==null)&&(lastNode==null)){
            firstNode=newNode;
        }
        else{
            lastNode.next=newNode;
        }
        lastNode=newNode;
    }
    node dequeue(){
        node temp=firstNode;
        if(firstNode!=lastNode){
            firstNode=firstNode.next;
            temp.next=null;
        }
        else{
            temp.num=firstNode.num;
            firstNode=null;
            lastNode=null;
        }
        return temp;
    }
    void show(){
        node currNode=firstNode;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
}
class hashTable{
    int size, key;
    linkList[] arrayLL;
    stack[] arrayStk;
    queue[] arrayQ;
    node nullNode;

    hashTable(int sizeIn){
        nullNode=new node(-1);
        size=sizeIn;
        arrayLL=new linkList[size];
        arrayStk=new stack[size];
        arrayQ=new queue[size];
        for(int i=0;i<size;i++){
            arrayLL[i]=new linkList();
            arrayStk[i]=new stack();
            arrayQ[i]=new queue();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insertLastLLNum(int newNum){
        key=findKey(newNum);
        arrayLL[key].addAtPos(arrayLL[key].amount+1, newNum);
    };
    void insertFirstLLNum(int newNum){
        key=findKey(newNum);
        arrayLL[key].addAtPos(0, newNum);
    }
    void insertStkNum(int newNum){
        key=findKey(newNum);
        arrayStk[key].push(newNum);
    }
    void insertQNum(int newNum){
        key=findKey(newNum);
        arrayQ[key].enqueue(newNum);
    }
    void showAll(){
        System.out.println("\tLinkList");
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayLL[i].show();
        }
        System.out.println("");
        System.out.println("\tStack");
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayStk[i].show();
            System.out.println("");
        }
        System.out.println("");
        System.out.println("\tQueue");
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayQ[i].show();
            System.out.println("");
        }
    }
    node findNumInLL(int numIn){
        key=findKey(numIn);
        node currNode=arrayLL[key].head;
        while(currNode!=null){
            if(currNode.num==numIn){
                return currNode;
            }
            else{
                currNode=currNode.next;
            }
        }
        return nullNode;
    }
    void deleteNumInLL(int numIn){
        key=findKey(numIn);
        node currNode=arrayLL[key].head;
        while(currNode!=null) {
        	if(currNode.num==numIn) {
        		break;
        	}
        	else {
        		currNode=currNode.next;
        	}
        }
        arrayLL[key].deleteNode(currNode);
    }
    void sortAll(){
        for(int i=0;i<size;i++){
            arrayLL[i].sortMinMax();
        }
    }
}