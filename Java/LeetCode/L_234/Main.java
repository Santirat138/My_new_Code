package LeetCode.L_234;

public class Main{
    public static void main(String[] args){
        linkList list=new linkList();
        list.addFirst(1);
        list.addFirst(2);
        list.addFirst(3);
        list.addFirst(4);
        list.showLL();
        toolsBox tool=new toolsBox(list);
        tool.makeRev();
        tool.newLL.showLL();
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
    linkList(){
        head=null;
        tail=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.right=head;
        }
        else{
            tail=newNode;
        }
        head=newNode;
    }
    void showLL(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.right;
        }
        System.out.println("");
    }
}
class toolsBox{
    linkList newLL;
    toolsBox(linkList llIn){
        newLL=llIn;
    }
    void makeRev(){
        node prevNode=null;
        node currNode=newLL.head;
        node nextNode=currNode.right;
        while(currNode!=null){
            currNode.right=prevNode;
            prevNode=currNode;
            currNode=nextNode;
            nextNode=currNode.right;

        }
        
    }
}