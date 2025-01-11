// Test password.
#include<iostream>
using namespace std;
//------------------ variable

//------------------ functions
void spiralTraversal(int array[], int size) {
    int left = 0;           // Start pointer
    int right = size - 1;   // End pointer

    while (left <= right) {
        if (left == right) {
            // When pointers meet in the middle, print the last element
            cout << array[left] << " ";
        } else {
            // Print the element from the left end
            cout << array[left] << " ";
            // Print the element from the right end
            cout << array[right] << " ";
        }
        left++;
        right--;
    }
}
//------------------ main
int main(){
	int size=6;
	int array[]={1, 2, 3, 4, 5, 6};
	
}