package OOP.L1_3;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        triangle tri=new triangle();
        double x1, y1, x2, y2, x3, y3;
        x1=input.nextDouble();
        y1=input.nextDouble();
        x2=input.nextDouble();
        y2=input.nextDouble();
        x3=input.nextDouble();
        y3=input.nextDouble();
        tri.setSide(x1, y1, x2, y2, x3, y3);
        tri.setS();
        tri.showArea();
    }
}
class toolsBox{
    double findRoot(double numIn){
        return Math.sqrt(numIn);
    }
    double power(double base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }

}
class triangle{
    toolsBox tool=new toolsBox();
    double side1, side2, side3, s;
    void setSide(double x1, double y1, double x2, double y2, double x3, double y3){
        side1=tool.findRoot(tool.power((x2-x1), 2)+tool.power((y2-y1), 2));
        side2=tool.findRoot(tool.power((x3-x2), 2)+tool.power((y3-y2), 2));
        side3=tool.findRoot(tool.power((x3-x1), 2)+tool.power((y3-y1), 2));
    }
    void setS(){
        s=(side1+side2+side3)/2;
    }
    void showArea(){
        double area=tool.findRoot(s*(s-side1)*(s-side2)*(s-side3));
        System.out.printf("%f\n", area);
    }
}