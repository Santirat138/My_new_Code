public class DataStruct_Single {
    public static void main(String[] args){
        linkList list1=new linkList();
        for(int i=0;i<=5;i++){
            list1.addFirst(i);
        }
        list1.addLast(10);
        list1.show();
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
        node newNode=new node(newNum);
        if((head==null)&&(last==null)){
            head=newNode;
        }
        else{
            last.next=newNode;
        }
        last=newNode;
        amount++;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
    }
    node findNode(node currNode, int pos){
        if(currNode==null){
            return nullNode;
        }
        else{
            
        }
    }
}