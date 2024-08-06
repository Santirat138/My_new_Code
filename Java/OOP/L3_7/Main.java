package OOP.L3_7;

public class Main {
    public static void main(String[] args){
        MyTriangle tri=new MyTriangle();
        double ans=tri.findArea(2, 3, 4);
        System.out.println(ans);
    }
}
class MyTriangle{
    
    public boolean isValid(double side1, double side2, double side3){
        boolean status;
        if(side1+side2>side3){
            status=true;
        }
        else if(side1+side3>side2){
            status=true;
        }
        else if(side2+side3>side1){
            status=true;
        }
        else{
            status=false;
        }
        return status;
    }
    public double findArea(double side1, double side2, double side3){
        boolean isTriangle=isValid(side1, side2, side3);
        double area=-1;
        if(isTriangle){
            System.out.println("1");
            double s=(side1+side2+side3)/2;
            area=Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
        }
        else{
            System.out.println("0");
        }
        return area;
    }
}