#include<iostream>
using namespace std;
class passBox{
    private:
        int passCode;
        string status;
    public:
        int codeIn;
        int num1, num2, menuNum, ans;
        passBox(int passCodeIn);
        void inputPass(int tryN, int wrongN);
        void calculate();
        void mainFunc();
};
passBox::passBox(int passCodeIn){
    passCode=passCodeIn;;
}
void passBox::inputPass(int tryN, int wrongN){
    if(wrongN<4){
        cout<<"Enter code: ";
        cin>>codeIn;
        if(codeIn==passCode){
            status="pass";
        }
        else{
            inputPass(tryN+1, wrongN+1);
        }
    }
    else if(wrongN==4){
        status="lock";
        cout<<"Lock"<<endl;
    }
}
void passBox::calculate(){
    do{
        cout<<"Enter number1 ";
        cin>>num1;
    }

    while(num1>10);
    do{
        cout<<"Enter number2 ";
        cin>>num2;
    }
    while(num2>10);
    cout<<"Enter 1-5"<<endl;
    cout<<"Enter number more than 5 for exit."<<endl;
    do{
        cin>>menuNum;
        if(menuNum==1){
            cout<<num1<<" + "<<num2<<endl;
            ans=num1+num2;
            cout<<ans<<endl;
        }
        else if(menuNum==2){
            if(num1>num2){
                cout<<num1<<" - "<<num2<<endl;
                ans=num1-num2;
            }
            else if(num1<num2){
                cout<<num2<<" - "<<num1<<endl;
                ans=num2-num1;
            }
            cout<<ans<<endl;
        }
        else if(menuNum==3){
            cout<<num1<<" * "<<num2<<endl;
            ans=num1*num2;
            cout<<ans<<endl;
        }
        else if(menuNum==4){
            if(num1>num2){
                ans=num1/num2;
                cout<<num1<<" / "<<num2<<endl;
                cout<<ans;
            }
            else if(num1<num2){
                ans=num2/num1;
                cout<<num2<<" / "<<num1<<endl;
                cout<<ans<<endl;
            }
        }
        else if(menuNum==5){
            if(num1>num2){
                ans=num1%num2;
                cout<<num1<<" mod "<<num2<<endl;
                cout<<ans;
            }
            else if(num1<num2){
                ans=num2%num1;
                cout<<num2<<" mod "<<num1<<endl;
                cout<<ans<<endl;
            }
        }
    }
    while(menuNum<=5);
}
void passBox::mainFunc(){
    inputPass(0, 0);
    if(status=="lock"){
        cout<<"Can't do."<<endl;
    }
    else if(status=="pass"){
        calculate();
    }
}
int main(){
    passBox box(123);
    box.mainFunc();
}