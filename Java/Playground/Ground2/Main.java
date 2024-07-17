package Playground.Ground2;

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args){
        linkList list=new linkList();
        list.addFirst(1);
        list.addFirst(2);
        list.addFirst(3);
        list.show();
    }
}
class node{
    int num;
    node right;
    node(int numIn){
        num=numIn;
        right=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;
    int amount;
    String[] str;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.right=head;
        }
        else{
            tail=newNode;
        }
        head=newNode;
        amount++;
    }
    void llToArray(){
        node currNode=head;
        String data;
        int i=0;
        str=new String[amount];
        while(currNode!=null){
            data=Integer.toString(currNode.num);
            str[i]=data;
            i++;
            currNode=currNode.right;
        }
    }
    void show(){
        llToArray();
        JOptionPane.showMessageDialog(null, str);
    }
}
