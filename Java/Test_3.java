public class Test_3{
    public static void main(String[] args){
        linkList[] array=new linkList[5];
        for(int i=0;i<5;i++){
            array[i]=new linkList();
        }
        array[0].add(10);
        array[0].add(20);
        node currNode=array[0].head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
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

    void add(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
}