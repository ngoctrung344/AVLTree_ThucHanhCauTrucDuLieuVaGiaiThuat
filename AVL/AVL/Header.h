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
typedef Node* nodeptr;

//đặt tên biến ngắn gọn, chi tiết, dễ hiểu
//phần main đặt tên biến ngắn gọn viết tắt 


//void NLR(tree root);
//void LRN(tree root);
//void NLR(tree root);

void init(nodeptr& node);
nodeptr createNode(int key);
int getHeight(nodeptr node);
int getBalance(nodeptr node);
nodeptr rightRotate(nodeptr y);
nodeptr leftRotate(nodeptr x);
nodeptr minValueNode(nodeptr node);
nodeptr insert(nodeptr node, int key);
nodeptr deleteNode(nodeptr root, int key);
void preOrder(nodeptr root);
void printMenu();