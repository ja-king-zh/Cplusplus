#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<cstring>
using namespace std;






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