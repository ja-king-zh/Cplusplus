#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

////全缺省(一般写在声明，不能声明和实现同时出现）
//void func1(int a = 10, int b = 20, int c = 30) {
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
////半缺省只能从右至左缺省(一般写在声明，不能声明和实现同时出现）
//void func2(int a, int b, int c = 30) {
//
//}
//
//int main() {
//	//// << 流插入	
//	//cout << "hello world" << endl;
//	////和printf哪个方便用哪个
//	//int a;
//
//	//// >> 流提取运算符
//	//cin >> a;
//	//scanf("%d", &a);
//
//	func1();
//	func1(1);
//	func1(1, 2);
//	func1(1, 2, 3);
//	return 0;
//}



//函数重载--函数名相同，类型不同或参数个数不同或者顺序不同...
//但返回值不同不能构成重载!!!
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