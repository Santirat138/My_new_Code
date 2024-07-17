package Playground.Ground1;

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args){
        String question1=JOptionPane.showInputDialog(null, "Fahren or Cels");
        float fahren;
        float cels;
        float ans;
        if(question1.equals("CToF")){
            String question2=JOptionPane.showInputDialog(null, "Enter Celsius.");
            cels=Float.valueOf(question2);
            fahren=((9.f/5.f)*cels)-32.f;
            ans=fahren;
        }
        else if(question1.equals("FToC")){
            String question3=JOptionPane.showInputDialog(null, "Enter Fahrenheit.");    
            fahren=Float.valueOf(question3);
            cels=(5.f/9.f)*(fahren-32.f);
            ans=cels;
        }
        else{
            ans=-9999;
            System.out.println("Error");
        }
        JOptionPane.showMessageDialog(null, ans);
    }
}
