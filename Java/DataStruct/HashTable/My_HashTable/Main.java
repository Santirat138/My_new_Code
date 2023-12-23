public class Main{
    public static void main(String[] args){
        hashTable table1=new hashTable(5);
        table1.insertNum(5);
        table1.insertNum(50);
        table1.insertNum(55);
        table1.insertNum(1);
        table1.insertNum(6);
        table1.insertNum(54);
        table1.showAll();
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
class queue{
    node firstNode;
    node lastNode;
    queue(){
        firstNode=null;
        lastNode=null;
    }
    void buildFirstNode(int newNum){
        node newNode=new node(newNum);
        firstNode=newNode;
        lastNode=newNode;
    }
    void enqueue(int newNum){
        node newNode=new node(newNum);
        newNode.next=lastNode;
        lastNode=newNode;
    }
    int dequeue(){
        node temp=lastNode;
        while(temp!=null){
            if(temp.next==firstNode){
                break;
            }
            else if(temp.next==null){
                return temp.num;
            }
            else{
                temp=temp.next;
            }
        }
        firstNode=temp;
        temp=temp.next;
        firstNode.next=null;
        return temp.num;
    }
}
class hashTable{
    int size, key;
    queue[] arrayQ;

    hashTable(int sizeIn){
        size=sizeIn;
        arrayQ=new queue[size];
        for(int i=0;i<size;i++){
            arrayQ[i]=new queue();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insertNum(int newNum){
        key=findKey(newNum);
        if(arrayQ[key].firstNode==null){
            arrayQ[key].buildFirstNode(newNum);
        }
        else{
            arrayQ[key].enqueue(newNum);
        }
    }
    void showAll(){
        node currNode;
        for(int i=0;i<size;i++){
            currNode=arrayQ[i].lastNode;
            System.out.printf("Index %d : ", i);
            while(currNode!=null){
                System.out.printf("%d ", currNode.num);
                currNode=currNode.next;
            }
            System.out.println("");
        }
    }
}