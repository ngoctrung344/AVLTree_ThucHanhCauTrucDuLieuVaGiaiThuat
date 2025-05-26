#include "iostream"
using  namespace std;


// Cấu trúc nút của cây AVL
struct Node {
    int key; // Giá trị của nút
    struct Node* left; // Con trỏ đến nút con bên trái
    struct Node* right; // Con trỏ đến nút con bên phải
    int height; // Chiều cao của nút
};
// Định nghĩa kiểu con trỏ NodePtr thay cho Node*
typedef Node* NodePtr;
//đặt tên biến ngắn gọn, chi tiết, dễ hiểu
//phần main đặt tên biến ngắn gọn viết tắt 


//void NLR(tree root);
//void LRN(tree root);
//void NLR(tree root);
NodePtr insert(NodePtr node, int key);
int max(int a, int b);
NodePtr init(int k);
int height(NodePtr node);
NodePtr rightRotate(NodePtr y);
NodePtr leftRotate(NodePtr x);
int getBalance(NodePtr node);
void inOrder(NodePtr root);