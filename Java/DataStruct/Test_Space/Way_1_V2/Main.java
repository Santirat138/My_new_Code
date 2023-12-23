package DataStruct.Test_Space.Way_1_V2;

public class Main {
    public static void main(String[] args){
        int size=5;
        arrayLL list1=new arrayLL(size);
        list1.addFirstInIdx(1, 8);
        list1.addFirstInIdx(1, 7);
        list1.addFirstInIdx(1, 6);
        list1.addFirstInIdx(2, 5);
        list1.addFirstInIdx(2, 4);
        list1.showAll();
        System.out.printf("%d", list1.findNodeInIdx(1, 2).num);
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
        amount=0;
        nullNode=new node(-1);
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
            connectNode(newNode ,head);
        }
        head=newNode;
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
        amount++;
    }
    void show(){
        System.out.println("");
        node currNode=head;
        System.out.print("Head --> Tail. ");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
        currNode=tail;
        System.out.print("Tail --> Head. ");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
        System.out.println("\n");
    }
    node findNode(node currNode, int currPos, int pos){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currPos==pos){
                return currNode;
            }
            else{
                return findNode(currNode.next, currPos+1, pos);
            }
        }
    }
    void deleteNode(int pos){
        if(pos<=1){
            deleteNode(1);
        }
        else if(pos>=amount){
            deleteNode(amount);
        }
        else{
            node delNode=findNode(head, 1, pos);
            connectNode(delNode.prev, delNode.next);
            delNode.prev=null;
            delNode.next=null;
            amount--;
        }
    }
}
class arrayLL{
    int size;
    linkList[] arrayLL;

    arrayLL(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
        for(int i=0;i<size;i++){
            arrayLL[i]=new linkList();
        }
    }
    void addFirstInIdx(int idx, int newNum){
        arrayLL[idx].addFirst(newNum);
    }
    void addLastInIdx(int idx, int newNum){
        arrayLL[idx].addLast(newNum);
    }
    void showAll(){
        for(int i=0;i<size;i++){
            System.out.printf("Index %d", i);
            arrayLL[i].show();
        }
        System.out.println("");
    }
    node findNodeInIdx(int idx, int pos){
        return arrayLL[idx].findNode(arrayLL[idx].head, 1, pos);
    }
    void deleteNodeInIdx(int idx, int pos){
        arrayLL[idx].deleteNode(pos);
    }
}