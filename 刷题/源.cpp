#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n < 3)cout << n << endl;
		else cout << (n/2)+1 << endl;
	}
	return 0;
}







//int main() {
//	char arr[1010];
//	cin >> arr;
//	int sz = strlen(arr);
//	int ans = 0;
//	for (int i = 0;i < sz;i++) {
//		ans += arr[i] - '0';
//	}
//	ans %= 3;
//	cout << ans;
//	return 0;
//}








//const int N = 2e5 + 10;
//int b[N], p[N],arr[N],d[N];
//bool st[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		memset(d, -1, sizeof d);
//		for (int i = 1;i <= n;i++)
//			cin >> b[i];
//		for (int i = 1;i <= n;i++)
//			cin>>p[i];
//
//		for (int i = 2;i <= n;i++) {
//			int t = p[i];
//
//			if (d[b[]] == -1) {
//				cout << -1 << endl;
//				goto a;
//			}
//			d[i] = d[t] + i;
//		}
//
//		a:
//	}
//}






//const int N = 4e5 + 10;
//int e[N], ne[N], h[N], idx;
//int f[N];
//bool st[N], fst[N];
//int d[N], fd[N];
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		memset(h, -1, sizeof h);
//		int n, k;
//		cin >> n >> k;
//		for (int i = 0;i < k;i++) {
//			cin >> f[i];
//		}
//		for (int i = 0;i < n - 1;i++) {
//			int a, b;
//			cin >> a >> b;
//			add(a, b);
//			add(b, a);
//		}
//		for (int i = 0;i <= n;i++) {
//			st[i] = false;
//			fst[i] = false;
//			d[i] = 0;
//			fd[i] = 0;
//		}
//		queue<int>q;
//		q.push(1);
//		st[1] = true;
//		while (!q.empty()) {
//			int t = q.front();
//			q.pop();
//			for (int i = h[t];i != -1;i = ne[i]) {
//				int j = e[i];
//				if (!st[j]) {
//					st[j] = true;
//					q.push(j);
//					d[j] = d[t] + 1;
//				}
//			}
//		}
//		for (int i = 0;i < k;i++) {
//			int cnm = f[i];
//			fst[cnm] = true;
//			q.push(cnm);
//		}
//		while (!q.empty()) {
//			int t = q.front();
//			q.pop();
//			for (int i = h[t];i != -1;i = ne[i]) {
//				int j = e[i];
//				if (!fst[j]) {
//					fst[j] = true;
//					fd[j] = fd[t] + 1;
//					q.push(j);
//					
//				}
//			}
//		}
//		int flag = 0;
//		for (int i = 2;i <= n;i++) {
//			if (ne[h[i]] == -1) {
//				if (d[i] < fd[i]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag)cout << "YES" << endl;
//		else cout << "NO" << endl;
//		
//	}
//	return 0;
//}





//const int N = 2e5 + 10;
//int a[N], p[N];
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n,m=0;
//		cin >> n;
//		for (int i = 0;i < n;i++) {
//			cin >> a[i];
//			m = max(m, a[i]);
//		}
//		if (a[0] < m && a[n - 1] < m) {
//			cout << -1 << endl;
//			continue;
//		}
//		if (n == 1) {
//			cout << 1 << endl;
//			continue;
//		}
//		if (a[0] < a[n - 1]) {
//			p[n - 1] = a[n - 1];
//			for (int i = n - 2,j=0;i >= 0;i--,j++) {
//				p[j] = a[i];
//			}
//		}
//		else {
//			p[0] = a[0];
//			for (int i = n - 1, j = 1;j<n;i--, j++) {
//				p[i] = a[j];
//			}
//		}
//		for (int i = 0;i < n;i++)cout << p[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}





//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int a, b,ans=0;
//		cin >> a >> b;
//		if (a < b)swap(a, b);
//		int c = a - b;
//		/*while (c >= 2 && a >= 3 && b > 0) {
//			a -= 3;
//			b -= 1;
//			c -= 2;
//			ans++;
//		}*/
//		int cnm = min(a / 3, b);
//		int mmp = min(cnm, c / 2);
//		ans += mmp;
//		a = a - mmp * 3;
//		b = b - mmp;
//		int m = min(a / 2, b / 2);
//		ans += m;
//		
//		cout << ans << endl;
//	}
//	return 0;
//}





//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		char a[100];
//		scanf("%s", a);
//		int sz = strlen(a);
//		if ((a[sz-1]-'0') % 2 == 0) {
//			cout << 0 << endl;
//			continue;
//		}
//		else {
//			if ((a[0] - '0') % 2 == 0) {
//				cout << 1 << endl;
//			}
//			else {
//				int flag = 0;
//				for (int i = 0;i < sz;i++) {
//					if ((a[i] - '0') % 2 == 0) {
//						cout << 2 << endl;
//						flag = 1;
//						break;
//					}
//				}
//				if (!flag)cout << -1<<endl;
//			}
//		}
//	}
//	return 0;
//}








//int idx;
//const int N = 1e6 + 10;
//int arr[N];
//int qiu(int x, int y) {
//    int z = y;
//    while (x % y != 0) {
//        z = x % y;
//        x = y;
//        y = z;
//    }
//    return z;
//}
//int main() {
//    int a, b;
//    cin >> a >> b;
//    int t;
//    int res = qiu(a, b);
//    for (int i = 1;i <= res / i;i++) {
//        if (res % i == 0) {
//            arr[idx++] = i;
//            if (i != res / i)arr[idx++] = res / i;
//        }
//    }
//    arr[idx++] = res;
//    sort(arr, arr + idx);
//    for (int i=0;i < idx;i++) {
//        cout << arr[i] << ' ';
//    }
//    cin >> t;
//    while (t--) {
//        int l, r;
//        cin >> l >> r;
//        for (int i=0;i < idx;i++) {
//            if (arr[i] >= l) {
//                cout << arr[i] << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}




//const int N = 110;
//int arr[N];
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n, t,ans=0,cnt=0;
//		cin >> n >> t;
//		for (int i = 0;i < n;i++)cin >> arr[i];
//		sort(arr, arr + n);
//		int c = t;
//		while (t--) {
//			ans += arr[n -1-c-cnt] / arr[n - 1 - cnt];
//			arr[n - 1 - c - cnt] = 0;
//			arr[n - 1 - cnt] = 0;
//			cnt++;
//		}
//		for (int i = 0;i < n;i++)ans += arr[i];
//		cout << ans << endl;
//	}
//	return 0;
//}




//typedef long long ll;
//ll arr[110];
//int t, n;
//ll measure(ll x, ll y)
//{
//	ll z = y;
//	while (x % y != 0)
//	{
//		z = x % y;
//		x = y;
//		y = z;
//	}
//	return z;
//}
//
//int main() {
//	cin >> t;
//	while (t--) {
//		for (int i = 0;i < 110;i++)arr[i] = 0;
//		cin >> n;
//		ll m = 0;
//		for (int i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		int flag=1;
//		ll ji = arr[0], ou = arr[1];
//		for (int i = 0;i < n;i += 2)ji = measure(ji, arr[i]);
//		for (int i = 1;i < n;i += 2)ou = measure(ou, arr[i]);
//		for (int i = 0;i < n;i += 2) {
//			if (arr[i] % ou == 0) {
//				flag = 0;
//			}
//		}
//		if (flag) {
//			cout << ou << endl;
//			continue;
//		}
//		flag = 1;
//		for (int i = 1;i < n;i += 2) {
//			if (arr[i] % ji == 0) {
//				flag = 0;
//			}
//		}
//		if (flag) {
//			cout << ji << endl;
//			continue;
//		}
//		cout << 0 << endl;
//	}
//}




//
//int arr[110],d[110];
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		memset(arr, 0, sizeof arr);
//		int n, t;
//		int m1, m2;
//		m1 = m2 = 0;
//		int ans = 0,cnt=0;
//		cin >> n >> t;
//		for (int i = 0;i < n;i++) {
//			cin >> arr[i];
//		}
//		while (t--) {
//			for (int i = 0;i < n;i++) {
//				if (arr[i] > m1) {
//					m1 = arr[i];
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] == m1) {
//					arr[i] = 0;
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] > m2) {
//					m2 = arr[i];
//				}
//			}
//			for (int i = 0;i < n;i++) {
//				if (arr[i] == m2) {
//					arr[i] = 0;
//				}
//			}
//			d[cnt] = m1;
//			d[cnt + 1] = m2;
//			cnt += 2;
//		}
//
//		for (int i = 0;i < n;i++) {
//			ans += arr[i];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}




//char s[110][2],arr[110];
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		memset(arr, 0, sizeof arr);
//		int l;
//		cin >> l;
//		for (int i = 0;i < l - 2;i++) {
//			scanf("%s", s[i]);
//		}
//		arr[0] = s[0][0];
//		arr[1] = s[0][1];
//		int cnt = 2;
//		for (int i = 0;i < l - 3;i++) {
//			if (s[i][1] == s[i + 1][0]) {
//				arr[cnt] = s[i+1][1];
//				cnt++;
//			}
//			else {
//				arr[cnt] = s[i + 1][0];
//				cnt++;
//				arr[cnt] = s[i + 1][1];
//				cnt++;
//			}
//		}
//		int sz = strlen(arr);
//		cout << arr;
//		while (sz < l) {
//			cout << 'a';
//			sz++;
//		}
//		cout << endl;
//	}
//	return 0;
//}




//
//int arr[10];
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		for (int i = 0;i < 7;i++) {
//			cin >> arr[i];
//		}
//		if (arr[0] + arr[1] == arr[2]) {
//			cout << arr[0] << ' ' << arr[1] << ' ' << arr[3]<<endl;
//		}
//		else {
//			cout << arr[0] << ' ' << arr[1] << ' ' << arr[2]<<endl;
//		}
//	}
//	return 0;
//}








//int main() {
//	int n, m;
//	cin >> n >> m;
//	if (n < m) {
//		cout << "bsa";
//	}
//	else {
//		if (n % (m + 1) == 0) {
//			cout << "bs";
//		}
//		else {
//			cout << "bsa";
//		}
//	}
//	return 0;
//}





//
//#include<map> 
//#define ll long long 
//
//map<ll, int> mp;
//ll m, z, p;
//ll a, b, c;
//
//ll msc(ll a, ll b)
//{
//    ll sum = 0;
//    while (b)
//    {
//        if (b % 2 == 1)
//            sum = (sum + a) % p;
//        b >>= 1;
//        a = (a + a) % p;
//    }
//    return sum;
//}
//
//ll msc(int a, int b)
//{
//    ll sum = 0;
//    while (b)
//    {
//        if (b % 2 == 1)
//            sum = (sum + a) % p;
//        b >>= 1;
//        a = (a + a) % p;
//    }
//    return sum;
//}
//
//ll qsm(ll x)
//{
//    ll sum = 1; ll aa = a;
//    while (x > 0)
//    {
//        if (x & 1)
//            sum = msc(sum, aa) % c;
//        x = x >> 1;
//        //    if(aa > 1e9)
//        aa = msc(aa, aa) % c;
//        //    else
//        //    	aa = (aa * aa) % c;  
//    }
//    return sum;
//}
//int main()
//{
//    cin >> z >> p;
//    mp.clear();
//    m = ceil(sqrt(p));
//    long long ans;
//    c = p;
//    a = 10;
//    b = (msc(9 % p, z) + 1) % p;
//    for (int i = 0; i <= m; i++)
//    {
//        if (i == 0)
//        {
//            ans = b % c;
//            mp[ans] = i;
//            continue;
//        }
//        ans = msc(ans, a) % c;
//        mp[ans] = i;
//    }
//    long long t = qsm(m);
//    ans = 1;
//    for (int i = 1; i <= m; i++)
//    {
//        ans = msc(ans, t) % c;
//        if (mp[ans])
//        {
//            int t = i * m - mp[ans];
//            cout << (t % c + c) % c;
//            p = true;
//            break;
//        }
//    }
//    return 0;
//}



//const int N = 1e6 + 10;
//int arr[N],d[N];
//int main() {
//	int n, t;
//	cin >> n >> t;
//	for (int i = 0;i < n;i++) {
//		cin >> arr[i];
//	}
//	while (t--) {
//		int l, r, c;
//		cin >> l >> r >> c;
//		d[l - 1] += c;
//		d[r] -= c;
//	}
//	int res = 0,ans=10000;
//	for (int i = 0;i < n;i++) {
//		res += d[i];
//		arr[i] = arr[i] + res;
//		ans = min(arr[i], ans);
//	}
//	cout << ans;
//	return 0;
//}







//const int N = 1010;
//int f[N], v[N], w[N];
//
//
//int main() {
//
//
//    int n, m;
//    cin >> m >> n;
//    for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//
//    for (int i = 1;i <= n;i++) {
//        for (int j = m;j >= v[i];j--) {
//            f[j] = max(f[j], f[j - v[i]] + w[i]);
//        }
//    }
//    cout << f[m];
//    return 0;
//
//}





//int main() {
//	long long n, arr1[200000], arr2[200000], c, count = 0;
//	scanf("%lld", &n);
//	for (int i = 0;i < n;i++) {
//		scanf("%lld", &arr1[i]);
//	}
//	scanf("%lld", &c);
//	for (int i = 0;i < n;i++) {
//		arr2[i] = arr1[i] + c;
//	}
//	sort(arr2, arr2 + n);
//	for (int i = 0;i < n;i++) {
//		if (binary_search(arr2, arr2 + n, arr1[i]))
//			count++;
//	}
//	printf("%lld", count);
//	return 0;
//}





//int n;
//int panduan(int x) {
//	for (int i = 2;i <= x / i;i++) {
//		if (x % i == 0)return 0;
//	}
//	return 1;
//}
//int main() {
//	cin >> n;
//	for (int i = 4;i <= n;i+=2) {
//		for (int j = 2;j < i - 1;j++) {
//			if (panduan(j) && panduan(i - j)) {
//				printf("%d=%d+%d\n", i, j, i - j);
//				break;
//			}
//		}
//	}
//	return 0;
//}








//char s[100];
//int main() {
//	cin >> s;
//	int sz = strlen(s);
//	for (int i = 0;i < sz;i++) {
//		switch (s[i]-'0')
//		{
//		case 1:
//			cout << "yi" << ' ';
//			break;
//		case 2:
//			cout << "er" << ' ';
//			break;
//		case 3:
//			cout << "san" << ' ';
//			break;
//		case 4:
//			cout << "si" << ' ';
//			break;
//		case 5:
//			cout << "wu" << ' ';
//			break;
//		case 6:
//			cout << "liu" << ' ';
//			break;
//		case 7:
//			cout << "qi" << ' ';
//			break;
//		case 8:
//			cout << "ba" << ' ';
//			break;
//		case 9:
//			cout << "jiu" << ' ';
//			break;
//		case 0:
//			cout << "ling" << ' ';
//			break;
//		default:
//			cout << "fu" << ' ';
//			break;
//		}
//	}
//	return 0;
//}







//const int N = 10;
//char g[N][N];
//int n, k,cnt;
//bool st[N];
//void dfs(int r,int K) {
//	if (K == 0) {
//		cnt++;
//		return;
//	}
//	for (int i = r;i < n;i++) {
//		for (int j = 0;j < n;j++) {
//			if (g[i][j] == '#' && !st[j]) {
//				st[j] = true;
//				dfs(r + 1, K - 1);
//				st[j] = false;
//			}
//		}
//	}
//}
//int main() {
//	while (1) {
//		cin >> n >> k;
//		cnt = 0;
//		if (n == -1 && k == -1)break;
//		for (int i = 0;i < n;i++) {
//			for (int j = 0;j < n;j++) {
//				cin >> g[i][j];
//			}
//		}
//		dfs(0,k);
//		cnt = cnt % (int)pow(2, 31);
//		cout << cnt << endl;
//	}
//	return 0;
//}





//typedef long long ll;
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		ll n, k,s,j;
//		j = 1;
//		cin >> n >> k;
//		s = n - k;
//		ll cnt = 0;
//		while (1) {
//			if (j >= k)break;
//			cnt++;
//			j *= 2;
//		}
//		s =s - j + k;
//		if (s < 0) {
//			;
//		}
//		else {
//			ll cao = s / k;
//			cnt += cao;
//			s = s - cao * k;
//			if (s > 0)cnt++;
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}






//const int N = 1e5 + 10;
//double a[2010], b[2010], ans;
//int p[N];
//int n;
//struct node {
//	int x1, x2;
//	double v;
//
//}e[N];
//int idx, cnt;
//bool cmp(node a, node b)
//{
//	return a.v < b.v;
//}
//double juli(int i, int j) {
//	double dx = a[i] - a[j];
//	double dy = b[i] - b[j];
//	return sqrt(dx * dx + dy * dy);
//}
//int find(int x) {
//	if (x != p[x])p[x] = find(p[x]);
//	return p[x];
//}
//
//int main() {
//	while (1) {
//		++cnt;
//		cin >> n;
//		if (n == 0)break;
//		for (int i = 1;i <= n;i++)p[i] = i;
//		for (int i = 1;i <= n;i++)cin >> a[i] >> b[i];
//		for (int i = 1;i <= n;i++) {
//			for (int j = i + 1;j <= n;j++) {
//				e[++idx].x1 = i, e[idx].x2 = j, e[idx].v = juli(i, j);
//			}
//		}
//		sort(e + 1, e + idx + 1, cmp);
//		for (int i = 1;i <= idx;i++) {
//			if (find(e[i].x1) != find(e[i].x2)) {
//				p[find(e[i].x1)] = find(e[i].x2);
//				if (find(1) == find(2)) {
//					ans = e[i].v;
//					break;
//				}
//			}
//		}
//		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cnt, ans);
//	}
//	return 0;
//}





//const int N = 40;
//int arr[N][N][N];
//char s[N][N][N];
//bool st[N][N][N];
//int x, y, z;
//int main() {
//	int a, b, c;
//	while (1) {
//		cin >> a >> b >> c;
//		if (a == 0 && b == 0 && c == 0)break;
//		for (int i = 1;i <= a;i++) {
//			for (int j = 1;j <= b;j++) {
//				for (int k = 1;k <= c;k++) {
//					cin >> s[i][j][k];
//					if (s[i][j][k] == 'S') {
//						x = i, y = j, z = k;
//					}
//				}
//			}
//		}
//		queue<int>q;
//		q.push(y);
//		q.push(z);
//		q.push(x);
//		int dx[6]{ 0,1,0,-1,0,0 }, dy[6] = { 1,0,-1,0,0,0 }, dz[6]={ 0,0,0,0,1,-1 };
//		int cnt = 0;
//		while (!q.empty()) {
//			int ddx = q.front();
//			q.pop();
//			int ddy = q.front();
//			q.pop();
//			int ddz = q.front();
//			q.pop();
//			int flag = 0;
//			for (int i = 0;i < 6;i++) {
//				int dddx = ddx + dx[i], dddy = ddy + dy[i], dddz = ddz + dz[i];
//				if (dddx<1 || dddy<1 || dddz<1 || dddx>b || dddy>c || dddz>a&&!st[dddx][dddy][dddz]&&s[dddx][dddy][dddz]!='#') {
//					q.push(dddx), q.push(dddy), q.push(dddz);
//					st[dddx][dddy][dddz] = true;
//					flag = 1;
//					arr[dddx][dddy][dddz] = cnt + 1;
//				}
//			}
//			if (flag)cnt++;
//
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}




//char a[200];
//int main() {
//	int n;
//    scanf("%d%s", &n, a);
//    for (int i = 0;i <= n - 1;)
//    {
//        if (i + 2 <= n - 1 && a[i] == 'o' && a[i + 1] == 'g' && a[i + 2] == 'o')
//        {
//            printf("***");
//            i = i + 3;
//            while (i + 1 <= n - 1 && a[i] == 'g' && a[i + 1] == 'o')i += 2;
//        }
//        else printf("%c", a[i]), i++;
//    }
//    printf("\n");
//	
//	return 0;
//}




////
//int n, c, qaq;
//double a[2010], b[2010], ans;
//struct kkk {
//    int x, y;double v;
//}bb[1000000];int tot;
//bool cmp(kkk a, kkk b)
//{
//    return a.v < b.v;
//}
//int fa[2010];
//int get(int x) { return fa[x] == x ? fa[x] : fa[x] = get(fa[x]); }
//double turn(int x, int y)
//{
//    double dx = a[x] - a[y];
//    double dy = b[x] - b[y];
//    return sqrt(dx * dx + dy * dy);
//}
//int main()
//{
//    while (1)
//    {
//        ++qaq;
//        scanf("%d", &n);
//        if (n == 0) break;
//        tot = 0;
//        for (int i = 1;i <= n;i++)
//            fa[i] = i;
//        for (int i = 1;i <= n;i++)
//            scanf("%lf %lf", &a[i], &b[i]);
//
//        for (int i = 1;i <= n;i++)
//            for (int j = i + 1;j <= n;j++)
//                bb[++tot].x = i, bb[tot].y = j, bb[tot].v = turn(i, j);
//
//        sort(bb + 1, bb + tot + 1, cmp);
//
//        for (int i = 1;i <= tot;i++)
//            if (get(bb[i].x) != get(bb[i].y))
//            {
//                fa[get(bb[i].x)] = get(bb[i].y);
//                if (get(1) == get(2))
//                {
//                    ans = bb[i].v;
//                    break;
//                }
//            }
//        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", qaq, ans);
//    }
//    return 0;
//}







//typedef long long ll;
//int main() {
//	int t,n,m;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		ll ans=1;
//		for (int i = n - 1;i >n - m;i--) {
//			ans *= i;
//		}
//		for (int i = m - 1;i >= 1;i--) {
//			ans /= i;
//		}
//		cout << ans << endl;
//	}
//}









//char str[1000];
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> str;
//		int sz = strlen(str);
//		if ( sz== 1 && str[0] == '1')cout << 2 << endl;
//		else cout << str << endl;
//	}
//}





//int main() {
//	int t, m, n;
//	cin >> t;
//	while (t--) {
//		cin >> str >> m;
//		int sz = strlen(str);
//		n = str[sz - 1] - '0' + 10 * (str[sz - 2] - '0');
//		if (m == 5) {
//			for (int i = sz - 3;i >= 0;i--) {
//				n += 4 * (str[i] - '0');
//			}
//		}
//		if (m == 2) {
//			for (int i = sz - 3;i >= 0;i--) {
//				n += str[i] - '0';
//			}
//		}
//		if (n % (m + 1) == 0)cout << "Nolv" << endl;
//		else cout << "Hibiki" << endl;
//	}
//	return 0;
//}





//typedef long long ll;
//const int N = 1e5 + 10;
//ll arr[N];
//int main() {
//	ll m;
//	cin >> arr[0] >> arr[1] >> arr[2]>>m;
//	if (arr[0] >= m)cout << 1;
//	else if (arr[1] >= m)cout << 2;
//	else if (arr[2] >= m)cout << 3;
//	else {
//		for (int i = 3;i < N;i++) {
//			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
//			if (arr[i] >= m) {
//				cout << i + 1;
//				break;
//			}
//		}
//	}
//	return 0;
//}









//const int N = 1e5 + 10;
//int e[N], ne[N],h[N], idx;
//int n, m;
//int dist[N];
//bool st[N];
//void add(int a, int b) {
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int spfa() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	st[1] = true;
//	queue<int>q;
//	q.push(1);
//	while (!q.empty()) {
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//		for (int i = h[t];i != -1;i = ne[i]) {
//			int j = e[i];
//			if ( dist[j] > dist[t] + 1) {
//				dist[j] = dist[t] + 1;
//				if (!st[j]) {
//					q.push(j);
//					st[j] = true;
//				}
//			}
//		}
//	}
//	return dist[n];
//}
//int main() {
//	memset(h, -1, sizeof h);
//	cin >> m >> n;
//	for (int i = 1;i <= m;i++) {
//		int a;
//		cin >> a;
//		if (i - a > 0)add(i, i - a);
//		add(i, i + a);
//	}
//	if (spfa() == 0x3f3f3f3f)cout << "AlbionAlbion!";
//	else cout << spfa();
//	return 0;
//}