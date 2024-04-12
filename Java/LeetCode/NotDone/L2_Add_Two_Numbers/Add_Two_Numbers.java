package LeetCode.NotDone.L2_Add_Two_Numbers;
public class Add_Two_Numbers{
    public static void main(String[] args){
        mainBox box=new mainBox();
        box.list1.addLast(1);
        box.list1.addLast(3);
        box.list1.addLast(5);
        box.list1.addLast(7);
        box.list2.addLast(2);
        box.list2.addLast(4);
        box.list2.addLast(6);
        box.list2.addLast(8);
        box.mainFunc();
        box.ansList.showList(box.ansList.head);
    }
}
class tools{
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
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
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void addLast(int numIn){
        node newNode=new node(numIn);
        if(tail==null){
            head=newNode;
        }
        else{
            tail.next=newNode;
        }
        tail=newNode;
    }
    void showList(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            showList(currNode.next);
        }
        else{
            System.out.println("End");
        }
    }
    node findPrevNode(node nodePrev, node nodeIn){
        if((nodeIn==head)||(nodeIn==null)){
            return nullNode;
        }
        else{
            if(nodePrev.next==nodeIn){
                return nodePrev;
            }
            else{
                return findPrevNode(nodePrev.next, nodeIn);
            }
        }
    }
    void makeRev(){
        node newHead=head;
        node newTail=tail;
        node prevNode;
        do { 
            prevNode=findPrevNode(head, newTail);
            newTail.next=prevNode;
            newTail=prevNode;
            if(newHead==newTail){
                head=tail;
                tail=newHead;
                tail.next=null;
                break;
            }
        } while (prevNode!=nullNode);
    }
    int countNode(node currNode, int amount){
        if(currNode!=null){
            return countNode(currNode.next, amount+1);
        }
        else{
            return amount;
        }
    }
    int llToInt(){
        node currNode=head;
        int size=countNode(head, 0);
        tools tool1=new tools();
        int powNum;
        int numRem=0;
        for(int i=1;i<=size;i++){
            powNum=tool1.power(10, size-i);
            numRem=numRem+(currNode.num*powNum);
            currNode=currNode.next;
        }
        return numRem;
    }
}
class mainBox{
    linkList list1;
    linkList list2;
    linkList ansList;
    int num1;
    int num2;
    mainBox(){
        list1=new linkList();
        list2=new linkList();
    }
    void makeReverse(){
        list1.makeRev();
        list2.makeRev();
    }
    void showAll(){
        node curr1=list1.head;
        node curr2=list2.head;
        System.out.print("List1: ");
        while(curr1!=null){
            System.out.printf("%d ", curr1.num);
            curr1=curr1.next;
        }
        System.out.print("\nList2: ");
        while(curr2!=null){
            System.out.printf("%d ", curr2.num);
            curr2=curr2.next;
        }
        System.out.println("\n");
    }
    int plusNum(){
        list1.makeRev();
        list2.makeRev();
        num1=list1.llToInt();
        num2=list2.llToInt();
        return num1+num2;
    }
    void numToLL(){
        int ansNum=plusNum();
        int numRem=ansNum;
        int num;
        ansList=new linkList();
        while(numRem>0){
            num=numRem%10;
            numRem=numRem/10;
            ansList.addLast(num);
        }
    }
    void mainFunc(){
        makeReverse();
        int ansNum=plusNum();
        numToLL();
        ansList.addLast(ansNum);
    }
}