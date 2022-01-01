#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int dp[N];

int main()
{
	dp[2] = 1;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
		}
		//cout << dp[i] << ' ';
	}

	cout << dp[n] << endl;

	return 0;
}                                       