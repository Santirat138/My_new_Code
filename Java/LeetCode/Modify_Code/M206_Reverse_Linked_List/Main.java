package LeetCode.Modify_Code.M206_Reverse_Linked_List;

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
    node tail;
    linkList(){
        head=null;
        tail=null;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(tail!=null){
            tail.next=newNode;
        }
        else{
            head=newNode;
        }
        tail=newNode;
    }
    void showList(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            showList(currNode.next);
        }
        else{
            System.out.println("End.");
        }
    }
    
}