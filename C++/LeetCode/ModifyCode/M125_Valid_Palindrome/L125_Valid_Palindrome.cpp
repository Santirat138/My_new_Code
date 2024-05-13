#include<iostream>
#define nullNum -1
using namespace std;
class arrayBox{
    public:
        int size;
        string txtMain;
        char *ch;
        arrayBox(string txtIn);
};
arrayBox::arrayBox(string txtIn){
    txtMain=txtIn;
    size=txtIn.size();
    ch=new char[size];
    txtMain.copy(ch, size);
}
//************ main ************
int main(){

}
