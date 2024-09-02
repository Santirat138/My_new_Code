#include<iostream>
using namespace std;
//----------------- class data
class name{
    public:
        string fName;
        string lName;
};
class data{
    public:
        int id;
        name rName;
        int age;
};
//----------------- class node
class node{
    public:
        data info;
        node *right;
        node(int idIn, string fNameIn, string lNameIn, int ageIn);
};
node::node(int idIn, string fNameIn, string lNameIn, int ageIn){
    info.id=idIn;
    info.rName.fName=fNameIn;
    info.rName.lName=lNameIn;
    info.age=ageIn;
}
//----------------- class linkList

//----------------- class hashTable