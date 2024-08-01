package Data_Structure.LinkList;

public class Main {
    public static void main(String[] args){

    }    
}
class node{
    int num;
    node left;
    node right;
    node(int numIn){
        num=numIn;
        left=null;
        right=null;
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
    void linkNode(node node1, node node2){
        node1.right=node2;
        node2.left=node1;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            linkNode(newNode, head);
        }
        else{
            tail=newNode;
        }
        head=newNode;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(tail!=null){
            linkNode(tail, newNode);
        }
        else{
            head=newNode;
        }
        tail=newNode;
    }
    void showLL(){
        node currNode=head;
        if(currNode!=null){
            
        }
        else{
            System.out.println("Empty");
        }
    }
}