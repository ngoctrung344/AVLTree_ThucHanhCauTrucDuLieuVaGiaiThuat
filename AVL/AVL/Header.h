#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int key;        // giá trị trong node
    Node* left;     // con trỏ đến cây con bên trái
    Node* right;    // con trỏ đến cây con bên phải
    int height;     // chiều cao node (để cân bằng AVL)
};

// Định nghĩa alias cho con trỏ Node*
typedef Node* treeAVL;

//đặt tên biến ngắn gọn, chi tiết, dễ hiểu
//phần main đặt tên biến ngắn gọn viết tắt 


//void NLR(tree root);
//void LRN(tree root);
//void NLR(tree root);

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