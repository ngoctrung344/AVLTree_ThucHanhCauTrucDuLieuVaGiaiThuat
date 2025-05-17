#include "Header.h"

void init(tree& r) {
	r = NULL;
}
tree taoNode(typeinfo x) {
	tree p = new Node();
	p->info = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}
tree themNode(tree& root, typeinfo x) {
	if (root == NULL)
		return taoNode(x);
	else {
		if (x < root->info)
			root->left = themNode(root->left, x);
		if (x > root->info)
			root->right = themNode(root->right, x);
	}
	return root;
}
void NLR(tree root) {
	if (root != NULL) {
		cout << root->info << " ";
		NLR(root->left);
		NLR(root->right);
	}
}