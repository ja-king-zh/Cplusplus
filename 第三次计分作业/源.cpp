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
//	//��������ture�������Ƕ���������
//	if (root == NULL)
//		return true;
//	stack<tree*>s;
//	//��ǰ�������ͬ��һ��ʼ�Ȳ���ջ
//	tree* current = root;
//	//��¼��ջ��node
//	//����������һ����ջ��node������ֵ�Ƚϣ�ǰһ��ҪС�ں�һ�����������������������
//	tree* pre = NULL;
//	//�����������Ϊһ��ʼrootû����ջ����ʱջ�յ�û�б�������
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