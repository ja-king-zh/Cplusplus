#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


typedef long long ll;
const int N = 5e5 + 10;
int arr[N];
int n,maxi=-1;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		if (arr[i] > maxi)
			maxi = arr[i];
	}
	int j = 1, ans = 0,a=0;
	for (;j <= maxi;j++) {
		int p = 0;
		ans = 0;
		while (p < n) {
			int flag = 1;
			while (p<n&&arr[p] >= j) {
				p++;
				if (flag) {
					ans++;
					flag = 0;
				}
			}
			if (arr[p] < j)p++;
		}
		if (ans > a)
			a = ans;
	}
	cout << a;
	return 0;
}



//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//
//const int N = 110;
//ll maxi[N], mini[N];
//
//int main() {
//	ll n,sum=0;
//	cin >> n;
//	for (int i = 0;i < n;i++) {
//		cin >> maxi[i];
//		sum += maxi[i];
//	}
//	cout << sum << endl;
//	sum = 0;
//	ll m = maxi[0];
//	mini[0] = m;
//	for (int i = 1;i < n;i++) {
//		if (maxi[i] > m) {
//			m = maxi[i];
//			mini[i] = maxi[i];
//		}
//		else {
//			mini[i] = 0;
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		sum += mini[i];
//	}
//	cout << sum << endl;
//	return 0;
//}