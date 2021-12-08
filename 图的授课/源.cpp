#define _CRT_SECURE_NO_WARNINGS 1
//A=>1;? A-'A'+1;
//邻接表的bfs
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110;
int h[N], e[N], ne[N], idx;
bool st[N];
int n, m;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	queue<int>q;
	st[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = h[cur];i != -1;i = ne[i]) {
			int j = e[i];
			if (st[j] != true) {
				q.push(j);
				st[j] = true;

			}
		}
	}
	return 0;
}






////邻接矩阵的bfs
//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int N = 110;
//int g[N][N];
//bool st[N];
//int n, m;
//int main() {
//	memset(g, 0x3f, sizeof g);//跟双重for循环一样的效果
//	cin >> n >> m;
//	while (m--) {
//		int a, b;
//		cin >> a >> b;
//		g[a][b] = 1;
//	}
//	queue<int>q;
//	q.push(1);
//	st[1] = true;
//	while (!q.empty()) {
//		int cur = q.front();
//		cout << cur<<' ';
//		q.pop();
//		for (int i = 1;i <= n;i++) {
//			if (g[cur][i] == 1 && st[i] != true) {
//				q.push(i);
//				st[i] = true;
//			}
//		}
//	}
//	return 0;
//}






////邻接表的dfs
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int h[N], e[N], ne[N], idx;
//int n, m;
//bool st[N];
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void dfs(int x) {
//	cout << x;
//	for (int i = h[x];i != -1;i = ne[i]) {
//		int j = e[i];
//		if (st[j] != true) {
//			st[j] = true;
//			dfs(j);
//		}
//	}
//}
//int main() {
//	memset(h, -1, sizeof h);//important!!!!!!!!!!!
//	cin >> n >> m;
//	while (m--) {
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a);
//	}
//	st[1] = true;
//	dfs(1);
//	return 0;
//}




//
////邻接矩阵的dfs
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define INF 999999999
//
//const int N = 110;
//int g[N][N];
//bool st[N];
//int n, m;
//void dfs(int x) {
//	cout << x<<' ';
//	for (int i = 1;i <= n;i++) {
//		if (g[x][i] == 1 && st[i] != true) {
//			st[i] = true;
//			dfs(i);
//		}
//	}
//}
//int main() {
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < N;j++) {
//			if (i == j)g[i][j] = 0;
//			else g[i][j] = INF;
//		}
//	}
//	
//	cin >> n >> m;
//	while (m--) {
//		int a, b;
//		cin >> a >> b;
//		g[a][b] = 1, g[b][a] = 1;
//	}
//	st[1] = true;
//	dfs(1);
//	return 0;
//}