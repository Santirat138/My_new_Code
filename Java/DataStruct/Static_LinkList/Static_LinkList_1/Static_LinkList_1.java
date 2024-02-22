package DataStruct.Static_LinkList.Static_LinkList_1;

public class Static_LinkList_1 {
    public static void main(String[] args){
        arrayLinkList arrLL=new arrayLinkList(5);
        arrLL.addNum(1);
        arrLL.addNum(2);
        arrLL.addNum(3);
        arrLL.showArray(0);
    }
}
class arrayNode{
    int num;
    int next;
    arrayNode(int numIn, int nextIn){
        num=numIn;
        next=nextIn;
    }
}
class arrayLinkList{
    int head;
    int tail;
    int size;
    arrayNode[] arrNode;
    arrayLinkList(int sizeIn){
        size=sizeIn;
        head=-1;
        tail=-1;
        arrNode=new arrayNode[size];
        for(int i=0;i<size;i++){
            arrNode[i]=new arrayNode(-1, -1);
        }
    }
    int findEmpty(int currIdx){
        if(currIdx<size){
            if(arrNode[currIdx].num!=-1){
                return currIdx;
            }
            else if(arrNode[currIdx].num==-1){
                return findEmpty(currIdx+1);
            }
        }
        return -1;  
    }
    void addNum(int newNum){
        int currIdx=findEmpty(0);
        if(currIdx!=-1){
            arrNode[currIdx].num=newNum;
        }
        else{
            System.out.println("Full.");
        }
    }
    void showArray(int currIdx){
        if(currIdx>=size){
            System.out.println("End.");
        }
        else{
            System.out.printf("%d ", arrNode[currIdx].num);
            showArray(arrNode[currIdx].next);
        }
    }
}