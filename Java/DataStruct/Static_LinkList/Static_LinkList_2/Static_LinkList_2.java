package DataStruct.Static_LinkList.Static_LinkList_2;
public class Static_LinkList_2 {
    public static void main(String[] args){

    }
}
class arrNode{
    int num;
    int prev;
    int next;
    arrNode(int numIn, int prevIn, int nextIn){
        num=numIn;
        prev=prevIn;
        next=nextIn;
    }
}
class arrLinkList{
    int head;
    int tail;
    int size;
    arrNode[] nodeObj;
    arrLinkList(int sizeIn){
        size=sizeIn;
        nodeObj=new arrNode[size];
        for(int i=0;i<size;i++){
            nodeObj[i]=new arrNode(-1, -1, -1);
        }
    }
}