package LeetCode.NotDone.L125_Valid_Palindrome;

public class L125_Valid_Palindrome {
    public static void main(String[] args){
        palinBox palinObj=new palinBox("Pleum");

    }
}
class palinBox{
    int size;
    String str;
    char[] arrChar;
    char[] arrCharRev;
    palinBox(String strIn){
        str=strIn;
        size=str.length();
        arrChar=new char[size];
        arrCharRev=new char[size];
        for(int i=0;i<size;i++){
            arrChar[i]=str.charAt(i);
        }
    }
    void makeRev(){
        for(int i=0;i<size;i++){
            arrCharRev[i]=arrChar[size-1-i];
        }
    }
    void check(){
        
    }
}