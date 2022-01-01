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
//m�����Ĵ���
char CreateMtree() {
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	idx = 0;
	char parent, child;
	int n;
	cout << "�������һ���ڵ㣨���ڵ㣩" << endl;
	cin >> parent;
	if (parent == '-') {
		getchar();
		return 0;
	}
	cout << "������1�Žڵ�ĺ���,-1��ʾ����" << endl;
	cout << "����ʱע���м��޿ո�" << endl;
	//���ö��еķ�ʽ
	queue<int>q;
	q.push(parent);
	int cnt = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (cnt == 1);
		else {
			printf("������%d�Žڵ�ĺ��ӣ�-1��ʾ����\n", cnt);
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
//m�����ĺ������
void MtreePostTraversal(int root) {
	//����������ջ
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