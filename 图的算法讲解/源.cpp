#define _CRT_SECURE_NO_WARNINGS 1

//floyd
#include<iostream>
#include<cstring>
#include<algorithm>//min,max
using namespace std;
const int N = 110;
int g[N][N];
int n, m;

int main() {
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while (m--) {
		int a,b,w;
		cin >> a >> b >> w;
		g[a][b] = min(g[a][b], w);
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	return 0;
}







//
////dijkstra
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//const int N = 110;
//int g[N][N];
//int dist[N];
//bool st[N];
//int n, m;
//int dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0;i < n;i++) {
//		int t = -1;
//		for (int j = 1;j <= n;j++) {
//			if (!st[j] && (t == -1 || dist[j] < dist[t]))
//				t = j;
//		}
//		st[t] = true;
//		for (int k = 1;k <= n;k++) {
//			dist[k] = min(dist[k], dist[t] + g[t][k]);
//		}
//	}
//	if (dist[n] == 0x3f3f3f3f)return -1;
//	else return dist[n];
//}
//int main() {
//	memset(g, 0x3f, sizeof g);
//	cin >> n >> m;
//	while (m--) {
//		int a, b, w;
//		cin >> a >> b >> w;
//		g[a][b] = min(g[a][b], w);
//	}
//	int t=dijkstra();
//	cout << t;
//	return 0;
//}