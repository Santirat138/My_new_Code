package Test.Test_3;
// Palindrome Linked List
public class Main{
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
    void addSort(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else if(head==tail){
            if(newNum>head.num){
                head.next=newNode;
            }
            else if(newNum<head.num){
                newNode.next=head;
                head=newNode;
            }
        }
        else{
            node compare=head;
            if(compare!=tail){
                if((newNum<compare.num)&&(newNum<compare.next.num)){

                }
                else if((newNum>compare.num)&&(newNum<compare.next.num)){
                    
                }
                else if((newNum>compare.num)&&(newNum>compare.next.num)){
                    compare=compare.next;
                }
            }
            else if(compare==tail){

            }
        }
    }
}