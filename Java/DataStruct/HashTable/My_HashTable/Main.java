package DataStruct.HashTable.My_HashTable;
// Open Hash Table(2.0LSQ)
public class Main{
    public static void main(String[] args){
        hashTable table=new hashTable(5);
        table.push(1);
        table.push(5);
        table.push(6);
        table.push(15);
        table.push(10);
        table.showStkAll();
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

    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void connectNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head!=null)&&(tail!=null)){
            connectNode(newNode, head);
        }
        else{
            tail=newNode;
        }
        head=newNode;
    }
    int pop(){
        node temp=head;
        if(head!=tail){
            head=head.next;
            head.prev=null;
            temp.next=null;
        }
        else{
            head=nullNode;
        }
        return temp.num;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(head==null){
            head=newNode;
        }
        else{
            connectNode(tail, newNode);
        }
        tail=newNode;
    }
    int dequeue(){
        node temp=tail;
        if(head!=tail){
            temp=tail;
            tail=tail.prev;
            tail.next=null;
            temp.prev=null;
        }
        else{
            temp.num=tail.num;
            tail=nullNode;
        }
        return temp.num;
    }
    void showHeadTail(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
    void showTailHead(){
        node currNode=tail;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
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
        for(int i=0;i<size;i++){
            arrayStk[i]=new linkList();
            arrayQ[i]=new linkList();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void push(int newNum){
        key=findKey(newNum);
        arrayStk[key].addFirst(newNum);
    }
    void enqueue(int newNum){
        key=findKey(newNum);
        arrayQ[key].addLast(newNum);
    }
    void showStkAll(){
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayStk[i].showHeadTail();
            System.out.println("");
        }
    }
    void showQAll(){
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayQ[i].showTailHead();
            System.out.println("");
        }
    }
}