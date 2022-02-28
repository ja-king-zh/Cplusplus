#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int 
int main()
{
	
	return 0;
}



//const int N = 20;
//int sum[N], w[N];
//int n, m;
//int res = N;
//
//void dfs(int u, int k)
//{
//    if (k >= res) return;
//    if (u == n)
//    {
//        res = k;
//        return;
//    }
//    for (int i = 0; i < k; i++)
//        if (sum[i] + w[u] <= m)
//        {
//            sum[i] += w[u];
//            dfs(u + 1, k);
//            sum[i] -= w[u];
//        }
//    sum[k] += w[u];
//    dfs(u + 1, k + 1);
//    sum[k] -= w[u];
//}
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> w[i];
//    dfs(0, 0);
//    cout << res << endl;
//    return 0;
//}

//const int N = 310;
//int f[N][N], a[N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int ans = 0;
//	for (int len = 1; len <= n; len++)
//	{
//		for (int l = 1; l + len - 1 <= n; l++)
//		{
//			int r = l + len - 1;
//			if (l == r) f[l][r] = a[l];
//			else
//			{
//				for (int k = l; k < r; k++)
//				{
//					if (f[l][k] == f[k + 1][r] && f[l][k]) f[l][r] = max(f[l][r], f[l][k] + 1);
//				}
//			}
//			ans = max(ans, f[l][r]);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}





//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#include<cstring>
//using namespace std;
//
//typedef long long ll;
//const int N = 2010;
//ll dist[N], g[N][N];
//ll x[N], y[N], z[N];
//bool st[N];
//
//ll dis(int i, int j)
//{
//    return ceil(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j])));
//}
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> x[i] >> y[i] >> z[i];
//        for (int j = i; j >= 1; j--)
//        {
//            g[i][j] = g[j][i] = dis(i, j);
//        }
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        dist[i] = 1e18;
//    }
//    dist[1] = 0;
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        int t = -1;
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//        st[t] = true;
//        ans += dist[t];
//        for (int j = 1; j <= n; j++)
//        {
//            if (dist[j] > g[t][j]) dist[j] = g[t][j];
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#include<stdio.h>
//#include<queue>
//#include<deque>
//#include<map>
//#include<cstring>
//#include<vector>
//using namespace std;
//
//const int N = 110;
//int g[N][N], dist[N];
//int n, ans;
//bool st[N];
//
//void prime()
//{
//	memset(dist, 0x3f, sizeof dist);
//	memset(st, 0, sizeof st);
//	dist[1] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int t = -1;
//		for (int j = 1; j <= n; j++)
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		if (i - 1) ans += dist[t];
//		st[t] = true;
//		for (int j = 1; j <= n; j++)
//		{
//			if (dist[j] > g[t][j]) dist[j] = g[t][j];
//		}
//	}
//}
//
//int main()
//{
//	while (cin >> n, n)
//	{
//		ans = 0;
//		memset(g, 0x3f, sizeof g);
//		for (int i = 1; i < n; i++)
//		{
//			char a;
//			int m;
//			cin >> a >> m;
//			for (int i = 0; i < m; i++)
//			{
//				char b;
//				int c;
//				cin >> b >> c;
//				g[a - 'A' + 1][b - 'A' + 1] = g[b - 'A' + 1][a - 'A' + 1] = c;
//			}
//		}
//		prime();
//		cout << ans << endl;
//	}
//	return 0;
//}





//const int N = 1e3 + 10;
//int p[N], g[N][N];
//int n, d;
//bool nst[N];
//struct node
//{
//	int first, second;
//}a[N];
//
//int dis(int i, int j)
//{
//	return (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
//}
//
//int find(int x)
//{
//	if (x == p[x]) return p[x];
//	return p[x] = find(p[x]);
//}
//
//signed main()
//{
//	cin >> n >> d;
//	memset(g, 0x3f, sizeof g);
//	memset(nst, 0, sizeof nst);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i].first >> a[i].second;
//		for (int j = 1; j < i; j++)
//		{
//			g[j][i] = g[i][j] = dis(i, j);
//		}
//	}
//	for (int i = 0; i <= n; i++)p[i] = i;
//	char c;
//	while (cin >> c)
//	{
//		if (c == 'O')
//		{
//			int x;
//			cin >> x;
//			nst[x] = true;
//			for (int i = 1; i <= n; i++)
//			{
//				if (nst[i] && i != x)
//				{
//					if (g[x][i] <= d * d)
//					{
//						p[find(x)] = find(i);
//					}
//				}
//			}
//		}
//		else
//		{
//			int s, ed;
//			cin >> s >> ed;
//			if (nst[s] && nst[ed] && find(s) == find(ed)) cout << "SUCCESS" << endl;
//			else cout << "FAIL" << endl;
//		}
//	}
//	return 0;
//}






//typedef pair<int, int>PII;
//const int N = 1e3 + 10;
//double g[N][N];
//PII a[N];
//double n, d;
//bool st[N], nst[N];
//
//double dis(int i, int j)
//{
//	return sqrt((pow(double(a[i].first - a[j].first),2) + pow(double(a[i].second - a[j].second),2)));
//}
//
//bool spfa(int s, int ed)
//{
//	if (!nst[s] || !nst[ed]) return false;
//	memset(st, 0, sizeof st);
//	queue<int>q;
//	q.push(s);
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//		for (int i = 1; i <= n; i++)
//		{
//			if (i != t && nst[i])
//			{
//				if (dis(t, i) < g[s][i])
//				{
//					g[i][s] = g[s][i] = dis(t, i);
//					q.push(i);
//					st[i] = true;
//				}
//			}
//		}
//	}
//	if (g[s][ed] > d) return false;
//	else return true;
//}
//
//signed main()
//{
//	cin >> n >> d;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i].first >> a[i].second;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n;j++)
//		{
//			if (i == j)g[i][j] = 0;
//			else g[i][j] = 1e9;
//		}
//	}
//	char c;
//	while (cin >> c)
//	{
//		if (c == 'O')
//		{
//			int x;
//			cin >> x;
//			nst[x] = true;
//		}
//		else
//		{
//			int s, ed;
//			cin >> s >> ed;
//			if (spfa(s, ed)) cout << "SUCCESS" << endl;
//			else cout << "FAIL" << endl;
//		}
//	}
//	return 0;
//}




//const int N = 1e3 + 10, M = 1e5 + 10;
//int g[N][N], dist[N];
//bool st[N];
//int n, m, t;
//
//void spfa()
//{
//	queue<int>q;
//	q.push(1);
//	dist[1] = 0x3f3f3f3f;
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		for (int i = 1; i <= n; i++)
//		{
//			if (g[t][i] != -1)
//			{
//				if (dist[i] < min(dist[t], g[t][i]))
//				{
//					dist[i] = min(dist[t], g[t][i]);
//					q.push(i);
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	cin >> t;
//	for (int i = 1; i <= t; i++)
//	{
//		cin >> n >> m;
//		memset(g, -1, sizeof g);
//		memset(st, 0, sizeof st);
//		memset(dist, 0, sizeof dist);
//		for (int i = 0; i < m; i++)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			g[a][b] = g[b][a] = c;
//		}
//		spfa();
//		printf("Scenario #%d:\n%d\n\n", i, dist[n]);
//	}
//	return 0;
//}




//const int N = 1e5 + 10;
//int st, ed;
//int dist[N];
//
//int bfs()
//{
//	memset(dist, -1, sizeof dist);
//	dist[st] = 0;
//	queue<int>q;
//	q.push(st);
//	int dx[3] = { 1, -1, 2 };
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		if (t == ed) return dist[t];
//		for (int i = 0; i < 3; i++)
//		{
//			int x = 0;
//			if (i != 2) x = dx[i] + t;
//			else x = dx[i] * t;
//			if (dist[x] != -1)continue;
//			dist[x] = dist[t] + 1;
//			q.push(x);
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	cin >> st >> ed;
//	if (ed < st)cout << st - ed << endl;
//	else cout << bfs() << endl;
//	return 0;
//}




//const int N = 3e4 + 10, M = 3e5 + 10;
//int ra[N];
//int e[M], ne[M], w[M], h[N], idx;
//int n, m;
//int d[15][N], dist[N];
//int ans;
//bool st[N],nst[N];
//
//void add(int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//
//void spfa1(int x)
//{
//	for (int i = 0; i <= n; i++) d[x][i] = 1e9;
//	memset(st, 0, sizeof st);
//	queue<int>q;
//	for (int i = 1; i <= n; i++)
//	{
//		if (ra[i] == x)
//		{
//			d[x][i] = 0;
//			q.push(i);
//		}
//	}
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//		for (int i = h[t]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (d[x][j] > d[x][t] + w[i])
//			{
//				d[x][j] = d[x][t] + w[i];
//				if (!st[j])
//				{
//					q.push(j);
//					st[j] = true;
//				}
//			}
//		}
//	}
//}
//
//void spfa2(int s)
//{
//	memset(dist, 0x3f, sizeof dist);
//	memset(st, 0, sizeof st);
//	memset(nst, 0, sizeof nst);
//	queue<int>q;
//	q.push(s);
//	dist[s] = 0;
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//		if (!nst[t])
//		{
//			ans++;
//			nst[t] = true;
//		}
//		for (int i = h[t]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[t] + w[i])
//			{
//				dist[j] = dist[t] + w[i];
//				if (!st[j] && dist[j] < d[ra[s] + 1][j])
//				{
//					st[j] = true;
//					q.push(j);
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 1; i <= n; i++)cin >> ra[i];
//	for (int i = 0; i < m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	for (int i = 1; i <= 10; i++) spfa1(i);
//	for (int i = 9; i >= 1; i--)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			d[i][j] = min(d[i][j], d[i + 1][j]);
//		}
//	}
//	for (int i = 1; i <= n; i++)spfa2(i);
//	cout << ans << endl;
//	return 0;
//}
//






//const int N = 2e3 + 10;
//int c[N][N], sum[N][N];
//int n, m;
//
//int main()
//{
//	int t, k;
//	cin >> t >> k;
//	c[0][0] = c[1][0] = c[1][1] = 1;
//
//	for (int i = 2; i <= N; i++)
//	{
//		c[i][0] = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
//		}
//	}
//	for (int i = 1;i <= N;i++) {
//		for (int j = 1;j <= N;j++) {
//			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//			if (c[i][j] == 0)sum[i][j]++;
//		}
//	}
//	while (t--)
//	{
//		cin >> n >> m;
//		if (n < m) cout << sum[n][n] << endl;
//		else cout << sum[n][m] << endl;
//	}
//}






//const int N = 1010;
//
//#define x first
//#define y second
//#define int long long 
//
//typedef pair<pair<int, int>, int> PPI;
//int n, m;
//int g[N][N];
//struct Node
//{
//    int x, y, z;
//};
//int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
//bool st[N][N][3];
//int dist[N][N][3];
//int pre[N][N];
////1黄色，2红色， 3万能色
//
//int bfs()
//{
//    queue<Node> q;
//    memset(dist, 0x3f, sizeof dist);
//
//    dist[1][1][g[1][1]] = 0;
//    q.push({ 1, 1, g[1][1] });
//
//    while (q.size())
//    {
//        auto t = q.front();
//        q.pop();
//        st[t.x][t.y][t.z] = false;
//
//        for (int i = 0; i < 4; i++)
//        {
//            int a = t.x + dx[i], b = t.y + dy[i];
//
//            if (a < 1 || a > m || b < 1 || b > m) continue;
//            //if(st[a][b]) continue;
//            //if(t.z == 3 && g[a][b] == 0) continue;      //万能格子不能向无色跳
//            if (g[a][b] == 0 && g[t.x][t.y] == 0)continue;
//            int c = 0;
//            if ((t.z == 1 && g[a][b] == 2) || (t.z == 2 && g[a][b] == 1))   //1->2 || 2->1 花费1
//            {
//                c = g[a][b];
//                if (dist[a][b][c] > dist[t.x][t.y][t.z])
//                {
//                    dist[a][b][c] = dist[t.x][t.y][t.z] + 1;
//                    if (!st[a][b][c])
//                    {
//                        q.push({ a, b, c });
//                        st[a][b][c] = true;
//                    }
//                    continue;
//                }
//            }
//            else if ((t.z == 1 && g[a][b] == 1) || (t.z == 2 && g[a][b] == 2))      //1->1 || 2->2 直接跳
//            {
//                c = t.z;
//                if (dist[a][b][c] > dist[t.x][t.y][t.z])
//                {
//                    dist[a][b][c] = dist[t.x][t.y][t.z];
//                    if (!st[a][b][c])
//                    {
//                        q.push({ a, b, c });
//                        st[a][b][c] = true;
//                    }
//                    continue;
//                }
//            }
//            else if (g[a][b] == 0)                                                   //把0变万能格子需2
//            {
//                c = 2;
//                if (g[t.x][t.y] != 2)
//                {
//                    if (dist[a][b][c] > dist[t.x][t.y][t.z] + 3)
//                    {
//                        dist[a][b][c] = dist[t.x][t.y][t.z] + 3;
//                        if (!st[a][b][c])
//                        {
//                            q.push({ a, b, c });
//                            st[a][b][c] = true;
//                        }
//                    }
//                }
//                else
//                {
//                    if (dist[a][b][c] > dist[t.x][t.y][t.z] + 2)
//                    {
//                        dist[a][b][c] = dist[t.x][t.y][t.z] + 2;
//                        if (!st[a][b][c])
//                        {
//                            q.push({ a, b, c });
//                            st[a][b][c] = true;
//                        }
//                    }
//                }
//
//                c = 1;
//                if (g[t.x][t.y] != 1)
//                {
//                    if (dist[a][b][c] > dist[t.x][t.y][t.z] + 3)
//                    {
//                        dist[a][b][c] = dist[t.x][t.y][t.z] + 3;
//                        if (!st[a][b][c])
//                        {
//                            q.push({ a, b, c });
//                            st[a][b][c] = true;
//                        }
//                    }
//                }
//                else
//                {
//                    if (dist[a][b][c] > dist[t.x][t.y][t.z] + 2)
//                    {
//                        dist[a][b][c] = dist[t.x][t.y][t.z] + 2;
//                        if (!st[a][b][c])
//                        {
//                            q.push({ a, b, c });
//                            st[a][b][c] = true;
//                        }
//                    }
//                }
//                continue;
//            }
//        }
//    }
//
//    int ans = 0x3f3f3f3f;
//    for (int i = 1; i < 3; i++)
//    {
//        ans = min(ans, dist[m][m][i]);
//        //cout << dist[1][3][i] << ' ';
//    }
//
//    if (ans > 0x3f3f3f3f / 2) return -1;
//
//    return ans;
//}
//
//signed main()
//{
//    ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//
//    cin >> m >> n;
//
//    while (n--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//
//        if (c == 0) c = 2;
//        g[a][b] = c;
//    }
//
//    /*for(int i = 1; i <= m; i ++)
//    {
//       for(int j = 1; j <= m; j ++)
//        {
//            cout << g[i][j] << ' ';
//        }
//        cout << endl;
//    }*/
//
//    cout << bfs() << endl;
//
//    return 0;
//}










//typedef pair<pair<int, int>, pair<int, pair<int, int>>>PII;
//const int N = 110;
//int n, m;
//bool st[N][N];
//int dist[N][N];
//int g[N][N];
//#define x first
//#define y second
//
//int main()
//{
//	memset(dist, -1, sizeof dist);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n;j++)
//		{
//			g[i][j] = 2;
//		}
//	}
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = c;
//	}
//	priority_queue<PII, vector<PII>, greater<PII>>q;
//	q.push({ { 0, g[1][1] } ,{-1, { 1, 1 }} });
//	dist[1][1] = 0;
//	int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//	int last = -1;
//	while (!q.empty())
//	{
//		auto t = q.top();
//		q.pop();
//		int x = t.y.y.x, y = t.y.y.y;
//		if (x == n && y == n)break;
//		st[x][y] = true;
//		int color = t.x.y;
//		last = t.y.x;
//		for (int i = 0; i < 4; i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if (a < 1 || a > n || b < 1 || b > n) continue;
//			if (st[a][b]) continue;
//			if (color == g[a][b] && g[a][b] == 2) continue;
//			if (color == g[a][b])
//			{
//				if (dist[a][b] == -1 || dist[a][b] >= dist[x][y])
//				{
//					dist[a][b] = dist[x][y];
//					q.push({ {dist[a][b],g[a][b] }, {last,{ a,b } } });
//				}
//			}
//			else if (color == 2 && g[a][b] != 2)
//			{
//				if (last == g[a][b])
//				{
//					if (dist[a][b] == -1 || dist[a][b] >= dist[x][y])
//					{
//						dist[a][b] = dist[x][y];
//						q.push({ {dist[a][b],g[a][b] }, {last,{ a,b } } });
//					}
//				}
//				else
//				{
//					if (dist[a][b] == -1 || dist[a][b] >= dist[x][y] + 1)
//					{
//						dist[a][b] = dist[x][y] + 1;
//						q.push({ {dist[a][b],g[a][b] }, {last,{ a,b } } });
//					}
//				}
//			}
//			else if (color != g[a][b] && g[a][b] != 2)
//			{
//				if (dist[a][b] == -1 || dist[a][b] >= dist[x][y] + 1)
//				{
//					dist[a][b] = dist[x][y] + 1;
//					q.push({ {dist[a][b],g[a][b] }, {last,{ a,b } } });
//				}
//			}
//			else
//			{
//				if (dist[a][b] == -1 || dist[a][b] >= dist[x][y] + 2)
//				{
//					dist[a][b] = dist[x][y] + 2, last = color;
//					q.push({ {dist[a][b],g[a][b] }, {last,{ a,b } } });
//				}
//			}
//
//		}
//	}
//	cout << dist[n][n] << endl;
//	return 0;
//}



//const int N = 1e4 + 10;
//int g[N][N];
//int n, m;
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a + 1][b + 1] += c;
//	}
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
//
//	int ans = -1;
//	for (int i = m + 1;i <= 5e3; i++)
//	{
//		for (int j = m + 1; j <= 5e3; j++)
//		{
//			ans = max(ans, g[i][j] - g[i - m - 1][j] - g[i][j - m - 1] + g[i - m - 1][j - m - 1]);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}








//const int N = 5010;
//double dist[N];
//bool st[N];
//double x[N], y[N];
//int n;
//
//double length(int i, int j)
//{
//	return sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
//}
//
//double prime()
//{
//	st[1] = true;
//	for (int i = 1; i <= n;i++)
//	{
//		dist[i] = length(1, i);
//	}
//	double ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int t = -1;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		}
//		ans += dist[t];
//		st[t] = true;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!st[j] && dist[j] > length(t, j))
//			{
//				dist[j] = length(t, j);
//			}
//		}
//	}
//	return ans;
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x[i] >> y[i];
//	}
//	printf("%.2f", prime());
//	return 0;
//}





//#define int long long
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//signed main()
//{
//	ios::sync_with_stdio(false);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a0, a1, b0, b1;
//		cin >> a0 >> a1 >> b0 >> b1;
//		int ans = 0;
//		for (int i = 1; i <= b1 / i; i++)
//		{
//			if (b1 % i == 0)
//			{
//				if (i % a1 == 0 && gcd(i, a0) == a1 && (i * b0 / gcd(i, b0))== b1) ans++;
//				if (b1 / i % a1 == 0 && (b1/i) != i && gcd(b1 / i, a0) == a1 && (b1 * b0 / (i * gcd(b1 / i, b0))) == b1)ans++;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}





//const int N = 4e5 + 10;
//int n, m, k;
//int f[N], use[N], ans[N], p[N];
//vector<int>q[N];
//int find(int x)
//{
//	if (x == p[x]) return p[x];
//	p[x] = find(p[x]);
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		q[a].push_back(b);
//		q[b].push_back(a);
//	}
//	cin >> k;
//	for (int i = 0; i < k; i++)
//	{
//		cin >> f[i];
//		use[f[i]]++;
//	}
//	for (int i = 0; i <= n; i++)p[i] = i;
//	int cnt = n - k;
//	for (int i = 0; i < n; i++)
//	{
//		if (!use[i])
//		{
//			while (q[i].size())
//			{
//				int t = q[i].back();
//				q[i].pop_back();
//				if (find(t) != find(i) && !use[t]) p[find(t)] = find(i), cnt--;
//			}
//		}
//	}
//	for (int i = k; i >= 0;i--)
//	{
//		ans[i] = cnt;
//		cnt++;
//		if (i == 0) break;
//		while (q[f[i - 1]].size())
//		{
//			int t = q[f[i - 1]].back();
//			q[f[i - 1]].pop_back();
//			if (find(t) != find(f[i - 1]) && !use[t]) cnt--, p[find(t)] = find(f[i - 1]);
//		}
//		use[f[i - 1]] = 0;
//	}
//	for (int i = 0; i <= k; i++) cout << ans[i] << endl;
//	return 0;
//}







//typedef pair<int, int> PII;
//#define x first
//#define y second
//const int N = 2010;
//
//int n, m, k, l, T;
//map<int, int> col, row;
//PII c[N], r[N];
//int cnt1, cnt2;
//
//bool cmp(PII a, PII b)
//{
//    return a.y > b.y;
//}
//
//signed main()
//{
//    cin >> n >> m >> k >> l;
//
//    cin >> T;
//
//    while (T--)
//    {
//        int sx, sy, ex, ey;
//        cin >> sx >> sy >> ex >> ey;
//        int t;
//        if (sx == ex)
//        {
//            t = min(sy, ey);
//            col[t]++;
//        }
//        if(sy == ey)
//        {
//            t = min(sx, ex);
//            row[t]++;
//        }
//    }
//
//
//    for (auto t : row) r[cnt1++] = { t.first,t.second };
//    for (auto t : col) c[cnt2++] = { t.first, t.second };
//
//
//    sort(r, r + cnt1, cmp);
//    sort(c, c + cnt2, cmp);
//    sort(r, r + k);
//    sort(c, c + l);
//    for (int i = 0; i < k; i++) cout << r[i].x << ' ';
//    cout << endl;
//    for (int i = 0; i < l; i++) cout << c[i].x << ' ';
//
//    return 0;
//}



//const int N = 1010;
//int a[N][N];
//int n, m, k, l, d;
//struct node
//{
//	int cnt, id;
//}x[N], y[N];
//
//bool cmp1(node a, node b)
//{
//	return a.cnt > b.cnt;
//}
//
//bool cmp2(node a, node b)
//{
//	return a.id < b.id;
//}
//
//int main()
//{
//	cin >> n >> m >> k >> l >> d;
//	for (int i = 0; i < 1010; i++)x[i].id = i, y[i].id = i;
//	for (int i = 0; i < d; i++)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		if (x1 == x2)y[min(y1, y2)].cnt++;
//		if (y1 == y2)x[min(x1, x2)].cnt++;
//	}
//	sort(x + 1, x + 1 + n, cmp1);
//	sort(y + 1, y + 1 + m, cmp1);
//	sort(x + 1, x + 1 + k, cmp2);
//	sort(y + 1, y + 1 + l, cmp2);
//	for (int i = 1; i <= k; i++)
//	{
//		cout << x[i].id << ' ';
//	}
//	cout << endl;
//	for (int i = 1; i <= l; i++)
//	{
//		cout << y[i].id << ' ';
//	}
//	return 0;
//}
//



//const int N = 5e5 + 10, mod = 80112002;
//int e[N], ne[N], h[N], idx;
//int n, m;
//int f1[N], f2[N], dist[N];
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void solve()
//{
//	queue<int>q;
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!f1[i]) q.push(i),dist[i] = 1;
//	}
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		for (int i = h[t]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			dist[j] = (dist[j] + dist[t]) % mod;
//			f1[j]--;
//			if (!f1[j]) q.push(j);
//		}
//	}
//}
//
//
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(b, a);
//		f1[a]++, f2[b]++;
//	}
//	solve();
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!f2[i]) ans = (ans + dist[i]) % mod;
//	}
//	cout << ans << endl;
//	return 0;
//}





//int main()
//{
//	int n;
//	cin >> n;
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		res ^= a;
//	}
//	cout << res << endl;
//	return 0;
//}
//



//#define int long long
//const int N = 1e5 + 10;
//int a[N];
//int n, k;
//int check(int x)
//{
//	int sum = 0, cnt = 0;
//	for (int i = 0; i < n;i++)
//	{
//		sum += a[i];
//		if (sum >= x)
//		{
//			cnt++;
//			sum = 0;
//		}
//		sum = max(sum, (long long)0);
//	}
//	return cnt;
//}
//
//signed main()
//{
//	int maxi = 0;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		if (a[i] > maxi) maxi = a[i];
//	}
//	int l = 1, r = 1e18, ans = -1;
//	while (l <= r)
//	{
//		int mid = (l + r) >> 1;
//		if (check(mid) > k) l = mid + 1;
//		else r = mid - 1;
//		if (check(mid) == k) ans = mid;
//	}
//	if (ans == -1)
//	{
//		cout << ans << endl;
//		return 0;
//	}
//	cout << ans << ' ';
//	l = 1, r = 1e18;
//	while (l <= r)
//	{
//		int mid = (l + r) >> 1;
//		if (check(mid) >= k)
//		{
//			l = mid + 1;
//			if (check(mid) == k) ans = mid;
//		}
//		else r = mid - 1;
//	}
//	cout << ans << ' ';
//	return 0;
//}
//




//const int N = 110;
//int n, m;
//int g[N][N];
//int dist[N][N];
//int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
//
//int dfs(int x, int y)
//{
//	if (dist[x][y] != -1) return dist[x][y];
//	dist[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a < 0 || a >= n || b < 0 || b >= m) continue;
//		if (g[a][b] >= g[x][y]) continue;
//		dist[x][y] = max(dist[x][y], dfs(a, b) + 1);
//	}
//	return dist[x][y];
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> g[i][j];
//		}
//	}
//	int res = 0;
//	memset(dist, -1, sizeof dist);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			res = max(res, dfs(i, j));
//		}
//	}
//	cout << res << endl;
//	return 0;
//}






//const int N = 1010;
//int e[N], ne[N], h[N], idx;
//int n, m;
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a);
//	}
//	int t;
//	cin >> t;
//	
//	return 0;
//}





//const int N = 110;
//int a[N];
//
//int main()
//{
//	int n, sum = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		sum += a[i];
//	}
//	int d = sum / n;
//	int cnt = 0;
//	for (int i = 0; i < n;i++)
//	{
//		if (a[i] > d)
//		{
//			int c = a[i] - d;
//			a[i] -= c;
//			a[i + 1] += c;
//			cnt++;
//		}
//		else if (a[i] == d)
//		{
//			continue;
//		}
//		else
//		{
//			int c = d - a[i];
//			a[i] += c;
//			a[i + 1] -= c;
//			cnt++;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}





//
//#define x first
//#define y second
//
//typedef pair<char, pair<int, int>> PII;
//
//int g[N][N];
//int dist[N][N];
//bool st[N][N];
//int n, m;
//int sx, sy, ex, ey;
//char face, last_face;
//
////E S W N 东南西北
//int dx[12] = { -1, -2, -3, 0, 0, 0, 1, 2, 3, 0, 0, 0 }, dy[12] = { 0, 0, 0, 1, 2, 3, 0, 0, 0, -1, -2, -3 };
//
//int bfs()
//{
//    memset(dist, 0x3f, sizeof dist);
//
//    queue<PII> q;
//    q.push({ last_face,{ sx, sy } });
//    dist[sx][sy] = 0;
//
//    while (q.size())
//    {
//        auto t = q.front();
//        q.pop();
//        last_face = t.x;
//        for (int i = 0; i < 4; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                int a = t.y.x + dx[3 * i + j], b = t.y.y + dy[3 * i + j];
//
//
//                if (a <= 0 || a >= n || b <= 0 || b >= m) continue;
//                if (g[a][b] == 1) break;
//
//                if (dx[3 * i + j] < 0) face = 'N';
//                else if (dx[3 * i + j] > 0) face = 'S';
//                else if (dy[3 * i + j] < 0) face = 'W';
//                else face = 'E';
//
//                if (face == last_face)
//                {
//                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 1)
//                    {
//                        dist[a][b] = dist[t.y.x][t.y.y] + 1;
//                        q.push({ face,{ a, b } });
//                    }
//                }
//                else if ((face == 'S' && last_face == 'N') || (face == 'N' && last_face == 'S') || (face == 'W' && last_face == 'E') || (face == 'E' && last_face == 'W'))
//                {
//                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 3)
//                    {
//                        dist[a][b] = dist[t.y.x][t.y.y] + 3;
//                        q.push({ face,{ a, b } });
//                    }
//                }
//                else
//                {
//                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 2)
//                    {
//                        dist[a][b] = dist[t.y.x][t.y.y] + 2;
//                        q.push({ face,{ a, b } });
//                    }
//                }
//            }
//        }
//    }
//    if (dist[ex][ey] != 0x3f3f3f3f)return dist[ex][ey];
//    else return -1;
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> g[i][j];
//            if (g[i][j] == 1) {
//                g[i - 1][j - 1] = g[i - 1][j] = g[i][j - 1] = 1;
//            }
//        }
//    }
//
//    cin >> sx >> sy >> ex >> ey >> last_face;
//    //sx--, sy--, ex--, ey--;
//
//    /*g[sx][sy] = 'S';
//    g[ex][ey] = 'E';
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cout << g[i][j] << ' ';
//        }
//        cout << endl;
//    }*/
//
//    cout << bfs() << endl;
//
//    return 0;
//}

//const int N = 2e5 + 10;
//int a[N], p[N];
//
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	for (int i = 1;i <= n; i++) cin >> a[i];
//	for (int i = 0; i <= n; i++)p[i] = i;
//	for (int i = 1; i < n; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		p[b] = a;
//	}
//	while (k--)
//	{
//		int op, x;
//		cin >> op;
//		if (op == 1)
//		{
//			cin >> x;
//			int father = p[x];
//			if (father == x)
//			{
//				cout << -1 << endl;
//				continue;
//			}
//			else
//			{
//				int f = 0;
//				int last = x;
//				while (x != p[x])
//				{
//					x = p[x];
//					if (gcd(a[last], a[x]) != 1)
//					{
//						cout << x << endl;
//						f = 1;
//						break;
//					}
//				}
//				if (!f)
//				{
//					cout << -1 << endl;
//				}
//			}
//		}
//		else
//		{
//			int id, w;
//			cin >> id >> w;
//			a[id] = w;
//		}
//	}
//	return 0;
//}



//#define x first
//#define y second
//
//typedef pair<char, pair<int, int>>PCII;
//typedef pair<int, int>PII;
//const int N = 1010;
//int g[N][N], dist[N][N];
//bool st[N][N];
//int n, m;
//PII S, T;
//char go;
////上左下右NWSE
//char str[5] = "NWSE";
//int dy[] = { 0, -1, 0, 1 }, dx[] = { -1, 0, 1, 0 };
//
//int spfa(char start)
//{
//	if (g[S.x][S.y] == 1) return -1;
//	memset(dist, 0x3f, sizeof dist);
//	dist[S.x][S.y] = 0;
//	st[S.x][S.y] = true;
//	queue<PCII>q;
//	q.push({ start,S });
//	while (!q.empty())
//	{
//		auto t = q.front();
//		q.pop();
//		st[t.y.x][t.y.y] = false;
//		char mu = t.x;
//		int ji = 0;
//		for (;ji < 4; ji++)
//		{
//			if (str[ji] == mu)break;
//		}
//		int cnt[10];
//		cnt[ji] = 0, cnt[ji + 1] = 1, cnt[ji + 2] = 2;
//		cnt[ji + 3] = 1;
//		if (ji > 0)cnt[ji - 1] = 1;
//		if (ji > 1)cnt[ji - 2] = 2;
//		if (ji > 2)cnt[ji - 3] = 1;
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 1; j <= 3; j++)
//			{
//				int a = t.y.x + dx[i] * j, b = t.y.y + dy[i] * j;
//				if (a <= 0 || a >= n || b <= 0 || b >= m) break;
//				//if (st[a][b]) continue;
//				if (g[a][b])break;
//				if (dist[a][b] > dist[t.y.x][t.y.y] + cnt[i] + 1)
//				{
//					dist[a][b] = dist[t.y.x][t.y.y] + cnt[i] + 1;
//					q.push({ str[i],{a, b} });
//					st[a][b] = true;
//				}
//			}
//		}
//	}
//	if (dist[T.x][T.y] == 0x3f3f3f3f) return -1;
//	else return dist[T.x][T.y];
//}
//
//int main()
//{
//	cin >> n >> m;
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 1) {
				g[i - 1][j - 1] = g[i - 1][j] = g[i][j - 1] = 1;
			}
		}
	}*/
//	cin >> S.first >> S.second >> T.first >> T.second >> go;
//	cout << spfa(go) << endl;
//	return 0;
//}






//const int N = 5e4 + 10;
//int a[N], b[N];
//int n, m, L;
//
//bool check(int x)
//{
//	int cnt = 0, aa = 0;
//	for (int i = 1; i <= n + 1; i++)
//	{
//		if (a[i] - aa < x)
//		{
//			cnt++;
//			continue;
//		}
//		aa = a[i];
//	}
//	if (cnt <= m)return true;
//	else return false;
//}
//
//int main()
//{
//	cin >> L >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	a[n + 1] = L;
//	int l = 0, r = L;
//	while (l < r)
//	{
//		int mid = (l + r) >> 1;
//		if (check(mid)) l = mid + 1;
//		else r = mid;
//	}
//	if (check(l))
//		cout << l << endl;
//	else
//		cout << l - 1 << endl;
//	return 0;
//}





//const int N = 1e5 + 10;
//int a[N], b[N];
//
//int main()
//{
//	int l, n, k;
//	cin >> l >> n >> k;
//	priority_queue<int>heap;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		b[i] = a[i] - a[i - 1];
//		heap.push(b[i]);
//	}
//	heap.push(l - a[n]);
//	while (k--)
//	{
//		int t = heap.top();
//		heap.pop();
//		if (t % 2 == 0)
//		{
//			t /= 2;
//			heap.push(t);
//			heap.push(t);
//		}
//		else
//		{
//			t = (t + 1) / 2;
//			heap.push(t);
//			heap.push(t - 1);
//		}
//	}
//	cout << heap.top() << endl;
//	return 0;
//}




//#define x first
//#define y second
//#define int long long
//
//typedef pair<int, int> PII;
//
//const int N = 10000010, INF = 0x3f3f3f3f;
//int n, m, len;
//int a[N];
//
//bool check(int x)
//{
//    int cnt = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if ((a[i] - a[i - 1]) >= x)
//        {
//            cnt += (a[i] - a[i - 1]) / x;
//            if ((a[i] - a[i - 1]) % x == 0) cnt--;
//        }
//    }
//
//    if (cnt > m) return false;
//    else return true;
//}
//
//signed main()
//{
//    cin >> len >> n >> m;
//
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    int l = -1, r = len + 1;
//
//    while (l + 1 != r)
//    {
//        int mid = l + r >> 1;
//
//        if (!check(mid)) l = mid;
//        else r = mid;
//    }
//
//    cout << r << endl;
//
//    return 0;
//}

//const int N = 1e5 + 10;
//int a[N], b[N];
//int main() 
//{
//	int n;
//	cin >> n;
//	int p = 0, q = 0;
//	for (int i = 1; i <= n;i++)
//	{
//		cin >> a[i];
//		b[i] = a[i] - a[i - 1];
//		if (b[i] > 0)p += b[i];
//		else q -= b[i];
//	}
//	cout << max(p, q);
//	return 0;
//}



//const int N = 1e6 + 10;
//
//int n, k;
//deque<int> q;
//int a[N];
//
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) 
//    {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; i++) 
//    {
//        if (!q.empty() && i - k + 1 > q.front()) 
//        {
//            q.pop_front();
//        }
//        while (!q.empty() && a[q.back()] <= a[i]) 
//        {
//            q.pop_back();
//        }
//        q.push_back(i);
//        if (i >= k - 1) 
//        {
//            cout << a[q.front()] << endl;
//        }
//    }
//    return 0;
//}







//typedef pair<double, double>PDD;
//const int N = 1010;
//PDD a[N];
//double s[N][N];
//bool st[N];
//int n, l;
//double res = 1e9;
//
//double length(int x, int y)
//{
//	return (double)sqrt((a[x].first - a[y].first) * (a[x].first - a[y].first) + (a[x].second - a[y].second) * (a[x].second - a[y].second));
//}
//
//void dfs(int x, int u, double dist)
//{
//	l++;
//	if (l > 30000000)
//	{
//		printf("%.2lf", res);
//		exit(0);
//	}
//	if (dist >= res) return;
//
//	if (u == n)
//	{
//		res = min(res, dist);
//		return;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (!st[i])
//		{
//			st[i] = true;
//			dfs(i, u + 1, dist + s[x][i]);
//			st[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		double x, y;
//		scanf("%lf%lf", &x, &y);
//		a[i] = { x, y };
//	}
//
//	for (int i = 0; i <= n;i++)
//		for (int j = i + 1; j <= n; j++)
//			s[i][j] = s[j][i] = length(i, j);
//
//	dfs(0, 0, 0.0);
//
//	printf("%.2lf", res);
//
//	return 0;
//}





//const int N = 1e5 + 10;
//int e[N], ne[N], h[N], idx;
//int n, m, f[N];
//bool st[N];
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void dfs(int x, int d)
//{
//	if (f[x])return;
//	f[x] = d;
//	for (int i = h[x]; i != -1; i = ne[i])
//	{
//		int j = e[i];
//		dfs(j, d);
//	}
//}
//
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(b, a);
//	}
//	
//	for (int i = n;i >= 1;i--)
//	{
//		dfs(i, i);
//	}
//
//	for (int i = 1;i <= n;i++) cout << f[i] << ' ';
//	
//	return 0;
//}







//const int N = 1e5 + 10;
//const int mod = 1e8 - 3;
//int a[N], b[N];
//int c[N], d[N];
//int num1[N], num2[N];
//int e[N];
//long long ans = 0;
//int tmp[N];
//
//void merge(int x, int y)
//{
//	if (x == y)return;
//	int mid = (x + y) >> 1;
//	merge(x, mid), merge(mid + 1, y);
//	int i = x, j = mid + 1;
//	int k = x;
//	while (i <= mid && j <= y)
//	{
//		if (a[i] <= a[j])tmp[k++] = a[i++];
//		else	tmp[k++] = a[j++], ans += mid - i + 1, ans %= mod;;
//	}
//	while (i <= mid)
//		tmp[k++] = a[i++];
//	while (j <= y)
//		tmp[k++] = a[j++];
//	for (int i = x;i <= y;++i)
//		a[i] = tmp[i];
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;++i)cin >> a[i], c[i] = a[i];
//	for (int i = 1;i <= n;++i)cin >> b[i], d[i] = b[i];
//
//	sort(d + 1, d + 1 + n);
//
//	for (int i = 1;i <= n;++i)
//		num1[d[i]] = i;
//
//	sort(c + 1, c + 1 + n);
//
//	for (int i = 1;i <= n;++i)
//		num2[c[i]] = i;
//
//	for (int i = 1;i <= n;++i)
//		e[num1[b[i]]] = i;
//
//	for (int i = 1;i <= n;++i)
//		a[i] = e[num2[a[i]]];
//
//	merge(1, n);
//	cout << ans % mod << endl;
//	return 0;
//}





//typedef long long ll;
//
//const int N = 55;
//int n, m, a, b;
//ll g[N][N];
//bool f[N][N][65];
//
//int main()
//{
//	cin >> n >> m;
//	memset(g, 0x3f, sizeof(g));
//
//	for (int i = 1;i <= m; i++)
//	{
//		cin >> a >> b;
//		f[a][b][0] = 1;
//		g[a][b] = 1;
//	}
//
//	for (int q = 1;q <= 64;++q)
//	{
//		for (int i = 1;i <= n;++i)
//		{
//			for (int j = 1;j <= n;++j)
//			{
//				for (int k = 1;k <= n;++k)
//				{
//					if (f[i][k][q - 1] && f[k][j][q - 1])
//					{
//						f[i][j][q] = 1;
//						g[i][j] = 1;
//					}
//				}
//			}
//		}
//	}
//
//	for (int k = 1;k <= n;++k)
//		for (int i = 1;i <= n;++i)
//			for (int j = 1;j <= n;++j)
//				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//
//	cout << g[1][n] << endl;
//	return 0;
//}







//const int N = 210;
//int aa[N];
//int dist[N];
//bool st[N];
//int n, m;
//
//
//int spfa(int x, int y, int tt, int f[N][N])
//{
//	if (aa[x] > tt) return -1;
//	if (aa[y] > tt) return -1;
//	memset(dist, 0x3f, sizeof dist);
//	memset(st, 0, sizeof st);
//	dist[x] = 0;
//	queue<int>q;
//	q.push(x);
//	st[x] = true;
//	while (!q.empty())
//	{
//		auto t = q.front();
//		q.pop();
//		st[t] = false;
//		for (int i = 0; i < n; i++)
//		{
//			if (f[t][i] != 1e8 && aa[i] <= tt)
//			{
//				if (dist[i] > dist[t] + f[t][i])
//				{
//					dist[i] = f[t][i] + dist[t];
//					q.push(i);
//					st[i] = true;
//				}
//			}
//		}
//	}
//	if (dist[y] > 1e7) return -1;
//	else return dist[y];
//}
//
//int main()
//{
//	int g[N][N];
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (i == j) g[i][j] = 0;
//			else g[i][j] = 0x3f3f3f3f;
//		}
//	}
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> aa[i];
//	}
//	while (m--)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		g[a][b] = g[b][a] = min(g[a][b], w);
//	}
//	int t;
//	cin >> t;
//	int k = 0;
//	while (t--)
//	{
//		int x, y, t;
//		cin >> x >> y >> t;
//		if (aa[x] > t || aa[y] > t)
//		{
//			cout << "-1" << endl;
//			continue;
//		}
//		for (; aa[k] <= t && k < n;k++)
//		{
//			for (int i = 0;i < n;i++)
//			{
//				for (int j = 0; j < n;j++)
//				{
//					g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
//				}
//			}
//		}
//		if (g[x][y] == 0x3f3f3f3f) cout << "-1" << endl;
//		else cout << g[x][y] << endl;
//		//cout << spfa(x, y, t, g) << endl;
//	}
//	return 0;
//}




//typedef long long ll;
//const int N = 5050;
//struct people
//{
//	int p, x;
//}P[N];
//
//bool cmp(people a, people b)
//{
//	return a.p < b.p;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int p, x;
//		cin >> p >> x;
//		P[i] = { p, x };
//	}
//	sort(P, P + m, cmp);
//	ll res = 0;
//	for (int i = 0; i < m; i++)
//	{
//		if (n < P[i].x)
//		{
//			res = res + n * P[i].p;
//			break;
//		}
//		else
//		{
//			res = res + P[i].x * P[i].p;
//			n -= P[i].x;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}



//const int N = 1e5 + 10;
//int a[N], b[N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	long long res = 0, ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		b[i] = a[i] - a[i - 1];
//		if (i - 1 && b[i] > 0) res += b[i];
//		if (i - 1 && b[i] < 0) ans -= b[i];
//	}
//	cout << max(ans, res) << endl << abs(ans - res) + 1;
//	return 0;
//}



//typedef long long ll;
//const int N = 1010;
//struct range
//{
//	int l, r, s;
//}Ranges[N];
//
//bool cmp(range a, range b)
//{
//	return a.s < b.s;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		Ranges[i] = { l, r, l * r };
//	}
//	sort(Ranges + 1, Ranges + n + 1, cmp);
//	ll res = 1, ans = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		ans = max(ans, res / Ranges[i].r);
//		res *= Ranges[i].l;
//	}
//	cout << ans << endl;
//	return 0;
//}




//const int N = 50;
//int a[N][N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	int i = 1, j = (n + 1) / 2;
//	int cnt = 1;
//	a[i][j] = 1;
//	while (cnt != (n * n))
//	{
//		if (i == 1 && j != n)
//		{
//			a[n][j + 1] = a[i][j] + 1;
//			i = n, j = j + 1;
//			cnt++;
//		}
//		if (j == n && i != 1)
//		{
//			a[i - 1][1] = a[i][j] + 1;
//			i--;
//			j = 1;
//			cnt++;
//		}
//		if (i == 1 && j == n)
//		{
//			a[i + 1][j] = a[i][j] + 1;
//			i++;
//			cnt++;
//		}
//		if (i != 1 && j != n)
//		{
//			if (a[i - 1][j + 1] == 0 && i - 1 >= 1 && j + 1 <= n)
//			{
//				a[i - 1][j + 1] = a[i][j] + 1;
//				i--;
//				j++;
//				cnt++;
//			}
//			else if (a[i + 1][j] == 0 && i + 1 <= n)
//			{
//				a[i + 1][j] = a[i][j] + 1;
//				i++;
//				cnt++;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}




//const int N = 1010;
//int d[N][N];
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m;i++)
//	{
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int j = x1; j <= x2; j++)
//		{
//			d[j][y1] += 1;
//			d[j][y2 + 1] -= 1;
//		}
//	}
//	int res = 0;
//	for (int i = 1; i <= n + 1;i++)
//	{
//		for (int j = 1; j <= n + 1;j++)
//		{
//			res += d[i][j];
//			d[i][j] = res;
//		}
//	}
//	for (int i = 1; i <= n;i++)
//	{
//		for (int j = 1; j <= n;j++)
//		{
//			cout << d[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}




//typedef long long ll;
//const int N = 2e5 + 10;
//struct range
//{
//	ll x, y, s;
//	double d;
//}Ranges[N];
//
//bool cmp(range a, range b)
//{
//	return a.s < b.s;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n;i++)
//	{
//		ll x, y;
//		cin >> x >> y;
//		Ranges[i] = { x, y, x + y };
//	}
//	sort(Ranges, Ranges + n, cmp);
//	double res = 1e9;
//	for (int i = 0; i < n - 1;i++)
//	{
//		Ranges[i].d = sqrt(pow((Ranges[i].x - Ranges[i + 1].x), 2) + pow((Ranges[i].y - Ranges[i + 1].y), 2));
//		res = min(res, Ranges[i].d);
//	}
//	printf("%.4f", res);
//	return 0;
//}



//const int N = 1e7 + 10;
//long long f[N];
//
//int main()
//{
//	int m;
//	cin >> m;
//	f[1] = 1;
//	for (int i = 2;i < 1e7;i++)
//	{
//		f[i] = (f[i - 1] + f[i - 2]) % m;
//		f[i + 1] = (f[i] + f[i - 1]) % m;
//		if ((f[i] % m) == 0 && (f[i + 1] % m) == 1)
//		{
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}





//typedef pair<int, int>PII;
//const int N = 500;
//int a[N][N];
//bool st[N][N];
//
//int main()
//{
//	int n, m, xx, yy;
//	cin >> n >> m >> xx >> yy;
//	queue<PII>q;
//	q.push({ xx, yy });
//	st[xx][yy] = true;
//	int dx[8] = { -1, -2, -2, -1, 1 , 2, 2,1 }, dy[8] = { -2, -1, 1, 2, 2,1, - 1, - 2 };
//	while (!q.empty())
//	{
//		auto t = q.front();
//		q.pop();
//		for (int i = 0; i < 8;i++)
//		{
//			int x = t.first + dx[i], y = t.second + dy[i];
//			if (x > 0 && x <= n && y > 0 && y <= m && !st[x][y])
//			{
//				st[x][y] = true;
//				//cout << x << ' ' << y << endl;
//				a[x][y] = a[t.first][t.second] + 1;
//				q.push({ x, y });
//			}
//		}
//	}
//	for (int i = 1; i <= n;i++)
//	{
//		for (int j = 1; j <= m;j++)
//		{
//			if (!st[i][j]) a[i][j] = -1;
//			printf("%-5d", a[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}





//const int N = 110;
//int a[N][N], dp[N][N];
//int n, m;
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (a[i][j])
//			{
//				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (dp[i][j] > ans)
//			{
//				ans = dp[i][j];
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}





//typedef pair<int, int>PII;
//const int N = 110;
//int a[N][N];
//bool st[N][N];
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++) 
//		{
//			cin >> a[i][j];
//		}
//	}
//	int res = 0, ans = 0;
//	int dx[3] = { 1, 0, 1 }, dy[3] = { 0, 1, 1 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (a[i][j] == 1)
//			{
//				queue<PII>q;
//				q.push({ i, j });
//				while (!q.empty())
//				{
//					res++;
//					int w = q.size();
//					for (int i = 0; i < w; i++)
//					{
//						auto t = q.front();
//						q.pop();
//						for (int i = 0;i < 3; i++)
//						{
//							int x = dx[i] + t.first, y = dy[i] + t.second;
//							if (a[x][y] && !st[x][y])
//							{
//								q.push({ x, y });
//								st[x][y] = true;
//							}
//							else
//							{
//								goto aa;
//							}
//						}
//					}
//				}
//			}
//			aa:
//			ans = max(ans, res);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}




//const int N = 3e4 + 10;
//int a[N];
//int main()
//{
//	int w;
//	cin >> w;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	int l = 0, r = n - 1;
//	int res = 0;
//	while (l <= r)
//	{
//		if ((a[l] + a[r]) > w)
//		{
//			res++;
//			r--;
//		}
//		else
//		{
//			res++;
//			l++;
//			r--;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}







//typedef pair<int, int>PII;
//typedef long long ll;
//const int N = 1e6 + 10;
//ll a[N], d[N], c[N];
//PII q[N];
//int n, m;
//bool solve(int x)
//{
//	memset(d, 0, sizeof d);
//	for (int i = 1; i <= x; i++)
//	{
//		int l = q[i].first, r = q[i].second;
//		d[l] += c[i], d[r + 1] -= c[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		d[i] += d[i - 1];
//		if (d[i] > a[i])return false;
//	}
//	return true;
//}
//
//int main()
//{
//	
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		int l, r, t;
//		cin >> t >> l >> r;
//		c[i] = t;
//		q[i] = { l,r };
//	}
//	if (solve(m))
//	{
//		cout << 0 << endl;
//	}
//	else
//	{
//		int l = 1, r = m;
//		while (l < r - 1)
//		{
//			int mid = l + r >> 1;
//			if (solve(mid)) l = mid + 1;
//			else r = mid;
//		}
//		cout << -1 << endl;
//		//cout << l << ' ' << r << endl;
//		if (solve(l)) cout << r << endl;
//		else cout << l << endl;
//	}
//	return 0;
//}





//const int N = 1010, M = 1e5 + 10;
//int p[N];
//struct node
//{
//	int a, b, c;
//}nodes[M];
//
//bool cmp(node e, node d)
//{
//	return e.c < d.c;
//}
//
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cin >> nodes[i].a >> nodes[i].b >> nodes[i].c;
//	}
//	sort(nodes, nodes + m, cmp);
//	int ans = -1;
//	for (int i = 0;i < m;i++)
//	{
//		int aa, bb;
//		aa = nodes[i].a, bb = nodes[i].b;
//		if (find(aa) != find(bb))
//			p[find(aa)] = find(bb);
//		int flag = 0;
//		for (int j = 1;j <= n;j++)
//		{
//			if (p[j] == j)
//			{
//				flag++;
//			}
//		}
//		if (flag == 1)
//		{
//			ans = nodes[i].c;
//			break;
//		}
//	}
//	cout << ans;
//	return 0;
//}




//const int N = 1e6 + 10;
//int a[N];
//
//int main()
//{
//	int n, res = 0;
//	cin >> n;
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//		res ^= a[i];
//	}
//	if (!res) cout << "lose" << endl;
//	else
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (a[i] > (res ^ a[i]))
//			{
//				cout << a[i] - (res ^ a[i]) << ' ' << i + 1 << endl;
//				a[i] ^= res;
//				for (int j = 0;j < n;j++)
//				{
//					cout << a[j] << ' ';
//				}
//				break;
//			}
//		}
//	}
//	return 0;
//}




//const int N = 1010;
//int w[N], v[N], f[N][N];
//int n, m;
//
//int main()
//{
//	
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			f[i][j] = f[i - 1][j];
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}



//typedef pair<int, int>PII;
//const int N = 50;
//int a[N][N];
//bool st[N][N];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	queue<PII>q;
//	int flag = 0;
//	q.push({ 0,0 });
//	int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//	while (q.size()>0)
//	{
//		auto t = q.front();
//		q.pop();
//		//a[t.first][t.second] = 2;
//		st[t.first][t.second] = true;
//		for (int i = 0;i < 4;i++)
//		{
//			int x = t.first + dx[i], y = t.second + dy[i];
//			if (a[x][y] == 0 && x <= n && y <= n && x >= 0 && y >= 0 && !st[x][y])
//			{
//				q.push({ x,y });
//			}
//		}
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (!st[i][j] && a[i][j]!=1) cout << 2 << ' ';
//			else cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}




//int n, cnt = 0;
//int a[20];
//bool c[20], x[20], ux[20];
//void dfs(int u)
//{
//	if (u == n +1)
//	{
//		if (cnt < 3) {
//			for (int i = 1; i <= n;i++)cout << a[i] << ' ';
//			cout << endl;
//		}
//		cnt++;
//	}
//	for (int i = 1; i <= n;i++)
//	{
//		if (!c[i] && !x[u + i] && !ux[n + i - u]) {
//			a[u] = i;
//			c[i] = x[u + i] = ux[n - u + i] = true;
//			dfs(u + 1);
//			
//			c[i] = x[u + i] = ux[n - u + i] = false;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n;i++)
//	{
//		c[i] = x[1 + i] = ux[n - 1 + i] = true;
//		a[1] = i;
//		dfs(2);
//		c[i] = x[1 + i] = ux[n - 1 + i] = false;
//
//	}
//	cout << cnt;
//	return 0;
//}



//const int N = 310;
//int a[N];
//typedef long long ll;
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	int l = 1, r = n;
//	sort(a + 1, a + 1 + n, cmp);
//	ll res = 0;
//	if (n % 2 == 0)
//	{
//		while (l < r)
//		{
//			if (!res)
//			{
//				res += a[l] * a[l];
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				l++;
//			}
//			else
//			{
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				r--;
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				l++;
//			}
//		}
//	}
//	else
//	{
//		while (l <= r)
//		{
//			if (!res)
//			{
//				res += a[l] * a[l];
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				l++;
//			}
//			else
//			{
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				r--;
//				res += (a[l] - a[r]) * (a[l] - a[r]);
//				l++;
//			}
//		}
//	}
//	cout << res << endl;
//	return 0;
//}


//char a[100];
//int main()
//{
//	int j = 0;
//	scanf("%c", &a[j]);
//	while (a[j] != '\n')
//	{
//		j++;
//		scanf("%c", &a[j]);
//	}
//	int i = 0, res = 0;
//	while (a[i] != '\0')
//	{
//		if (a[i] != ' ' && a[i] != '\n')res++;
//		i++;
//	}
//	cout << res << endl;
//	return 0;
//}



//const int N = 1e4 + 10;
//int a[N];
//int main()
//{
//	int n, m;
//	for (int i = 0; i < N; i++)a[i] = 1;
//	cin >> n >> m;
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		for (int i = l; i <= r; i++)
//		{
//			a[i] = 0;
//		}
//	}
//	int res = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		res += a[i];
//	}
//	cout << res << endl;
//	return 0;
//}



//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int m, n, x, y;
//const int N = 110;
//int arr[N][N];
//int main() {
//	cin >> m >> n >> x >> y;
//	int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
//	int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
//	for (int i = 0;i <= m;i++) {
//		for (int j = 0;j <= n;j++) {
//			arr[i][j] = 1;
//		}
//	}
//	for (int i = 0;i < 8;i++) {
//		int ddx = dx[i] + x;
//		int ddy = dy[i] + y;
//		if (ddx > 0 && ddy > 0) {
//			arr[ddx][ddy] = 0;
//		}
//	}
//	arr[x][y] = 0;
//	for (int i = 1;i <= m;i++) {
//		for (int j = 1;j <= n;j++) {
//			if (arr[i][j]==0);
//			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
//		}
//	}
//	cout << arr[m][n];
//	return 0;
//}







//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//int n;
//const int N = 1e5 + 10;
//int arr[N];
//
//int main() {
//    cin >> n;
//    for (int i = 0;i < n;i++)cin >> arr[i];
//    int ans = arr[0];
//    for (int i = 1;i < n;i++) {
//        if (arr[i] < 0)ans -= arr[i];
//        else ans += arr[i];
//    }
//    cout << ans;
//    return 0;
//}