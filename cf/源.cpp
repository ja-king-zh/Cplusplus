#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
using namespace std;






//const int N = 2e5 + 10;
//int pre[N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int res = -1;
//		memset(pre, 0, sizeof pre);
//		for (int i = 1; i <= n; i++)
//		{
//			int a;
//			cin >> a;
//			if (pre[a])
//			{
//				res = max(res, n - (i - pre[a]));
//			}
//			pre[a] = i;
//		}
//		cout << res << endl;
//	}
//	return 0;
//}



//typedef pair<int, int>PII;
//const int N = 2e5 + 10;
//int f[N];
//int a[N];
//struct node
//{
//	int id1, id2;
//}Node[N];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(f, 0, sizeof f);
//		memset(Node, 0, sizeof Node);
//		int n;
//		cin >> n;
//		int d = n / 2, ans = 1e9;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//			f[a[i]]++;
//			if (Node[a[i]].id1 == 0)Node[a[i]].id1 = i;
//			if (Node[a[i]].id2 == 0 && Node[a[i]].id1 != i)Node[a[i]].id2 = i;
//			int md = abs(Node[a[i]].id1 - d), mmp = Node[a[i]].id1;
//			int md2 = abs(Node[a[i]].id2 - d), mmp2 = Node[a[i]].id2;
//
//			if (abs(i - d) < abs(Node[a[i]].id1 - d) && Node[a[i]].id2 != i)Node[a[i]].id1 = i;
//			else if (abs(i - d) < abs(d - Node[a[i]].id2) && Node[a[i]].id1 != i)Node[a[i]].id2 = i;
//			if (md < abs(Node[a[i]].id2 - d) && Node[a[i]].id1 != mmp)Node[a[i]].id2 = mmp;
//			if (md2 < abs(Node[a[i]].id1 - d) && Node[a[i]].id2 != mmp2)Node[a[i]].id1 = mmp2;
//
//		}
//
//		int res = -1, flag = 0;
//		for (int i = 0; i < 1e5 + 10;  i++)
//		{
//			if (f[i] >= 2)
//			{
//				
//				int x1 = Node[i].id1, x2 = Node[i].id2;
//				flag = 1;
//				if (x1 > x2)
//				{
//					res = max(res, x2 + n - x1);
//				}
//				else
//				{
//					res = max(res, x1 - x2 + n);
//				}
//			}
//		}
//		cout << res << endl;
//	}
//	return 0;
//}


//int o[55], y[55];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(o, 0, sizeof o);
//		memset(y, 0, sizeof y);
//		int n, k;
//		cin >> n >> k;
//		for (int i = 0; i < n; i++)
//		{
//			int a;
//			cin >> a;
//			int j = 0;
//			for(int cc = 0; cc < k;cc++)
//			{
//				if (a & 1)y[j]++;
//				else o[j]++;
//				a >>= 1;
//				j++;
//			}
//		}
//		int ans = 0;
//		for (int i = 0; i < k;i++)
//		{
//			if (y[i] > o[i])ans += pow(2, i);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//const int N = 2e5 + 10;
//int cnt[150],kaobei[150];
//int n, k;
//
//bool check(int x)
//{
//	int st = 'a', ed = 'z';
//	int sum = 0;
//	for (int i = 0;i <= 149; i++)kaobei[i] = cnt[i];
//	for (int i = 0;i <= 149;i++)
//	{
//		if (!cnt[i])continue;
//		if (cnt[i] >= x)
//		{
//			sum++;
//			cnt[i] -= x;
//			if (cnt[i] % 2 == 0)
//			{
//				cnt[i + 1] += cnt[i];
//				cnt[i] = 0;
//			}
//			else
//			{
//				for (int j = i + 1; j <= 149;j++)
//				{
//					if ( cnt[j] % 2 == 0 || cnt[j]%2==1)
//					{
//						cnt[j] += cnt[i] - 1;
//						cnt[i] = 0;
//						break;
//					}
//				}
//			}
//		}
//		else
//		{
//			if (cnt[i] % 2 == 0)
//			{
//				cnt[i + 1] += cnt[i];
//				cnt[i] = 0;
//			}
//			else
//			{
//				for (int j = i + 1; j <= 149;j++)
//				{
//					if ( cnt[j] % 2 == 0 || cnt[j] % 2 == 1)
//					{
//						cnt[j] += cnt[i] - 1;
//						cnt[i] = 0;
//						break;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0;i <= 149; i++)cnt[i] = kaobei[i];
//	if (sum >= k) return true;
//	else return false;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(cnt, 0, sizeof cnt);
//		cin >> n >> k;
//		/*if (n == k)
//		{
//			cout << 1 << endl;
//			continue;
//		}*/
//		string s;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//		{
//			cnt[s[i]]++;
//		}
//		int l = 1, r = n;
//		if (k > 1)
//		{
//			while (l <= r)
//			{
//				int mid = (l + r) >> 1;
//				if (check(mid)) l = mid + 1;
//				else r = mid - 1;
//			}
//			if (check(r)) cout << r << endl;
//			else cout << l << endl;
//		}
//		else
//		{
//			int res = 0,maxi = 0, f = 0;
//			for (int i = 0;i < 149; i++)
//			{
//				if (cnt[i] % 2 == 0)
//				{
//					res += cnt[i];
//					cnt[i] = 0;
//				}
//				else
//				{
//					res = res + cnt[i] - 1;
//					f = 1;
//				}
//			}
//			if (f) res += 1;
//			cout << res << endl;
//			
//		}
//	}
//	return 0;
//}




//int a[110];
//bool st[110];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(st, 0, sizeof st);
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//			while (a[i] > n || st[a[i]])
//			{
//				a[i] /= 2;
//				if (a[i] == 0)break;
//			}
//			st[a[i]] = true;
//		}
//		if (st[0])
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		int f = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (!st[i])
//			{
//				cout << "NO" << endl;
//				f = 1;
//				break;
//			}
//		}
//		if(!f) cout << "YES" << endl;
//	}
//	return 0;
//}





//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (c < a)swap(c, a);
//		if ((b - (c - b)) % a == 0 && ((b - (c - b)) / a) > 0)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		if ((b + (b - a)) % c == 0 && ((b + (b - a)) / c) > 0)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		if ((c - a) % 2 == 1)
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		if ((((a + ((c - a) / 2)) % b) == 0 && (((a + ((c - a) / 2))) / b > 0)))
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		cout << "NO" << endl;
//	}
//	return 0;
//}



//int a[110];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int maxi = -1, mini = 1e9 + 10;
//		for (int i = 0; i < n;i++) 
//		{
//			cin >> a[i];
//			if (a[i] > maxi)maxi = a[i];
//			if (a[i] < mini)mini = a[i];
//		}
//		cout << maxi - mini << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//typedef pair<int, pair<int, int>>PII;
////bool cmp(PII a, PII b)
////{
////	return a.l < b.l;
////}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		priority_queue<PII, vector<PII>, greater<PII>>a;
//		priority_queue<PII>b;
//		int l, r, w;
//		cin >> l >> r >> w;
//		cout << w << endl;
//		a.push({ l,{r,w} });
//		b.push({ r,{l,w }});
//		for (int i = 1;i < n;i++)
//		{
//			cin >> l >> r >> w;
//			if(l<=a.top().first)
//				a.push({ l,{r,w} });
//			if(r>=b.top().first)
//				b.push({ r,{l,w } });
//			if (a.top().second.first >= b.top().first)
//			{
//				cout << a.top().second.second << endl;
//			}
//			else if (b.top().second.first <= a.top().first)
//			{
//				cout << b.top().second.second << endl;
//			}
//			else
//			{
//				cout << a.top().second.second + b.top().second.second << endl;
//			}
//		}
//	}
////	return 0;
//}


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