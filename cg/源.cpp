#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	char arr[10010];
	cin >> arr;
	int sz = strlen(arr);
	int n = arr[sz - 1] - '0';
	for (int i = 0;i < sz - 1;i++)n += arr[i] - '0';
	cout << n % 3;
}






//int main() {
//	int t, m, n;
//	char arr[100010];
//	cin >> t;
//	while (t--) {
//		cin >> arr >> m;
//		int sz = strlen(arr);
//		if (sz <= 1)n = arr[0] - '0';
//		else
//			n = arr[sz - 1] - '0' + 10 * (arr[sz - 2] - '0');
//		if (m == 2) {
//			for (int i = 0;i < sz - 2;i++)
//				n += (arr[i] - '0');
//		}
//		if (m == 5) {
//			for (int i = 0;i < sz - 2;i++)
//				n += (arr[i] - '0')*4;
//		}
//		if (n % (m + 1) == 0)
//			cout << "Nolv" << endl;
//		else
//			cout << "Hibiki" << endl;
//	}
//	return 0;
//}






//const int N = 1010;
//int v[N], w[N], f[N][N];
//int n, m;
//
//int main() {
//	cin >> m >> n;
//	for (int i = 1;i <= n;i++)cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++) {
//		for (int j = 0;j <= m;j++) {
//			f[i][j] = f[i - 1][j];
//			if (j >= v[i])
//				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//		}
//	}
//	cout << f[n][m];
//	return 0;
//}