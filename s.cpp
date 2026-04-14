#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode= new Node();
    newNode->data= value;
    newNode->left= NULL;
    newNode->right= NULL;
    return newNode;
}
Node* insertion(Node* root, int value){

if(root==NULL){
    return createNode(value);
}
if (value < root -> data){
    root->left= insertion(root -> left, value);
}
if (value> root->data){
    root->right= insertion(root -> right, value);
}
return root ;
}
 void inorder(Node* root){
 if(root==NULL)
    return;
    inorder(root-> left);
    cout<< root-> data<<" ";
    inorder(root-> right);
 }
int main(){
 Node*root =NULL;
 int n,value;

  cout<<"Prefer your Number of value :` ";
  cin>>n;

 for(int i=0; i<n; i++){
    cout<<"Enter the value  "<<i+1 <<" : ";
    cin>>value;
    root=insertion(root,value);

 }
    cout<<"\n Inorder Traversal :";

   inorder(root);

 }
