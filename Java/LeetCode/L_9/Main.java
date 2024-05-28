package LeetCode.L_9;

public class Main {
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=0;i<=5;i++){
            list.push(i);
        }
        while(list.head!=null){
            System.out.printf("%d\n", list.pop(list.head).num);
        }
    }
}
// 1)Use stack link-list.
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
    node nullNode;
    linkList(){
        head=null;
        nullNode=new node(-1);
    }
    void push(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
    node pop(node currNode){
        if(head!=null){
            head=head.next;
            currNode.next=null;
        }
        else{
            currNode=null;
        }
        return currNode;
    }
}
class checkBox{
    linkList list1;
    linkList list2;
    checkBox(){
        
    }
}

// 2)Use mod(%).