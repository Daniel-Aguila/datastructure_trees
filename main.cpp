#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

class tree{
public:
    Node* root;
    tree(){root=nullptr;}
    void insert(int);
    void insert(int,Node*);
    void inorder(Node*);
};

void tree::insert(int key) {
    if(root!=NULL)
        insert(key, root);
    else{
        root = new Node;
        root->data = key;
        root->lchild = nullptr;
        root->rchild = nullptr;
    }
}

void tree::insert(int key, Node*p){
    if(key<p->data){
        if(p->lchild!=NULL){
            insert(key,p->lchild);
        }
        else{ //Insert it on left Node
            p->lchild = new Node;
            p->lchild->data = key;
            p->lchild->lchild = nullptr;
            p->lchild->rchild = nullptr;
        }
    }
    else if(key>=p->data){
        if(p->rchild!=NULL)
            insert(key,p->rchild);
        else{
            p->rchild=new Node;
            p->rchild->data=key;
            p->rchild->lchild=nullptr;
            p->rchild->rchild=nullptr;
        }
    }
}

void tree::inorder(Node *p) {
    if(p!=nullptr){
        inorder(p->lchild);
        cout << p->data << endl;
        inorder(p->rchild);
    }
}

int main() {
    tree tree1;
    for(int i=0;i<10;i++){
        tree1.insert(i);
    }
    tree1.inorder(tree1.root);
    return 0;
}