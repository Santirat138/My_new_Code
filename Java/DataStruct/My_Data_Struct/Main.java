package DataStruct.My_Data_Struct;

// Fix oldDataStruct.
public class Main{
    public static void main(String[] args){
        linkList objList=new linkList();
        objList.addSort(2, objList.head);
        objList.addSort(1, objList.head);
        objList.addSort(50, objList.head);
        objList.addSort(6, objList.head);
        objList.addSort(0, objList.head);
        objList.showList();
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
    void showH(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showH(currNode.next);
        }
    }
    void showT(node currNode){
        if(currNode==null){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", currNode.num);
            showT(currNode.prev);
        }
    }
    void showList(){
        showH(head);
        showT(tail);
    }
    void addSort(int newNum, node compare){
        if(compare==null){
            node newNode=new node(newNum);
            head=newNode;
            tail=newNode;
        }
        else if((compare==head)&&(compare==tail)){
            node newNode=new node(newNum);
            if(newNum>compare.num){
                linkNode(tail, newNode);
                tail=newNode;
            }
            else if(newNum<compare.num){
                linkNode(newNode, head);
                head=newNode;
            }
        }
        else{
            if(compare!=tail){
                if((newNum<compare.num)&&(newNum<compare.next.num)){
                    node newNode=new node(newNum);
                    linkNode(newNode, head);
                    head=newNode;
                }
                else if((newNum>compare.num)&&(newNum<compare.next.num)){
                    node newNode=new node(newNum);
                    linkNode(newNode ,compare.next);
                    linkNode(compare, newNode);
                }
                else if((newNum>compare.num)&&(newNum>compare.next.num)){
                    addSort(newNum, compare.next);
                }
            }
            else if(compare==tail){
                node newNode=new node(newNum);
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
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            linkNode(newNode, head);
        }
        else if(head==null){
            tail=newNode;
        }
        head=newNode;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if(tail!=null){
            linkNode(tail, newNode);
        }
        else if(tail==null){
            head=newNode;
        }
        tail=newNode;
    }
    //node findNumByHalf(int numIn){}
    node findNumAtPos(int currPos, int targetPos, node currNode){
        if(currNode!=null){
            if(currPos==targetPos){
                return currNode;
            }
            else{
                return findNumAtPos(currPos+1, targetPos, currNode.next);
            }
        }
        else{
            return nullNode;
        }
    }
    int countNode(int amount, node currNode){
        if(currNode==null){
            return amount;
        }
        else{
            return countNode(amount+1, currNode.next);
        }
    }
    void addAtPos(int newNum, int posIn){
        int amount=countNode(0, head);
        int currPos=1;
        node currNode=findNumAtPos(currPos, posIn, head);
        node newNode=new node(newNum);
        if(posIn>amount){
            addLast(newNum);
        }
        else if(posIn<=1){
            addFirst(newNum);
        }
        else{
            linkNode(currNode.prev, newNode);
            linkNode(newNode, currNode);
        }
    }
    node findNum(int numIn, node currNode){
        if(currNode!=null){
            if(numIn==currNode.num){
                return currNode;
            }
            else{
                return findNum(numIn, currNode.next);
            }
        }
        else{
            return nullNode;
        }
    }
    void deleteNum(int numIn){
        node delNode=head;
        while(delNode!=null){
            if(delNode.num==numIn){
                if((delNode==head)&&(delNode==tail)){
                    head=null;
                    tail=null;
                }
                else if(delNode==head){
                    head=head.next;
                    head.prev=null;
                    delNode.next=null;
                }
                else if(delNode==tail){
                    tail=tail.prev;
                    tail.next=null;
                    delNode.prev=null;
                }
                else{
                    linkNode(delNode.prev, delNode.next);
                    delNode.prev=null;
                    delNode.next=null;
                }
                delNode=head;
            }
            else{
                delNode=delNode.next;
            }
        }
    }
    void deleteAtPos(int posIn){
        node delNode=findNumAtPos(1, posIn, head);
        deleteNum(delNode.num);
    }
    node findMax(node currNode, node maxNode){
        if(currNode!=tail){
            if(currNode.num>maxNode.num){
                maxNode.num=currNode.num;
            }
            return findMax(currNode.next, maxNode);
        }
        else if(currNode==tail){
            return maxNode;
        }
        else{
            return nullNode;
        }
    }
    
}
