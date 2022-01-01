#define _CRT_SECURE_NO_WARNINGS 1
#include"Mtree.h"

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = -1;
	if (h[a] == -1)h[a] = idx++;
	else {
		int i;
		for (i = h[a];ne[i] != -1;i = ne[i]) {
			;
		}
		ne[i] = idx++;
	}
}
//m叉树的创建
char CreateMtree() {
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	idx = 0;
	char parent, child;
	int n;
	cout << "请输入第一个节点（根节点）" << endl;
	cin >> parent;
	if (parent == '-') {
		getchar();
		return 0;
	}
	cout << "请输入1号节点的孩子,-1表示结束" << endl;
	cout << "输入时注意中间无空格" << endl;
	//利用队列的方式
	queue<int>q;
	q.push(parent);
	int cnt = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (cnt == 1);
		else {
			printf("请输入%d号节点的孩子，-1表示结束\n", cnt);
		}
		while (1) {
			cin >> child;
			if (child == '-')break;
			add(t, child);
			q.push(child);
		}
		cnt++;
		getchar();
	}
	getchar();
	return parent;
}
//m叉树的后序遍历
void MtreePostTraversal(int root) {
	//利用了两个栈
	stack<int>s, ans;
	s.push(root);
	while (s.size()) {
		auto t = s.top();
		ans.push(t);
		s.pop();
		for (int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			s.push(j);
		}
	}
	while (ans.size()) {
		auto t = ans.top();
		printf("%c ", t);
		ans.pop();
	}
	cout << endl;
}