#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;




//const int N = 2e3 + 10;
//int h1[N], h2[N], e1[N], ne1[N], ne2[N], e2[N], idx1, idx2;
//int n;
//int f1[N], f2[N];
//int a[N], b[N];
//
//void add1(int a, int b)
//{
//    e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1++;
//}
//
//void add2(int a, int b)
//{
//    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2++;
//}
//int cnt1 = 0;
//void dfs1(int r)
//{
//    for (int i = h1[r]; i != -1; i = ne1[i])
//    {
//        int j = e1[i];
//        a[cnt1++] = j;
//        dfs1(j);
//    }
//}
//int cnt2 = 0;
//void dfs2(int r)
//{
//    for (int i = h2[r]; i != -1; i = ne2[i])
//    {
//        int j = e2[i];
//        b[cnt2++] = j;
//        dfs2(j);
//    }
//}
//
//int main()
//{
//    cin >> n;
//    memset(h1, -1, sizeof h1);
//    memset(h2, -1, sizeof h2);
//    for (int i = 0; i <= n; i++) f1[i] = f2[i] = i;
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        if (a) add1(i, a), f1[a] = i;
//        if (b) add1(i, b), f1[b] = i;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        if (a) add2(i, a), f2[a] = i;
//        if (b) add2(i, b), f2[b] = i;
//    }
//    int root1 = 0, root2 = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (f1[i] == i) root1 = i;
//        if (f2[i] == i) root2 = i;
//    }
//    if (root1 != root2) cout << 1 << endl << root1 << endl;
//    else
//    {
//        dfs1(root1);
//        dfs2(root2);
//        int f = 0;
//        for (int i = 0; i < n; i++)
//        {
//            cout << a[i] << ' ' << b[i] << endl;
//            //             if(a[i] != b[i]) 
//            //             {
//            //                 cout << 1 << endl << a[i] << endl, f = 1;
//            //                 break;
//            //             }
//        }
//        if (!f) cout << 0 << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//
//const int N = 1010, M = 5e4 + 10;
//int a[N][N];
//string s[N];
//char res[M];
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < m; i++)
//        cin >> s[i];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> a[i][j];
//        }
//    }
//    for (int i = 0; i < 5e4 + 10; i++)
//    {
//        cin >> res[i];
//        if (res[i] == 'Y') break;
//    }
//    string mmp, cnm;
//    cin >> mmp;
//    vector<string>ans;
//    for (int i = 0; i < mmp.size(); i++)
//    {
//        int f = 0;
//        if (mmp[i] == ',' || mmp[i] == ';')
//        {
//            ans.push_back(cnm);
//            f = 1;
//        }
//        cnm += mmp[i];
//        if (f) cnm.clear();
//    }
//    vector<int>hh;
//    for (auto t : ans)
//    {
//        for (int i = 0; i < m; i++)
//            if (s[i] == t)
//            {
//                hh.push_back(i);
//                break;
//            }
//    }
//    map<string, int>mp;
//    for (int i = 0; i < n; i++)
//    {
//        string res;
//        for (auto t : hh)
//        {
//            char woc = a[i][t] + '0';
//            res += woc;
//        }
//        mp[res]++;
//        res.clear();
//    }
//    cout << mp.size() << endl;
//    for (auto t : mp) cout << t.second << ' ';
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//#define int long long
//const int N = 1e5 + 10, mod = 1e9 + 7;
//char a[N];
//int b[N];
//
//int qq(int x, int y)
//{
//    int res = 1;
//    while (y)
//    {
//        if (y & 1) res *= x % mod;
//        x = x * x % mod;
//        y >>= 1;
//    }
//    return res;
//}
//
//bool cmp(char a, char b)
//{
//    return a > b;
//}
//
//signed main()
//{
//    int n, m, k;
//    cin >> n >> m >> k;
//    cin >> a;
//    for (int i = 0; i < n; i++) cin >> b[i];
//    int ans = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        int j = i;
//        while (b[j] == b[j + 1] && j < n) j++;
//        sort(a + i, a + j + 1, cmp);
//        i = j;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        ans += (a[i] - '0') * qq(10, n - i - 1) % mod;
//    }
//    cout << ans % mod << endl;
//    while (k-- > 0)
//    {
//        int p, q;
//        cin >> p >> q;
//        for (int i = 0; i < n; i++) if (b[i] == p) b[i] = q;
//        ans = 0;
//        for (int i = 0; i < n - 1; i++)
//        {
//            int j = i;
//            while (b[j] == b[j + 1]) j++;
//            sort(a + i, a + j + 1, cmp);
//            i = j;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            ans += (a[i] - '0') * qq(10, n - i - 1) % mod;
//        }
//        cout << ans % mod << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include<algorithm>
//using namespace std;
//
//#define int long long
//const int N = 2e3 + 10, mod = 1e9 + 7;
//int f[N], a[N];
//
//signed main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1, j = n + 1; i <= n; i++, j++) a[j] = a[i] / 2;
//    f[0] = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = m; j >= a[i] / 2; j--)
//        {
//            for(int k = 0; k <= 1; k ++ )
//                f[j] = f[j] + f[j - a[i + n * k]] % mod;
//        }
//    }
//    for (int i = 1; i <= m; i++) cout << f[i] % mod << ' ';
//    return 0;
//}
//const int N = 1e7 + 10, mod = 1000000007;
//int f[N], ff[N], p[N];
//
//int max(int x, int y) { return (x > y) ? x : y; }
//int min(int x, int y) { return (x > y) ? y : x; }
//int find(int x)
//{
//    if (x == p[x]) return p[x];
//    return p[x] = find(p[x]);
//}
//signed main()
//{
//    int n, q;
//    cin >> n >> q;
//    string res;
//    cin >> res;
//    for (int i = 0; i < n; i++) cin >> ff[i], p[i] = i, ff[i]%=mod;
//    memcpy(f, ff, n * 8);
//    for (int i = 0; i < res.size(); i++)
//    {
//        if (res[i] == '*')
//        {
//            ff[i + 1] = ff[i] * ff[i + 1] % mod;
//            ff[i] = -1;
//            p[find(i)] = find(p[i + 1]);
//        }
//    }
//
//    int cnm = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (ff[i] != -1) cnm += ff[i];
//        //         cout << ff[i] << ' ';
//        //         cout << p[i] << ' ';
//    }
//    //cout << cnm <<endl;
//    while (q--)
//    {
//        int x, y;
//        cin >> x >> y;
//        x--;
//        int a = 0, gai = 0;
//        if (ff[x] == -1 || (x != 0 && ff[x - 1] == -1))
//        {
//            a = find(x);
//            gai = (ff[a] * y + mod) / f[x] % mod - ff[a];
//            ff[a] = (ff[a] + mod) / (f[x] % mod) * y % mod;
//            f[x] = y;
//        }
//        else
//        {
//            gai = y - f[x];
//            f[x] = y;
//        }
//        cnm += gai;
//        cout << cnm % mod << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <stack>
//#include <unordered_map>
//using namespace std;
//
//#define int long long
//const int N = 1e6 + 10;
//int f[N];
//
//stack<int> num;
//stack<char> op;
//int max(int x, int y) { return (x > y) ? x : y; }
//int min(int x, int y) {return (x > y) ? y : x;}
//void eval()
//{
//    auto b = num.top(); num.pop();
//    auto a = num.top(); num.pop();
//    auto c = op.top(); op.pop();
//    int x;
//    if (c == '+') x = a + b;
//    else if (c == '-') x = a - b;
//    else if (c == '*') x = a * b;
//    else x = a / b;
//    num.push(x);
//}
//
//signed main()
//{
//    unordered_map<char, int> pr{ {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
//    int n, q;
//    cin >> n >> q;
//    string res;
//    cin >> res;
//    string str;
//    for (int i = 0; i < n; i++) cin >> f[i];
//    for (int i = 0; i < n; i++)
//    {
//        str += f[i] + '0';
//        if (n - 1 - i) str += res[i];
//    }
//    for (int i = 0; i < str.size(); i++)
//    {
//        auto c = str[i];
//        if (isdigit(c))
//        {
//            int x = 0, j = i;
//            while (j < str.size() && isdigit(str[j]))
//                x = x * 10 + str[j++] - '0';
//            i = j - 1;
//            num.push(x);
//        }
//        else if (c == '(') op.push(c);
//        else if (c == ')')
//        {
//            while (op.top() != '(') eval();
//            op.pop();
//        }
//        else
//        {
//            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();
//            op.push(c);
//        }
//    }
//    while (op.size()) eval();
//    int cnm = num.top();
//    //cout << cnm <<endl;
//    while (q--)
//    {
//        int x, y;
//        cin >> x >> y;
//        int a = min(n - 2, x - 1), b = max(0, x - 2);
//        if (res[a] == '+' && res[b] == '+')
//        {
//            int gai = y - f[x - 1];
//            cnm += gai;
//            f[x - 1] = y;
//            cout << gai << endl;
//        }
//        else {
//            if (res[x - 1] == '*' && res[x - 2] == '*')
//            {
//                int gai = y * f[x] * f[x - 2] - f[x - 2] * f[x] * f[x - 1];
//                cnm += gai;
//                f[x - 1] = y;
//            }
//            else if (res[x - 2] == '*')
//            {
//                int gai = y * f[x - 2] - f[x - 2] * f[x - 1];
//                cnm += gai;
//                f[x - 1] = y;
//            }
//            else
//            {
//                int gai = y * f[x] - f[x] * f[x - 1];
//                cnm += gai;
//                f[x - 1] = y;
//            }
//        }
//        cout << cnm << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 1e6 + 10;
//int a[4] = { 1,2 };
//bool isp(int x)
//{
//    for (int i = 2; i <= x / i; i++)
//    {
//        if (x % i == 0) return false;
//    }
//    return true;
//}
//
//int main()
//{
//    for (int i = 2; i <= 1e3; i++)
//    {
//        if (isp(i)) cout << i << ',';
//    }
//    int t, n;
//    cin >> t;
//    while (t--)
//    {
//        cin >> n;
//        if (n < 2)
//        {
//            cout << -1 << endl;
//            continue;
//        }
//        int x = 2;
//
//    }
//    return 0;
//}



//#include<iostream>
//#include<deque>
//#include<cstring>
//#include<stdlib.h>
//#include<string.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int x, y;
//		cin >> x >> y;
//		cout << x * y << endl;
//	}
//	return 0;
//}




//const int N = 1e5 + 10;
//int a[N], f[N];
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		memset(f, 0, sizeof f);
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		deque<int>ans;
//		for (int i = 1; i <= n; i++)
//		{
//			while (ans.size() != 0 && a[i] > a[ans.back()])
//			{
//				f[ans.back()] = i - ans.back();
//				ans.pop_back();
//			}
//			ans.push_back(i);
//		}
//		for (int i = 1; i <= n; i++) cout << f[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}




//const int N = 1e6 + 10;
//int a[N];
//int n, k;
//
//int main()
//{
//    deque<int>q;
//    cin >> n >> k;
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (!q.empty() && q.front() <= i - k) q.pop_back();
//        while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
//        q.push_back(i);
//        if (i >= k) cout << a[q.front()] << ' ';
//    }
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<cstring>
//#include<vector>
//using namespace std;
//
//map<string, int>::iterator it;
//map<string, int>mp;
//#pragma GCC optimize(2)
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//#pragma GCC optimize(2)
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		string res1, res2, res;
//		int ans = 0;
//		for (int i = 0; i < s.size() - 1; i++)
//		{
//			if (!i)res1 = s[0];
//			else res1 = s.substr(0, i + 1);
//			res2 = s.substr(i + 1);
//			res = res1 + res2;
//			if (mp[res] == 0) ans++, mp[res]++;
//			res = res2 + res1;
//			if (mp[res] == 0) ans++, mp[res]++;
//
//			reverse(res1.begin(), res1.end());
//			res = res1 + res2;
//			if (mp[res] == 0) ans++, mp[res]++;
//			res = res2 + res1;
//			if (mp[res] == 0) ans++, mp[res]++;
//			reverse(res1.begin(), res1.end());
//
//			reverse(res2.begin(), res2.end());
//			res = res1 + res2;
//			if (mp[res] == 0) ans++, mp[res]++;
//			res = res2 + res1;
//			if (mp[res] == 0) ans++, mp[res]++;
//			reverse(res2.begin(), res2.end());
//
//			reverse(res1.begin(), res1.end());
//			reverse(res2.begin(), res2.end());
//			res = res1 + res2;
//			if (mp[res] == 0) ans++, mp[res]++;
//			res = res2 + res1;
//			if (mp[res] == 0) ans++, mp[res]++;
//		}
//		cout << ans << endl;
//		mp.clear();
//	}
//	return 0;
//}





//int main()
//{
//	int x, y;
//	while (cin >> x >> y)
//	{
//		int ans = 0;
//		if (x * 4 - y < 0) ans = x * 10 - 2 * y;
//		else if (x * 3 - 2 * y < 0) ans = x * 8 - 4 * y;
//		else if (x * 2 - 3 * y < 0) ans = x * 6 - y * 6;
//		else if (x - 4 * y < 0) ans = x * 3 - y * 9;
//		else ans = -12 * y;
//		if (ans >= 0) cout << ans << endl;
//		else cout << "Deficit" << endl;
//	}
//	return 0;
//}




//map<string, int>::iterator it;
//
//int main()
//{
//	string s;
//	string end = "*";
//	while (cin >> s, s != end)
//	{
//		if (s.size() < 3)
//		{
//			cout << s << " is surprising." << endl;
//			continue;
//		}
//		else
//		{
//			map<string, int>mp;
//			string res;
//			int f = 1;
//			for (int i = 0; i < s.size(); i++)
//			{
//				for (int j = 0; i + j < s.size() - 1; j++)
//				{
//					res += s[j];
//					res += s[i + j + 1];
//					mp[res]++;
//					res.clear();
//				}
//				for (it = mp.begin();it != mp.end();it++)
//				{
//					if (it->second > 1)
//					{
//						f = 0;
//						break;
//					}
//				}
//				mp.clear();
//				if (!f)break;
//			}
//			
//			if (f) cout << s << " is surprising." << endl;
//			else cout << s << " is NOT surprising." << endl;
//		}
//	}
//	return 0;
//}




//struct node
//{
//	int x;
//	bool operator< (node& a) 
//	{
//		return x > a.x;
//	}
//}Node[3];
//
//int main()
//{
//	Node[0].x = 1;
//	Node[1].x = 2;
//	Node[2].x = 3;
//	sort(Node, Node + 3);
//
// 	return 0;
//}



//typedef long long ll;
//using namespace std;
//#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
//#define endl '\n'
//typedef long long ll;
//#define all(a) (a).begin(), (a).end()
//
//ll nxt() {
//    ll x; cin >> x; return x;
//}
//string def = "abcdefghijklmnopqrstuvwxyz";
//
//void solve() {
//    //cout << "---------------" << endl;
//    string x; cin >> x;
//    int last = x[x.length() - 1] - '0';
//    int best = 0;
//    for (int i = x.length() - 2; i >= 0; i--) {
//        int temp1 = x[i] - '0';
//        if (temp1 + last >= 10) {
//            best = i;
//            break;
//        }
//
//        last = temp1;
//    }
//    fore(i, 0, best) cout << x[i];
//    cout << x[best] - '0' + x[best + 1] - '0';
//    fore(i, best + 2, x.length()) cout << x[i]; cout << endl;
//}
//
//int main()
//{
//    int t = nxt();
//    while (t--) {
//        solve();
//    }
//    return 0;
//}
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    ll t = 1;
//    cin >> t;
//    while (t--)
//    {
//        ll i, j, k, n, m;
//        string ss;
//        cin >> ss;
//        string ans = "";
//        m = -1; n = -1;
//        for (i = 1; i < ss.length(); i++)
//        {
//            string x = ss;
//            k = ss[i - 1] - '0';
//            k += ss[i] - '0';
//            if (k > 9)
//            {
//                m = i;
//            }
//            else if (n == -1)
//            {
//                n = i;
//            }
//
//        }
//        if (m == -1)
//        {
//            k = ss[n - 1] - '0';
//            k += ss[n] - '0';
//            string s1, s2, s3;
//            s1 = ss.substr(0, n - 1);
//            s2 = to_string(k);
//            s3 = ss.substr(n + 1, ss.length());
//            s1 += s2 + s3;
//            ans = s1;
//        }
//        else
//        {
//            k = ss[m - 1] - '0';
//            k += ss[m] - '0';
//            string s1, s2, s3;
//            s1 = ss.substr(0, m - 1);
//            s2 = to_string(k);
//            s3 = ss.substr(m + 1, ss.length());
//            s1 += s2 + s3;
//            ans = s1;
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}

//const int N = 1e4 + 10;
//int a[N];
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//    }
//    long long ans = 0, res = 1e18;
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = i + 1; j <= n; j++)
//        {
//            if (j - i == 1)
//            {
//                res = min(res, a[i]);
//                res = min(res, a[j]);
//            }
//            else res = max(res, a[j]);
//            ans += res;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int n, m;
//const int N = 1e3 + 10;
//int a[N][N];
//typedef pair<int, int>PII;
//PII s[15], e[15];
//int dist[N][N];
//int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//void bfs(PII x, PII y)
//{
//    memset(dist, -1, sizeof dist);
//    dist[x.first][x.second] = 0;
//    queue<PII>q;
//    q.push(x);
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++)
//        {
//            int aa = t.first + dx[i], bb = t.second + dy[i];
//            if (aa < 0 || aa >= n || bb < 0 || bb >= n) continue;
//            if (dist[aa][bb] != -1) continue;
//            if (a[aa][bb] == -1 || a[aa][bb] == 1 || (a[aa][bb] == 2 && aa != y.first && bb != y.second)) continue;
//            dist[aa][bb] = dist[t.first][t.second] + 1;
//            q.push({ aa, bb });
//        }
//    }
//    cout << dist[y.first][y.second] << endl;
//}
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < m; i++)
//    {
//        int x, y;
//        cin >> x >> y;
//        a[x][y] = -1;
//    }
//    int t;
//    cin >> t;
//    for (int i = 1; i <= t; i++)
//    {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        s[i] = { x1, y1 };
//        e[i] = { x2, y2 };
//        a[x1][y1] = 1;
//        a[x2][y2] = 2;
//    }
//    for (int i = 1; i <= t; i++)
//    {
//        bfs(s[i], e[i]);
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int base = 1000000000;
//
//vector<int> add(vector<int>& A, vector<int>& B)
//{
//    if (A.size() < B.size()) return add(B, A);
//
//    vector<int> C;
//    int t = 0;
//    for (int i = 0; i < A.size(); i++)
//    {
//        t += A[i];
//        if (i < B.size()) t += B[i];
//        C.push_back(t % base);
//        t /= base;
//    }
//
//    if (t) C.push_back(t);
//    return C;
//}
//
//int main()
//{
//    string a, b;
//    vector<int> A, B;
//    cin >> a;
//
//    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
//    {
//        s += (a[i] - '0') * t;
//        j++, t *= 10;
//        if (j == 9 || i == 0)
//        {
//            A.push_back(s);
//            s = j = 0;
//            t = 1;
//        }
//    }
//    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
//    {
//        s += (a[i] - '0') * t;
//        j++, t *= 10;
//        if (j == 9 || i == 0)
//        {
//            B.push_back(s);
//            s = j = 0;
//            t = 1;
//        }
//    }
//
//    auto C = add(A, B);
//
//    cout << C.back();
//    for (int i = C.size() - 2; i >= 0; i--) printf("%09d", C[i]);
//    cout << endl;
//
//    return 0;
//}









//
//int main()
//{
//	string a;
//	vector<int>ans;
//	cin >> a;
//	int cnt = 0;
//	for (int i = a.size() - 1; i >= 0; i--)
//	{
//		int f = (a[i] - '0') * 2 + cnt;
//		ans.push_back(f % 10);
//		cnt = f / 10;
//	}
//	if (cnt)ans.push_back(cnt);
//	for (int i = ans.size() - 1;i >= 0;i--) cout << ans[i];
//}





//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//typedef pair<int, int>PII;
//
//const int N = 1e5 + 10;
//struct range
//{
//    int l, r;
//}ranges[N];
//
//bool cmp(range a, range b)
//{
//    return a.l < b.l;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int l, r;
//        cin >> l >> r;
//        ranges[i] = { l, r };
//    }
//    sort(ranges, ranges + n, cmp);
//    priority_queue<int, vector<int>, greater<int>>a;
//    a.push(ranges[0].r);
//    int res = 1;
//    for (int i = 1; i < n; i++)
//    {
//        int flag = 0;
//        for (int j = 0; j < a.size(); j++)
//        {
//            int aa = a.top();
//            if (ranges[i].l > aa)
//            {
//                a.pop();
//                a.push(ranges[i].r);
//                flag = 1;
//                break;
//            }
//        }
//        if (!flag)
//        {
//            a.push(ranges[i].r);
//            res++;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}




//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#include<stdbool.h>
//#include<iomanip>
//#include<stdio.h>
//#include<vector>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//
//const int N = 1e6 + 10;
//struct range
//{
//	int l, r;
//}ranges[N];
//
//bool cmp(range a, range b)
//{
//	return a.r < b.r;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n;i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		ranges[i] = { l, r };
//	}
//	sort(ranges, ranges + n, cmp);
//	int res = 1, ed = ranges[0].r;
//	for (int i = 1; i < n; i++)
//	{
//		if (ed <= ranges[i].l)
//		{
//			res++;
//			ed = ranges[i].r;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}



//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        double p;
//        cin >> p;
//        double ans = 1;
//        for (int i = 1; i <= n - 1; i++)
//        {
//            ans *= 2;
//        }
//        int mmp = n * (n + 1) / 4;
//        for (int i = 0; i < mmp; i++)
//        {
//            ans *= p;
//            ans = ans * (1 - p);
//        }
//        if (n % 2 == 1)ans = ans * p;
//        cout << ans << endl;
//    }
//    return 0;
//}
//
//#include <windows.h>
//
//#include <ctime>
//using namespace std;
//const int m = 3;             //m·
//const int MAXM = m + 1;        //ÿ���ڵ�ؼ�������Ĵ�С
//const int MAX = m - 1;       //�ؼ��ֽ����Ŀ
//const int NUM = (m + 1) / 2; //�ָ��  [m/2]����ȡ��
//const int MIN = NUM - 1;     //ÿ���ڵ�ؼ�����Ŀ��Сֵ
//typedef int KeyType;
//typedef struct BTNode {
//    int KeyNum;             //�ؼ�������
//    KeyType key[MAXM];      //�ؼ�������
//    struct BTNode* parent;  //ָ�򸸽ڵ�ָ��
//    struct BTNode* child[MAXM];//ָ������ָ��
//} BTNode, * BTree;
////����֮ǰ�������в����Ƿ���ڹؼ���x��
////���ڼ�����ʧ�ܣ�//�����ڼ����Բ��룬���²���Ľ�� ����йؼ��ֵ�λ�� �ͼ�¼���� �ɹ����ı�־
//typedef struct Result {
//    BTree p;
//    int i;
//    int tag;
//} Result;
//int SearchBTNode(BTree p, KeyType x) {
//    int i = 0;
//    while (i < p->KeyNum && p->key[i + 1] <= x) ++i;
//    return i;
//}
//Result SearchBTree(BTree tree, KeyType k) {
//    BTree q = tree, p = NULL;
//    int found_tag = 0, i = 0;
//    Result r;
//    while (q != NULL && found_tag == 0) {  // found_tag  �ǲ��ҳɹ��ı�־
//        i = SearchBTNode(q, k);
//        if (i > 0 && q->key[i] == k) found_tag = 1;
//        else {
//            p = q;
//            q = q->child[i];  //����ڵ�һ�����û�в鵽�����������С���ڵ�һ������ҵ��亢��ָ�룬Ȼ������ת����//ָ�� ��������
//        }
//    }
//    if (found_tag == 1) {
//        r.i = i;
//        r.p = q;
//        r.tag = 1;
//    }
//    else {
//        r.i = i;
//        r.p = p;
//        r.tag = 0;
//    }
//    return r;
//}
//void NewRoot(BTree& tree, KeyType k, BTree p, BTree q) {
//    tree = new BTNode;
//    tree->key[1] = k;
//    tree->KeyNum = 1;
//    tree->child[0] = p;
//    tree->child[1] = q;
//    /*�Ǹ����Ļ� pq���ܴ��ںϷ��Ľ�� ��Ҫ�޸��丸���*/
//    if (p != NULL) p->parent = tree;
//    if (q != NULL) q->parent = tree;
//    tree->parent = NULL;
//}
///*�����µĽ��*/
//void InSertBTNode(BTree& p, int i, KeyType k, BTree q) {
//    /*�ڵ�i��λ�� ����*/
//    /*�漰��������� 1.����ĩβ��2.�����м�*/
//    for (int j = p->KeyNum; j > i; j--) { /*������*/
//        p->key[j + 1] = p->key[j];
//        p->child[j + 1] = p->child[j];
//    }
//    p->key[i + 1] = k; /*ǰ����ҹ��� ���õ�i�ǲ����ǰһ��λ������*/
//    p->child[i + 1] = q;
//    if (q != NULL) q->parent = p;
//    p->KeyNum++;  //�ؼ�����Ŀ+1
//}
////�����p���ѳ��������,ǰһ�뱣��,��һ��������q
//void SplitBTNode(BTree& p, BTree& q) {
//    q = new BTNode;  //�����q����ռ�
//    int s = NUM;
//    q->child[0] = p->child[s];  //��һ��������q  ���ÿ�
//    p->child[s] = NULL;
//    for (int i = s + 1; i <= m; i++) {
//        q->child[i - s] = p->child[i];
//        q->key[i - s] = p->key[i];
//        p->child[i] = NULL;
//        p->key[i] = 0;
//    }
//    /*�޸Ľṹ������*/
//    q->KeyNum = p->KeyNum - s;
//    q->parent = p->parent;
//    /*�޸� �ù���������˫��*/
//    for (int j = 0; j <= q->KeyNum; j++) {
//        if (q->child[j] != NULL) q->child[j]->parent = q;
//    }
//    p->KeyNum = s - 1;
//}
///*��һ�����Ľ��p�ĵ�i��λ�ò���ؼ���k*/
//void InsertBTree(BTree& tree, int i, KeyType k, BTree p) {
//    /*����һ���µĹؼ��ֵĻ���ͬʱҲ������һ���µ�����  ���ܿ���Ϊ��*/
//    BTree q;
//    int finish_tag, newroot_tag;
//    /*����ɹ��ı�־ ���µĽ�����ɵı�־*/ /*����������ؼ�������������û�к��ʵĽ���ʱ��Ҫ�����µĽ��*/
//    KeyType x;
//    if (p == NULL) NewRoot(tree, k, NULL, NULL);/*�����ʱ�� ���� ���Ҳ��*/ /*��ʱ���Ҫ������һ������*/
//    else {
//        x = k;
//        q = NULL;
//        finish_tag = 0, newroot_tag = 0;
//        while (finish_tag == 0 && newroot_tag == 0) {
//            InSertBTNode(p, i, x, q); /*������p��  �ؼ��ֲ���ҲҪ����һ����������Ϊ�գ�*/
//            if (p->KeyNum <= MAX) finish_tag = 1;/*�жϹؼ�����Ŀ�Ƿ�Ϸ�*/ /*�Ϸ� ���޸�ѭ����־  ����ɹ�*/
//            else {              /*���Ϸ� ���ؼ��������� ���ֽ��*/
//                int s = NUM;
//                SplitBTNode(p, q); /*��sΪ�ֽ���  ��p��  */
//                /*����ָ���ϵ�Ԫ��    �������*/
//                x = p->key[s];
//                p->key[s] = '\0';
//                if (p->parent) { /*���˫�״��� Ѱ���ʺϲ����λ��*/
//                    p = p->parent;
//                    i = SearchBTNode(p, x); /*�ص�whileѭ�� �ֿ�ʼһ���µĲ���λ��  ��ʱ  ���ѽ�㽫��Ϊ�µĲ�����*/
//                }
//                else newroot_tag = 1;/*������ û�к��ʵĿ��Բ��� ��ô������һ����㿩*/
//            }
//        }
//        if (newroot_tag == 1) NewRoot(tree, x, p, q);/*Ҫ�����µĽ�� ˵�� ԭ����ɢ���Ǹ����   ���ｫ������һ���µĸ����*/
//    }
//}
///*ʵ���ö����������B��*/
//void PrintBTree(BTree tree, int newLine, int sum, queue<BTree>& qu) {
//    BTree p;
//    if (tree != NULL) {
//        cout << " [ ";
//        qu.push(tree->child[0]);
//        /*�ֽ�����ߵĺ��ӽ�������*/  //ÿ������� ��������������Դﵽ��һ��һ�еĴ���
//        for (int i = 1; i <= tree->KeyNum; i++) {
//            cout << tree->key[i] << " ";
//            qu.push(tree->child[i]);
//        }
//        sum += tree->KeyNum + 1; /*��¼�����˶��ٸ�����*/
//        cout << "]";
//        /*��newLine���ж�  �Ƿ���Ҫ���ӽ�㴦�����*/
//        if (newLine == 0) {
//            newLine = sum - 1; /*��������һ������ ��� ���Լ�¼������������*/
//            sum = 0;           /*��0����������*/
//            cout << endl;
//        }
//        else newLine--;
//    }
//    if (!qu.empty()) {
//        p = qu.front();
//        qu.pop();
//        PrintBTree(p, newLine, sum, qu);
//    }
//}
///***************************/ /*������ɾ���ؼ���ʱ�Ĳ���*/ /***************************/
////�Ȳ���Ҫɾ���Ĺؼ��֣����������ڵĽ��ؼ��������е�λ��
////����ֵ�����֣���㲻����ʱ����0
////����ʱ����1
////�ý����û�У����ǿ��ԴӸý�������ߣ�������һ������ָ���λ��
//int FindKeyTree(BTree p, int& i, KeyType k) {
//    if (k < p->key[1]) {
//        i = 0;  //�ؼ�������0���洢Ԫ��
//        return 0;
//    }
//    else {
//        i = p->KeyNum;
//        while (k < p->key[i] && i > 1) i--;
//        if (k == p->key[i]) return 1;
//        else return 0;
//    }
//}
///****************************/ /*����ɾ������*/ /************************/
///*ֱ��ɾ�������ؼ�����Ŀ������С�ؼ�����������ֱ��ɾȥ*/
///*ֱ��ɾ�������λ��i���Ĺؼ��֡��������ڣ�����йؼ��ִ�����С�ؼ��������ն˽��*/
///*ɾ��ֱֵ�ӽ��ؼ�����ǰ�ƣ����ұ߿��˳��������渳ֵ����*/
//void ReMove(BTree p, int i) {
//    for (int j = i + 1; j <= p->KeyNum; j++) {
//        p->key[j - 1] = p->key[j];
//        p->child[j - 1] = p->child[j];
//    }
//    p->key[p->KeyNum] = '\0';
//    p->KeyNum--;
//}
///************/
///*�ؼ�����Ŀ������С�ؼ�����Ŀ������ֱ��ɾ�������ֵ��д�����С�ؼ���Ŀ�������ǽ躢��*/  //**************
////��λ����Ը�����������������ؼ��֣���λ����Ը����������������С�ؼ��֡�������ֻ�Ǹ�����һ��
//void SubstitutionLeft(BTree p, int i) {
//    // p��Ѱ�ҵ���Ը���㣬i��������Ҫ�滻�Ĺؼ��ֵ�λ�ã�˼·Ѱ�����������ؼ���
//    BTree q;
//    q = p->child[i - 1];
//    while (NULL != q->child[q->KeyNum]) q = q->child[q->KeyNum];
//    p->key[i] = q->key[q->KeyNum - 1];
//}
//void SubstitutionRight(BTree p, int i)  //����Ѱ��
//{
//    BTree q;
//    q = p->child[i];
//    while (NULL != q->child[0]) q = q->child[0];
//    p->key[i] = q->key[1];
//}
///*��������� ��������ɾ���˹ؼ���֮�󣬶���������*/
////����p�Ǳ�ɾ�ؼ��ֵĽ�㣬i��ָ��ؼ��ֵĵĺ���ָ��λ��
//void MoveRight(BTree p, int i) {
//    int j;
//    BTree q = p->child[i];  //��ɾ���Ľ��
//    BTree aq = p->child[i - 1];  //������ֵܽ��  ���õ�����ֵܽ��ʱ���Ѿ�ɸѡ�ˣ����Ĺؼ�����������С������//����ѡȡ���������һ��ȡ��
//    /*֮ǰɾ����ʱ���Ѿ�����ɾ��㣬���������ߵĴ���*/
//    /*�����i����Ԫ��Ӧ�ø����ڱ�ɾ��������ߣ�����Ҫ�����ߴ���*/
//    for (j = q->KeyNum; j >= 1; j--) {
//        q->key[j + 1] = q->key[j];
//        q->child[j + 1] = q->child[j];
//    }
//    q->child[1] = q->child[0];
//    q->key[1] = p->key[i];
//    q->KeyNum++;
//    /*����������Ը����*/
//    p->key[i] = aq->key[aq->KeyNum];
//    p->child[i]->child[0] = aq->child[aq->KeyNum];  //�������ֵܽ躢��ʱ�������������ָ�룬�������ֵܵ���С����ָ��
//    aq->KeyNum--;
//}
//void MoveLeft(BTree p, int i) /*����*/
//{
//    int j;
//    BTree q, aq;
//    q = p->child[i + 1];  //���ֵܽ躢��
//    aq = p->child[i];     //���ֵܱ�ɾ��
//    /*����ת����Ը��Ĺؼ��ַ��ڣ������������ؼ��ִ�*/
//    //��ɾ������ʱ�����λ�ô������յ�
//    aq->key[aq->KeyNum + 1] = p->key[i + 1];
//    aq->KeyNum++;
//    aq->child[aq->KeyNum] = p->child[i + 1]->child[0]; /*��ͼ��֪�������ֵܽ躢�ӵ�ͬʱ��������0�ź���ָ�븳�����ֵܵ������ָ��*/
//    /*�����ֵܵĺ��ӣ�ѡ����С�ģ��滻�������ؼ���*/
//    p->key[i + 1] = q->key[1];
//    q->child[0] = q->child[1];
//    //��ǰ��
//    for (j = 2; j <= q->KeyNum; j++) {
//        q->key[j - 1] = q->key[j];
//        q->child[j - 1] = q->child[j];
//    }
//    q->KeyNum--;
//}
///*����ɾ�������ֵܲ��ܺϲ������ֵܺϲ�*/
//void CombineRight(BTree p, int i) {
//    int j, count = 0;
//    BTree q = p->child[i];  //��ɾ���  /*���ֵ��Ǳ�ɾ�ģ������ұ��Ѿ�����*/
//    BTree aq = p->child[i + 1];  //���ֵ�
//    q->KeyNum++; /*����1���Ƚ�˫�׽���i+1��Ԫ���õ����ֵ���*/
//    q->key[q->KeyNum] = p->key[i + 1];
//    for (j = i + 2; j <= p->KeyNum; j++) /*����2���Ѹ���㡢����ָ��������һ��*/
//    {
//        p->key[j - 1] = p->key[j];
//        p->child[j - 1] = p->child[j];
//    }
//    p->child[p->KeyNum] = NULL;
//    p->KeyNum--;
//    /*����3�������ֵܵĹؼ��������ֵܺϲ�*/
//    q->child[q->KeyNum] = aq->child[0];
//    for (j = 1; j <= aq->KeyNum; j++) {
//        q->key[q->KeyNum + j] = aq->key[j];
//        q->child[q->KeyNum + j] = aq->child[j];
//        count++;
//    }
//    q->KeyNum += count;
//    delete(aq);
//}
//void CombineLeft(BTree p, int i) {
//    /*Ҳ������ϲ�*/
//    int j, count = 0;
//    BTree q = p->child[i];       /*���ֵ��Ǳ�ɾ�ģ��������ұ��Ѿ�����*/
//    BTree aq = p->child[i - 1];  //���ֵ�
//    /*����1���Ƚ�˫�׽��һ��Ԫ���õ����ֵ��еĵ�һ��Ԫ��*/
//    for (j = q->KeyNum; j >= 1; j--) { /*�����ֵܽ������ƴ���*/
//        q->key[j + 1] = q->key[j];
//        q->child[j + 1] = q->child[j];
//    }
//    q->child[1] = q->child[0];
//    q->key[1] = p->key[i];
//    p->key[i] = '\0';
//    q->KeyNum++;
//    /*����2������ɾ��������ֵ���*/
//    for (j = 1; j <= q->KeyNum; j++) {
//        aq->key[aq->KeyNum + j] = q->key[j];
//        aq->child[aq->KeyNum + j] = q->child[j];
//        q->key[j] = '\0';
//        q->child[j] = NULL;
//        count++;
//    }
//    aq->KeyNum += count;
//    q->KeyNum -= count;
//    /*����3: �����������*/
//    for (j = i + 1; j <= p->KeyNum; j++) {
//        p->key[j - 1] = p->key[j];
//        p->child[j - 1] = p->child[j];
//    }
//    p->KeyNum--;
//    delete(q);
//}
///*k�ؼ����Ѿ�ɾ����Ҫ��������p�ǹؼ���k�ĸ���㣬i�Ǹ��������k���ڽ��ĺ���ָ����*/
//void AdjustBTree(BTree p, int i) {
//    if (i == 0) {                       //���ɾ�����ǵ�һ��1������ָ��
//        if (p->child[1]->KeyNum > MIN) MoveLeft(p, i);//�Һ��ӿ��Խ�
//        else CombineRight(p, i);  //���ܽ裬ֻ�ܺϲ�
//    }
//    else if (i == p->KeyNum) {  //���ɾ���������һ������ָ��
//        if (p->child[i - 1]->KeyNum > MIN) MoveRight(p, i);//���ӿɽ�
//        else CombineLeft(p, i);  //�����ܽ裬ֻ�ܺϲ�
//    }
//    else {  //���ɾ�������м䲿�ֵĹؼ���
//        if (p->child[i - 1]->KeyNum > MIN) MoveRight(p, i);//���ӿɽ�
//        else if (p->child[i + 1]->KeyNum > MIN) MoveLeft(p, i);//�Һ��ӿɽ�
//        else CombineRight(p, i);  //�������Խ� ֻ�ܺϲ�
//    }
//}
//int BTNodeDelete(BTree p, KeyType k) {
//    //�ڽ��p�в��Ҳ�ɾ���ؼ���k
//    int i;
//    int found_tag;  //���ұ�־
//    if (p == NULL) return 0;
//    else {
//        found_tag = FindKeyTree(p, i, k);  //���ز��ҽ��
//        if (found_tag == 1)  //���Һ�������Ϊ1ʱ���ǣ����ҳɹ�  iֵ���Ǹ�ɾ���ؼ��ֵ�λ��
//        {
//            if (p->child[i] != NULL) {    //ɾ�����Ƿ�Ҷ�ӽ��
//                SubstitutionRight(p, i);  //Ѱ�����ڹؼ���(����������С�Ĺؼ���)
//                BTNodeDelete(p->child[i], p->key[i]);  //ִ��ɾ������
//            }
//            else if (p->child[i - 1] != NULL) {
//                SubstitutionLeft(p, i);
//                BTNodeDelete(p->child[i], p->key[i]);
//            }
//            else ReMove(p, i);  //�ӽ��p��λ��i��ɾ���ؼ���
//        }
//        else found_tag = BTNodeDelete(p->child[i], k);  //�غ��ӽ��ݹ���Ҳ�ɾ���ؼ���k
//        if (p->child[i] != NULL) /*��Ϊ���������ѭ������������ÿ�ζ������һ��*/
//            if (p->child[i]->KeyNum < MIN)  //ɾ����ؼ��ָ���С��MIN
//                AdjustBTree(p, i);          //����B��  �����Ǳ�ɾ�ؼ��ʵĸ����
//        return found_tag;
//    }
//}
//int BTreeDelete(BTree& t, KeyType k) {
//    //����ɾ����ܣ�ִ��ɾ������
//    BTree p;
//    int a = BTNodeDelete(t, k);  //ɾ���ؼ���k
//    if (a == 0) return 0;//����ʧ��
//    else if (t->KeyNum == 0) {  //����
//        p = t;
//        t = t->child[0];
//        delete(p);
//    }
//    return 1;
//}
//void DestroyBTree(BTree& t) {
//    //�ݹ��ͷ�B�� 
//    int i;
//    BTree p = t;
//    if (p != NULL) {                                    //B����Ϊ��  
//        for (i = 0;i <= p->KeyNum;i++) {                  //�ݹ��ͷ�ÿһ����� 
//            DestroyBTree(*&p->child[i]);
//        }
//        free(p);
//    }
//    t = NULL;
//}
//void ShowChoose() {
//    cout << "=============Operation Table=============" << endl;
//    cout << "   1.Insert    2.Delete   3.Show B-Tree  " << endl;
//    cout << "   4.Search    5.Destroy  6.Exit         " << endl;
//    cout << "   7.RandomTest                          " << endl;
//    cout << "=========================================" << endl;
//    cout << "Enter number to choose operation:_____\b\b\b";
//}
//void RandomTest() {
//    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);//��ɫ����
//    cout << "Please enter how many numbers do you want to insert:" << endl;
//    BTree tree = NULL;
//    queue<BTree>qu;
//    int n = 0; cin >> n;
//    clock_t start = clock();
//    for (int i = 0;i < n;++i) {
//        int value = rand() % 99999;
//        Result s = SearchBTree(tree, value);    //�����Ƿ��ظ�
//        if (1 != s.tag) InsertBTree(tree, s.i, value, s.p);
//        // if(1==s.tag) cout<<"The number "<<value<<" has existed!"<<endl;
//        // else{ 
//        //     InsertBTree(tree,s.i,value,s.p);
//        //     cout<<"Insert successfully!"<<endl;
//        // }
//    }
//    clock_t end = clock();
//    //PrintBTree(tree,0,0,qu);
//    cout << "Insert " << n << " numbers spends " << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl;
//    PrintBTree(tree, 0, 0, qu);
//    DestroyBTree(tree);
//}
//void Test() {
//    system("cls");
//    BTree tree = NULL;
//    queue<BTree>qu;
//    int choose = 0;
//    while (true) {
//        cout << endl;
//        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        ShowChoose();
//        cin >> choose;
//        switch (choose) {
//        case 1: {                       //����
//            system("cls");             //����
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);//��ɫ����
//            cout << "Please enter the number that you want to insert:_____\b\b\b";
//            KeyType value = 0; cin >> value;
//            Result s = SearchBTree(tree, value);    //�����Ƿ��ظ�
//            if (1 == s.tag) cout << "The number " << value << " has existed!" << endl;
//            else {
//                InsertBTree(tree, s.i, value, s.p);
//                cout << "Insert successfully!" << endl;
//            }
//            break;
//        }
//        case 2: {                         //ɾ��
//            system("cls");
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
//            cout << "Please enter the number that you want to delete:_____\b\b\b";
//            KeyType value = 0; cin >> value;
//            if (0 == BTreeDelete(tree, value)) cout << "Cannot find " << value << " in B-Tree!" << endl;
//            else cout << "Delete successfully!" << endl;
//            break;
//        }
//        case 3: {                     //��ӡB-Tree
//            system("cls");
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
//            if (!tree) cout << "B-Tree is NULL!" << endl;
//            else PrintBTree(tree, 0, 0, qu);
//            break;
//        }
//        case 4: {                       //����
//            system("cls");
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
//            cout << "Please enter the number that you want to search:_____\b\b\b";
//            KeyType value = 0; cin >> value;
//            Result s = SearchBTree(tree, value);
//            if (1 == s.tag) cout << "Search successfully!" << endl << value << " is in B-Tree!" << endl;
//            else cout << "Cannot find " << value << " in B-Tree!" << endl;
//            break;
//        }
//        case 5: {                          //����B-Tree
//            system("cls");
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
//            DestroyBTree(tree);
//            cout << "B-Tree is Destroyed!" << endl;
//            break;
//        }
//        case 6: {                           //�˳�
//            system("cls");
//            exit(0);
//            break;
//        }
//        case 7: {
//            system("cls");             //����
//            RandomTest();
//            break;
//        }
//        default: {
//            system("cls");
//            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
//            cout << "Error!" << endl << "Please enter again:" << endl;
//        }
//        }
//    }
//}
//int main() {
//    srand((unsigned)time(NULL));
//    Test();
//    system("pause");
//    return 0;
//}

//static int n = 0;  //ͳ��������Ŀ������
//int pastscore = 0;//��ʷ�ɼ�
//void get_value();//���ú���
//void read(string filename);
//void get_value1(); //�ӷ�
//void get_value2(); //����
//void get_value3(); //�˷�
//void get_value4(); //����
//void get_value5();//�����ŵĻ������
//int main() {
//	system("color F0");
//	cout << "==============================" << endl;
//	cout << "*  ��ӭʹ��Сѧ��С�Ϳ���ϵͳ*" << endl;
//	cout << "*     1.��10������           *" << endl;
//	srand((unsigned)time(NULL));//��ʼ�������������
//
//	
//	FILE* fp = fopen("./2.txt", "r");
//	if (!fp)
//		return 0;
//	int c;
//	c = _getw(fp);
//	cout << "�����ʷ�ɼ�Ϊ:" << c<<' ';
//	pastscore = c;
//	
//	fclose(fp);
//	cout << endl;
//
//	int y;
//	cout << "ѡ����";
//	cin >> y;
//	if (y != 1)
//		cout << "��������" << endl;
//	else
//	{
//		switch (y)
//		{
//		case 1:
//			get_value();break;
//
//		}
//
//	}
//
//}
//void get_value()
//{
//	int m, i;
//	int score;
//	for (i = 0;i < 10;i++)
//	{
//		cout << "===================" << endl;
//		cout << "��" << i + 1 << "�⣺" << endl;
//		m = rand() % 5;
//
//		switch (m)
//		{
//		case 0:
//			get_value1();break;
//		case 1:
//			get_value2();break;
//		case 2:
//			get_value3();break;
//		case 3:
//			get_value4();break;
//		case 4:
//			get_value5();break;
//		}
//	}
//	cout << "��������" << n << "����" << endl;
//	score = n * 10;
//	cout << "��ı��ε÷�Ϊ" << score << endl;
//	if (score > pastscore)
//		printf("�������\n");
//	else
//		printf("���˲���\n");
//	
//	FILE* fp = fopen("2.txt", "a");
//	_putw(score,fp);
//	fclose(fp);
//	
//}
//void get_value1()
//{
//
//	int a, b, x;
//	char m = '+', ch;
//	a = 1 + rand() % 100;
//	b = 1 + rand() % 100;
//	cout << a << m << b << '=';
//	cin >> x;
//	if (x == a + b)
//	{
//		cout << "������" << endl;
//		n++;
//	}
//	else
//	{
//		cout << "������" << endl;
//		cout << "�Ƿ������ȷ�𰸣�(Y��N)" << endl;
//		cin >> ch;
//		if (ch == 'Y')
//		{
//			cout << "��ȷ��Ϊ��" << a + b << endl;
//		}
//
//	}
//
//}
//
//
////��������
//void get_value2()
//{
//
//	int a, b, x;
//	char m = '-', ch;
//	a = 1 + rand() % 100;
//	b = 1 + rand() % 100;
//	if (a >= b)
//	{
//		cout << a << m << b << '=';
//		cin >> x;
//		if (x == a - b)
//		{
//			cout << "������" << endl;
//			n++;
//		}
//		else
//		{
//			cout << "������" << endl;
//			cout << "�Ƿ������ȷ�𰸣�(Y��N)" << endl;
//			cin >> ch;
//			if (ch == 'Y')
//			{
//				cout << "��ȷ��Ϊ��" << a - b << endl;
//			}
//
//		}
//	}
//	else
//		get_value2();
//}
//
//
////�˷�����
//void get_value3()
//{
//
//	int a, b, x;
//	char m = '*', ch;
//	a = 1 + rand() % 9;
//	b = 1 + rand() % 9;
//	if (a < b)
//	{
//		cout << a << m << b << '=';
//		cin >> x;
//		if (x == a * b)
//		{
//			cout << "������" << endl;
//			n++;
//		}
//		else
//		{
//			cout << "������" << endl;
//			cout << "�Ƿ������ȷ�𰸣�(Y��N)" << endl;
//			cin >> ch;
//			if (ch == 'Y')
//			{
//				cout << "��ȷ��Ϊ��" << a * b << endl;
//			}
//
//		}
//	}
//	else
//		get_value3();
//}
//
//
////��������
//void get_value4()
//{
//
//	int a, b, x;
//	char m = '/', ch;
//	a = 1 + rand() % 9;
//	b = 1 + rand() % 9;
//	if (a >= b && a % b == 0)
//	{
//		cout << a << m << b << '=';
//		cin >> x;
//		if (x == a / b)
//		{
//			cout << "������" << endl;
//			n++;
//		}
//		else
//		{
//			cout << "������" << endl;
//			cout << "�Ƿ������ȷ�𰸣�(Y��N)" << endl;
//			cin >> ch;
//			if (ch == 'Y')
//			{
//				cout << "��ȷ��Ϊ��" << a / b << endl;
//			}
//
//		}
//	}
//	else
//		get_value4();
//}
//
//void get_value5()
//{
//	int a, b, c;int m, k;
//
//	a = rand() % 10 + 1;
//	b = rand() % 10 + 1;
//	c = rand() % 10 + 1;
//
//	m = rand() % 4 + 1;
//	switch (m)
//	{
//	case 1:
//	{	cout << a << "+" << "(" << b << "*" << c << ")" << "=";
//	scanf("%d", &k);
//	if (k = a + (b * c))
//	{
//		printf("������");
//		n++;
//		break;
//	}
//	else
//		printf("������");
//	}
//	case 2:
//
//	{	cout << a << "-" << "(" << b << "*" << c << ")" << "=";
//	scanf("%d", &k);
//	if (k = a - (b * c))
//	{
//		printf("������");
//		n++;
//		break;
//	}
//	else
//		printf("������");
//	}
//	case 3:
//	{	cout << "(" << a << "-" << b << ")" << "*" << c << "=";
//	scanf("%d", &k);
//	if (k = (a - b) * c)
//	{
//		printf("������");
//		n++;
//		break;
//	}
//	else
//		printf("������");
//	}
//	case 4:
//	{	cout << "(" << a << "+" << b << ")" << "/" << c << "=";
//	scanf("%d", &k);
//	if (k = (a + b) / c)
//	{
//		printf("������");
//		n++;
//		break;
//	}
//	else
//		printf("������");
//	}
//	}
//
//}


//#define pi 3.141592653589793238462643383
//long double x1, x2, y11, y2,r1,r2;
//
//int main() {
//	//scanf("%llf%llf%llf%llf%llf%llf", &x1, &y11, &r1, &x2, &y2, &r2);
//	cin >> x1 >> y11 >> r1 >> x2 >> y2 >> r2;
//	long double cao = pow(x1 - x2, 2);
//	long double kao = pow(y11 - y2, 2);
//	long double d = sqrt(cao + kao);
//	if (r1 == 0 || r2 == 0 || d >= r1 + r2)cout << setprecision(25) << 0;
//	else if (d <= fabs(r1 - r2))cout << setprecision(25) << pi * (min(r1, r2)*min(r1,r2));
//	else {
//		long double c = d + r1 + r2;
//		long double p = c / 2;
//		long double s = sqrt(p * (p - r1) * (p - r2) * (p - d));
//		long double mmp = s / (d * r2);
//		long double wuyuzi = s / (d * r1);
//		long double val = 180.0 / pi;
//		long double jiao1 = asin(mmp) * val;
//		long double jiao2 = asin(wuyuzi) * val;
//		long double ans = 2 * jiao1 / 360 * pi * r2 * r2 + 2 * jiao2 / 360 * pi * r1 * r1;
//		long double angA = 2 * acos(((r1 * r1) + (d * d) - (r2 * r2)) / (2 * r1 * d));
//		long double angB = 2 * acos(((r2 * r2) + (d * d) - (r1 * r1)) / (2 * r2 * d));
//		long double cccc = (r1 * r1) * (angA - sin(angA)) / 2;
//		long double ccc = (r2 * r2) * (angB - sin(angB)) / 2;
//		long double ccccc = cccc + ccc;
//		//printf("%llf", ccccc);
//		cout << setprecision(25) << ccccc;
//	}
//	return 0;
//}





//typedef long long ll;
//const int N = 1000050;
//int a[N], b[N], ah, at, bh, bt;
//
////int main() {
////	char arr[110];
////	cin >> arr;
////	cout << arr;
////	return 0;
////}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0;i < n;i++) {
//		int x;
//		cin >> x;
//		a[ah++] = x;
//	}
//	int ans = 0,prev=-100005000;
//	while (at < ah) {
//		int t = a[at++];
//		if (ans == 0)ans++;
//		else {
//			if (t == prev) {
//				b[bh++] = t;
//				continue;
//			}
//			else {
//				ans++;
//			}
//		}
//		prev = t;
//	}
//	prev = -100005000;
//	while (bt < bh) {
//		int t = b[bt++];
//		if (ans == 0)ans++;
//		else {
//			if (t == prev) {
//				continue;
//			}
//			else {
//				ans++;
//			}
//		}
//		prev = t;
//	}
//	cout << ans << endl;
//	return 0;
//}








//const int N = 2e5 + 10;
//int e[N], ne[N], h[N], idx;
//int color[N];
////match[j]=a,��ʾŮ��j���������������a
//int match[N];
////st[]�����ҳ�Ϊ��ʱԤ�����飬st[j]=a��ʾһ��ģ��ƥ���У�Ů��j���к�aԤ���ˡ�
//int st[N];
//int n, m;
//int find(int x)
//{
//	//�����Լ�ϲ����Ů��
//	for (int i = h[x]; i != -1;i = ne[i])
//	{
//		int j = e[i];
//		if (!st[j])//�������һ��ģ��ƥ����,���Ů����δ��Ԥ��
//		{
//			st[j] = true;//��x��Ԥ�����Ů����
//			//���Ů��jû�������ѣ�������ԭ�����������ܹ�Ԥ������ϲ����Ů������Գɹ�,����match
//			if (!match[j] || find(match[j]))
//			{
//				match[j] = x;
//				return true;
//			}
//
//		}
//	}
//	//�Լ������ȫ������Ԥ���ˡ����ʧ�ܡ�
//	return false;
//}
//
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//bool dfs(int t, int c) {
//	color[t] = c;
//	for (int i = h[t];i != -1;i = ne[i]) {
//		int j = e[i];
//		if (!color[j]) {
//			if (!dfs(j, 3 - c))return false;
//		}
//		else if (color[j] == c)return false;
//
//	}
//	return true;
//}
//int main() {
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	while (m--) {
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//	}
//	int flag = 1;
//	for (int i = 1;i <= n;i++) {
//		if (!color[i]) {
//			if (!dfs(i, 1)) {
//				flag = 0;
//				break;
//			}
//		}
//	}
//	if (flag) {
//		//��¼���ƥ��
//		int res = 0;
//		for (int i = 1; i <= n;i++)
//		{
//			//��Ϊÿ��ģ��ƥ���Ԥ��������ǲ�һ��������ÿ��ģ�ⶼҪ��ʼ��
//			memset(st, false, sizeof st);
//			if (color[i] == 1)
//				if (find(i))
//					res++;
//		}
//		cout << res << endl;
//	}
//	else cout << "YE5";
//	return 0;
//}





//int a[2010],f[2010],ans;
//void find(int x) {
//	ans++;
//	if (x == f[x])return;
//	find(f[x]);
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++) {
//		cin >> a[i];
//		if (a[i] == -1)f[i]=i;
//		else f[i] = a[i];
//	}
//	int maxi = 0;
//	for (int i = 1;i <= n;i++) {
//		ans = 0;
//		find(i);
//		maxi = max(ans, maxi);
//	}
//	cout << maxi;
//	return 0;
//}







//typedef pair<int, int>PII;
//const int N = 1010;
//char a[N][N];
//int dist[N][N];
//bool st[N][N];
//int dx[4] = { 1,0,0,-1 }, dy[4] = {0,-1,1,0 };
//int n, m, k;
//void bfs(int x,int y) {
//	queue<PII>q;
//	memset(dist, -1, sizeof dist);
//	dist[x][y] = 0;
//	st[x][y] = true;
//	q.push({ x,y });
//	while (!q.empty()) {
//		auto t = q.front();
//		q.pop();
//		for (int i = 0;i < 4;i++) {
//			int nx = t.first + dx[i];
//			int ny = t.second + dy[i];
//			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && dist[nx][ny] == -1 && !st[nx][ny]&&a[nx][ny]!='*') {
//				q.push({ nx,ny });
//				st[nx][ny] = true;
//				dist[nx][ny] = dist[t.first][t.second] + 1;
//			}
//		}
//	}
//}
//int main() {
//	
//	cin >> n >> m >> k;
//	int x, y;
//	
//	for (int i = 1;i <= n;i++) {
//		getchar();
//		for (int j = 1;j <= m;j++) {
//			scanf("%c", &a[i][j]);
//			if (a[i][j] == 'X') {
//				x = i, y = j;
//			}
//		}
//	}
//	bfs(x,y);
//	if (k % 2 == 1)cout << "IMPOSSIBLE";
//	else {
//		//D>L>R>U
//		int nx, ny,cao=1;
//		char s[5] = "DLRU";
//		string res;
//		int flag = 1;
//		for (int i = 1;i <= k;i++) {
//			flag = 0;
//			for (int j = 0;j < 4;j++) {
//				nx = x + dx[j], ny = y + dy[j];
//				if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && a[nx][ny] != '*' && k - i >= dist[nx][ny]) {
//					flag = 1;
//					res += s[j];
//					x = nx, y = ny;
//					break;
//				}
//			}
//			if (!flag) {
//				cout << "IMPOSSIBLE";
//				cao =0;
//				break;
//			}
//		}
//		if (cao)cout << res;
//	}
//	return 0;
//}




//
//vector<int> add(vector<int>& A, vector<int>& B) {
//	vector<int>C;
//	int t = 0;
//	for (int i = 0;i < A.size() || i < B.size();i++) {
//		if (i < A.size())t += A[i];
//		if (i < B.size())t += B[i];
//		C.push_back(t % 10);
//		t /= 10;
//	}
//	if (t)C.push_back(1);
//	return C;
//}
//
//vector<int> sub(vector<int>& A, vector<int>& B) {
//	vector<int>C;
//	int t = 0;
//	for (int i = 0;i < A.size();i++) {
//		t += A[i];
//		if (i < B.size())t -= B[i];
//		C.push_back((t + 10) % 10);
//		if (t < 0)t = -1;
//		else t = 0;
//	}
//	while (C.size() > 1 && C.back() == 0)C.pop_back();
//	return C;
//}
//
//
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string a, b;
//		vector<int>A, B;
//		cin >> a >> b;
//		for (int i = a.size()-1;i >=0;i--)A.push_back(a[i] - '0');
//		for (int i = b.size() - 1;i >= 0;i--)B.push_back(b[i] - '0');
//		vector<int> C = add(A, B);
//		for (int i = C.size() - 1;i >= 0;i--)cout << C[i];
//		cout << endl;
//		
//		vector<int> D = sub(A, B);
//		for (int i = D.size() - 1;i >= 0;i--)cout << D[i];
//		
//		cout << endl;
//
//	}
//	return 0;
//}






//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		if (n < 3)cout << n << endl;
//		else cout << (n/2)+1 << endl;
//	}
//	return 0;
//}







//int main() {
//	char arr[1010];
//	cin >> arr;
//	int sz = strlen(arr);
//	int ans = 0;
//	for (int i = 0;i < sz;i++) {
//		ans += arr[i] - '0';
//	}
//	ans %= 3;
//	cout << ans;
//	return 0;
//}








//const int N = 2e5 + 10;
//int b[N], p[N],arr[N],d[N];
//bool st[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		memset(d, -1, sizeof d);
//		for (int i = 1;i <= n;i++)
//			cin >> b[i];
//		for (int i = 1;i <= n;i++)
//			cin>>p[i];
//
//		for (int i = 2;i <= n;i++) {
//			int t = p[i];
//
//			if (d[b[]] == -1) {
//				cout << -1 << endl;
//				goto a;
//			}
//			d[i] = d[t] + i;
//		}
//
//		a:
//	}
//}






//const int N = 4e5 + 10;
//int e[N], ne[N], h[N], idx;
//int f[N];
//bool st[N], fst[N];
//int d[N], fd[N];
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		memset(h, -1, sizeof h);
//		int n, k;
//		cin >> n >> k;
//		for (int i = 0;i < k;i++) {
//			cin >> f[i];
//		}
//		for (int i = 0;i < n - 1;i++) {
//			int a, b;
//			cin >> a >> b;
//			add(a, b);
//			add(b, a);
//		}
//		for (int i = 0;i <= n;i++) {
//			st[i] = false;
//			fst[i] = false;
//			d[i] = 0;
//			fd[i] = 0;
//		}
//		queue<int>q;
//		q.push(1);
//		st[1] = true;
//		while (!q.empty()) {
//			int t = q.front();
//			q.pop();
//			for (int i = h[t];i != -1;i = ne[i]) {
//				int j = e[i];
//				if (!st[j]) {
//					st[j] = true;
//					q.push(j);
//					d[j] = d[t] + 1;
//				}
//			}
//		}
//		for (int i = 0;i < k;i++) {
//			int cnm = f[i];
//			fst[cnm] = true;
//			q.push(cnm);
//		}
//		while (!q.empty()) {
//			int t = q.front();
//			q.pop();
//			for (int i = h[t];i != -1;i = ne[i]) {
//				int j = e[i];
//				if (!fst[j]) {
//					fst[j] = true;
//					fd[j] = fd[t] + 1;
//					q.push(j);
//					
//				}
//			}
//		}
//		int flag = 0;
//		for (int i = 2;i <= n;i++) {
//			if (ne[h[i]] == -1) {
//				if (d[i] < fd[i]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag)cout << "YES" << endl;
//		else cout << "NO" << endl;
//		
//	}
//	return 0;
//}





//const int N = 2e5 + 10;
//int a[N], p[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n,m=0;
//		cin >> n;
//		for (int i = 0;i < n;i++) {
//			cin >> a[i];
//			m = max(m, a[i]);
//		}
//		if (a[0] < m && a[n - 1] < m) {
//			cout << -1 << endl;
//			continue;
//		}
//		if (n == 1) {
//			cout << 1 << endl;
//			continue;
//		}
//		if (a[0] < a[n - 1]) {
//			p[n - 1] = a[n - 1];
//			for (int i = n - 2,j=0;i >= 0;i--,j++) {
//				p[j] = a[i];
//			}
//		}
//		else {
//			p[0] = a[0];
//			for (int i = n - 1, j = 1;j<n;i--, j++) {
//				p[i] = a[j];
//			}
//		}
//		for (int i = 0;i < n;i++)cout << p[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}





//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int a, b,ans=0;
//		cin >> a >> b;
//		if (a < b)swap(a, b);
//		int c = a - b;
//		/*while (c >= 2 && a >= 3 && b > 0) {
//			a -= 3;
//			b -= 1;
//			c -= 2;
//			ans++;
//		}*/
//		int cnm = min(a / 3, b);
//		int mmp = min(cnm, c / 2);
//		ans += mmp;
//		a = a - mmp * 3;
//		b = b - mmp;
//		int m = min(a / 2, b / 2);
//		ans += m;
//		
//		cout << ans << endl;
//	}
//	return 0;
//}





//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		char a[100];
//		scanf("%s", a);
//		int sz = strlen(a);
//		if ((a[sz-1]-'0') % 2 == 0) {
//			cout << 0 << endl;
//			continue;
//		}
//		else {
//			if ((a[0] - '0') % 2 == 0) {
//				cout << 1 << endl;
//			}
//			else {
//				int flag = 0;
//				for (int i = 0;i < sz;i++) {
//					if ((a[i] - '0') % 2 == 0) {
//						cout << 2 << endl;
//						flag = 1;
//						break;
//					}
//				}
//				if (!flag)cout << -1<<endl;
//			}
//		}
//	}
//	return 0;
//}








//int idx;
//const int N = 1e6 + 10;
//int arr[N];
//int qiu(int x, int y) {
//    int z = y;
//    while (x % y != 0) {
//        z = x % y;
//        x = y;
//        y = z;
//    }
//    return z;
//}
//int main() {
//    int a, b;
//    cin >> a >> b;
//    int t;
//    int res = qiu(a, b);
//    for (int i = 1;i <= res / i;i++) {
//        if (res % i == 0) {
//            arr[idx++] = i;
//            if (i != res / i)arr[idx++] = res / i;
//        }
//    }
//    arr[idx++] = res;
//    sort(arr, arr + idx);
//    for (int i=0;i < idx;i++) {
//        cout << arr[i] << ' ';
//    }
//    cin >> t;
//    while (t--) {
//        int l, r;
//        cin >> l >> r;
//        for (int i=0;i < idx;i++) {
//            if (arr[i] >= l) {
//                cout << arr[i] << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}




//const int N = 110;
//int arr[N];
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n, t,ans=0,cnt=0;
//		cin >> n >> t;
//		for (int i = 0;i < n;i++)cin >> arr[i];
//		sort(arr, arr + n);
//		int c = t;
//		while (t--) {
//			ans += arr[n -1-c-cnt] / arr[n - 1 - cnt];
//			arr[n - 1 - c - cnt] = 0;
//			arr[n - 1 - cnt] = 0;
//			cnt++;
//		}
//		for (int i = 0;i < n;i++)ans += arr[i];
//		cout << ans << endl;
//	}
//	return 0;
//}




//typedef long long ll;
//ll arr[110];
//int t, n;
//ll measure(ll x, ll y)
//{
//	ll z = y;
//	while (x % y != 0)
//	{
//		z = x % y;
//		x = y;
//		y = z;
//	}
//	return z;
//}
//
//int main() {
//	cin >> t;
//	while (t--) {
//		for (int i = 0;i < 110;i++)arr[i] = 0;
//		cin >> n;
//		ll m = 0;
//		for (int i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		int flag=1;
//		ll ji = arr[0], ou = arr[1];
//		for (int i = 0;i < n;i += 2)ji = measure(ji, arr[i]);
//		for (int i = 1;i < n;i += 2)ou = measure(ou, arr[i]);
//		for (int i = 0;i < n;i += 2) {
//			if (arr[i] % ou == 0) {
//				flag = 0;
//			}
//		}
//		if (flag) {
//			cout << ou << endl;
//			continue;
//		}
//		flag = 1;
//		for (int i = 1;i < n;i += 2) {
//			if (arr[i] % ji == 0) {
//				flag = 0;
//			}
//		}
//		if (flag) {
//			cout << ji << endl;
//			continue;
//		}
//		cout << 0 << endl;
//	}
//}




//
//int arr[110],d[110];
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		memset(arr, 0, sizeof arr);
//		int n, t;
//		int m1, m2;
//		m1 = m2 = 0;
//		int ans = 0,cnt=0;
//		cin >> n >> t;
//		for (int i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		while (t--) {
//			for (int i = 0;i < n;i++) {
//				if (arr[i] > m1) {
//					m1 = arr[i];
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] == m1) {
//					arr[i] = 0;
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] > m2) {
//					m2 = arr[i];
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] == m2) {
//					arr[i] = 0;
//				}
//			}
//			d[cnt] = m1;
//			d[cnt + 1] = m2;
//			cnt += 2;
//		}
//
//		for (int i = 0;i < n;i++) {
//			ans += arr[i];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}




//char s[110][2],arr[110];
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		memset(arr, 0, sizeof arr);
//		int l;
//		cin >> l;
//		for (int i = 0;i < l - 2;i++) {
//			scanf("%s", s[i]);
//		}
//		arr[0] = s[0][0];
//		arr[1] = s[0][1];
//		int cnt = 2;
//		for (int i = 0;i < l - 3;i++) {
//			if (s[i][1] == s[i + 1][0]) {
//				arr[cnt] = s[i+1][1];
//				cnt++;
//			}
//			else {
//				arr[cnt] = s[i + 1][0];
//				cnt++;
//				arr[cnt] = s[i + 1][1];
//				cnt++;
//			}
//		}
//		int sz = strlen(arr);
//		cout << arr;
//		while (sz < l) {
//			cout << 'a';
//			sz++;
//		}
//		cout << endl;
//	}
//	return 0;
//}




//
//int arr[10];
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		for (int i = 0;i < 7;i++) {
//			cin >> arr[i];
//		}
//		if (arr[0] + arr[1] == arr[2]) {
//			cout << arr[0] << ' ' << arr[1] << ' ' << arr[3]<<endl;
//		}
//		else {
//			cout << arr[0] << ' ' << arr[1] << ' ' << arr[2]<<endl;
//		}
//	}
//	return 0;
//}








//int main() {
//	int n, m;
//	cin >> n >> m;
//	if (n < m) {
//		cout << "bsa";
//	}
//	else {
//		if (n % (m + 1) == 0) {
//			cout << "bs";
//		}
//		else {
//			cout << "bsa";
//		}
//	}
//	return 0;
//}





//
//#include<map> 
//#define ll long long 
//
//map<ll, int> mp;
//ll m, z, p;
//ll a, b, c;
//
//ll msc(ll a, ll b)
//{
//    ll sum = 0;
//    while (b)
//    {
//        if (b % 2 == 1)
//            sum = (sum + a) % p;
//        b >>= 1;
//        a = (a + a) % p;
//    }
//    return sum;
//}
//
//ll msc(int a, int b)
//{
//    ll sum = 0;
//    while (b)
//    {
//        if (b % 2 == 1)
//            sum = (sum + a) % p;
//        b >>= 1;
//        a = (a + a) % p;
//    }
//    return sum;
//}
//
//ll qsm(ll x)
//{
//    ll sum = 1; ll aa = a;
//    while (x > 0)
//    {
//        if (x & 1)
//            sum = msc(sum, aa) % c;
//        x = x >> 1;
//        //    if(aa > 1e9)
//        aa = msc(aa, aa) % c;
//        //    else
//        //    	aa = (aa * aa) % c;  
//    }
//    return sum;
//}
//int main()
//{
//    cin >> z >> p;
//    mp.clear();
//    m = ceil(sqrt(p));
//    long long ans;
//    c = p;
//    a = 10;
//    b = (msc(9 % p, z) + 1) % p;
//    for (int i = 0; i <= m; i++)
//    {
//        if (i == 0)
//        {
//            ans = b % c;
//            mp[ans] = i;
//            continue;
//        }
//        ans = msc(ans, a) % c;
//        mp[ans] = i;
//    }
//    long long t = qsm(m);
//    ans = 1;
//    for (int i = 1; i <= m; i++)
//    {
//        ans = msc(ans, t) % c;
//        if (mp[ans])
//        {
//            int t = i * m - mp[ans];
//            cout << (t % c + c) % c;
//            p = true;
//            break;
//        }
//    }
//    return 0;
//}



//const int N = 1e6 + 10;
//int arr[N],d[N];
//int main() {
//	int n, t;
//	cin >> n >> t;
//	for (int i = 0;i < n;i++) {
//		cin >> arr[i];
//	}
//	while (t--) {
//		int l, r, c;
//		cin >> l >> r >> c;
//		d[l - 1] += c;
//		d[r] -= c;
//	}
//	int res = 0,ans=10000;
//	for (int i = 0;i < n;i++) {
//		res += d[i];
//		arr[i] = arr[i] + res;
//		ans = min(arr[i], ans);
//	}
//	cout << ans;
//	return 0;
//}







//const int N = 1010;
//int f[N], v[N], w[N];
//
//
//int main() {
//
//
//    int n, m;
//    cin >> m >> n;
//    for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//
//    for (int i = 1;i <= n;i++) {
//        for (int j = m;j >= v[i];j--) {
//            f[j] = max(f[j], f[j - v[i]] + w[i]);
//        }
//    }
//    cout << f[m];
//    return 0;
//
//}





//int main() {
//	long long n, arr1[200000], arr2[200000], c, count = 0;
//	scanf("%lld", &n);
//	for (int i = 0;i < n;i++) {
//		scanf("%lld", &arr1[i]);
//	}
//	scanf("%lld", &c);
//	for (int i = 0;i < n;i++) {
//		arr2[i] = arr1[i] + c;
//	}
//	sort(arr2, arr2 + n);
//	for (int i = 0;i < n;i++) {
//		if (binary_search(arr2, arr2 + n, arr1[i]))
//			count++;
//	}
//	printf("%lld", count);
//	return 0;
//}





//int n;
//int panduan(int x) {
//	for (int i = 2;i <= x / i;i++) {
//		if (x % i == 0)return 0;
//	}
//	return 1;
//}
//int main() {
//	cin >> n;
//	for (int i = 4;i <= n;i+=2) {
//		for (int j = 2;j < i - 1;j++) {
//			if (panduan(j) && panduan(i - j)) {
//				printf("%d=%d+%d\n", i, j, i - j);
//				break;
//			}
//		}
//	}
//	return 0;
//}








//char s[100];
//int main() {
//	cin >> s;
//	int sz = strlen(s);
//	for (int i = 0;i < sz;i++) {
//		switch (s[i]-'0')
//		{
//		case 1:
//			cout << "yi" << ' ';
//			break;
//		case 2:
//			cout << "er" << ' ';
//			break;
//		case 3:
//			cout << "san" << ' ';
//			break;
//		case 4:
//			cout << "si" << ' ';
//			break;
//		case 5:
//			cout << "wu" << ' ';
//			break;
//		case 6:
//			cout << "liu" << ' ';
//			break;
//		case 7:
//			cout << "qi" << ' ';
//			break;
//		case 8:
//			cout << "ba" << ' ';
//			break;
//		case 9:
//			cout << "jiu" << ' ';
//			break;
//		case 0:
//			cout << "ling" << ' ';
//			break;
//		default:
//			cout << "fu" << ' ';
//			break;
//		}
//	}
//	return 0;
//}







//const int N = 10;
//char g[N][N];
//int n, k,cnt;
//bool st[N];
//void dfs(int r,int K) {
//	if (K == 0) {
//		cnt++;
//		return;
//	}
//	for (int i = r;i < n;i++) {
//		for (int j = 0;j < n;j++) {
//			if (g[i][j] == '#' && !st[j]) {
//				st[j] = true;
//				dfs(r + 1, K - 1);
//				st[j] = false;
//			}
//		}
//	}
//}
//int main() {
//	while (1) {
//		cin >> n >> k;
//		cnt = 0;
//		if (n == -1 && k == -1)break;
//		for (int i = 0;i < n;i++) {
//			for (int j = 0;j < n;j++) {
//				cin >> g[i][j];
//			}
//		}
//		dfs(0,k);
//		cnt = cnt % (int)pow(2, 31);
//		cout << cnt << endl;
//	}
//	return 0;
//}





//typedef long long ll;
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		ll n, k,s,j;
//		j = 1;
//		cin >> n >> k;
//		s = n - k;
//		ll cnt = 0;
//		while (1) {
//			if (j >= k)break;
//			cnt++;
//			j *= 2;
//		}
//		s =s - j + k;
//		if (s < 0) {
//			;
//		}
//		else {
//			ll cao = s / k;
//			cnt += cao;
//			s = s - cao * k;
//			if (s > 0)cnt++;
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}






//const int N = 1e5 + 10;
//double a[2010], b[2010], ans;
//int p[N];
//int n;
//struct node {
//	int x1, x2;
//	double v;
//
//}e[N];
//int idx, cnt;
//bool cmp(node a, node b)
//{
//	return a.v < b.v;
//}
//double juli(int i, int j) {
//	double dx = a[i] - a[j];
//	double dy = b[i] - b[j];
//	return sqrt(dx * dx + dy * dy);
//}
//int find(int x) {
//	if (x != p[x])p[x] = find(p[x]);
//	return p[x];
//}
//
//int main() {
//	while (1) {
//		++cnt;
//		cin >> n;
//		if (n == 0)break;
//		for (int i = 1;i <= n;i++)p[i] = i;
//		for (int i = 1;i <= n;i++)cin >> a[i] >> b[i];
//		for (int i = 1;i <= n;i++) {
//			for (int j = i + 1;j <= n;j++) {
//				e[++idx].x1 = i, e[idx].x2 = j, e[idx].v = juli(i, j);
//			}
//		}
//		sort(e + 1, e + idx + 1, cmp);
//		for (int i = 1;i <= idx;i++) {
//			if (find(e[i].x1) != find(e[i].x2)) {
//				p[find(e[i].x1)] = find(e[i].x2);
//				if (find(1) == find(2)) {
//					ans = e[i].v;
//					break;
//				}
//			}
//		}
//		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cnt, ans);
//	}
//	return 0;
//}





//const int N = 40;
//int arr[N][N][N];
//char s[N][N][N];
//bool st[N][N][N];
//int x, y, z;
//int main() {
//	int a, b, c;
//	while (1) {
//		cin >> a >> b >> c;
//		if (a == 0 && b == 0 && c == 0)break;
//		for (int i = 1;i <= a;i++) {
//			for (int j = 1;j <= b;j++) {
//				for (int k = 1;k <= c;k++) {
//					cin >> s[i][j][k];
//					if (s[i][j][k] == 'S') {
//						x = i, y = j, z = k;
//					}
//				}
//			}
//		}
//		queue<int>q;
//		q.push(y);
//		q.push(z);
//		q.push(x);
//		int dx[6]{ 0,1,0,-1,0,0 }, dy[6] = { 1,0,-1,0,0,0 }, dz[6]={ 0,0,0,0,1,-1 };
//		int cnt = 0;
//		while (!q.empty()) {
//			int ddx = q.front();
//			q.pop();
//			int ddy = q.front();
//			q.pop();
//			int ddz = q.front();
//			q.pop();
//			int flag = 0;
//			for (int i = 0;i < 6;i++) {
//				int dddx = ddx + dx[i], dddy = ddy + dy[i], dddz = ddz + dz[i];
//				if (dddx<1 || dddy<1 || dddz<1 || dddx>b || dddy>c || dddz>a&&!st[dddx][dddy][dddz]&&s[dddx][dddy][dddz]!='#') {
//					q.push(dddx), q.push(dddy), q.push(dddz);
//					st[dddx][dddy][dddz] = true;
//					flag = 1;
//					arr[dddx][dddy][dddz] = cnt + 1;
//				}
//			}
//			if (flag)cnt++;
//
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}




//char a[200];
//int main() {
//	int n;
//    scanf("%d%s", &n, a);
//    for (int i = 0;i <= n - 1;)
//    {
//        if (i + 2 <= n - 1 && a[i] == 'o' && a[i + 1] == 'g' && a[i + 2] == 'o')
//        {
//            printf("***");
//            i = i + 3;
//            while (i + 1 <= n - 1 && a[i] == 'g' && a[i + 1] == 'o')i += 2;
//        }
//        else printf("%c", a[i]), i++;
//    }
//    printf("\n");
//	
//	return 0;
//}




////
//int n, c, qaq;
//double a[2010], b[2010], ans;
//struct kkk {
//    int x, y;double v;
//}bb[1000000];int tot;
//bool cmp(kkk a, kkk b)
//{
//    return a.v < b.v;
//}
//int fa[2010];
//int get(int x) { return fa[x] == x ? fa[x] : fa[x] = get(fa[x]); }
//double turn(int x, int y)
//{
//    double dx = a[x] - a[y];
//    double dy = b[x] - b[y];
//    return sqrt(dx * dx + dy * dy);
//}
//int main()
//{
//    while (1)
//    {
//        ++qaq;
//        scanf("%d", &n);
//        if (n == 0) break;
//        tot = 0;
//        for (int i = 1;i <= n;i++)
//            fa[i] = i;
//        for (int i = 1;i <= n;i++)
//            scanf("%lf %lf", &a[i], &b[i]);
//
//        for (int i = 1;i <= n;i++)
//            for (int j = i + 1;j <= n;j++)
//                bb[++tot].x = i, bb[tot].y = j, bb[tot].v = turn(i, j);
//
//        sort(bb + 1, bb + tot + 1, cmp);
//
//        for (int i = 1;i <= tot;i++)
//            if (get(bb[i].x) != get(bb[i].y))
//            {
//                fa[get(bb[i].x)] = get(bb[i].y);
//                if (get(1) == get(2))
//                {
//                    ans = bb[i].v;
//                    break;
//                }
//            }
//        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", qaq, ans);
//    }
//    return 0;
//}







//typedef long long ll;
//int main() {
//	int t,n,m;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		ll ans=1;
//		for (int i = n - 1;i >n - m;i--) {
//			ans *= i;
//		}
//		for (int i = m - 1;i >= 1;i--) {
//			ans /= i;
//		}
//		cout << ans << endl;
//	}
//}









//char str[1000];
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> str;
//		int sz = strlen(str);
//		if ( sz== 1 && str[0] == '1')cout << 2 << endl;
//		else cout << str << endl;
//	}
//}





//int main() {
//	int t, m, n;
//	cin >> t;
//	while (t--) {
//		cin >> str >> m;
//		int sz = strlen(str);
//		n = str[sz - 1] - '0' + 10 * (str[sz - 2] - '0');
//		if (m == 5) {
//			for (int i = sz - 3;i >= 0;i--) {
//				n += 4 * (str[i] - '0');
//			}
//		}
//		if (m == 2) {
//			for (int i = sz - 3;i >= 0;i--) {
//				n += str[i] - '0';
//			}
//		}
//		if (n % (m + 1) == 0)cout << "Nolv" << endl;
//		else cout << "Hibiki" << endl;
//	}
//	return 0;
//}





//typedef long long ll;
//const int N = 1e5 + 10;
//ll arr[N];
//int main() {
//	ll m;
//	cin >> arr[0] >> arr[1] >> arr[2]>>m;
//	if (arr[0] >= m)cout << 1;
//	else if (arr[1] >= m)cout << 2;
//	else if (arr[2] >= m)cout << 3;
//	else {
//		for (int i = 3;i < N;i++) {
//			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
//			if (arr[i] >= m) {
//				cout << i + 1;
//				break;
//			}
//		}
//	}
//	return 0;
//}









//const int N = 1e5 + 10;
//int e[N], ne[N],h[N], idx;
//int n, m;
//int dist[N];
//bool st[N];
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int spfa() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	st[1] = true;
//	queue<int>q;
//	q.push(1);
//	while (!q.empty()) {
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//		for (int i = h[t];i != -1;i = ne[i]) {
//			int j = e[i];
//			if ( dist[j] > dist[t] + 1) {
//				dist[j] = dist[t] + 1;
//				if (!st[j]) {
//					q.push(j);
//					st[j] = true;
//				}
//			}
//		}
//	}
//	return dist[n];
//}
//int main() {
//	memset(h, -1, sizeof h);
//	cin >> m >> n;
//	for (int i = 1;i <= m;i++) {
//		int a;
//		cin >> a;
//		if (i - a > 0)add(i, i - a);
//		add(i, i + a);
//	}
//	if (spfa() == 0x3f3f3f3f)cout << "AlbionAlbion!";
//	else cout << spfa();
//	return 0;
//}