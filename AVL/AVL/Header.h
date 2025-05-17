#include "iostream"
using  namespace std;
const int max = 100;

typedef int typeinfo;
struct Node {
	typeinfo info;
	Node* left, *right;
	typeinfo height;
};
typedef Node* tree;


void init(tree& r);
tree taoNode(typeinfo x);
tree themNode(tree& root, typeinfo x);
void NLR(tree root);
void LRN(tree root);
void NLR(tree root);