package LeetCode.NotDone.L66_Plus_One;

public class L66_Plus_One {
    public static void main(String[] args){
        int[] array={1, 2, 3, 4, 5};
        arrayBox arrObj=new arrayBox(5, array);

    }
}
class toolsBox{
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
    int countDigi(int numIn, int digi){
        if(numIn==0){
            return digi;
        }
        else{
            return countDigi(numIn/10, digi+1);
        }
    }
}
class arrayBox{
    int plusNum, num;
    int[] array1;
    int[] array2;
    int size1, size2;
    toolsBox tool=new toolsBox();
    arrayBox(int sizeIn, int[] arrayIn1){
        array1=arrayIn1;
        size1=sizeIn;
    }
    int makeInt(int curr, int newNum){
        if(curr==size1){
            return newNum;
        }
        else{
            newNum=(array1[curr]*tool.power(10, size1-curr-1))+newNum;
            return makeInt(curr+1, newNum);
        }
    }
    int plusMeth(int plusNumIn){
        plusNum=plusNumIn;
        int num=makeInt(0, 0);
        return num+plusNum;
    }
    void makeArr(int numIn){
        num=numIn;
        int size=tool.countDigi(numIn, 0);
        array2=new int[size];
        for(int curr=size-1;curr>=0;curr--){
            array2[curr]=num%10;
            num=num/10;
        }
    }
}