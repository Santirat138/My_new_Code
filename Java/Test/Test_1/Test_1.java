// Test L21_Merge_Two_Sorted_Lists (Double link-list).
package Test.Test_1;

public class Test_1{
    public static void main(String[] args){
        linkList list=new linkList();
        for(int i=5;i>=0;i--){
            list.addSort(i);
        }
        list.showList(list.head, false);
    }
}
class node{
    int num;
    node prev;
    node next;
    node(int numIn){
        num=numIn;
        prev=null;
        next=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void linkNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void addSort(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else if(head==tail){
            if(newNum>head.num){
                linkNode(tail, newNode);
                tail=newNode;
            }
            else if(newNum<head.num){
                linkNode(newNode, head);
                head=newNode;
            }
        }
        else{
            node compare=head;
            while(compare!=tail){
                if((newNum<compare.num)&&(newNum<compare.next.num)){
                    linkNode(newNode, head);
                    head=newNode;
                    break;
                }
                else if((newNum>compare.num)&&(newNum<compare.next.num)){
                    linkNode(newNode, compare.next);
                    linkNode(compare, newNode);
                    break;
                }
                else if((newNum>compare.num)&&(newNum>compare.next.num)){
                    compare=compare.next;
                }
            }
            if(compare==tail){
                if(newNum>tail.num){
                    linkNode(tail, newNode);
                    tail=newNode;
                }
                else if(newNum<tail.num){
                    linkNode(tail.prev, newNode);
                    linkNode(newNode, tail);
                }
            }
        }
    }
    void showList(node currNode, boolean toTail){
        if(currNode!=null){
            System.out.printf("%d ", currNode.num);
            if(currNode==tail){
                toTail=true;
                System.out.printf("\n%d ", currNode.num);
            }
            if(!toTail){
                showList(currNode.next, toTail);
            }
            else if(toTail){
                showList(currNode.prev, toTail);
            }
        }
        else{
            System.out.println("End.");
        }
    }

}