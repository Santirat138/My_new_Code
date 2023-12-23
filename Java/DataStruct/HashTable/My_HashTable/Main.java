package DataStruct.HashTable.My_HashTable;

public class Main{
    public static void main(String[] args){
        hashTable table=new hashTable(5);
        table.insert(2);
        table.insert(1);
        table.insert(5);
        table.insert(25);
        table.showAll();
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
class stack{
    node top;
    stack(){
        top=null;
    }
    void push(int newNum){
        node newNode=new node(newNum);
        if(top!=null){
            newNode.next=top;
        }
        top=newNode;
    }
    int pop(){
        node temp=top;
        top=top.next;
        temp.next=null;
        return temp.num;
    }
}
class hashTable{
    int key, size;
    stack[] arrayStk;
    int[] temp;

    hashTable(int sizeIn){
        size=sizeIn;
        arrayStk=new stack[size];
        for(int i=0;i<size;i++){
            arrayStk[i]=new stack();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insert(int newNum){
        key=findKey(newNum);
        arrayStk[key].push(newNum);
    }
    void showAll(){
        node currNode;
        for(int i=0;i<size;i++){
            currNode=arrayStk[i].top;
            System.out.printf("Index %d : ", i);
            while(currNode!=null){
                System.out.printf("%d ", currNode.num);
                currNode=currNode.next;
            }
            System.out.println("");
        }
    }
    node findNum(int numIn){
        key=findKey(numIn);
        node currNode=arrayStk[key].top;
        while(currNode!=null){
            if(currNode.num==numIn){
                return currNode;
            }
            else{
                currNode=currNode.next;
            }
        }
        return null;
    }
}