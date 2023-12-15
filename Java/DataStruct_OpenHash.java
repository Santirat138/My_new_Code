public class DataStruct_OpenHash {
    public static void main(String[] args){

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

    linkList(){
        head=null;
    }
    void addNode(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
}
class table extends linkList{
    int size;
    int[] array;
    int idx;
    int num;

    table(int sizeIn){
        size=sizeIn;
        array=new int[size];
        for(int i=0;i<size;i++){
            array[i]=-1;
        }
    }
    int findIdx(int numIn){
        return numIn%size;
    }
    void insert(int newNum){
        
    }
}