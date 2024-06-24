// Bisection method
#include<iostream>
#include<cmath>
using namespace std;
//--------------- functions ---------------
float bisectionMethod(float xL, float xR);
float fX(float xIn);
float findError(float xN, float xO);
//--------------- main ---------------
int main(){
    cout<<bisectionMethod(1, 2);
}
//--------------- functions ---------------
float bisectionMethod(float xL, float xR){
    
}
float fX(float xIn){
    return pow(xIn, 3)-xIn-2;
}
float findError(float xN, float xO){
    return abs(xN-xO)/xN;
}