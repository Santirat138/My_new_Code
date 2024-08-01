package OOP.L1_7;

public class Main {
    public static void main(String[] args){
        mainBox box=new mainBox();
        box.mainFunc(10, 30);
    }
}
class toolsBox{
    int power(int  base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
}
class mainBox{
    int x, n;
    int ans=0;
    toolsBox tool=new toolsBox();
    void mainFunc(int xIn, int nIn){
        x=xIn;
        n=nIn;
        for(int currN=0;currN<=n;currN++){
            ans=ans+tool.power(x, currN);
        }
        System.out.printf("%d", ans);
    }
}