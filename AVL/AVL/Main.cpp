#include "Header.h"

int main() {
    NodePtr root = nullptr; // Khởi tạo cây AVL rỗng

    // Chèn một số khóa
    int keys[] = { 10, 20, 30, 40, 50, 25 };

    cout << "Chèn các khóa: ";
    for (int k : keys)
        cout << k << " "; // In các khóa đã chèn
    cout << endl;

    for (int k : keys) {
        root = insert(root, k); // Chèn từng khóa vào cây
    }

    cout << "Duyệt cây theo thứ tự (in-order) là:\n";
    inOrder(root); // In cây theo thứ tự
    cout << endl;

    return 0;
}