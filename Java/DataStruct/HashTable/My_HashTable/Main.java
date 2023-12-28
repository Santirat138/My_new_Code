package DataStruct.HashTable.My_HashTable;
public class Main{
    public static void main(String[] args){

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
    void connectNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    node findPos(node currNode, int currPos, int pos){
        if(currPos==pos){
            return currNode;
        }
        else if(currPos<pos){
            return findPos(currNode.next, currPos+1, pos);
        }
        else{
            return nullNode;
        }
    }
    void addAtPos(int pos, int newNum){
        node newNode=new node(newNum);
        if(pos<=1){
            connectNode(newNode, head);
            head=newNode;
        }
        else if(pos>amount){
            connectNode(tail, newNode);
            tail=newNode;
        }
        else{
            node currNode=findPos(head, 1, pos);
            connectNode(currNode.prev, newNode);
            connectNode(newNode, currNode);
        }
        amount++;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
        currNode=tail;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
    }
    void deleteNode(node nodeIn){
        if(nodeIn==head){
            head=head.next;
            head.prev=null;
            nodeIn.next=null;
        }
        else if(nodeIn==tail){
            tail=tail.prev;
            tail.next=null;
            nodeIn.prev=null;
        }
        else{
            connectNode(nodeIn.prev, nodeIn.next);
            nodeIn.prev=null;
            nodeIn.next=null;
        }
        amount--;
    }
}
class hashTable{
    int size, key;
    linkList[] arrayStk;
    linkList[] arrayQ;
    hashTable(int sizeIn){
        size=sizeIn;
        arrayStk=new linkList[size];
        arrayQ=new linkList[size];
        
    }
}