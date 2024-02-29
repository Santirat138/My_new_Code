package Test.Test_2;

public class Main{
    public static void main(String[] args){
        linkList listObj=new linkList();
        for(int i=0;i<5;i++){
            listObj.addLast(i);
        }
        System.out.printf("%d ", listObj.findPrev(listObj.head, 5).num);
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
    node top;
    node curr;
    node headNew;
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        headNew=null;
        nullNode=new node(-1);
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head!=null)&&(tail!=null)){
            tail.next=newNode;
        }
        else{
            head=newNode;
        }
        tail=newNode;
    }
    void show(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            show(currNode.next);
        }
    }
    node findPrev(node curr, int numIn){
        if(curr!=tail){
            if(curr.next.num==numIn){
                return curr;
            }
            else{
                return findPrev(curr.next, numIn);
            }
        }
        else{
            return nullNode;
        }
    }
    node pop(){
        top=head;
        if(top!=null){
            head=head.next;
            top.next=null;
            return top;
        }
        else{
            return nullNode;
        }
    }
    void makeRev(){
        
    }
}