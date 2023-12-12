public class DataStruct_cirSingle {
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
    int amount;
    node nullNode=new node(-1);
    node head;
    node tail;

    linkList(){
        amount=0;
        head=null;
        tail=null;
    }
    
}