package OOP.L3_5;

public class Main {
    public static void main(String[] args){
        roachCity city=new roachCity(10);
        city.waitSpray(3);
    }
}
class roachCity{
    int roachAmount;
    int decreaseAmount;
    roachCity(int startAmount){
        roachAmount=startAmount;
    }
    void doWait(int waitAmount){
        for(int i=1;i<=waitAmount;i++){
            roachAmount=roachAmount*2;
        }
    }
    void doSpray(int sprayAmount){
        for(int i=1;i<=sprayAmount;i++){
            decreaseAmount=(10*roachAmount)/100;
            roachAmount=roachAmount-decreaseAmount;
        }
    }
    void waitSpray(int amount){
        doWait(amount);
        doSpray(amount);
        System.out.printf("%d\n", roachAmount);
    }
}