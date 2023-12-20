package DataStruct.Array_LinkList;

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
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            connectNode(tail, newNode);
        }
        tail=newNode;
        nodeAmount++;
    }
    void showList(){
        node currNode=head;
        System.out.println("Head --> Tail.");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.printf("\n");
        currNode=tail;
        System.out.println("Tail --> Head.");
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
        System.out.printf("\n\n");
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
    node findNum(node currNode, int num){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currNode.num==num){
                return currNode;
            }
            else{
                return findNum(currNode.next, num);
            }
        }
    }
    void deleteFirst(){
        node delNode=head;
        head=head.next;
        delNode.next=null;
        head.prev=null;
        nodeAmount--;
    }
    void deleteLast(){
        node delNode=tail;
        tail=tail.prev;
        tail.next=null;
        delNode.prev=null;
        nodeAmount--;
    }
    void deleteAt(int pos){
        if(pos<=1){
            deleteFirst();
        }
        else if(pos>=nodeAmount){
            deleteLast();
        }
        else{
            node delNode=findNode(head, 1, pos);
            connectNode(delNode.prev, delNode.next);
            delNode.prev=null;
            delNode.next=null;
            nodeAmount--;
        }
    }
    void swapNode(int pos1, int pos2){
        node node1=findNode(head, 1, pos1);
        node node2=findNode(head, 1, pos2);
        int temp=node1.num;
        node1.num=node2.num;
        node2.num=temp;
    }
    void swapNum(int num1, int num2){
        node node1=findNum(head, num1);
        node node2=findNum(head, num2);
        int temp=node1.num;
        node1.num=node2.num;
        node2.num=temp;
    }
    void sortMinMax(){
        node currNode=head;
        node lastNode=tail;
        while(lastNode!=head){
            while(currNode!=lastNode){
                if(currNode.num>currNode.next.num){
                    swapNum(currNode.num, currNode.next.num);
                }
                currNode=currNode.next;
            }
            currNode=head;
            lastNode=lastNode.prev;
        }
    }
}
class stack{
    node top;
    stack(){
        top=null;
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
}
//class queue
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
            System.out.printf("\n     Index %d\n", i);
            arrayLL[i].showList();
        }
    }
    node findNodeInIdx(int idx, int pos){
        return arrayLL[idx].findNode(arrayLL[idx].head, 1, pos);
    }
    void deleteNodeInIdx(int idx, int pos){
        arrayLL[idx].deleteAt(pos);
    }
    void sortMaxMinInIdx(int idx){
        arrayLL[idx].sortMinMax();
    }
    void sortAll(){
        int currIdx=0;
        while(currIdx<arraySize){
            arrayLL[currIdx].sortMinMax();
            currIdx++;
        }
    }
    void showIdx(int idx){
        arrayLL[idx].showList();
    }
}