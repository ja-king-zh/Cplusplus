#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;





//const int N = 110, M = 4010;
//int h[N], e[M], ne[M], w[M], idx;
//int dp[N][N][N][2];
//
//void add(int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//
//int main()
//{
//	int n, k, m;
//	cin >> n >> k >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(b, a, c);
//	}
//	for (int i = 1; i < k; i++)
//		for (int l = 1; l <= n; l++)
//			for (int r = l; r <= n; r++)
//			{
//				dp[l][r][i][0] = 1e9;
//				for (int t = h[l]; t != -1; t = ne[t])
//				{
//					int j = e[t];
//					if (j > r)
//					{
//						dp[l][r][i][0] = min(dp[l][r][i][0], dp[l][j][i - 1][1] + w[t]);
//					}
//					if (j < l)
//					{
//						dp[l][r][i][0] = min(dp[l][r][i][0], dp[j][r][i - 1][0] + w[t]);
//					}
//				}
//				dp[l][r][i][1] = 1e9;
//				for (int t = h[r]; t != -1; t = ne[t])
//				{
//					int j = e[t];
//					if (j < l)
//					{
//						dp[l][r][i][1] = min(dp[l][r][i][1], dp[j][r][i - 1][0] + w[t]);
//					}
//					if (j > r)
//					{
//						dp[l][r][i][1] = min(dp[l][r][i][1], dp[l][j][i - 1][1] + w[t]);
//					}
//				}
//			}
//	int ans = 1e9;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i; j <= n; j++)
//		{
//			ans = min(ans, dp[i][j][k - 1][0]);
//			ans = min(ans, dp[i][j][k - 1][1]);
//		}
//	}
//	if (ans == 1e9) cout << -1 << endl;
//	else cout << ans << endl;
//	return 0;
//}



//#define int long long
//typedef pair<int, int>PII;
//#define x first
//#define y second
//const int N = 5e5 + 10;
//int a[N];
//PII b[N], c[N];
//
//signed main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	deque<int>q;
//	for (int i = 1; i <= n; i++)
//	{
//		while (!q.empty() && a[q.back()] < a[i])
//		{
//			b[q.back()].y = i;
//			q.pop_back();
//		}
//		if (q.empty()) b[i].x = 0;
//		else b[i].x = q.back();
//		q.push_back(i);
//	}
//	while (!q.empty())
//	{
//		b[q.back()].y = n + 1;
//		q.pop_back();
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		while (!q.empty() && a[q.back()] > a[i])
//		{
//			c[q.back()].y = i;
//			q.pop_back();
//		}
//		if (q.empty()) c[i].x = 0;
//		else c[i].x = q.back();
//		q.push_back(i);
//	}
//	while (!q.empty())
//	{
//		c[q.back()].y = n + 1;
//		q.pop_back();
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int x = b[i].x, y = b[i].y;
//		int l = i - x, r = y - i;
//		ans = ans + a[i] * (l + r - 2 + (l - 1) * (r - 1));
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		int x = c[i].x, y = c[i].y;
//		int l = i - x, r = y - i;
//		ans = ans - a[i] * (l + r - 2 + (l - 1) * (r - 1));
//	}
//	cout << ans << endl;
//	return 0;
//}

//int main()
//{
//    string a, b;
//    cin >> a >> b;
//    if (a.size() < b.size())
//    {
//        sort(a.begin(), a.end());
//        reverse(a.begin(), a.end());
//        cout << a << endl;
//    }
//    else
//    {
//        string ans;
//        int f = 0;
//        sort(a.begin(), a.end());
//        reverse(a.begin(), a.end());
//        for (int i = 0; i < b.size(); i++)
//        {
//            int idx = a.find(b[i]);
//            if (idx != -1)
//            {
//                ans.push_back(a[idx]);
//                a.erase(idx, 1);
//            }
//            else
//            {
//                
//                for (int j = 0; j < a.size(); j++)
//                {
//                    if (a[j] < b[i])
//                    {
//                        ans.push_back(a[j]);
//                        a.erase(j, 1);
//                        f = 1;
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//        if (f || a.size() == 0)
//        {
//            ;
//        }
//        else
//        {
//            for (int i = ans.size() - 1; i >= 0; i--)
//            {
//                int f = 0;
//                for (int j = 0; j < a.size(); j++)
//                {
//                    if (a[j] < ans[i])
//                    {
//                        a.push_back(ans.back()), ans.pop_back();
//                        ans.push_back(a[j]);
//                        a.erase(j, 1);
//                        f = 1;
//                        break;
//                    }
//                }
//                if (f) break;
//                a.push_back(ans.back()), ans.pop_back();
//                sort(a.begin(), a.end());
//                reverse(a.begin(), a.end());
//               
//            }
//        }
//        sort(a.begin(), a.end());
//        reverse(a.begin(), a.end());
//        cout << ans << a << endl;
//    }
//    return 0;
//}



//#define int long long
//const int N = 1e6 + 10;
//int z, p;
//
//int qmi(int a, int b)
//{
//	int res = 1;
//	while (b)
//	{
//		if (b & 1) res = res * a % p;
//		b >>= 1;
//		a = a * a % p;
//	}
//	return res;
//}
//
//signed main()
//{
//	cin >> z >> p;
//	int r = 9 * z % p;
//	for (int i = 0; i < N; i++)
//	{
//		if (r == ((qmi(10, i) - 1 + p) % p))
//		{
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//#include<algorithm>  
//using namespace std;
//
//#define int long long
//typedef pair<int, int>PII;
//#define x first
//#define y second
//const int N = 5e5 + 10;
//int a[N];
//PII b[N];
//
//signed main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int ans = 0;
//	for (int i = 1; i <= n - 1; i++) 
//		b[i] = { min(a[i], a[i + 1]), max(a[i], a[i + 1]) }, ans += b[i].y - b[i].x;
//	for (int len = 2; len < n; len++)
//	{
//		
//	}
//	return 0;
//}




//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#include<vector>
//#include<map>
//using namespace std;
//
//typedef long long ll;
//const int N = 1e6 + 10, mod = 1e9 + 7;
//int f[N], inf[N];
//
//ll qmi(ll a, ll k, ll p)
//{
//    ll res = 1;
//    while (k)
//    {
//        if (k & 1) res = (ll)res * a % p;
//        k >>= 1;
//        a = (ll)a * a % p;
//    }
//
//    return res;
//
//}
//
//int main()
//{
//    ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//    f[0] = inf[0] = 1;
//    for (int i = 1; i < N; i++)
//    {
//        f[i] = (ll)f[i - 1] * i % mod;
//        inf[i] = (ll)inf[i - 1] * qmi(i, mod - 2, mod) % mod;
//    }
//
//    int n;
//    cin >> n;
//
//    while (n--)
//    {
//        int a, b;
//        cin >> a >> b;
//        for (int i = 0; i < a; i++)
//        {
//            int x;
//            cin >> x;
//        }
//        //cout << f[a] << inf[a - b] << inf[b] << endl;
//        cout << (ll)f[a] * inf[a - b] % mod * inf[b] % mod << endl;
//    }
//    return 0;
//}

//const int N = 1e6 + 10;
//int a[N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	int ans = 1, prev1 = a[1], prev2 = 1e9;
//	for (int i = 2; i <= n; i++)
//	{
//		if (a[i] == prev1 && a[i] == prev2) continue;
//		if (a[i] == prev1 && a[i] != prev2)
//		{
//			ans++;
//			prev2 = a[i];
//		}
//		else if (a[i] != prev1 && a[i] == prev2)
//		{
//			ans++;
//			prev1 = a[i];
//		}
//		else
//		{
//			if (a[i + 1] == prev1) prev1 = a[i], ans++;
//			else prev2 = a[i], ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



//const int N = 1e6 + 10;
//int p[N], st[N], d[N];
//
//int main()
//{
//	int cnt = 0;
//	for (int i = 2; i <= 1e6; i++)
//	{
//		if (!st[i])
//		{
//			p[cnt++] = i;
//			for (int j = i * 2; j <= 1e6; j += i)
//			{
//				st[j] = 1;
//			}
//		}
//	}
//	/*cout << cnt << endl;
//	for (int i = 0; i < 100; i++) cout << p[i] << ' ';*/
//	int l, r;
//	while (cin >> l >> r)
//	{
//		int k = upper_bound(p, p + cnt, r) - lower_bound(p, p + cnt, l);
//		int L = lower_bound(p, p + cnt, l) - p;
//		int R = upper_bound(p, p + cnt, r) - p - 1;
//		//cout << k << endl;
//		if (k < 2)
//		{
//			cout << "N0" << endl;
//			continue;
//		}
//		for (int i = L; i < R; i++)
//		{
//			d[i] = p[i + 1] - p[i];
//		}
//		int maxi = 0, mini = 1e9;
//		for (int i = L; i < R; i++)
//		{
//			if (d[i] > maxi) maxi = d[i];
//			if (d[i] < mini) mini = d[i];
//		}
//		for (int i = L; i < R; i++)
//		{
//			if (d[i] == mini)
//			{
//				cout << p[i] << ' ' << p[i + 1] << ' ';
//				break;
//			}
//		}
//		for (int i = L; i < R; i++)
//		{
//			if (d[i] == maxi)
//			{
//				cout << p[i] << ' ' << p[i + 1] << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}






//int main() {
//	int t, m, n;
//	char arr[100010];
//	cin >> t;
//	while (t--) {
//		cin >> arr >> m;
//		int sz = strlen(arr);
//		if (sz <= 1)n = arr[0] - '0';
//		else
//			n = arr[sz - 1] - '0' + 10 * (arr[sz - 2] - '0');
//		if (m == 2) {
//			for (int i = 0;i < sz - 2;i++)
//				n += (arr[i] - '0');
//		}
//		if (m == 5) {
//			for (int i = 0;i < sz - 2;i++)
//				n += (arr[i] - '0')*4;
//		}
//		if (n % (m + 1) == 0)
//			cout << "Nolv" << endl;
//		else
//			cout << "Hibiki" << endl;
//	}
//	return 0;
//}






//const int N = 1010;
//int v[N], w[N], f[N][N];
//int n, m;
//
//int main() {
//	cin >> m >> n;
//	for (int i = 1;i <= n;i++)cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++) {
//		for (int j = 0;j <= m;j++) {
//			f[i][j] = f[i - 1][j];
//			if (j >= v[i])
//				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//		}
//	}
//	cout << f[n][m];
//	return 0;
//}