
#include<unordered_map>
#include<iostream>
#include<vector>
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
//typedef long long ll;
//int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);} 
//ll qmi(ll a,ll b,ll mod){ll res = 1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
int a[N], mul[N];
// 注意爆 int 
void solve()
{
	int n, res = 0;
	cin >> n;
	mul[0] = 0;
	vector<int>v, f;
	v.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i], mul[i] = 0;
		if (a[i] < 0) res++;
		if (a[i] == 0) v.push_back(i);
		if (a[i] < 0) f.push_back(i);
	}
	v.push_back(n + 1);
	for (int i = 1; i <= n; i++)
	{
		mul[i] = mul[i - 1];
		if (abs(a[i]) == 2) mul[i]++;
	}
	mul[n + 1] = mul[n];
	
	if (res % 2 == 0 && v.size() == 2)
	{
		cout << 0 << ' ' << 0 << endl;
		return;
	}
	if (v.size() > 2)
	{
		int res = 0, ll = 0, rr = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			int cnmm = 0, cnt = 0;
			vector<int>ff;
			for (int j = v[i] + 1; j < v[i + 1]; j++)
			{
				if (a[j] < 0) cnmm++, ff.push_back(j);
				if (abs(a[j]) == 2) cnt++;
			}
			int ans = -1, l = 0, r = 0;
			if (cnmm % 2 == 1)
			{
				int cnm = mul[v[i + 1]] - mul[ff[0]];
				int mmp = mul[ff[0] - 1] - mul[v[i]];
				if (cnm > ans)
				{
					ans = cnm;
					l = ff[0];
					r = n-v[i+1]+1;
				}
				if (mmp > ans)
				{
					ans = mmp;
					r = n - ff[0] + 1;
					l = v[i];
				}
				cnm = mul[v[i + 1]] - mul[ff[(int)ff.size() - 1]];
				mmp = mul[ff[(int)ff.size() - 1] - 1] - mul[v[i]];
				if (cnm > ans)
				{
					ans = cnm;
					l = ff[(int)ff.size() - 1];
					r = n-v[i+1]+1;
				}
				if (mmp > ans)
				{
					ans = mmp;
					r = n - ff[(int)ff.size() - 1] + 1;
					l = v[i];
				}
			}
			else
			{
				ans = cnt;
				l = v[i], r = n - v[i + 1] + 1;
			}
			if (ans > res)
			{
				res = ans;
				ll = l, rr = r;
			}
		}
		if (res != 0) cout << ll << ' ' << rr << endl;
		else cout << n << ' ' << 0 << endl;
	}
	else
	{
		int ans = -1, l = 0, r = 0;
		int cnm = mul[n] - mul[f[0]];
		int mmp = mul[f[0] - 1];

		if (cnm > ans)
		{
			ans = cnm;
			l = f[0];
			r = 0;
		}
		if (mmp > ans)
		{
			ans = mmp;
			r = n - f[0] + 1;
			l = 0;
		}
		cnm = mul[n] - mul[f[f.size() - 1]];
		mmp = mul[f[f.size() - 1] - 1];
		if (cnm > ans)
		{
			ans = cnm;
			l = f[f.size() - 1];
			r = 0;
		}
		if (mmp > ans)
		{
			ans = mmp;
			r = n - f[f.size() - 1] + 1;
			l = 0;
		}
		cout << l << ' ' << r << endl;
	}
	for (int i = 0; i <= n; i++) mul[i] = 0;
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

