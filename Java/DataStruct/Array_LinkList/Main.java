package DataStruct.Array_LinkList;

public class Main {
    public static void main(String[] args){
        int size=5;
        arrayLL array1=new arrayLL(size);
        for(int i=0;i<=size;i++){
            array1.insertAtIdx(1, i);
        }
        for(int i=0;i<=size;i++){
            array1.insertAtIdx(2, i);
        }
        for(int i=0;i<=size;i++){
            array1.insertAtIdx(3, i);
        }
        array1.showAll();
        System.out.printf("\n%d", array1.showTargetNum(1).num);
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
    int amount;
    linkList(){
        amount=0;
        head=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            tail=newNode;
        }
        else{
            newNode.next=head;
        }
        head=newNode;
        amount++;
    }
    void deleteFirst(){
        node delNode=head;
        head=head.next;
        delNode.next=null;
        amount--;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            tail.next=newNode;
        }
        tail=newNode;
        amount++;
    }
    node findNumInIdx(int numIn){
        node currNode=head;
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
    void deleteLast(){
        tail=findNode(head, 1, amount);
        tail.next=null;
    }
}
class arrayLL{
    linkList[] array;
    int size;
    node nullNode=new node(-1);
    arrayLL(int sizeIn){
        size=sizeIn;
        array=new linkList[size];
        for(int i=0;i<size;i++){
            array[i]=new linkList();
        }
    }
    void insertAtIdx(int idx, int newNum){
        array[idx].addFirst(newNum);
    }
    void showIdx(int idx){
        node currNode=array[idx].head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
    void showAll(){
        int idx=0;
        node currNode;
        while(idx<size){
            currNode=array[idx].head;
            System.out.printf("Index %d : ", idx);
            while(currNode!=null){
                System.out.printf("%d ", currNode.num);
                currNode=currNode.next;
            }
            idx++;
            System.out.println("");
        }
    }
    node findNumIdx(int idx, int numIn){
        return array[idx].findNumInIdx(numIn);
    }
    node showTargetNum(int numIn){
        int idx=0;
        node currNode;
        while(idx<size){
            currNode=array[idx].head;
            while(currNode!=null){
                if(currNode.num==numIn){
                    System.out.printf("Found %d at %d.\n", numIn, idx);
                }
                currNode=currNode.next;
            }
            idx++;
        }
        return nullNode;
    }

}