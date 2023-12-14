public class DataStruct_cirDouble {
    public static void main(String[] args){
        cirLinkList list1=new cirLinkList();
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
class cirLinkList{
    int amount;
    node nullNode=new node(-1);
    node head;
    node tail;

    cirLinkList(){
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
            head=newNode;
            tail=newNode;
        }
        else{
            connectNode(newNode, head);
            head=newNode;
        }
        connectNode(tail, head);
        amount++;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else{
            connectNode(tail, newNode);
            tail=newNode;
        }
        connectNode(tail, head);
        amount++;
    }
    void show(){
        node currNode=head;
        System.out.println("Head --> Tail.");
        while(currNode!=tail){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.printf("%d\n", tail.num);
        System.out.println("Tail --> Head.");
        currNode=tail;
        while(currNode!=head){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
        System.out.printf("%d\n\n", head.num);
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
    node findNum(node currNode, int currPos, int num){
        if((currPos<1)||(currPos>amount||(currNode==null))){
            return nullNode;
        }
        else{
            if(currNode.num==num){
                return currNode;
            }
            else{
                return findNum(currNode.next, currPos+1, num);
            }
        }
    }
    void insertAt(int pos, int newNum){
        node currNode=findNode(head, 1, pos);
        node prevNode=findNode(head, 1, pos-1);
        if(currNode==head){
            addFirst(newNum);
        }
        else if(currNode==tail){
            addLast(newNum);
        }
        else{
            node newNode=new node(newNum);
            connectNode(newNode, currNode);
            connectNode(prevNode, newNode);
            amount++;
        }
    }
    void deleteFirst(){
        node delNode=head;
        head=delNode.next;
        connectNode(tail, head.next);
        delNode.next=null;
        amount--;
    }
    void deleteLast(){
        node delNode=tail;
        tail=delNode.prev;
        connectNode(tail, head);
        delNode.prev=null;
        amount--;
    }
    void deleteAt(int pos){
        node currNode=findNode(head, 1, pos);
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
    void swapNode(int pos1, int pos2){
        node node1=findNode(head, 1, pos1);
        node node2=findNode(head, 1, pos2);
        if((node1!=nullNode)&&(node2!=nullNode)){
            int temp=node1.num;
            node1.num=node2.num;
            node2.num=temp;
        }
        else{
            System.out.println("Can't swap.");
        }
    }
    void swapNum(int num1, int num2){
        node node1=findNum(head, 1, num1);
        node node2=findNum(head, 1, num2);
        if((node1!=nullNode)&&(node2!=nullNode)){
            int temp=node1.num;
            node1.num=node2.num;
            node2.num=temp;
        }
        else{
            System.out.println("Can't swap.");
        }
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