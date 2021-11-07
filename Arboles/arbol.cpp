#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insert (Node* t, int d){
    if(t==NULL){
        return new Node(d);
    }

    if(d < t->data){
        t->left = insert(t->left, d);
    }else{
        t->right = insert(t->right, d);
    }

    return t;
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;

    while(current && current->left!=NULL){
        current = current->left;
    }

    return current;
}

struct Node* maxValueNode(struct Node* node){
    struct Node* current = node;

    while(current && current->right!=NULL){
        current = current->right;
    }

    return current;
}

Node* search(Node* t, int k){
    if(t->data == k){
        return t;
    }

    if(k < t->data){
        return search(t->left, k);
    }else{
        return search(t->right, k);
    }
}

void printInOrder(struct Node* node){
    if(node==NULL)
        return;
    
    //L
    printInOrder(node->left);

    //N
    cout<<node->data<<" ";

    //R
    printInOrder(node->right);
}

void printPreOrder(struct Node* node){
    if(node==NULL)
        return;
    
    //N
    cout<<node->data<<" ";
    //L
    printPreOrder(node->left);
    //R
    printPreOrder(node->right);
}


void printPostOrder(struct Node* node){
    if(node==NULL)
        return;
    
    //L
    printPostOrder(node->left);
    //R
    printPostOrder(node->right);
    //N
    cout<<node->data<<" ";
}

int main(){

    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);

    printInOrder(root);
    cout<<endl;
    printPreOrder(root);
    cout<<endl;
    printPostOrder(root);

    return 0;
}