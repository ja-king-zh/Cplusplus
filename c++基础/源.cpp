#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

////ȫȱʡ(һ��д������������������ʵ��ͬʱ���֣�
//void func1(int a = 10, int b = 20, int c = 30) {
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
////��ȱʡֻ�ܴ�������ȱʡ(һ��д������������������ʵ��ͬʱ���֣�
//void func2(int a, int b, int c = 30) {
//
//}
//
//int main() {
//	//// << ������	
//	//cout << "hello world" << endl;
//	////��printf�ĸ��������ĸ�
//	//int a;
//
//	//// >> ����ȡ�����
//	//cin >> a;
//	//scanf("%d", &a);
//
//	func1();
//	func1(1);
//	func1(1, 2);
//	func1(1, 2, 3);
//	return 0;
//}



//��������--��������ͬ�����Ͳ�ͬ�����������ͬ����˳��ͬ...
//������ֵ��ͬ���ܹ�������!!!
int add(int a, int b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}
int main() {
	add(1, 2);
	add(1.1, 2.2);

	return 0;
}