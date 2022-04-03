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
const int N = 1e5 + 10, mod = 998244353;
typedef long long ll;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);} 
//ll qmi(ll a,ll b,ll mod){ll res = 1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}

// 注意爆 int 
void solve()
{
	int n;
	string res;
	cin >> n >> res;
	int cnt = 0;
	for(auto t : res)
	{
		if(t == '2') cnt++;
	}
	if(cnt == 1 || cnt == 2) 
	{
		cout << "NO" << endl;
		return;
	}
	if(cnt == 0)
	{
		cout << "YES" << endl;
		for(int i = 0; i < n; i ++ )
		{
			for(int j = 0; j < n; j ++ )
			{
				if(i == j) cout << "X";
				else cout << "=";
			}
			cout << endl;
		}
		return;
	}
	cout << "YES" << endl;
	int last = -1;
	for(int i = n - 1; i >= 0; i -- )
		if(res[i] == '2') 
		{
			last = i;
			break;
		}
	for(int i = 0; i < n; i ++ )
	{
		if(res[i] == '1')
		{
			for(int j = 0; j < n; j ++ )
			{
				if(i == j) cout << "X";
				else cout << "=";
			}
			cout << endl;
		}
		else
		{
			int idx = -1;
			for(int j = i + 1; j < n; j ++ )
			{
				if(res[j] == '2')
				{
					idx = j;
					break;
				}
			}
			if(idx == -1)
			{
				for(int j = 0; j < n; j ++ )
				{
					if(res[j] == '2')
					{
						idx = j;
						break;
					}
				}
			}
			for(int j = 0; j < n; j ++ )
			{
				if(j == idx) cout << "+";
				else if(i == j) cout << "X";
				else if(j == last) cout << "-";
				else cout << "=";
			}
			last = i;
			cout <<endl;
		}
	}
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

