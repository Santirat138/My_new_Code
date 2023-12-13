public class DataStruct_Single{
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
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
    node head;
    node tail;
    node nullNode=new node(-1);
    int amount;

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
        tail.next=newNode;
        tail=newNode;
        amount++;
    }
    void insertAtPos(int pos, int newNum){
        if((pos<=1)||(head==null)){
            addFirst(newNum);
        }
        else if((pos>amount)||(head==null)){
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
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
    }
    node findNode(node currNode, int currPos ,int pos){
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
        if(currNode.num==num){
            return currNode;
        }
        else{
            return findNum(currNode.next, num);
        }
    }
    node findPrevNum(int num){
        node currNode=findNum(head, num);
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
    void deleteFirst(){
        node currNode=head;
        node temp=head.next;
        head=temp;
        currNode.next=null;
        amount--;
    }
    void deleteLast(){
        node temp=findNode(head, 1,  amount-1);
        tail=temp;
        tail.next=null;
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
            node prevNode=findNode(head, 1, pos-1);
            prevNode.next=currNode.next;
            currNode.next=null;
        }
    }
    void swapNode(int pos1, int pos2){
        if(pos1<1){
            pos1=1;
        }
        if(pos2>amount){
            pos2=amount;
        }
        node node1=findNode(head, 1, pos1);
        node node2=findNode(head, 1, pos2);
        node temp=new node(-1);
        temp.num=node1.num;
        node1.num=node2.num;
        node2.num=temp.num;
    }
    void swapNum(int num1, int num2){
        node node1=findNum(head, num1);
        node node2=findNum(head, num2);
        if((node1!=nullNode)&&(node2!=nullNode)){
            node temp=new node(-1);
            temp.num=node1.num;
            node1.num=node2.num;
            node2.num=temp.num;
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
            lastNode=findPrevNum(lastNode.num);
        }
    }
}