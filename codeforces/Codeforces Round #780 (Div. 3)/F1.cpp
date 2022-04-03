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
const int N = 3010, mod = 998244353;
typedef long long ll;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);} 
ll qmi(ll a,ll b,ll mod){ll res = 1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
int a[N], sum[N];
// 注意爆 int 
void solve()
{
	memset(sum, 0, sizeof sum);
	int n;
	string res;
	cin >> n >> res;
	for(int i = 0; i < n; i ++ )
		if(res[i] == '-') a[i + 1] = 1;
		else a[i + 1] = 0;
	for(int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + a[i];
	int cnt = 0;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j =  i + 1; j <= n; j ++ )
		{
			int d = sum[j] - sum[i - 1];
			int x = j - i + 1 - d;
			if(x == d) cnt++;
			else if(d > x && (d - x) % 3 == 0) cnt++;
		}
	}
	cout << cnt << endl;
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

