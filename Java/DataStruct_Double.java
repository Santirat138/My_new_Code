public class DataStruct_Double {
    public static void main(String[] args){
        doubLinkList list1=new doubLinkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.sortMinMax();
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
class doubLinkList{
    node nullNode=new node(-1);
    node head;
    node tail;
    int amount;

    doubLinkList(){
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
            tail=newNode;
        }
        else{
            connectNode(newNode, head);
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
        System.out.println("\nHead --> Tail.");
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("\nTail --> Head.");
        currNode=tail;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.prev;
        }
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
    void insertAt(int pos, int newNum){
        if(pos<=1){
            addFirst(newNum);
        }
        else if(pos>amount){
            addLast(newNum);
        }
        else{
            node newNode=new node(newNum);
            node currNode=findNode(head, 1, pos);
            node prevNode=findNode(head, 1, pos-1);
            connectNode(newNode, currNode.next);
            connectNode(prevNode, newNode);
            amount++;
        }
    }
    void deleteFirst(){
        node temp=head;
        head=temp.next;
        head.prev=null;
        temp.next=null;
        amount--;
    }
    void deleteLast(){
        node temp=tail;
        tail=tail.prev;
        tail.next=null;
        temp.prev=null;
        amount--;
    }
    void deleteAt(int pos){
        if(pos<=1){
            deleteFirst();
        }
        else if(pos>=amount){
            deleteLast();
        }
        else{
            node delNode=findNode(head, 1, pos);
            connectNode(delNode.prev, delNode.next);
            delNode.prev=null;
            delNode.next=null;
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
        node node1=findNum(head, num1);
        node node2=findNum(head, num2);
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
        while(lastNode!=null){
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