#include "Header.h"

void main() {
	tree r;
	typeinfo x, n;
	init(r);
	cout << "\nBan muon nhap bao nhieu node trong cay?";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << i << " .";
		cin >> x;
		r=themNode(r, x);
	}
	NLR(r);

	system("pause");
}