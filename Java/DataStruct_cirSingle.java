public class DataStruct_cirSingle {
    public static void main(String[] args){
        cirLinkList list1=new cirLinkList();
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
class cirLinkList{
    int amount;
    int currPos;
    node nullNode=new node(-1);
    node head;
    node tail;

    cirLinkList(){
        currPos=1;
        amount=0;
        head=null;
        tail=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode.next=head;
            head=newNode;
        }
        tail.next=head;
        amount++;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            newNode.next=head;
            tail.next=newNode;
        }
        tail=newNode;
        amount++;
    }
    void show(){
        node currNode=head;
        currPos=1;
        while(currPos<=amount){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
            currPos++;
        }
        System.out.printf("\n\n");
    }
    node findNode(node currNode, int currPos, int pos){
        if(currPos>amount){
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
    node findNum(int num){
        node currNode=head;
        currPos=1;
        while(currPos<=amount){
            if(currNode.num==num){
                return currNode;
            }
            else{
                currNode=currNode.next;
                currPos++;
            }
        }
        return nullNode;
    }
    node findPrevNum(int num){
        node currNode=findNum(num);
        node prevNode=head;
        currPos=1;
        while(currPos<=amount){
            if(prevNode.next==currNode){
                return prevNode;
            }
            else{
                prevNode=prevNode.next;
                currPos++;
            }
        }
        return nullNode;
    }
    node findPrevNode(node currNode, int currPos, int pos){
        if(pos>amount){
            return tail;
        }
        else if(pos<=1){
            return head;
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
    void deleteFirst(){
        node temp=head;
        head=head.next;
        tail.next=head;
        temp.next=null;
        amount--;
    }
    void deleteLast(){
        node temp=tail;
        tail=findNode(head, 1, amount-1);
        tail.next=head;
        temp.next=null;
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
            node currNode=findNode(head, 1, pos);
            node prevNode=findNode(head, 1, pos-1);
            prevNode.next=currNode.next;
            currNode.next=null;
            amount--;
        }
    }
    void insertAt(int pos, int newNum){
        node newNode=new node(newNum);
        if(pos<=1){
            addFirst(newNum);
        }
        else if(pos>amount){
            addLast(newNum);
        }
        else{
            node prevNode=findNode(head, 1, pos-1);
            node currNode=findNode(head, 1, pos);
            newNode.next=currNode;
            prevNode.next=newNode;
            amount++;
        }
    }
    void swapNode(int pos1, int pos2){
        if(pos1<1){
            pos1=1;
        }
        else if(pos1>amount){
            pos1=amount;
        }
        if(pos2<1){
            pos2=1;
        }
        else if(pos2>amount){
            pos2=amount;
        }
        node node1=findNode(head, 1, pos1);
        node node2=findNode(head, 1, pos2);
        if((node1!=null)&&(node2!=null)){
            int temp=node1.num;
            node1.num=node2.num;
            node2.num=temp;
        }
        else{
            System.out.println("Can't swap.");
        }
    }
    void swapNum(int num1, int num2){
        node node1=findNum(num1);
        node node2=findNum(num2);
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
            lastNode=findPrevNum(lastNode.num);
        }
    }
}