#include<bits/stdc++.h>
using namespace std;
/*
Ja_king
Take the green hills as your friends
invite the fragrance of flowers as your companions
capture the starlight as your eyes
and pull the rivers as your guide
*/
#define debug "---"
#define endl '\n'
//#define int long long 
typedef pair<int, int>PII;
typedef pair<double, double>PDD;
#define x first
#define y second
const int N = 2e5 + 10, mod = 998244353;
typedef long long ll;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll qmi(ll a, ll b, ll mod) { ll res = 1;while (b) { if (b & 1)res = res * a % mod;a = a * a % mod;b >>= 1; }return res; }
char a[N];
// 注意爆 int 
void solve()
{
	cin >> a + 1;
	int n = strlen(a + 1);
	vector<int>v[26];
	for (int i = 1; i <= n; i++)
	{
		v[a[i] - 'a'].push_back(i);
	}
	int res = 0, idx = 1;
	while (1)
	{
		int cnm = 1e9;
		if (idx >= n) break;
		for (int i = 0; i < 26; i++)
		{
			int mmp = lower_bound(v[i].begin(), v[i].end(), idx) - v[i].begin() + 1;
			if (mmp >= v[i].size()) continue;
			cnm = min(cnm, v[i][mmp]);
		}
		if (cnm == 1e9) break;
		idx = cnm + 1;
		res += 2;
	}
	cout << n - res << endl;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
	int t;
	cin >> t;
	//t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}

// 队友会了 => 我会了 
/*
				 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
			 __.'              ~.   .~              `.__
		   .'//                  \./                  \`.
		 .'//                     |                     \`.
	   .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
	 .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/

