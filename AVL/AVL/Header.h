#include <iostream>
using namespace std;

struct Node {
    int key;        
    Node* left;    
    Node* right;    
    int height;     
};

typedef Node* treeAVL;





void init(treeAVL& node);
treeAVL createNode(int key);
int getHeight(treeAVL node);
int getBalance(treeAVL node);
treeAVL rightRotate(treeAVL y);
treeAVL leftRotate(treeAVL x);
treeAVL minValueNode(treeAVL node);
treeAVL insert(treeAVL node, int key);
treeAVL deleteNode(treeAVL root, int key);
void preOrder(treeAVL root);
void printMenu();