#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, pair<int, int>>PII;
//bool cmp(PII a, PII b)
//{
//	return a.l < b.l;
//}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<PII, vector<PII>, greater<PII>>a;
		priority_queue<PII>b;
		int l, r, w;
		cin >> l >> r >> w;
		cout << w << endl;
		a.push({ l,{r,w} });
		b.push({ r,{l,w }});
		for (int i = 1;i < n;i++)
		{
			cin >> l >> r >> w;
			if(l<=a.top().first)
				a.push({ l,{r,w} });
			if(r>=b.top().first)
				b.push({ r,{l,w } });
			if (a.top().second.first >= b.top().first)
			{
				cout << a.top().second.second << endl;
			}
			else if (b.top().second.first <= a.top().first)
			{
				cout << b.top().second.second << endl;
			}
			else
			{
				cout << a.top().second.second + b.top().second.second << endl;
			}
		}
	}
	return 0;
}


//char a[50][50];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(a,0,sizeof a);
//		int n, k;
//		cin >> n >> k;
//		if ((n + 1) < (2 * k))
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		else
//		{
//			int i = 0, j = 0;
//			while (k--)
//			{
//				a[i][j] = 'R';
//				i += 2, j += 2;
//			}
//			for (int i = 0;i < n;i++)
//			{
//				for (int j = 0;j < n;j++)
//				{
//					if (a[i][j] != 'R')cout << '.';
//					else cout << a[i][j];
//				}
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}


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