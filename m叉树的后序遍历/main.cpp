#define _CRT_SECURE_NO_WARNINGS 1
#include"Mtree.h"

void menu() {
	cout << "******************************" << endl;
	cout << "*****  1.m�����Ĵ���       ***" << endl;
	cout << "*****  2.m�����ĺ������   ***" << endl;
	cout << "*****  0.�˳�����          ***" << endl;
	cout << "******************************" << endl;

}
int main() {
	memset(h, -1, sizeof h);
	int input;
	int root = 0;
	do {
		menu();
		cout << "��������Ҫִ�еĲ���:>" << endl;
		cin >> input;
		
		switch (input)
		{
		case 0:
			cout << "�˳�����" << endl;
			break;
		case 1:
			root=CreateMtree();
			break;
		case 2:
			MtreePostTraversal(root);
			break;
		default:
			cout << "������Ч����������Ч����" << endl;
			break;
		}
	} while (input);
	return 0;
}