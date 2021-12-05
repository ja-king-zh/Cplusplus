#define _CRT_SECURE_NO_WARNINGS 1




//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1e4 + 10;
//int arr[N];
//int n;
//int main() {
//	cin >> n;
//	for (int i = 0;i < n;i++)cin >> arr[i];
//	int maxi, mini;
//	cin >> maxi >> mini;
//	sort(arr, arr + n);
//	for (int i = 0;i < n;i++)cout<<arr[i]<<' ';
//
//	return 0;
//}




//
//#include<iostream>
//#include<cstring>
//#include<stack>
//#include<stdio.h>
//#include<stdbool.h>
//#include<algorithm>
//using namespace std;
//typedef int Elemtype;
//typedef struct tree {
//	tree* left;
//	tree* right;
//	Elemtype data;
//}tree;
//tree* prevcreate() {
//	int a;
//	scanf("%d, ", &a);
//	//cin >> a;
//	tree* cur = new tree;
// 	if (a == -1)cur = NULL;
//	else {
//		cur->data = a;
//		cur->left = prevcreate();
//		cur->right = prevcreate();
//	}
//	return cur;
//}
//bool isValidBST(tree* root) {
//	//空树返回ture，空树是二叉搜索树
//	if (root == NULL)
//		return true;
//	stack<tree*>s;
//	//与前序遍历不同，一开始先不入栈
//	tree* current = root;
//	//记录出栈的node
//	//作用是与下一个出栈的node进行数值比较，前一个要小于后一个才满足二叉搜索树的条件
//	tree* pre = NULL;
//	//或的条件是因为一开始root没有入栈，此时栈空但没有遍历结束
//	while (!s.empty() || current != NULL) {
//		if (current != NULL) {
//			s.push(current);
//			current = current->left;
//		}
//		else {
//			current = s.top();
//			s.pop();
//			if (pre != NULL && pre->data>= current->data)
//				return false;
//			pre = current;
//			current = current->right;
//		}
//	}
//	return true;
//}
//
//
//int main() {
//	tree* t;
//	t = prevcreate();
//	
//	if (isValidBST(t)) {
//		cout << "YES";
//	}
//	else {
//		cout << "NO";
//	}
//	return 0;
//}






#include<iostream>
using namespace std;
#include<algorithm>
const int N = 1e4 + 10;
int arr[N];


//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0;i < n;i++)cin >> arr[i];
//	int l = 0, r = n - 1;
//	int ans;
//	cin >> ans;
//	int flag = 0;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (arr[mid] > ans) {
//			l = mid + 1;
//		}
//		else if (arr[mid] < ans) {
//			r = mid - 1;
//		}
//		else {
//			mid += 1;
//			cout << mid;
//			flag = 1;
//			break;
//		}
//	}
//	if (!flag)cout << 0;
//	return 0;
//}




int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0;i < n;i++)cout<< arr[i]<<' ';
	return 0;
}