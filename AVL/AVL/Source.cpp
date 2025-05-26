#include "Header.h"

// Hàm khởi tạo nodeptr gán NULL (rỗng)
void init(nodeptr& node) {
    node = NULL;  // Sử dụng NULL để khởi tạo
}

// Hàm tạo node mới với key cho trước
nodeptr createNode(int key) {
    nodeptr node = new Node;
    node->key = key;
    node->left = NULL;  // Sử dụng NULL
    node->right = NULL; // Sử dụng NULL
    node->height = 1;   // node mới được tạo chiều cao là 1 (lá)
    return node;
}

// Hàm lấy chiều cao của node (nếu node null trả về 0)
int getHeight(nodeptr node) {
    if (node == NULL)  // Sử dụng NULL
        return 0;
    return node->height;
}

// Hàm lấy độ cân bằng của node = chiều cao cây con trái - chiều cao cây con phải
int getBalance(nodeptr node) {
    if (node == NULL)  // Sử dụng NULL
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Xoay phải cây con gốc y để cân bằng (Right Rotate)
nodeptr rightRotate(nodeptr y) {
    nodeptr x = y->left;
    nodeptr T2 = x->right;

    // Xoay
    x->right = y;
    y->left = T2;

    // Cập nhật lại chiều cao
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Trả về node gốc mới
    return x;
}

// Xoay trái cây con gốc x để cân bằng (Left Rotate)
nodeptr leftRotate(nodeptr x) {
    nodeptr y = x->right;
    nodeptr T2 = y->left;

    // Xoay
    y->left = x;
    x->right = T2;

    // Cập nhật lại chiều cao
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Trả về node gốc mới
    return y;
}

// Tìm node nhỏ nhất trong cây (node xa trái nhất)
nodeptr minValueNode(nodeptr node) {
    nodeptr current = node;
    while (current->left != NULL)  // Sử dụng NULL
        current = current->left;
    return current;
}

// Hàm đệ quy chèn một key vào cây AVL, trả về node gốc mới sau khi cân bằng
nodeptr insert(nodeptr node, int key) {
    // 1. Chèn bình thường như BST
    if (node == NULL)  // Sử dụng NULL
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Không cho chèn key trùng
        return node;

    // 2. Cập nhật chiều cao của node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Tính độ cân bằng để kiểm tra việc cân bằng
    int balance = getBalance(node);

    // 4. Kiểm tra 4 trường hợp mất cân bằng

    // Trường hợp Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Trường hợp Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Trường hợp Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Nếu cây cân bằng thì trả lại node hiện tại
    return node;
}

// Hàm đệ quy xóa node có key cho trước, trả về node gốc mới sau khi cân bằng
nodeptr deleteNode(nodeptr root, int key) {
    // Bước 1: tìm node cần xóa như BST
    if (root == NULL)  // Sử dụng NULL
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // node có key cần xóa tìm thấy

        // node chỉ có 1 con hoặc không có con
        if ((root->left == NULL) || (root->right == NULL)) {
            nodeptr temp = root->left ? root->left : root->right;

            // Không có con
            if (temp == NULL) {
                temp = root;
                root = NULL;  // Sử dụng NULL
            }
            else // Có 1 con thì thay node bằng con đó
                *root = *temp;

            delete temp;
        }
        else {
            // node có 2 con:
            // Tìm node nhỏ nhất bên cây con phải
            nodeptr temp = minValueNode(root->right);

            // Sao chép giá trị
            root->key = temp->key;

            // Xóa node nhỏ nhất đó trong cây con phải
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Nếu chỉ có 1 node thì return
    if (root == NULL)  // Sử dụng NULL
        return root;

    // Bước 2: cập nhật chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Bước 3: cân bằng lại cây
    int balance = getBalance(root);

    // Nếu mất cân bằng thì 4 trường hợp:

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Hàm duyệt cây theo thứ tự preorder và in key ra màn hình
void preOrder(nodeptr root) {
    if (root != NULL) {  // Sử dụng NULL
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Hàm in menu ra màn hình
void printMenu() {
    cout << "\n------------------- MENU -------------------\n";
    cout << "1. Chen phan tu vao cay AVL\n";
    cout << "2. Xoa phan tu khoi cay AVL\n";
    cout << "3. Duyet cay (Preorder)\n";
    cout << "4. Thoat\n";
    cout << "--------------------------------------------\n";
    cout << "Nhap lua chon: ";
}




