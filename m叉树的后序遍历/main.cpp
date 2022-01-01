#define _CRT_SECURE_NO_WARNINGS 1
#include"Mtree.h"

void menu() {
	cout << "******************************" << endl;
	cout << "*****  1.m叉树的创建       ***" << endl;
	cout << "*****  2.m叉树的后序遍历   ***" << endl;
	cout << "*****  0.退出程序          ***" << endl;
	cout << "******************************" << endl;

}
int main() {
	memset(h, -1, sizeof h);
	int input;
	int root = 0;
	do {
		menu();
		cout << "请输入你要执行的操作:>" << endl;
		cin >> input;
		
		switch (input)
		{
		case 0:
			cout << "退出程序" << endl;
			break;
		case 1:
			root=CreateMtree();
			break;
		case 2:
			MtreePostTraversal(root);
			break;
		default:
			cout << "操作无效，请输入有效操作" << endl;
			break;
		}
	} while (input);
	return 0;
}