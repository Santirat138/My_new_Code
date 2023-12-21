package DataStruct.Test_Space.Way_1;

public class Main {
    public static void main(String[] args){

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
    
    linkList(){
        head=null;
    }
}
class stack{
    node top;

    stack(){
        top=null;
    }
    void push(int newNum){
        node newNode=new node(newNum);
        if(top!=null){
            newNode.next=top;
        }
        top=newNode;
    }
    node pop(){
        node temp=top;
        top=top.next;
        temp.next=null;
        return temp;
    }
}
class queue{
    node firstNode;
    node lastNode;

    queue(){
        firstNode=null;
        lastNode=null;
    }
    void  enqueue(int newNum){
        node newNode=new node(newNum);
        if((firstNode==null)&&(lastNode==null)){
            firstNode=newNode;
        }
        else{
            lastNode.next=newNode;
        }
        lastNode=newNode;
    }
}