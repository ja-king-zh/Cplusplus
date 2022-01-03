#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int dp[N][N], a[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1;j <= i;j++)
		{
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(dp[n][i], res);
	}
	cout << res << endl;
	return 0;
}



//const int N = 1e5 + 10;
//int dp[N];
//
//int main()
//{
//	dp[2] = 1;
//	int n;
//	cin >> n;
//	for (int i = 3; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
//		}
//		//cout << dp[i] << ' ';
//	}
//
//	cout << dp[n] << endl;
//
//	return 0;
//}                                       