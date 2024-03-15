package LeetCode.NotDone.L21_Merge_Two_Sorted_Lists;

public class L21_Merge_Two_Sorted_Lists {
    public static void main(String[] args){
        linkList list1=new linkList();
        list1.addSort(5);
        list1.addSort(3);
        list1.addSort(8);
        list1.addSort(1);
        list1.showList(list1.head);
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
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
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
    void showList(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showList(currNode.next);
        }
    }
    void connectList(linkList list1, linkList list2){
        list1.tail.next=list2.head;
        list1.tail=list2.tail;
    }
    node findPrevNode(node currNode, int numIn){
        if(currNode!=null){
            if(currNode.next.num==numIn){
                return currNode;
            }
            else{
                return findPrevNode(currNode.next, numIn);
            }
        }
        else{
            return nullNode;
        }
    }
    void addSort(int numIn){
        node newNode=new node(numIn);
        if((head==null)&&(tail==null)){
            head=newNode;
            tail=newNode;
        }
        else if(head==tail){
            if(numIn>head.num){
                tail.next=newNode;
                tail=newNode;
            }
            else if(numIn<head.num){
                newNode.next=head;
                head=newNode;
            }
        }
        else{
            node compare=head;
            while(compare!=tail){
                if((numIn<compare.num)&&(numIn<compare.next.num)){
                    newNode.next=head;
                    head=newNode;
                    break;
                }
                else if((numIn>compare.num)&&(numIn<compare.next.num)){
                    newNode.next=compare.next;
                    compare.next=newNode;
                    break;
                }
                else if((numIn>compare.num)&&(numIn>compare.next.num)){
                    compare=compare.next;
                }
            }
            if(compare==tail){
                if(numIn>tail.num){
                    tail.next=newNode;
                    tail=newNode;
                }
                else if(numIn<tail.num){
                    node prevTail=findPrevNode(head, tail.num);
                    newNode.next=tail;
                    prevTail.next=newNode;
                }
            }
        }
    }
    void mergeList(linkList list1, linkList list2){
        
    }
}