package LeetCode.L_1;

public class Main {
    public static void main(String[] args){
        toolsBox box=new toolsBox();

        System.out.println(box.checkPalin("racecar"));
    }
}
class toolsBox{
    String str;
    int size;
    char[] arrayCh;

    void toRevArray(){
        for(int i=0, j=size-1;i<size;i++, j--){
            arrayCh[j]=str.charAt(i);
        }
    }
    boolean checkPalin(String strIn){
        str=strIn;
        size=str.length();
        arrayCh=new char[size];
        boolean status=true;
        toRevArray();
        for(int i=0; i<size;i++){
            if(arrayCh[i]!=str.charAt(i)){
                status=false;
                break;
            }
        }
        return status;
    }
}