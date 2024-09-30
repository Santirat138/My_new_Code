#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;  // height of a tree is the maximum number of nodes on the root-to-leaf path

    Node(int item) {
        key = item;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    int updateHeight(Node* node) {
        if (node == NULL) return 0;
        
        int hL = getHeight(node->left);
        int hR = getHeight(node->right);
        int max = (hL > hR) ? hL : hR;
        node->height = max + 1;
        return node->height;
    }

    bool checkAVLBalance(Node* node) {
        // the difference between heights of left and right subtrees 
        // for any node cannot be more than one.
        // Return TRUE if it is balanced, return FALSE, otherwise
        if (node == NULL) return true;
        
        int hL = getHeight(node->left);
        int hR = getHeight(node->right);
        if (hL - hR >= -1 && hL - hR <= 1) {
            return true;
        }
        
        return false;
    }

    Node* rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        updateHeight(node);
        updateHeight(leftChild);
        return leftChild;        // as a new root
    }

    Node* rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        updateHeight(node);
        updateHeight(rightChild);
        return rightChild;       // as a new root;
    }

    Node* reBalance(Node* node) {
        int hL = getHeight(node->left);
        int hR = getHeight(node->right);
        if (hL > hR) {
            if (getHeight(node->left->left) > getHeight(node->left->right)) {
                // Single Right rotation
                cout << "Right rotation: " << node->key << endl;
                node = rotateRight(node);
            } else {
                // Double Left-Right rotation
                cout << " Left-Right rotation: " << node->key << endl;
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        } else {
            if (getHeight(node->right->left) > getHeight(node->right->right)) {
                // Double Right-Left rotation
                cout << " Right-Left rotation: " << node->key << endl;
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            } else {
                // Single Left rotation
                cout << " Left rotation: " << node->key << endl;
                node = rotateLeft(node);
            }
        }
        return node;
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int key) {
        root = insert2(root, key);
    }
    void showLevelorder(){
        int treeHeight=getHeight(root);
        for(int i=0;i<=treeHeight;i++){
            showCurrLevel(root, i);
            cout<<endl;
        }
    }

private:
    Node* insert2(Node* node, int key) {
        // Base case: node is null
        if (node == NULL) {
            return new Node(key);
        }    
        if (key < node->key) {
            node->left = insert2(node->left, key);
        } else {
            node->right = insert2(node->right, key);
        }
        
        updateHeight(node);
        if (!checkAVLBalance(node)) {
            cout << "Not balance: " << node->key << endl;
            cout << " Left subtree height : " << getHeight(node->left) << endl;
            cout << " Right subtree height : " << getHeight(node->right) << endl;
            node = reBalance(node);
        }
        return node;
    }
    void showCurrLevel(Node *currNode, int levelIn){
        if(currNode==nullptr){
            return ;
        }
        if(levelIn==0){
            cout<<currNode->key<<" ";
        }
        showCurrLevel(currNode->left, levelIn-1);
        showCurrLevel(currNode->right, levelIn-1);
    }
};
int main(){
    AVLTree *tree=new AVLTree();
    tree->insert(1);
    tree->insert(10);
    tree->insert(5);
    tree->showLevelorder();
}