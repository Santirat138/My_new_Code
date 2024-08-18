package OOP.L3_6;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        String str=input.next();
        System.out.print(checkPalin(str));
    }
    static boolean checkPalin(String strIn){
        String str=strIn.replaceAll("\\s", "");;
        boolean isPalin=true;
        int strSize=str.length();
        if(strSize%2==0){
            for(int curr1=0, curr2=strSize-1;curr1<curr2;curr1++, curr2--){
                if(str.charAt(curr1)!=str.charAt(curr2)){
                    isPalin=false;
                    break;
                }
            }
        }
        else{
            for(int curr1=0, curr2=strSize-1;curr1!=curr2;curr1++, curr2--){
                if(str.charAt(curr1)!=str.charAt(curr2)){
                    isPalin=false;
                    break;
                }
            }
        }
        return isPalin;
    }
}