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
    arrayBox box("pleum_lol_abc");
    for(int i=0;i<box.size;i++){
        cout<<box.ch[i]<<" ";
    }
}
