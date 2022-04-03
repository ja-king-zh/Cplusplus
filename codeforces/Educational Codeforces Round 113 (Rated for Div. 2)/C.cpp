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
#define int long long 
typedef pair<int, int>PII;
typedef pair<double, double>PDD;
#define x first
#define y second
const int N = 2e5 + 10, mod = 998244353;
typedef long long ll;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);} 
//ll qmi(ll a,ll b,ll mod){ll res = 1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
int a[N];
// 注意爆 int 
void solve()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		cin >> a[i];
	}
	sort(a, a + n);
	if(a[n - 1] - a[n - 2] >= 2)
	{
		cout << 0 << endl;
		return;
	}
	int cnm = -1, mmp = a[n - 1];
	for(int i = n - 1; i >= 0; i -- )
	{
		if(a[i] != mmp)
		{
			cnm = a[i];
			break;
		}
	}
	int cnt = 0;
	for(int i = n - 1; i >= 0; i -- )
	{
		if(a[i] == cnm) cnt++;
	}
	int res = 1;
	for(int i = n; i >= 1; i -- ) res = res * i % mod;
	if(a[n - 1] == a[n - 2])
	{
		cout << res <<endl;
		return;
	}
	int ans = 1;
	for(int i = cnt; i >= 1; i -- )
	{
		ans = ans * i % mod;
	}
	for(int i = cnt + 2, j = 0; j < n - cnt - 1; j ++, i ++ )
	{
		ans = ans * i % mod;
	}
	cout << (res - ans + mod) % mod << endl;
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

