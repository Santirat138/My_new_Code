#include <iostream>
using namespace std;
// Add function deleteNode.
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;  // height of a tree is the maximum number of nodes on the root-to-leaf path (for this is Not edge use for"https://www.cs.usfca.edu/~galles/visualization/Algorithms.html") follow height by path by using recursive.
    
    Node(int item) {
        key = item;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root){
	if (root == NULL){
		return 0; //height = 0 
	}
	return root->height;
}

int updateHeight(Node* root){  //Call every time when insert.
	if (root == NULL){
        return 0;
    }
	
	int hL = getHeight(root->left);
	int hR = getHeight(root->right);
	root->height = max(hL, hR)+1;
	return root->height;
}

bool checkBalance(Node *root){
    if(root==nullptr){
        return true;
    }
    int hL=getHeight(root->left);
    int hR=getHeight(root->right);
    if((hL-hR>=-1)&&(hL-hR<=1)){
        return true;
    }
    else{
        return false;
    }
}
Node *rightRotate(Node *root){
    Node *newRoot=root->left;
    root->left=newRoot->right;
    newRoot->right=root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
Node *leftRotate(Node *root){
    Node *newRoot=root->right;
    root->right=newRoot->left;
    newRoot->left=root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
Node *reBalance(Node *root){
    if(getHeight(root->left)>getHeight(root->right)){
        if(getHeight(root->left->left)>getHeight(root->left->right)){
            // Single right rotation.
            root=rightRotate(root);
        }
        else{
            /* doubleLeftRightRotate; */
            root->left=leftRotate(root->left);
            root=rightRotate(root);
        }
    }
    else{
        if(getHeight(root->right->right)>getHeight(root->right->left)){
            // Single left rotation.
            root=leftRotate(root);
        }
        else{
            /* doublerightLeftRotate */
            root->right=rightRotate(root->right);
            root=leftRotate(root);
        }
    }
}

Node* insert2(Node* root, int key) {
  
  	// Base case: root is null
	if (root == NULL) return new Node(key);
	
	if (key < root->key) {
		root->left = insert2(root->left, key);
	} else {
		root->right = insert2(root->right, key);
	}
	
	updateHeight(root);
    if(!checkBalance(root)){
        root=reBalance(root);

    }
    
	return root;
}
void showCurrLevel(Node *root, int levelIn){
    if(root==nullptr){
        return ;
    }
    if(levelIn==0){
        cout<<root->key<<" ";
    }
    else{
        showCurrLevel(root->left, levelIn-1);
        showCurrLevel(root->right, levelIn-1);
    }
}
void showLevelorder(Node *root){
    int treeHeight=updateHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
    }
}
// Driver Code
int main() {
  
    Node* root = NULL;
    root = insert2(root, 3);
    root = insert2(root, 5);
    root = insert2(root, 10);
    root = insert2(root, 50);
    root = insert2(root, 8);
    root = insert2(root, 7);
    root = insert2(root, 1);
    root = insert2(root, 78);
    showLevelorder(root);
}
