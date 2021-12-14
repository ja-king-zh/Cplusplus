#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;


//int main() {
//	priority_queue<int, vector<int>, greater<int>>heap;
//	char a = 0;
//	do {
//		int data;
//		cin >> data;
//		heap.push(data);
//
//	} while (cin.get() != '\n');
//	int ans = 0;
//	while (heap.size()>1) {
//		int a = heap.top();
//		heap.pop();
//		int b = heap.top();
//		heap.pop();
//		ans = ans + a + b;
//		heap.push(a + b);
//	}
//	cout << ans;
//	return 0;
//}

#include<iostream>
#include<stdio.h>
using namespace std;
typedef char Elemtype;
typedef struct tree {
	tree* l;
	tree* r;
	Elemtype data;
}tree;

tree* prevcreate() {
	char a;
	//scanf("%c ", &a);
	cin >> a;
	tree* cur = new tree;
	if (a == '#') {
		cur = NULL;
	}
	else {
		cur->data = a;
		cur->l = prevcreate();
		cur->r = prevcreate();
	}
	return cur;
}

int treedepth(tree*t) {
	if (t == NULL)return 0;
	int l = treedepth(t->l);
	int r = treedepth(t->r);
	return l > r ? l + 1 : r + 1;
}
void posttraval(tree* t) {
	if (t == NULL)return;
	posttraval(t->l);
	posttraval(t->r);
	cout << t->data;
}
int TreeKtravelSize(tree* t, int k) {
	if (t == NULL)return 0;
	if (k == 1)return 1;
	return TreeKtravelSize(t->l, k - 1) + TreeKtravelSize(t->r, k - 1);
}
void Delete(tree** t) {
	if (*t == NULL)return;
	else {
		Delete(&(*t)->l);
		Delete(&(*t)->r);
		free(*t);
		*t = NULL;
	}
}
void find(tree** t, char x) {
	if (*t == NULL)return;
	if ((*t)->data == x)Delete(t);
	if (*t) {
		find(&(*t)->l, x);
		find(&(*t)->r, x);
	}
}
void prevtraval(tree* t) {
	if (t == NULL)return;
	cout << t->data;
	prevtraval(t->l);
	prevtraval(t->r);
}
int main() {
	tree* t;
	t = prevcreate();
	//cout << treedepth(t);
	//posttraval(t);
	/*int k;
	cin >> k;
	int n = treedepth(t);
	int falg = 1;
	for (int i = 1;i <= n;i++){
		if (k == TreeKtravelSize(t, i)) {
			cout << i;
			falg = 0;
			break;
		}
	}
	if (falg)cout << 0;*/
	char a;
	cin >> a;
	find(&t, a);
	prevtraval(t);
	return 0;
}