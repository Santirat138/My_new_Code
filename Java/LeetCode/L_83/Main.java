package LeetCode.L_83;

public class Main {
    public static void main(String[] args){
        
    }
}
class node{
    int num;
    node right;
    node(int numIn){
        num=numIn;
        right=null;
    }
}
class linkList{
    node head;
    linkList(){
        head=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.right=head;
        }
        head=newNode;
    }
    void show(node currNode){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            show(currNode.right);
        }
        else{
            System.out.println("End.");
        }
    }
    void removeDup(){
        node currNode;
        node checkNode;
        if((head!=null)&&(head.right!=null)){
            currNode=head;
            checkNode=head.right;
            
        }
        else{
            
        }
    }
}