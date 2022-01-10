#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cstring>
using namespace std;
const int N = 55;

#define x first
#define y second

typedef pair<char, pair<int, int>> PII;

int g[N][N];
int dist[N][N];
bool st[N][N];
int n, m;
int sx, sy, ex, ey;
char face, last_face;

//E S W N 东南西北
int dx[12] = { -1, -2, -3, 0, 0, 0, 1, 2, 3, 0, 0, 0 }, dy[12] = { 0, 0, 0, 1, 2, 3, 0, 0, 0, -1, -2, -3 };

int bfs()
{
    memset(dist, 0x3f, sizeof dist);

    queue<PII> q;
    q.push({ last_face,{ sx, sy } });
    dist[sx][sy] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        last_face = t.x;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int a = t.y.x + dx[3 * i + j], b = t.y.y + dy[3 * i + j];


                if (a <= 0 || a >= n || b <= 0 || b >= m) continue;
                if (g[a][b] == 1) break;

                if (dx[3 * i + j] < 0) face = 'N';
                else if (dx[3 * i + j] > 0) face = 'S';
                else if (dy[3 * i + j] < 0) face = 'W';
                else face = 'E';

                if (face == last_face)
                {
                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 1)
                    {
                        dist[a][b] = dist[t.y.x][t.y.y] + 1;
                        q.push({ face,{ a, b } });
                    }
                }
                else if ((face == 'S' && last_face == 'N') || (face == 'N' && last_face == 'S') || (face == 'W' && last_face == 'E') || (face == 'E' && last_face == 'W'))
                {
                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 3)
                    {
                        dist[a][b] = dist[t.y.x][t.y.y] + 3;
                        q.push({ face,{ a, b } });
                    }
                }
                else
                {
                    if (dist[a][b] >= dist[t.y.x][t.y.y] + 2)
                    {
                        dist[a][b] = dist[t.y.x][t.y.y] + 2;
                        q.push({ face,{ a, b } });
                    }
                }
            }
        }
    }
    if (dist[ex][ey] != 0x3f3f3f3f)return dist[ex][ey];
    else return -1;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                g[i - 1][j - 1] = g[i - 1][j] = g[i][j - 1] = 1;
            }
        }
    }

    cin >> sx >> sy >> ex >> ey >> last_face;
    //sx--, sy--, ex--, ey--;

    /*g[sx][sy] = 'S';
    g[ex][ey] = 'E';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }*/

    cout << bfs() << endl;

    return 0;
}

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