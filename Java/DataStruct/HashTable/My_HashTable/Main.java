package DataStruct.HashTable.My_HashTable;

// Open Hash Table (1.1)
public class Main{
    public static void main(String[] args){
        hashTable table1=new hashTable(5);
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
    node nullNode;

    linkList(){
        head=null;
        nullNode=new node(-1);
    }
    void buildHead(int newNum){
        node newHead=new node(newNum);
        head=newHead;
    }
    void addNext(int newNum){
        node newNode=new node(newNum);
        node currNode=head;
        while(currNode!=null){
            if(currNode.next==null){
                currNode.next=newNode;
                break;
            }
            else{
                currNode=currNode.next;
            }
        }
    }
    node findPrevNode(node currNode){
        node prevNode=head;
        while(prevNode!=null){
            if(prevNode.next==currNode){
                return prevNode;
            }
            else{
                prevNode=prevNode.next;
            }
        }
        return nullNode;
    }
    void swapNum(node node1, node node2){
        int temp=node1.num;
        node1.num=node2.num;
        node2.num=temp;
    }
    void sort(){
        node currNode=head;
        node lastNode=head;
        while(lastNode!=null){
            if(lastNode.next==null){
                break;
            }
            else{
                lastNode=lastNode.next;
            }
        }
        while(lastNode!=head){
            while(currNode!=lastNode){
                if(currNode.num>currNode.next.num){
                    swapNum(currNode, currNode.next);
                }
                currNode=currNode.next;
            }
            currNode=head;
            lastNode=findPrevNode(lastNode);
        }
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
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
            arrayLL[key].buildHead(newNum);
        }
        else{
            arrayLL[key].addNext(newNum);
        }
    }
    void deleteNum(int numIn){
        key=findKey(numIn);
        node currNode=arrayLL[key].head;
        while(currNode!=null){
            if(currNode.num==numIn){
                currNode.num=0;
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
            System.out.printf("Index %d : ", i);
            arrayLL[i].show();
        }
    }
}