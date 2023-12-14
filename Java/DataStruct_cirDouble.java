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
            connectNode(newNode, head);
            connectNode(tail, newNode);
            tail=newNode;
        }
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
        
    }
}