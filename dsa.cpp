#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};


void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


bool isFullBinary(Node* root) {

    if (root == NULL)
        return true;


    if (root->left == NULL && root->right == NULL)
        return true;


    if (root->left != NULL && root->right != NULL)
        return isFullBinary(root->left) && isFullBinary(root->right);


    return false;
}




int main() {
     Node* root=NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

   if (isFullBinary(root))
    cout << "\nYes, it is a Full Binary Tree";
   else
    cout << "\nNo, it is NOT a Full Binary Tree";



    return 0;
}


