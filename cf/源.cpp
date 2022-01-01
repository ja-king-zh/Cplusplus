#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
using namespace std;




//int arr[100];
//double d[100];
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		memset(d, 0x3f, sizeof d);
//		memset(arr, 0, sizeof arr);
//		cin >> n;
//		for (int i = 1;i <= n;i++) {
//			cin >> arr[i];
//		}
//		int res = 0, cnt = 1;
//		for (int i = 1;i <= n;i++) {
//			int k = 1;
//			for (int j = 1;j <= n;j++) {
//				
//				if (i == j)continue;
//				else {
//					d[k++] = (double)(arr[j] - arr[i]) / (j - i);
//					
//				}
//			}
//			sort(d+1, d + n);
//			
//			for (int m = 1;m < n;m++) {
//				if (d[m + 1] == d[m])cnt++;
//				else cnt = 1;
//				res = max(res, cnt);
//			}
//		}
//		cout << n - res -1 << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//char arr[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		memset(arr, 0, sizeof arr);
//		string ans;
//		cin >> n;
//		int i = 0;
//		for (i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		int flag = 0;
//		for (i = 0;i < n;i++) {
//			ans.push_back(arr[i]);
//			if (arr[i] == 'a'&&arr[i+1]!='a')break;
//			if (arr[i + 1] > arr[i])break;
//			if (arr[i + 1] < arr[i])flag = 1;
//			if (arr[i + 1] == arr[i]) {
//				int j = i,k=i+1;
//				if (flag)continue;
//				else break;
//			}
//		}
//		cout << ans;
//		reverse(ans.begin(), ans.end());
//		cout << ans;
//		cout << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		vector<int> arr;
//		int n;
//		cin >> n;
//		int ans = 0;
//		for (int i = 0;i < n;i++)
//		{
//			int a;
//			cin >> a;
//			arr.push_back(a);
//		}
//		sort(arr.begin(), arr.end());
//		for (int i = 0;i < n - 1;i++) {
//			if (arr[i] == arr[i + 1])arr[i] *= -1;
//		}
//		sort(arr.begin(), arr.end());
//		arr.erase(unique(arr.begin(),arr.end()), arr.end());
//		cout << arr.size() << endl;
//	}
//	return 0;
//}