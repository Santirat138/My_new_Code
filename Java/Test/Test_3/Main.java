package Test.Test_3;

public class Main{
    public static void main(String[] args){
        mainList objList=new mainList();
        objList.addNumAtLast(1, 2);
        objList.addNumAtLast(3, 4);
        objList.addNumAtLast(5, 6);
        objList.addNumAtLast(7, 8);
        objList.showMain();
        objList.mergeList();
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
    node tailOld;
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
    void addNumAtLast(int num1, int num2){
        list1.addLast(num1);
        list2.addLast(num2);
    }
    void linkNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void setMain(){
        if(list1.head.num>list2.head.num){
            headNew=list1.head;
            tailNew=list1.tail;
            headOld=list2.head;
            tailOld=list2.tail;
            curr1=list1.head;
            curr2=list1.head.next;
            compare=list2.head;
        }
        else if(list1.head.num<list2.head.num){
            headNew=list2.head;
            tailNew=list2.tail;
            headOld=list1.head;
            tailOld=list1.tail;
            curr1=list2.head;
            curr2=list2.head.next;
            compare=list1.head;
        }
    }
    /*--------------------- Problem ---------------------*/
    void mergeList(){
        setMain();
        while(compare!=null){
            if((compare.num>curr1.num)&&(compare.num<curr2.num)){
                headOld=headOld.next;
                linkNode(compare, curr2);
                linkNode(curr1, compare);
                compare=headOld;
                curr1=curr1.next;
            }
            else if((compare.num>curr1.num)&&(compare.num>curr2.num)){
                if(curr2.next!=null){
                    curr1=curr1.next;
                    curr2=curr2.next;
                }
                else{
                    linkNode(curr2, compare);
                    tailNew=compare;
                }
            }
        }
    }
    /*--------------------- Problem ---------------------*/
    void showMain(){
        System.out.println("List1 ");
        list1.showList();
        System.out.println("");
        System.out.println("List2 ");
        list2.showList();
    }
}