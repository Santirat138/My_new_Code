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
    node tail;
    node temp;
    linkList(){
        head=null;
        tail=null;
        temp=new node(-1);
    }
}