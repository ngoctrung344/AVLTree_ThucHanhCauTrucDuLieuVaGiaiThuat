#include "Header.h"

int main() {
    nodeptr root;
    init(root);  // Khởi tạo cây rỗng

    int choice,n;
    int value;

    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri phan tu can chen: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nGia tri phan tu thu " << i + 1 << " :";
                cin >> value;
                root = insert(root, value);
            }
            break;
        case 2:
            cout << "Nhap gia tri phan tu can xoa: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Da xoa " << value << " khoi cay AVL (neu co).\n";
            break;
        case 3:
            cout << "Duyet cay theo thu tu Preorder: ";
            preOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "Thoat chuong trinh. Tam biet!\n";
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }

    return 0;
}