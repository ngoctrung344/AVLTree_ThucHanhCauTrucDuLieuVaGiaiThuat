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
