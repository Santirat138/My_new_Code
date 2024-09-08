#include <iostream>
#define capacity 10
using namespace std;

class MinHeap {
    public:
        int heapArray[capacity];
        int lastIdx=0;
        int parent(int i) { return (i - 1) / 2; }
        int left(int i) { return (2 * i + 1); }
        int right(int i) { return (2 * i + 2); }
        void insertKey(int k);
        void showArray();
};

void MinHeap::insertKey(int newNum) {
    if (lastIdx == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    lastIdx++;
    int currIdx = lastIdx - 1;
    heapArray[currIdx] = newNum;
    while (currIdx != 0 && heapArray[parent(currIdx)] > heapArray[currIdx]) {
        swap(heapArray[currIdx], heapArray[parent(currIdx)]);
        currIdx = parent(currIdx);
    }
}
void MinHeap::showArray(){
    for(int i=0;i<lastIdx;i++){
        cout<<heapArray[i]<<" ";
    }
    cout<<endl;
}

int main() {
    MinHeap h;
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.showArray();
}
