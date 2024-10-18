package Data_Structure.Graph.GraphList;

public class Main {
    public static void main(String[] args){

    }
}
//----------------------- class node
class node{
    int num;
    node next;
    node(int numIn){
        num=numIn;
        next=null;
    }
}
//----------------------- class toolsBox
class toolsBox{
    static void showNode(node nodeIn){
        System.out.printf("%d ", nodeIn.num);
    }
    static void showStr(String strIn){
        System.out.print(strIn);
    }

}
//----------------------- class linkList
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
    void showLL(){
        for(node currNode=head;currNode!=null;currNode=currNode.next){
            toolsBox.showNode(currNode);
        }
        toolsBox.showStr("\n");
    }

}
class graph{
    
}