package OOP.L1_9;
import java.util.Scanner;
public class Main {
    Scanner input=new Scanner(System.in);
    public static void main(String[] args){
        Main func=new Main();
        func.inputNum();
    }
    void inputNum(){
        int num;
        int maxNum=0;
        int amount=0;
        do{ 
            num=input.nextInt();
            if(num>maxNum){
                maxNum=num;
            }
            else if(num==maxNum){
                amount++;
            }
        }
        while(num!=0);
        System.out.printf("%d amount : %d", maxNum, amount);
    }
}
