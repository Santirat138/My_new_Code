public class DataStruct_Single {
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
    int amount=0;
    node nullNode=new node(-1);
    node head;
    node last;

    linkList(){
        head=null;
        last=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
        amount++;
    }
    void addLast(int newNum){
        
    }
}