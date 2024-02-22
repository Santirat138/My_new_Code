package Test.Test_2;

public class Main{
    public static void main(String[] args){
        mainList objList=new mainList();
        objList.list1.addLast(1);
        objList.list1.addLast(3);
        objList.list1.addLast(5);
        objList.list1.addLast(7);
        objList.list2.addLast(2);
        objList.list2.addLast(4);
        objList.list2.addLast(6);
        objList.list2.addLast(8);
        objList.mergeList();
        objList.showMain();
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
    linkList(){
        nullNode=new node(-1);
        head=null;
        tail=null;
    }
    void linkNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void showH(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showH(currNode.next);
        }
    }
    void showT(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showT(currNode.prev);
        }
    }
    void showList(){
        showH(head);
        showT(tail);
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else{
            linkNode(tail, newNode);
            tail=newNode;
        }
    }
}
class mainList{
    node headNew;
    node headOld;
    node tailNew;
    node curr1;
    node curr2;
    node compare;
    linkList list1;
    linkList list2;
    mainList(){
        list1=new linkList();
        list2=new linkList();
    }
    void setMain(){
        if(list1.head.num>list2.head.num){
            headNew=list1.head;
            tailNew=list1.tail;
            headOld=list2.head;
            curr1=list1.head;
            curr2=list1.head.next;
            compare=list2.head;
        }
        else if(list1.head.num<list2.head.num){
            headNew=list2.head;
            tailNew=list2.tail;
            headOld=list1.head;
            curr1=list2.head;
            curr2=list2.head.next;
            compare=list1.head;
        }
    }
    /*--------------------- Problem ---------------------*/
    void mergeList(){
        setMain();
        while(compare!=null){
            if((curr1!=tailNew)&&(curr2!=tailNew)){
                if((compare.num>curr1.num)&&(compare.num<curr2.num)){
                    headOld=headOld.next;
                    compare.next=curr2;
                    curr1.next=compare;
                    compare=compare.next;
                    curr1=curr1.next;
                }
                else if((compare.num>curr1.num)&&(compare.num>curr2.num)){
                    curr1=curr1.next;
                    curr2=curr2.next;
                }
            }
            else if(curr2==tailNew){
                if((compare.num>curr1.num)&&(compare.num<curr2.num)){
                    compare.next=curr2;
                    curr1.next=compare;
                }
                else if((compare.num>curr1.num)&&(compare.num>curr2.num)){
                    curr2.next=compare;
                }
                break;
            }
        }
    }
    /*--------------------- Problem ---------------------*/
    void showMain(){
        node currNode=headNew;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("End");
    }
}