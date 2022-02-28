#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include<vector>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') v.push_back(i);
    }
    int k, w, q;
    cin >> k >> w >> q;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int mmp = v[i] + k;
        int idx = lower_bound(v.begin(), v.end(), mmp) - v.begin();
        int j, kk;
        //         if (abs(v[min((int)(v.size() - 1), idx + 1)] - k) >= abs(v[idx] - k)) j = idx;
        //         else j = idx + 1;
        j = idx;
        if (j + 1 < v.size())
        {
            if (abs(v[j + 1] - k) < abs(v[j] - k)) j++;
        }
        if (j - 1 >= 0)
        {
            if (j - 1 != i && abs(v[j - 1] - k) < abs(v[j] - k)) j--;
        }
        mmp = v[j] + k;
        idx = lower_bound(v.begin(), v.end(), mmp) - v.begin();
        //         if (abs(v[min((int)(v.size() - 1), idx + 1)] - k) >= abs(v[idx] - k)) kk = idx;
        //         else kk = idx + 1;
        kk = idx;
        if (kk + 1 < v.size())
        {
            if (abs(v[kk + 1] - k) < abs(v[kk] - k)) kk++;
        }
        if (kk - 1 >= 0)
        {
            if (kk - 1 != j && abs(v[kk - 1] - k) < abs(v[kk] - k)) kk--;
        }
        int res = 0;
        if (j < v.size()) res += max((int)0, w - q * abs(v[j] - v[i] - k));
        if (kk < v.size()) res += max((int)0, w - q * abs(v[kk] - v[j] - k));
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include<map>
//#include<assert.h>
//#include<vector>
//using i64 = long long;
//
//constexpr i64 inf = 1E18;
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int n, k;
//    std::cin >> n >> k;
//
//    std::vector<i64> dp(k, -inf);
//    dp[0] = 0;
//    for (int i = 0; i < n; i++) {
//        int a, b;
//        std::cin >> a >> b;
//
//        auto ndp = dp;
//        for (int j = 0; j < k; j++) {
//            int nj = (j + a) % k;
//            ndp[nj] = std::max(ndp[nj], dp[j] + b);
//        }
//
//        dp = ndp;
//    }
//
//    auto ans = dp[0];
//    if (ans == 0) {
//        ans = -1;
//    }
//
//    std::cout << ans << "\n";
//
//    return 0;
//}
//using namespace std;
//typedef long long LL;
//#define int long long
//const int N = 3e4 + 10, mod = 1000000007;
//bool st[N]; 
//int prime[N], cnt, sum[N];
//bool isprime(int n)
//{
//    for (int i = 2; i <= n / i; i++)
//    {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//void solve(int n)
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i])prime[cnt++] = i;
//        for (int j = 0; prime[j] <= n / i; j++)
//        {
//            st[prime[j] * i] = true;
//            if (prime[j] % i == 0)break;
//        }
//    }
//}
//
//int gcd(int a, int b)
//{
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//LL qmi(int a, int b, int p)
//{
//    LL res = 1;
//    while (b)
//    {
//        if (b & 1) res = res * a % p;
//        a = a * (LL)a % p;
//        b >>= 1;
//    }
//    return res;
//}
//int mul(int a, int b)
//{
//    int p = mod, res = 0;
//    while (a) {
//        if (a & 1) res = (res + b) % p;
//        b = (b + b) % p;
//        a >>= 1;
//    }
//    return res;
//}
//signed main()
//{
//    int l, r;
//    cin >> l >> r;
//    memset(st, 0, sizeof st);
//    solve(30010);
//    st[1] = false;
//    int f = 0;
//    for (int i = l; i <= r; i++)
//    {
//        if (st[i])
//        {
//            f = 1;
//        }
//    }
//    if (!f)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    for (int i = l; i <= r; i++)
//    {
//        if (st[i])
//        {
//            //cout << i << endl;
//            int ii = i;
//            for (int j = 0; prime[j] <= i / prime[j]; j++)
//            {
//                int s = 0;
//                if (ii % prime[j] == 0)
//                {
//                    while (ii % prime[j] == 0)
//                    {
//                        s++;
//                        ii /= prime[j];
//                    }
//                    int cnm = sum[prime[j]];
//                    sum[prime[j]] = max(s, cnm);
//                    cout << sum[prime[j]] << endl;
//                }
//
//            }
//            if (ii) sum[ii] = max((int)sum[ii], (int)1);
//        }
//    }
//    int res = 1;
//    for (int i = 1; i <= N; i++)
//    {
//        //cout << sum[i] << endl;
//        if (sum[i]) res = res * qmi(i, sum[i], mod) % mod;
//    }
//    cout << res << endl;
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include<vector>
//#include <algorithm>
//#include<map>
//using namespace std;
//
//const int N = 2e5 + 10;
//char s[N];
//
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int>r, p;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> s[i];
//        if (s[i] == 'R') r.push_back(i);
//        else if (s[i] == 'P') p.push_back(i);
//    }
//    int ans = 0, last = 1;
//    for (int t : p)
//    {
//        for (int i = last; i <= t; i++)
//        {
//            int st = i;
//            int idx = upper_bound(r.begin(), r.end(), i) - r.begin() - 1;
//            while (r[idx] < i) idx++;
//            if (idx + k - 1 >= r.size())break;
//            int l = r[idx + k - 1];
//            int R = t - 1;
//            if (R >= l) ans += R - l + 1;
//        }
//        last = t + 1;
//    }
//    for (int i = last; i <= n; i++)
//    {
//        int st = i;
//        int idx = upper_bound(r.begin(), r.end(), i) - r.begin() - 1;
//        while (r[idx] < i) idx++;
//        if (idx + k - 1 >= r.size())break;
//        int l = r[idx + k - 1];
//        int R = n;
//        if (R >= l) ans += R - l + 1;
//    }
//    cout << ans << endl;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include<map>
//using namespace std;
//
//#define int long long
//const int N = 1e5 + 10;
//typedef pair<int, char>PIC;
//PIC a[N];
//
//signed main()
//{
//    int n, t;
//    cin >> n >> t;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i].second;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i].first;
//    }
//    sort(a, a + n);
//    int st = a[0].first, ans = 0, res = a[0].first, mmp = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (a[i].second == 'B')
//        {
//            if (a[i].first > res)
//                mmp += a[i].first - res;
//            res = a[i].first + t;
//        }
//        else
//        {
//            if (i != 0 && a[i - 1].second != 'R') ans = ans + max((int)0, min(res, a[i].first) - st);
//            else;
//            st = a[i].first + t;
//            if (a[i + 1].second == 'B') st = max(st, a[i + 1].first);
//            res = st;
//        }
//    }
//    ans += res - st;
//    cout << ans - mmp << endl;
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include<map>
//using namespace std;
//
//const int N = 3e4 + 10, mod = 1000000007;
//int prime[N], cnt;
//bool st[N];
//
//void solve(int n)
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i])
//        {
//            prime[cnt++] = i;
//            for (int j = 2 * i; j <= n; j += i)
//            {
//                st[j] = true;
//            }
//        }
//    }
//    //     for(int i = 2; i <= n; i ++ )
//    //     {
//    //         if(!st[i])prime[cnt ++ ] = i;
//    //         for(int j = 0; prime[j] <= n / i; j++ )
//    //         {
//    //             st[prime[j] * i]=true;
//    //             if(prime[j] % i == 0)break;
//    //         }
//    //     }
//}
//
//int gcd(int a, int b)
//{
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//int main()
//{
//    int l, r;
//    cin >> l >> r;
//    solve(r);
//    st[1] = true;
//    int res = l;
//    for (int i = l; i <= r; i++)
//    {
//        if (st[i])
//        {
//            res = i;
//            break;
//        }
//    }
//    for (int i = res; i <= r; i++)
//    {
//        if (st[i])
//        {
//            res = gcd(res, i);
//        }
//    }
//    //cout << res << endl;
//    int ans = 1, f = 0;
//    for (int i = l; i <= r; i++)
//    {
//        if (st[i])
//        {
//            ans = (ans * i) % mod;
//            if (!f) ans = ans / res;
//            f = 1;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

//const int N = 2e5 + 10, M = 10;
//int a[M][N];
//typedef pair<int, int>PII;
//signed main()
//{
//	int t;
//	cin >> t;
//	map<int, int>mp;
//	for (int i = 0; i < t; i++)
//	{
//		int n;
//		cin >> n;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//			mp[a[i][j]]++;
//		}
//	}
//	int f = 1;
//	for (auto t : mp)
//	{
//		if (t.second % 2) f = 0;
//	}
//	if (f)
//	{
//
//	}
//	else
//	{
//		cout << "NO" << endl;
//	}
//	return 0;
//}

//typedef pair<int, int>PII;
//map<PII, int>mp;
//
//int gcd(int x, int y) 
//{
//    return y == 0 ? x : gcd(y, x % y);
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        mp.clear();
//        cin >> n;
//        int d = 0, k = 0;
//        string t;
//        cin >> t;
//        for (int i = 0;i < n;i++)
//        {
//            if (t[i] == 'D')d++;
//            else k++;
//            int x, y;
//            x = d / gcd(d, k), y = k / gcd(d, k);
//            PII p = { x,y };
//            mp[p]++;
//            if (d == 0)cout << k << endl;
//            else if (k == 0)cout << d << endl;
//            else cout << mp[p] << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}



//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include<map>
//using namespace std;
//
//string s, t;
//int len1, len2;
//bool flag;
//
//bool dfs(int idx, int u)
//{
//	if (u == len2) return true;
//	if (idx < len1 - 1 && s[idx + 1] == t[u] && flag)
//	{
//		if (dfs(idx + 1, u + 1))return true;
//	}
//	if (idx > 0 && s[idx - 1] == t[u])
//	{
//		flag = false;
//		if (dfs(idx - 1, u + 1)) return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int q;
//	cin >> q;
//	while (q--)
//	{
//		cin >> s >> t;
//		len1 = s.size();
//		len2 = t.size();
//		int f = 1;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == t[0])
//			{
//				flag = true;
//				if (dfs(i, 1))
//				{
//					puts("YES");
//					f = 0;
//					break;
//				}
//			}
//		}
//		if (f) puts("NO");
//	}
//	return 0;
//}



//typedef pair<int, int> PII;
//
//const int N = 110;
//int a[N], b[N];
//int n, m;
//PII ff[N], gg[N];
//bool cmp(PII a, PII b)
//{
//    return a.first > b.first;
//}
//int solve1(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//        }
//    }
//    return ans;
//}
//int solve2(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            
//        }
//    }
//    return ans;
//}
//int solve3(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//            
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//        }
//    }
//    return ans;
//}
//int solve4(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//        }
//    }
//    return ans;
//}
//int solve5(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//
//            
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//        }
//    }
//    return ans;
//}
//int solve6(PII gg[], map<int, int>& f)
//{
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (gg[i].first > 0)
//        {
//            if (gg[i].first >= f[gg[i].second - 1])
//            {
//                ans += f[gg[i].second - 1];
//                gg[i].first -= f[gg[i].second - 1];
//                f[gg[i].second - 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second - 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second])
//            {
//                ans += f[gg[i].second];
//                gg[i].first -= f[gg[i].second];
//                f[gg[i].second] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second] -= gg[i].first;
//                gg[i].first = 0;
//            }
//            if (gg[i].first >= f[gg[i].second + 1])
//            {
//                ans += f[gg[i].second + 1];
//                gg[i].first -= f[gg[i].second + 1];
//                f[gg[i].second + 1] = 0;
//            }
//            else
//            {
//                ans += gg[i].first;
//                f[gg[i].second + 1] -= gg[i].first;
//                gg[i].first = 0;
//            }
//
//
//            
//        }
//    }
//    return ans;
//}
//int main()
//{
//    cin >> n;
//    map<int, int>g, f;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//        g[a[i]]++;
//    }
//    cin >> m;
//    for (int i = 0; i < m; i++)
//    {
//        cin >> b[i];
//        f[b[i]]++;
//    }
//    int i = 0;
//    for (auto t : g)
//    {
//        gg[i] = { t.second, t.first };
//        i++;
//    }
//    sort(gg, gg + 110, cmp);
//    cout << max({ solve1(gg, f), solve2(gg, f),solve3(gg, f),solve4(gg, f),solve5(gg, f),solve6(gg, f) }) << endl;
//    return 0;
//}

//string s;
//int a()
//{
//	int a1 = 5, b1 = 5, a1s = 0, b1s = 0;
//	for (int i = 0;i <= 9;i++)
//	{
//		if (i % 2 == 0)
//		{
//			a1--;
//			if (s[i] == '?')
//				a1s++;	
//			else
//				a1s += s[i] - '0';
//		}
//		else
//		{
//			b1--;
//			if (s[i] == '?');
//			else
//				b1s += s[i] - '0';
//		}
//		if (b1s + b1 < a1s) return i + 1;
//	}
//	return 10;
//}
//int b()
//{
//	int a1 = 5, b1 = 5, a1s = 0, b1s = 0;
//	for (int i = 0;i <= 9;i++)
//	{
//		if (i % 2 == 0)
//		{
//			a1--;
//			if (s[i] == '?')
//			{
//			}
//			else
//				a1s += s[i] - '0';
//		}
//		else
//		{
//			b1--;
//			if (s[i] == '?')
//			{
//				b1s++;
//			}
//			else
//				b1s += s[i] - '0';
//		}
//		if (a1s + a1 < b1s)return i + 1;
//	}
//	return 10;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> s;
//		cout << min(a(), b()) << endl;
//	}
//}



//const int N = 1e5 + 10;
//int f[N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		map<int, int>mp;
//		vector<int>v;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> f[i];
//			mp[f[i]]++;
//			if (f[i] < 0) v.push_back(f[i]);
//		}
//		int len = 0, ans = 0;
//
//		for (auto t : mp)
//		{
//			if (t.first < 0)
//			{
//				ans += t.second;
//			}
//			else if (t.first == 0) len = t.second;
//		}
//		if (len)
//		{
//			v.push_back(0);
//			ans += len;
//		}
//		int minv = 1e9 + 10;
//		if (v.size())
//		{
//			sort(v.begin(), v.end());
//			for (int i = 0; i < v.size() - 1; i++)
//			{
//				minv = min(minv, v[i + 1] - v[i]);
//			}
//			if (len > 1) minv = 0;
//		}
//		for (auto t : mp)
//		{
//			if (t.first > 0 && t.first <= minv)
//			{
//				ans++;
//				break;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}




//const int N = 2e5 + 10;
//long long f[N];
//long long n, k, sum;
//bool check(long long x)
//{
//	if (sum - x <= k) return true;
//	long long a, b, j;
//	j = 0;
//	b = n - 1;
//	a = x - b;
//	if (a < 0) b += a, a = 0, j = n - b - 1;
//	while (1)
//	{
//		if (b > 0 && b > (f[j + 1] - f[0] + a)) j++, b--, a++;
//		else break;
//	}
//	long long res = 0, cnm = sum;
//	for (int i = n - 1; i > (n - 1) - b; i--)
//	{
//		cnm = cnm - (f[i] - f[0] + a);
//		if (cnm <= k) return true;
//	}
//	cnm -= a;
//	if (cnm <= k) return true;
//	return false;
//}
//signed main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> k;
//		sum = 0;
//		for (int i = 0; i < n; i++) cin >> f[i], sum += f[i];
//		sort(f, f + n);
//		long long l = 0, r = 1e15;
//		while (l < r)
//		{
//			long long mid = l + r + 1 >> 1;
//			if (check(mid)) r = mid - 1;
//			else l = mid;
//		}
//		if (check(r)) cout << r << endl;
//		else cout << r + 1 << endl;
//	}
//	return 0;
//}

//const int N = 1e3 + 10;
//int dp[N], b[N], c[N];
//
//int main()
//{
//	memset(dp, 0x3f, sizeof dp);
//	dp[1] = 0;
//	dp[0] = 1;
//	for (int i = 1; i < N; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			if (i + i / j < N) dp[i + i / j] = min(dp[i] + 1, dp[i + i / j]);
//		}
//	}
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(b, 0, sizeof b);
//		memset(c, 0, sizeof c);
//		int n, k;
//		cin >> n >> k;
//		k = min(12 * n, k);
//		vector<int>f(k + 1, 0);
//		for (int i = 1; i <= n; i++) cin >> b[i];
//		for (int i = 1; i <= n; i++) cin >> c[i];
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = k; j >= dp[b[i]]; j--)
//				f[j] = max(f[j], f[j - dp[b[i]]] + c[i]);
//		}
//		cout << f[k] << endl;
//	}
//	return 0;
//}



//#define int long long
//
//signed main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int hc, dc, hm, dm;
//		cin >> hc >> dc >> hm >> dm;
//		int ci, w, a;
//		cin >> ci >> w >> a;
//		int f = 1;
//		for (int i = 0; i <= ci; i++)
//		{
//			int h = hc + i * a;
//			int d = dc + (ci - i) * w;
//			int cnt = hm / d - (hm % d == 0);
//			int cnt2 = h / dm - (h % dm == 0);
//			if (cnt <= cnt2)
//			{
//				cout << "YES" << endl;
//				f = 0;
//				break;
//			}
//		}
//		if (f) puts("NO");
//	}
//	return 0;
//}






//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int ans = b - a;
//		for (int i = a; i <= b; i++)
//		{
//			ans = min(ans, (i | b) + i - a - b + 1);
//		}
//		int t = ans;
//		for (int i = b + 1, j = 1; j <= t; i++, j++)
//		{
//			ans = min(ans, (i | a) + 1 - b);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int t = a ^ b;
//		int c = a | b;
//		if (c != b)
//		{
//			int zui = 0;
//			for (int i = 31; i >= 0; i--)
//			{
//				if ((1 << i) & b)
//				{
//					zui = i;
//					break;
//				}
//			}
//			int tt = 1 << zui;
//			if (t - tt > 0) t -= tt;
//			for (int i = 31; i >= 0; i--)
//			{
//				if ((1 << i) & t)
//				{
//					zui = i;
//					break;
//				}
//			}
//			int cnm = 0, mmp = 0;
//			for (int i = 0; i <= zui; i++)
//			{
//				if ((b >> i) & 1) cnm += pow(2, i);
//			}
//			for (int i = 0; i <= zui; i++)
//			{
//				if ((a >> i) & 1) mmp += pow(2, i);
//			}
//			int d = t - max(cnm, mmp);
//			cout << min(b - a, d + 1) << endl;
//		}
//		else
//		{
//			cout << 1 << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, k;
//		cin >> n >> k;
//		if (n == 4)
//		{
//			if (k == 3) cout << -1 << endl;
//			else if (k == 0)
//			{
//				cout << 0 << ' ' << n - 1 << endl;
//				cout << n - 2 << ' ' << n - 3 << endl;
//			}
//			else
//			{
//				cout << n - 1 << ' ' << k << endl;
//				cout << 0 << ' ' << n - 1 - k << endl;
//			}
//		}
//		else if (k > 0 && k < n - 1)
//		{
//			cout << n - 1 << ' ' << k << endl;
//			cout << 0 << ' ' << n - 1 - k << endl;
//			for (int i = 1, j = n - 2; i < j; i++, j--)
//			{
//				if(i != k && j != k) cout << i << ' ' << j << endl;
//			}
// 		}
//		else if (k == 0)
//		{
//			for (int i = 0, j = n - 1; i < j; i++, j--)
//			{
//				cout << i << ' ' << j << endl;
//			}
//		}
//		else
//		{
//			cout << n - 1 << ' ' << n - 2 << endl;
//			cout << 0 << ' ' << n - 3 << endl;
//			cout << 1 << ' ' << 3 << endl;
//			cout << 2 << ' ' << n - 4 << endl;
//			for (int i = 4, j = n - 5; i < j; i++, j--)
//			{
//				cout << i << ' ' << j << endl;
//			}
//		}
//	}
//	return 0;
//}


//const int N = 2e5 + 10;
//int a[N], b[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//        int n;
//        cin >> n;
//        for (int i = 0; i < n; i++) cin >> a[i];
//        int l = 0;
//        for (int i = n - 1; i >= 0; i--)
//        {
//            if (a[i] == a[n - 1]) l++;
//            else break;
//        }
//        int ans = 0;
//        while (l < n)
//        {
//            l *= 2;
//            for (int i = n - l - 1; i >= 0; i--)
//            {
//                if (a[i] == a[n - 1])
//                {
//                    l++;
//                }
//                else break;
//            }
//            ans++;
//        }
//        cout << ans << endl;
//	}
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#include<math.h>
//#include<vector>
//#include<map>
//#include<set>
//using namespace std;
//
//
//
//
//const int N = 2e5 + 10;
//int a[N], b[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//		}
//		
//	}
//	return 0;
//}




//const int N = 110;
//int a[N], b[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int m1 = 0, m2 = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin >> b[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (a[i] < b[i]) swap(a[i], b[i]);
//		}
//		sort(a, a + n);
//		sort(b, b + n);
//		m1 = a[n - 1], m2 = b[n - 1];
//		cout << m1 * m2 << endl;
//	}
//	return 0;
//}


//#define int long long
//const int N = 2e5 + 10;
//int h[N], hh[N];
//
//signed main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++) cin >> h[i];
//		int l = 1, r = 1e9;
//		while (l < r)//二分
//		{
//			int mid = l + r + 1 >> 1;
//			int f = 1;
//			for (int i = 1; i <= n; i++) hh[i] = h[i];//拷贝h数组，防止h数组被改变
//			for (int i = n; i >= 3; i--)
//			{
//				if (hh[i] >= mid)//当前大于mid，所以可以将大于的部分移动到前面两堆
//				{
//					hh[i - 1] += min(h[i], hh[i] - mid) / 3;
//					//取min的原因在于，他是从后往前的，所以对于原本的i堆应最多移动h[i]个石子
//					hh[i - 2] += min(h[i], hh[i] - mid) / 3 * 2;
//				}
//				else
//				{
//					f = 0;
//					break;
//				}
//			}
//			if (hh[1] < mid || hh[2] < mid || f == 0)
//			{
//				r = mid - 1;
//			}
//			else l = mid;
//		}
//		cout << l << endl;
//	}
//	return 0;
//}






//typedef pair<int, int>PII;
//typedef long long ll;
//const int N = 1e6 + 10;
//string ans[N], res[N];
//
//bool check(string s1, string s2)
//{
//	return s1 == s2;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1;i <= n; i++) cin >> ans[i];
//	for (int i = 1; i <= m; i++) cin >> res[i];
//	int i = 1, j = 1;
//	while (i <= n)
//	{
//		if (check(ans[i], res[j]))
//		{
//			i++;
//			j++;
//			cout << "YES" << endl;
//		}
//		else
//		{
//			i++;
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}




//int main()
//{
//	int t;
//	cin >> t;
//	map<string, int>mp;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int f = 0;
//		for (int i = 0; i < n; i++)
//		{
//			string res;
//			cin >> res;
//			mp[res]++;
//			if (res.size() == 1) f = 1;
//			reverse(res.begin(), res.end());
//			if (res.size() % 2 == 1)
//			{
//				if (mp[res.substr(0, 2)] >= 1) f = 1;
//			}
//			else
//			{
//				for (int j = 0; j < 26; j++)
//				{
//					char ans = ('a' + j);
//					if (mp[res + ans] >= 1) f = 1;
//				}
//			}
//			if (mp[res] >= 1) f = 1;
//		}
//		if (f) cout << "YES" << endl;
//		else cout << "NO" << endl;
//		mp.clear();
//	}
//	return 0;
//}




//const int N = 2e5 + 10;
//int a[N], f[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//			f[a[i]]++;
//		}
//		vector<int>ans;
//		set<int>s;
//		int mex = 0;
//		for (int i = 0; i <= n;i++)
//		{
//			if (f[i]) s.insert(i);
//			else
//			{
//				mex = i;
//				if(i) ans.push_back(i);
//				break;
//			}
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			if (s.size() == 0)
//			{
//				ans.push_back(mex);
//				for (int i = 0; i < mex;i++)s.insert(i);
//			}
//			f[a[i]]--;
//			if (s.find(a[i]) != s.end()) s.erase(a[i]);
//			if (f[a[i]] == 0) mex = min(mex, a[i]);
//		}
//		cout << ans.size() << endl;
//		for (int i = 0; i < ans.size();i++)cout << ans[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}





//const int N = 2e5 + 10;
//int a[N], s[N], ans[N];
//bool ck[N];
//
//bool check(int x, int res)
//{
//	for (int i = 0; i <= res; i ++) ck[i] = 0;
//	for (int i = 0; i <= x; i++)
//	{
//		if(a[i] != -1)ck[a[i]] = true;
//	}
//	for (int i = 0; i < res; i++)
//	{
//		if (!ck[i]) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 0; i <= n; i++)s[i] = 0;
//		for (int i = 0; i < n; i++) cin >> a[i], s[a[i]]++;
//		int i = 0, cc = 0;
//		if (s[0] == 0)
//		{
//			cout << n << endl;
//			for (int i = 0;i < n; i++)
//				cout << 0 << ' ';
//			cout << endl;
//			continue;
//		}
//		while (i < n)
//		{
//			int res = 0;
//			for (int j = 0; j <= n; j++)
//			{
//				if (s[j]>0)res++;
//				else break;
//			}
//			if (res == 0)
//			{
//				break;
//			}
//			int l = i, r = n;
//			while (l < r)
//			{
//				int mid = l + r >> 1;
//				if (check(mid, res)) r = mid;
//				else l = mid + 1;
//			}
//			s[a[l]]--;
//			i = l;
//			for (int i = 0; i < l; i++) s[a[i]]--,a[i] = -1;
//			ans[cc++] = res;
//		}
//		for (int j = i; j < n; j++)ans[cc++] = 0;
//		if (i != 0) cc--;
//		cout << cc << endl;
//		for (int j = 0; j < cc;j++)cout << ans[j] << ' ';
//		cout << endl;
//	}
//	return 0;
//}



//typedef pair<int, int>PII;
//const int N = 110;
//int a[N], b[N];
//PII c[N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int l, r, k, res = 0;
//		cin >> l >> r >> k;
//		res = r - l + 1;
//		if (l == r && l != 1)
//		{
//			puts("YES");
//			continue;
//		}
//		if (l % 2 == 1) res++;
//		if (res / 2 <= k) puts("YES");
//		else puts("NO");
//	}
//	return 0;
//}





//#define int long long
//signed main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, l, r, w;
//		cin >> n;
//		int minl = 1e18, minr = -1e18, lw, rw,W,ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> l >> r >> w;
//			if (l < minl)
//			{
//				minl = l;
//				lw = w;
//				W = 1e18;
//			}
//			if (minl == l)
//			{
//				lw = min(lw, w);
//			}
//			if (minr == r)
//			{
//				rw = min(rw, w);
//			}
//			if (r > minr)
//			{
//				minr = r;
//				rw = w;
//				W = 1e18;
//			}
//			if (minl == l && minr == r)
//			{
//				W = min(W, w);
//			}
//			ans = min(W, rw + lw);
//			cout << ans << endl;
//		}
//		
//	}
//	return 0;
//}



//typedef long long ll;
//const int N = 110;
//ll a[N], b[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> b[i];
//		}
//		for (int i = n - 1; i; i--) {
//			b[i] = max(b[i], b[i + 1] - (a[i + 1] - a[i]));
//		}
//		ll ans = 0, last = -1;
//		for (int i = 1; i <= n; i++)
//		{
//			if (i - 1)
//			{
//				ll x = a[i], y = b[i];
//				if (x - a[i - 1] < y)
//				{
//					ans = ans + (2 * last + 1 + x - a[i - 1]) * (x - a[i - 1]) / 2;
//					last = last + x - a[i - 1];
//				}
//				else
//				{
//					ans = ans + (b[i] + 1) * b[i] / 2;
//					last = b[i];
//				}
//			}
//			else
//			{
//				ans = ans + (b[i] + 1) * b[i] / 2;
//				last = b[i];
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		sort(s.begin(), s.end());
//		cout << s << endl;
//	}
//	return 0;
//}


//const int N = 110;
//typedef long long ll;
//ll ans;
//ll a[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		ans = 0;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//		}
//		ll last = -1;
//		for (int i = 1; i <= n; i++)
//		{
//			ll x;
//			cin >> x;
//			ll y = last;
//			int ff = 0;
//			if (i - 1)
//			{
//				if ((2 * y + 1 + a[i] - a[i - 1]) * (a[i] - a[i - 1])  > ((1 + x) * x)  && x < (a[i] - a[i - 1])) ans = ans + (1 + x) * x / 2, last = x, ff = 1;
//				else
//				{
//					ans = ans + (2 * y + 1 + a[i] - a[i - 1]) * (a[i] - a[i - 1]) / 2;
//				}
//			}
//			else ans += (1 + x) * x / 2, last = x, ff = 1;
//			if(a[i] == x) ans = (1 + x) * x / 2, last = x, ff = 1;
//			if(!ff)last = a[i] - a[i - 1] + y;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		int f = 1;
//		for (int i = s.size() - 2; i >= 0; i--)
//		{
//			int x = s[i] + s[i + 1] - '0' - '0';
//			if (x >= 10)
//			{
//				s[i] = '1';
//				s[i + 1] = x - 10 + '0';
//				f = 0;
//				break;
//			}
//		}
//		if (f)
//		{
//			cout << s[0] + s[1] - '0' - '0';
//			
//			for (int i = 2; i < s.size(); i++)
//				cout << s[i];
//			cout << endl;
//		}
//		else cout << s << endl;
//	}
//	return 0;
//}





//const int N = 1e6 + 10;
//int a[N];
//
//int gcd(int a, int b)
//{
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int x;
//        cin >> x;
//        a[x]++;
//    }
//    int ans = 0;
//    for (int i = N; i >= 1; i--)
//    {
//        if (a[i]) continue;
//        int t = 0;
//        for (int j = i; j <= N; j += i)
//        {
//            if (a[j]) t = gcd(t, j);
//        }
//        if (t == i) ans++;
//    }
//    cout << ans << endl;
//    return 0;
//}




//typedef pair<int, int>PII;
//map<PII, int>mp;
//const int N = 1e5 + 10, M = 2e5 + 10;
//int rd[N], cd[N];
//int e[M], ne[M], h[N], idx;
//int n,dist[N];
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//bool st[N];
//void spfa()
//{
//	queue<PII>q;
//	memset(st, 0, sizeof st);
//	memset(dist, 0, sizeof dist);
//	for (int i = 1; i <= n; i++)
//	{
//		if (rd[i] == 1)
//		{
//			q.push({ i, 2 });
//			break;
//		}
//	}
//	while (!q.empty())
//	{
//		auto t = q.front();
//		st[t.first] = true;
//		q.pop();
//		for (int i = h[t.first]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (!st[j])
//			{
//				dist[mp[{t.first, j}]] = t.second;
//				q.push({ j, 5 - t.second });
//			}
//		}
//	}
//	for (int i = 1; i < n; i++)
//	{
//		cout << dist[i] << ' ';
//	}
//	cout << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		cin >> n;
//		memset(rd, 0, sizeof rd);
//		memset(cd, 0, sizeof cd);
//		memset(h, -1, sizeof h);
//		/*memset(e, 0, sizeof e);
//		memset(ne, 0, sizeof ne);*/
//
//		idx = 0;
//
//		for (int i = 1; i < n; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			rd[b]++;
//			rd[a]++;
//			cd[a]++;
//			cd[b]++;
//			mp[{a, b}] = mp[{b, a}] = i;
//			add(a, b), add(b, a);
//		}
//		int f = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			if (rd[i] + cd[i] >= 6)
//			{
//				cout << -1 << endl;
//				f = 0;
//				break;
//			}
//		}
//		if (!f) continue;
//		else
//		{
//			spfa();
//		}
//	}
//	return 0;
//}



//
//const int N = 1e5 + 10;
//int g[N];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(g , 0, sizeof g);
//		int n, m;
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				g[(i - 1) * m + j] = max(abs(i - 1) + abs(j - 1), g[(i - 1) * m + j]);
//				g[(i - 1) * m + j] = max(abs(i - n) + abs(j - m), g[(i - 1) * m + j]);
//				g[(i - 1) * m + j] = max(abs(i - 1) + abs(j - m), g[(i - 1) * m + j]);
//				g[(i - 1) * m + j] = max(abs(i - n) + abs(j - 1), g[(i - 1) * m + j]);
//			}
//		}
//		sort(g + 1, g + 1 + m * n);
//		for (int i = 1; i < 1 + m * n; i++) cout << g[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}




//const int N = 110;
//char a[N][N];
//int n, m;

//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		if (n == 1 || m == 1)
//		{
//			int tmp = max(m, n);
//			int cc = tmp / 2, dd = 0;
//			for (int i = 0; i < max(m,n); i++)
//			{
//				if (tmp % 2 == 1) {
//					cout << cc << ' ', cc++;
//					tmp--;
//					continue;
//				}
//				cout << cc << ' ';
//				dd++;
//				if (dd % 2 == 0)cc++;
//			}
//			cout << endl;
//			continue;
//		}
//		int d = (n - 2) * (m - 2);
//		int c = n + m - 4;
//		for (int i = 0; i < d; i++)
//		{
//			cout << c << ' ';
//		}
//		d = 2 * n + 2 * m - 8;
//		c++;
//		for (int i = 0; i < d; i++)
//		{
//			cout << c << ' ';
//		}
//		if (n == 1 || m == 1)d = 2;
//		else if (n == 1 && m == 1) d = 1;
//		else d = 4;
//		c++;
//		for (int i = 0; i < d; i++)
//		{
//			cout << c << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}



//const int N = 110;
//char a[N][N];
//int n, m;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(a, 0, sizeof a);
//		int x, y;
//		cin >> n >> m >> x >> y;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				cin >> a[i][j];
//			}
//		}
//		bool flag = false, f = false, ff = false;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				if (a[i][j] == 'B')
//				{
//					flag = true;
//				}
//				if (a[i][j] == 'B' && i == x)
//				{
//					f = true;
//				}
//				if (a[i][j] == 'B' && j == y)
//				{
//					f = true;
//				}
//				if (a[i][j] == 'B' && j == y && i == x)
//				{
//					ff = true;
//				}
//			}
//		}
//		if (f && flag && ff) cout << 0 << endl;
//		else if (f && flag && !ff) cout << 1 << endl;
//		else if (!f && flag && !ff) cout << 2 << endl;
//		else cout << -1 << endl;
//	}
//	return 0;
//}




//const int N = 2e5 + 10;
//int pre[N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int res = -1;
//		memset(pre, 0, sizeof pre);
//		for (int i = 1; i <= n; i++)
//		{
//			int a;
//			cin >> a;
//			if (pre[a])
//			{
//				res = max(res, n - (i - pre[a]));
//			}
//			pre[a] = i;
//		}
//		cout << res << endl;
//	}
//	return 0;
//}



//typedef pair<int, int>PII;
//const int N = 2e5 + 10;
//int f[N];
//int a[N];
//struct node
//{
//	int id1, id2;
//}Node[N];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(f, 0, sizeof f);
//		memset(Node, 0, sizeof Node);
//		int n;
//		cin >> n;
//		int d = n / 2, ans = 1e9;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//			f[a[i]]++;
//			if (Node[a[i]].id1 == 0)Node[a[i]].id1 = i;
//			if (Node[a[i]].id2 == 0 && Node[a[i]].id1 != i)Node[a[i]].id2 = i;
//			int md = abs(Node[a[i]].id1 - d), mmp = Node[a[i]].id1;
//			int md2 = abs(Node[a[i]].id2 - d), mmp2 = Node[a[i]].id2;
//
//			if (abs(i - d) < abs(Node[a[i]].id1 - d) && Node[a[i]].id2 != i)Node[a[i]].id1 = i;
//			else if (abs(i - d) < abs(d - Node[a[i]].id2) && Node[a[i]].id1 != i)Node[a[i]].id2 = i;
//			if (md < abs(Node[a[i]].id2 - d) && Node[a[i]].id1 != mmp)Node[a[i]].id2 = mmp;
//			if (md2 < abs(Node[a[i]].id1 - d) && Node[a[i]].id2 != mmp2)Node[a[i]].id1 = mmp2;
//
//		}
//
//		int res = -1, flag = 0;
//		for (int i = 0; i < 1e5 + 10;  i++)
//		{
//			if (f[i] >= 2)
//			{
//				
//				int x1 = Node[i].id1, x2 = Node[i].id2;
//				flag = 1;
//				if (x1 > x2)
//				{
//					res = max(res, x2 + n - x1);
//				}
//				else
//				{
//					res = max(res, x1 - x2 + n);
//				}
//			}
//		}
//		cout << res << endl;
//	}
//	return 0;
//}


//int o[55], y[55];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(o, 0, sizeof o);
//		memset(y, 0, sizeof y);
//		int n, k;
//		cin >> n >> k;
//		for (int i = 0; i < n; i++)
//		{
//			int a;
//			cin >> a;
//			int j = 0;
//			for(int cc = 0; cc < k;cc++)
//			{
//				if (a & 1)y[j]++;
//				else o[j]++;
//				a >>= 1;
//				j++;
//			}
//		}
//		int ans = 0;
//		for (int i = 0; i < k;i++)
//		{
//			if (y[i] > o[i])ans += pow(2, i);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//const int N = 2e5 + 10;
//int cnt[150],kaobei[150];
//int n, k;
//
//bool check(int x)
//{
//	int st = 'a', ed = 'z';
//	int sum = 0;
//	for (int i = 0;i <= 149; i++)kaobei[i] = cnt[i];
//	for (int i = 0;i <= 149;i++)
//	{
//		if (!cnt[i])continue;
//		if (cnt[i] >= x)
//		{
//			sum++;
//			cnt[i] -= x;
//			if (cnt[i] % 2 == 0)
//			{
//				cnt[i + 1] += cnt[i];
//				cnt[i] = 0;
//			}
//			else
//			{
//				for (int j = i + 1; j <= 149;j++)
//				{
//					if ( cnt[j] % 2 == 0 || cnt[j]%2==1)
//					{
//						cnt[j] += cnt[i] - 1;
//						cnt[i] = 0;
//						break;
//					}
//				}
//			}
//		}
//		else
//		{
//			if (cnt[i] % 2 == 0)
//			{
//				cnt[i + 1] += cnt[i];
//				cnt[i] = 0;
//			}
//			else
//			{
//				for (int j = i + 1; j <= 149;j++)
//				{
//					if ( cnt[j] % 2 == 0 || cnt[j] % 2 == 1)
//					{
//						cnt[j] += cnt[i] - 1;
//						cnt[i] = 0;
//						break;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0;i <= 149; i++)cnt[i] = kaobei[i];
//	if (sum >= k) return true;
//	else return false;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(cnt, 0, sizeof cnt);
//		cin >> n >> k;
//		/*if (n == k)
//		{
//			cout << 1 << endl;
//			continue;
//		}*/
//		string s;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//		{
//			cnt[s[i]]++;
//		}
//		int l = 1, r = n;
//		if (k > 1)
//		{
//			while (l <= r)
//			{
//				int mid = (l + r) >> 1;
//				if (check(mid)) l = mid + 1;
//				else r = mid - 1;
//			}
//			if (check(r)) cout << r << endl;
//			else cout << l << endl;
//		}
//		else
//		{
//			int res = 0,maxi = 0, f = 0;
//			for (int i = 0;i < 149; i++)
//			{
//				if (cnt[i] % 2 == 0)
//				{
//					res += cnt[i];
//					cnt[i] = 0;
//				}
//				else
//				{
//					res = res + cnt[i] - 1;
//					f = 1;
//				}
//			}
//			if (f) res += 1;
//			cout << res << endl;
//			
//		}
//	}
//	return 0;
//}




//int a[110];
//bool st[110];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(st, 0, sizeof st);
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//			while (a[i] > n || st[a[i]])
//			{
//				a[i] /= 2;
//				if (a[i] == 0)break;
//			}
//			st[a[i]] = true;
//		}
//		if (st[0])
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		int f = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (!st[i])
//			{
//				cout << "NO" << endl;
//				f = 1;
//				break;
//			}
//		}
//		if(!f) cout << "YES" << endl;
//	}
//	return 0;
//}





//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (c < a)swap(c, a);
//		if ((b - (c - b)) % a == 0 && ((b - (c - b)) / a) > 0)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		if ((b + (b - a)) % c == 0 && ((b + (b - a)) / c) > 0)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		if ((c - a) % 2 == 1)
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		if ((((a + ((c - a) / 2)) % b) == 0 && (((a + ((c - a) / 2))) / b > 0)))
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		cout << "NO" << endl;
//	}
//	return 0;
//}



//int a[110];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int maxi = -1, mini = 1e9 + 10;
//		for (int i = 0; i < n;i++) 
//		{
//			cin >> a[i];
//			if (a[i] > maxi)maxi = a[i];
//			if (a[i] < mini)mini = a[i];
//		}
//		cout << maxi - mini << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//typedef pair<int, pair<int, int>>PII;
////bool cmp(PII a, PII b)
////{
////	return a.l < b.l;
////}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		priority_queue<PII, vector<PII>, greater<PII>>a;
//		priority_queue<PII>b;
//		int l, r, w;
//		cin >> l >> r >> w;
//		cout << w << endl;
//		a.push({ l,{r,w} });
//		b.push({ r,{l,w }});
//		for (int i = 1;i < n;i++)
//		{
//			cin >> l >> r >> w;
//			if(l<=a.top().first)
//				a.push({ l,{r,w} });
//			if(r>=b.top().first)
//				b.push({ r,{l,w } });
//			if (a.top().second.first >= b.top().first)
//			{
//				cout << a.top().second.second << endl;
//			}
//			else if (b.top().second.first <= a.top().first)
//			{
//				cout << b.top().second.second << endl;
//			}
//			else
//			{
//				cout << a.top().second.second + b.top().second.second << endl;
//			}
//		}
//	}
////	return 0;
//}


//char a[50][50];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(a,0,sizeof a);
//		int n, k;
//		cin >> n >> k;
//		if ((n + 1) < (2 * k))
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		else
//		{
//			int i = 0, j = 0;
//			while (k--)
//			{
//				a[i][j] = 'R';
//				i += 2, j += 2;
//			}
//			for (int i = 0;i < n;i++)
//			{
//				for (int j = 0;j < n;j++)
//				{
//					if (a[i][j] != 'R')cout << '.';
//					else cout << a[i][j];
//				}
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}


//int arr[100];
//double d[100];
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		memset(d, 0x3f, sizeof d);
//		memset(arr, 0, sizeof arr);
//		cin >> n;
//		for (int i = 1;i <= n;i++) {
//			cin >> arr[i];
//		}
//		int res = 0, cnt = 1;
//		for (int i = 1;i <= n;i++) {
//			int k = 1;
//			for (int j = 1;j <= n;j++) {
//				
//				if (i == j)continue;
//				else {
//					d[k++] = (double)(arr[j] - arr[i]) / (j - i);
//					
//				}
//			}
//			sort(d+1, d + n);
//			
//			for (int m = 1;m < n;m++) {
//				if (d[m + 1] == d[m])cnt++;
//				else cnt = 1;
//				res = max(res, cnt);
//			}
//		}
//		cout << n - res -1 << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//char arr[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		memset(arr, 0, sizeof arr);
//		string ans;
//		cin >> n;
//		int i = 0;
//		for (i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		int flag = 0;
//		for (i = 0;i < n;i++) {
//			ans.push_back(arr[i]);
//			if (arr[i] == 'a'&&arr[i+1]!='a')break;
//			if (arr[i + 1] > arr[i])break;
//			if (arr[i + 1] < arr[i])flag = 1;
//			if (arr[i + 1] == arr[i]) {
//				int j = i,k=i+1;
//				if (flag)continue;
//				else break;
//			}
//		}
//		cout << ans;
//		reverse(ans.begin(), ans.end());
//		cout << ans;
//		cout << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		vector<int> arr;
//		int n;
//		cin >> n;
//		int ans = 0;
//		for (int i = 0;i < n;i++)
//		{
//			int a;
//			cin >> a;
//			arr.push_back(a);
//		}
//		sort(arr.begin(), arr.end());
//		for (int i = 0;i < n - 1;i++) {
//			if (arr[i] == arr[i + 1])arr[i] *= -1;
//		}
//		sort(arr.begin(), arr.end());
//		arr.erase(unique(arr.begin(),arr.end()), arr.end());
//		cout << arr.size() << endl;
//	}
//	return 0;
//}