#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<queue>
//using namespace std;
//const int N = 110;
//char p[N][N];
//bool st[N][N];
//typedef pair<int, int>PII;
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> p[i] + 1;
//    }
//    queue<PII>q;
//    for (int i = 1; i <= n; i++)
//    {
//        int f = 0;
//        for (int j = 1; j <= m; j++)
//        {
//            if (p[i][j] == 'P')
//            {
//                q.push({ i,j });
//                f = 1;
//                break;
//            }
//        }
//        if (f) break;
//    }
//    int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//    while (!q.empty())
//    {
//        auto t = q.front();
//        st[t.first][t.second] = true;
//        q.pop();
//        for (int i = 0; i < 4; i++)
//        {
//            int x = dx[i] + t.first, y = dy[i] + t.second;
//            if (x > 0 && x <= m && y > 0 && y <= n && !st[x][y] && p[x][y] != 'o')
//            {
//                q.push({ x,y });
//                st[x][y] = true;
//            }
//        }
//    }
//    int ff;
//    for (int i = 1; i <= n; i++)
//    {
//        ff = 0;
//        for (int j = 1; j <= m; j++)
//        {
//            if (p[i][j] == 'X' && st[i][j] == true)
//            {
//                cout << "Playftql" << endl;
//                ff = 1;
//                break;
//            }
//        }
//        if (ff) break;
//    }
//    if (!ff) cout << "Playftcl" << endl;
//    return 0;
//}







#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		if ((a.size()) >= (2 + b.size())) cout << "Yes" << endl;
		else if ((b.size()) >= (2 + a.size())) cout << "No" << endl;
		else
		{
			ll aa, bb;
			aa = bb = 0;
			for (int i = a.size() - 1; i >= 0;i--)
			{
				if (a[i] >= 'A' && a[i] <= 'F') aa = aa + (a[i] - 'A' + 10) * pow(16, a.size() - 1 - i);
				else aa = aa + (a[i] - '0') * pow(16, a.size() - 1 - i);
			}
			for (int i = b.size() - 1; i >= 0;i--)
			{
				if (b[i] >= 'A' && b[i] <= 'F') bb = bb + (b[i] - 'A' + 10) * pow(16, b.size() - 1 - i);
				else bb = bb + (b[i] - '0') * pow(16, b.size() - 1 - i);
			}
			if (aa > 0 && bb > 0 && (2 * aa + 10) > (3 * bb + 5))cout << "Yes" << endl;
			else if (aa < 0 && bb > 0) cout << "Yes" << endl;
			else if (aa < 0 && bb < 0 && (2 * aa + 10) > (3 * bb + 5))cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	}
	return 0;
}





//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string a, b;
//		cin >> a >> b;
//		ll aa, bb;
//		aa = bb = 0;
//		if (a.size() > b.size())
//		{
//			cout << "Yes" << endl;
//			break;
//		}
//		if (a.size() < b.size())
//		{
//			cout << "No" << endl;
//			break;
//		}
//		for (int i = a.size() - 1; i >= 0;i--)
//		{
//			if (a[i] >= 'A' && a[i] <= 'F') aa = aa + (a[i] - 'A' + 10) * pow(16, a.size() - 1 - i);
//			else aa = aa + (a[i] - '0') * pow(16, a.size() - 1 - i);
//		}
//		for (int i = b.size() - 1; i >= 0;i--)
//		{
//			if (b[i] >= 'A' && b[i] <= 'F') bb = bb + (b[i] - 'A' + 10) * pow(16, b.size() - 1 - i);
//			else bb = bb + (b[i] - '0') * pow(16, b.size() - 1 - i);
//		}
//		if (2 * aa + 10 > 3 * bb + 5)cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}


//C
//int k, q;
//const int mod = 998244353;
//ll qmi(ll a, ll k)
//{
//	ll res = 0;
//	while (k)
//	{
//		if (k & 1) res += a % mod;
//		k >>= 1;
//		a = a * a % mod;
//	}
//	return res;
//}
//int main()
//{
//	cin >> k >> q;
//	while (q--)
//	{
//		ll l, r, ans = 0;
//		cin >> l >> r;
//		for (int i = l; i <= r;i++)
//		{
//			ans += qmi(i, k) % mod;
//		}
//		cout << (ans % mod + mod) % mod << endl;
//	}
//	return 0;
//}