#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
int num;
{
    string passwd, name;
    int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;
    string p1 = "12345"; // Set : password
    int n1,i = 0;
   
    do
    {
        cout << "Enter Password : ";
        cin >> passwd;
        i++;
        if (i == 4) // Error :4 ENDg
        {
            break;
        }
        if (passwd != p1)
        {
           cout << "Input password ar " << i << " no correct" << endl;
        }
        cout << "\n";
    } while (!(passwd == p1));
    if (passwd == p1)
    for(i=1;i<=10;++i)
    {
    	cout << "\n\n";
    	cout << "-------------------------------------------------------------";
    	cout << "\n\n";
    	cout << "                         main menu                           ";
    	cout << "\n\n";
    	cout << "-------------------------------------------------------------";
    	cout << "\n\n";
    	cout << "                            1. +                             ";
    	cout << "\n\n";
    	cout << "                            2. -                             ";
    	cout << "\n\n";
    	cout << "                            3. x                             ";
    	cout << "\n\n";
    	cout << "                            4. div                           ";
    	cout << "\n\n";
    	cout << "                            5. mod                           ";
    	cout << "\n\n";
    	cout << "-------------------------------------------------------------";
    	cout << "\n\n";
    	cout << "                          Select to choice ==>  ";
    	cin >> num;
    	cout << "\n\n";

    
    
    switch (num){
    	case 1 :
    		cout << "Input numbrt 1 [1-10] ==> ";
    		cin >> a1;
    		cout << "\n\n";
    		cout << " input number 2 [1-10] ==> ";
    		cin >> a2;
    		n1 = a1 + a2 ;
    		cout << a1 << " + " << a2 << " = " << (a1+a2);
    		
    		break;
    		
    	case 2 :
    		cout << "Input numbrt 1 [1-10] ==> ";
    		cin >> b1;
    		cout << "\n\n";
    		cout << " input number 2 [1-10] ==> ";
    		cin >> b2;
    		n1 = b1 + b2 ;
    		cout << b1 << " - " << b2 << " = " << (b1-b2);
    		
    		break;
    	case 3 :
    		cout << "Input numbrt 1 [1-10] ==> ";
    		cin >> c1;
    		cout << "\n\n";
    		cout << " input number 2 [1-10] ==> ";
    		cin >> c2;
    		n1 = c1 * c2 ;
    		cout << c1 << " * " << c2 << " = " << (c1*c2);
    		
    		break;
    	case 4 :
    		cout << "Input numbrt 1 [1-10] ==> ";
    		cin >> d1;
    		cout << "\n\n";
    		cout << " input number 2 [1-10] ==> ";
    		cin >> d2;
    		n1 = d1 / d2 ;
    		cout << d1 << " / " << d2 << " = " << (d1/d2);
    		
    		break;
    	case 5 :
    		cout << "Input numbrt 1 [1-10] ==> ";
    		cin >> e1;
    		cout << "\n\n";
    		cout << " input number 2 [1-10] ==> ";
    		cin >> e2;
    		n1 = e1 % e2 ;
    		cout << e1 << " % " << e2 << " = " << (e1%e2);
    		
    		break;
    	case 6 :
    		cout << " <<< bye bye >>> ";
    		cout << "\n\nEND Program";
    		return 0;
    		
    	
    }
              
}}}

