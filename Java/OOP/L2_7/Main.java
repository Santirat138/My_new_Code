package OOP.L2_7;

public class Main{
    public static void main(String[] args){
        checkTool tool=new checkTool();
        tool.createRect1(200.5, 4, 2.5, 43);
        tool.createRect2(1.5, 5, 0.5, 3);
        tool.setDistanceXY();
        System.out.print(tool.checkOverlap());
    }
}
class rectangle{
    double x, y;
    double width, height;
    rectangle(double xIn, double yIn, double wIn, double hIn){
        x=xIn;
        y=yIn;
        width=wIn;
        height=hIn;
    }
}
class checkTool{
    rectangle rect1;
    rectangle rect2;
    double distanceXY;
    void createRect1(double xIn, double yIn, double wIn, double hIn){
        rect1=new rectangle(xIn, yIn, wIn, hIn);
    }
    void createRect2(double xIn, double yIn, double wIn, double hIn){
        rect2=new rectangle(xIn, yIn, wIn, hIn);
    }
    void setDistanceXY(){
        double horiDis=Math.pow((rect2.x-rect1.x), 2);
        double vertiDis=Math.pow((rect2.y-rect1.y), 2);
        distanceXY=Math.sqrt(horiDis+vertiDis);
    }
    boolean checkOverlap(){
        System.out.printf("Distance XY is %f\n", distanceXY);
        if((rect1.height+rect2.height>=distanceXY)||(rect1.width+rect2.width>=distanceXY)){
            return true;
        }
        else{
            return false;
        }
    }
}