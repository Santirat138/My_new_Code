package DataStruct.Single_Linklist;

public class Main {
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.insertAt(2, 80);
        list1.sortMinMax();
        list1.show();

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
    int amount;
    node head;
    node tail;
    node nullNode=new node(-1);
    linkList(){
        amount=0;
        head=null;
        tail=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            tail=newNode;
        }
        newNode.next=head;
        head=newNode;
        amount++;
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
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
    void deleteFirst(){
        if(head==tail){
            head=null;
            tail=null;
        }
        else{
            node temp=head;
            head=temp.next;
            temp.next=null;
        }
        amount--;
    }
    void deleteLast(){
        if(head==tail){
            head=null;
            tail=null;
        }
        else{
            node temp=head;
            while(temp.next!=tail){
                temp=temp.next;
            }
            tail=temp;
            temp.next=null;
        }
        amount--;
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
    node findPrevNode(node currNode, int currPos, int pos){
        if((currNode==null)||(pos<1)||(pos>amount)){
            return nullNode;
        }
        else{
            if(currPos==pos-1){
                return currNode;
            }
            else{
                return findPrevNode(currNode.next, currPos+1, pos);
            }
        }
    }
    node findPrevNum(node currNode, int num){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currNode.next.num==num){
                return currNode;
            }
            else{
                return findPrevNum(currNode.next, num);
            }
        }
    }
    void insertAt(int pos, int newNum){
        if(pos<=1){
            addFirst(newNum);
        }
        else if(pos>=amount){
            addLast(newNum);
        }
        else{
            node newNode=new node(newNum);
            node currNode=findNode(head, 1, pos);
            node prevNode=findNode(head, 1, pos-1);
            newNode.next=currNode;
            prevNode.next=newNode;
            amount++;
        }
    }
    void swapNode(int pos1, int pos2){
        node node1=findNode(head, 1, pos1);
        node node2=findNode(head, 1, pos2);
        if((node1!=null)||(node2!=null)){
            System.out.println("Can't swap.");
        }
        else{
            int temp=node1.num;
            node1.num=node2.num;
            node2.num=temp;
        }
    }
    void swapNum(int num1, int num2){
        node node1=findNum(head, num1);
        node node2=findNum(head, num2);
        if((node1==null)||(node2==null)){
            System.out.println("Can't swap.");
        }
        else{
            int temp=node1.num;
            node1.num=node2.num;
            node2.num=temp;
        }
    }
    void deleteAt(int pos){
        node delNode=findNode(head, 1, pos);
        if(delNode!=nullNode){
            node prevNode=findNode(head, 1, pos-1);
            prevNode.next=delNode.next;
            delNode.next=null;
        }
        else{
            System.out.println("Can't delete.");
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
            lastNode=findPrevNum(head, lastNode.num);
        }
    }

}