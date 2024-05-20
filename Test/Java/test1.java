
public class test1 {
    public static void main(String[] args){
        toolsBox box=new toolsBox("pleum");
        box.toArrayRev();
        for(int i=0;i<5;i++){
            System.out.printf("%c ", box.arrayCh[i]);
        }
    }
}
class toolsBox{
    String str;
    int size;
    char[] arrayCh;

    toolsBox(String strIn){
        str=strIn;
        size=str.length();
        arrayCh=new char[size];
    }
    void toArrayRev(){
        for(int i=0, j=size-1;i<size;i++, j--){
            arrayCh[j]=str.charAt(i);
        }
    }
}