package LeetCode.L_125_2;

public class Main{
    public static void main(String[] args){
        mainBox box=new mainBox("pleum");
        System.out.printf("%d", box.size);
    }
}
class mainBox{
    String mainStr;
    int size;
    mainBox(String strIn){
        mainStr=strIn;
        size=mainStr.length();
    }
}