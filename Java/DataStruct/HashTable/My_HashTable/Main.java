package DataStruct.HashTable.My_HashTable;

// Open Hash Table (2.0)
public class Main{
    public static void main(String[] args){
        
    }
}
class node{
    int num;
    node prev;
    node  next;
    
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
        node head=null;
        node tail=null;
        nullNode=new node(-1);
    }
    void connectNode(node node1, node node2){
        node1.next=node2;
        node2.prev=node1;
    }
    void buildHeadTail(int numIn){
        node newNode=new node(numIn);
        head=newNode;
        tail=newNode;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        connectNode(tail, newNode);
    }
    void sort(){
        node currNode=head;
        node lastNode=tail;
        while(lastNode!=head){
            while(currNode!=lastNode){
                if(currNode.num>currNode.next.num){
                    int temp=currNode.num;
                    currNode.num=currNode.next.num;
                    currNode.next.num=temp;
                }
                currNode=currNode.next;
            }
            currNode=head;
            lastNode=lastNode.prev;
        }
    }
    void show(){
        node currNode=head;
        System.out.print("Head --> Tail : ");
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
    }
}
class hashTable{
    int size, key;
    linkList[] arrayLL;
    
    hashTable(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
        for(int i=0;i<size;i++){
            arrayLL[i]=new linkList();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insertNum(int newNum){
        key=findKey(newNum);
        if(arrayLL[key].head==null){
            arrayLL[key].buildHeadTail(newNum);
        }
        else{
            arrayLL[key].addLast(newNum);
        }
    }
    void deleteNum(int numIn){
        key=findKey(numIn);
        node currNode=arrayLL[key].head;
        while(currNode!=null){
            if(currNode.num==numIn){
                currNode.num=-1;
            }
            else{
                currNode=currNode.next;
            }
        }
    }
    void sortAll(){
        for(int i=0;i<size;i++){
            arrayLL[i].sort();
        }
    }
    void showAll(){
        for(int i=0;i<size;i++){
            System.out.printf("\tIndex %d\n", i);
            arrayLL[i].show();
            System.out.println("\n");
        }
    }
}