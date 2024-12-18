// C++ program to convert sorted 
// array to BST.
#include<bits/stdc++.h>
using namespace std;
  
class Node { 
    public:
        int data; 
        Node* left; 
        Node* right; 
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

// Recursive function to construct BST
Node* sortedArrayToBSTRecur(vector<int>& arr, int start, int end) {
    if(start > end) return nullptr;
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create root node
    Node* root = new Node(arr[mid]);

    // Create left subtree
    root->left = sortedArrayToBSTRecur(arr, start, mid - 1);

    // Create right subtree
    root->right = sortedArrayToBSTRecur(arr, mid + 1, end);
    return root;
}

Node* sortedArrayToBST(vector<int> &arr) {
    int n = arr.size();
    return sortedArrayToBSTRecur(arr, 0, n-1);
}

void preOrder(Node* root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* root = sortedArrayToBST(arr);
    preOrder(root);
    
    return 0;
}
