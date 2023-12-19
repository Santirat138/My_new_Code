package DataStruct.Array_LinkList;

public class Main{
    public static void main(String[] args){
        int size=5;
        arrayBox array1=new arrayBox(size);
        array1.insertInIdx(0, 5);
        array1.insertInIdx(0, 8);
        array1.insertInIdx(0, 3);
        array1.insertInIdx(0, 1);
        array1.insertInIdx(1, 10);
        array1.insertInIdx(1, 50);
        array1.showAll();
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
    int nodeAmount;

    linkList(){
        nullNode=new node(-1);
        head=null;
        tail=null;
        nodeAmount=0;
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
        nodeAmount++;
    }
    void showList(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.printf("\n");
    }
    node findNode(int pos){
        int currPos=1;
        node currNode=head;
        if(pos<1){
            pos=1;
        }
        else if(pos>nodeAmount){
            pos=nodeAmount;
        }
        while(currNode!=null){
            if(currPos==pos){
                return currNode;
            }
            else{
                currNode=currNode.next;
                pos++;
            }
        }
        return nullNode;
    }
}
class arrayBox{
    int arraySize;
    linkList[] arrayLL;

    arrayBox(int sizeIn){
        arraySize=sizeIn;
        arrayLL=new linkList[arraySize];
        for(int i=0;i<arraySize;i++){
            arrayLL[i]=new linkList();
        }
    }
    void insertInIdx(int idx, int newNum){
        arrayLL[idx].addFirst(newNum);
    }
    void showAll(){
        for(int i=0;i<arraySize;i++){
            System.out.printf("Index %d : ", i);
            arrayLL[i].showList();
        }
    }
    node findNodeInIdx(int idx, int pos){
        
    }
}