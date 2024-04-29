// C++ program to illustrate 
// using break statement 
// in Linear Search 
#include <iostream> 
using namespace std; 

void findElement(int arr[], int size, int key) 
{ 
	for (int i = 0; i < size; i++) { 
		if (arr[i] == key) { 
			cout << "Element found at position: "<< (i + 1); 
			break; 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6 }; 
	// no of elements 
	int n = 6; 
	// key to be searched 
	int key = 3; 

	// Calling function to find the key 
	findElement(arr, n, key); 

	return 0; 
}
