#include <iostream>

int* createArray(int size) {
    int* newArray = new int[size];
    // Initialize the array elements if necessary
    for (int i = 0; i < size; ++i) {
        newArray[i] = 0; // Example initialization
    }
    return newArray;
}

int main() {
    int size = 10; // Size of the array
    int* myArray = createArray(size);

    // Use the array...
    
    // Don't forget to delete the array to avoid memory leaks
    delete[] myArray;

    return 0;
}
