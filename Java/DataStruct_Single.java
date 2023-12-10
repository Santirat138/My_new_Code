public class DataStruct_Single {
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.addLast(10);
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
    int amount=0;
    node nullNode=new node(-1);
    node head;
    node last;

    linkList(){
        head=null;
        last=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(last==null)){
            last=newNode;
        }
        else{
            newNode.next=head;
        }
        head=newNode;
        amount++;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(last==null)){
            head=newNode;
        }
        else{
            last.next=newNode;
        }
        last=newNode;
        amount++;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
    }
    node findNode(node currNode, int walk, int pos){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(walk==pos-1){
                return currNode;
            }
            else{
                return findNode(currNode.next, walk+1, pos);
            }
        }
    }
    void deleteFirst(){
        node tempNode=head;
        head=head.next;
        tempNode.next=null;
        amount--;
    }
    void deleteLast(){
        node tempNode=head;
        while(tempNode!=null){
            if(tempNode.next==last){
                last=tempNode;
                tempNode.next=null;
                amount--;
                break;
            }
            else{
                tempNode=tempNode.next;
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
            node currNode=findNode(head, 0, pos);
            node prevNode=findNode(head, 0, pos-1);
            newNode.next=currNode;
            prevNode.next=newNode;
            amount++;
        }
    }
    void deleteAt(int pos){
        if(pos<=1){
            deleteFirst();
        }
        else if(pos>=amount){
            deleteLast();
        }
        else{
            node delNode=findNode(head, 0, pos);
            node prevNode=findNode(head, 0, pos-1);
            prevNode.next=delNode.next;
            delNode.next=null;
            amount--;
        }
    }
    void swapNode(int pos1, int pos2){
        node temp=new node(-1);
        node node1=findNode(head, 0, pos1);
        node node2=findNode(head, 0, pos2);
        temp.num=node1.num;
        node1.num=node2.num;
        node2.num=temp.num;
    }
}