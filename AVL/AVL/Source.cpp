#include "Header.h"
// Hàm trả về giá trị lớn hơn giữa hai số nguyên
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Hàm khởi tạo một nút mới với giá trị key truyền vào
NodePtr init(int k) {
    NodePtr newNode = new Node; // Tạo nút mới
    newNode->key = k; // Gán giá trị cho nút
    newNode->left = nullptr; // Khởi tạo con trỏ bên trái
    newNode->right = nullptr; // Khởi tạo con trỏ bên phải
    newNode->height = 1; // Khởi tạo chiều cao
    return newNode; // Trả về nút mới
}

// Hàm lấy chiều cao của nút
int height(NodePtr node) {
    return node ? node->height : 0; // Nếu nút không tồn tại, trả về 0
}

// Hàm lấy hệ số cân bằng của nút
int getBalance(NodePtr node) {
    if (!node) return 0; // Nếu nút không tồn tại, trả về 0
    return height(node->left) - height(node->right); // Hệ số cân bằng = chiều cao bên trái - chiều cao bên phải
}

// Hàm xoay phải cho cây AVL
NodePtr rightRotate(NodePtr y) {
    NodePtr x = y->left; // Nút con bên trái
    NodePtr T2 = x->right; // Nút con bên phải của x

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Trả về nút gốc mới
    return x;
}

// Hàm xoay trái cho cây AVL
NodePtr leftRotate(NodePtr x) {
    NodePtr y = x->right; // Nút con bên phải
    NodePtr T2 = y->left; // Nút con bên trái của y

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Trả về nút gốc mới
    return y;
}

// Hàm chèn một khóa vào cây AVL và trả về nút gốc mới
NodePtr insert(NodePtr node, int key) {
    // Thực hiện chèn như cây nhị phân tìm kiếm
    if (!node)
        return init(key); // Tạo nút mới với hàm init

    if (key < node->key)
        node->left = insert(node->left, key); // Chèn vào bên trái
    else if (key > node->key)
        node->right = insert(node->right, key); // Chèn vào bên phải
    else // Không cho phép khóa trùng lặp
        return node;

    // Cập nhật chiều cao của nút tổ tiên
    node->height = 1 + max(height(node->left), height(node->right));

    // Lấy hệ số cân bằng
    int balance = getBalance(node);

    // Nếu nút không cân bằng, thực hiện các trường hợp xoay
    // Trường hợp trái trái
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Trường hợp phải phải
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Trường hợp trái phải
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp phải trái
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Trả về con trỏ nút không thay đổi
    return node;
}

// Hàm in thứ tự cây
void inOrder(NodePtr root) {
    if (root) {
        inOrder(root->left); // In cây con bên trái
        cout << root->key << " "; // In giá trị của nút
        inOrder(root->right); // In cây con bên phải
    }
}


