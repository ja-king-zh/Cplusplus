#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;
int f[N][M], a[N][N];
bool st[M];
vector<int>v[M];
vector<int>state;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    //预处理合法状态
    for (int i = 0; i < 1 << m; i++)
    {
        int flag = 1;
        for (int j = 0; j < m - 1; j++)
        {
            if ((i >> j) & 1 && (i >> (j + 1)) & 1) flag = 0;
        }
        if (flag) st[i] = true, state.push_back(i);
    }
    //预处理可转移状态
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((i & j) == 0) v[i].push_back(j);
        }
    }
    //dp
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            int f = 0;
            for (int k = 0; k < m; k++)
            {
                if (((j >> k) & 1))
                {
                    if (a[i][k] == 0) f = 1;
                }
            }
            if (f) continue;
            for (auto t : v[j])
            {
                f[i][j] = (f[i][j] + f[i - 1][t]) % mod;
            }
        }
    }
    cout << f[n + 1][0] % mod << endl;
    return 0;
}

///*
//下文对  if((j&k )==0 && st[ j| k] )  有清晰的解释！！！
//*/
//
//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m;
//		if (n == m)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//		if (m == 1)
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		int cnt = n / m;
//		int k = n - cnt * m + cnt;
//		while (k >= m)
//		{
//			cnt = k / m;
//			k =k - m * cnt + cnt;
//		}
//		cout << (2 * n - 2 * k + m - 1) / (m - 1) << endl;
//	}
//	return 0;
//}


//const int N = 12, M = 1 << N;
//
//long long f[N][M];// 第一维表示列， 第二维表示所有可能的状态
//
//bool st[M];  //存储每种状态是否有奇数个连续的0，如果奇数个0是无效状态，如果是偶数个零置为true。
//
////vector<int > state[M];  //二维数组记录合法的状态
//vector<vector<int>> state(M);  //两种写法等价:二维数组
//int m, n;
//
//int main() {
//
//    while (cin >> n >> m, n || m) { //读入n和m，并且不是两个0即合法输入就继续读入
//
//        //第一部分：预处理1
//        //对于每种状态，先预处理每列不能有奇数个连续的0
//
//        for (int i = 0; i < 1 << n; i++) {
//
//            int cnt = 0;//记录连续的0的个数
//
//            bool isValid = true; // 某种状态没有奇数个连续的0则标记为true
//
//            for (int j = 0;j < n;j++) { //遍历这一列，从上到下
//
//                if (i >> j & 1) {  //i>>j位运算，表示i（i在此处是一种状态）的二进制数的第j位； &1为判断该位是否为1，如果为1进入if
//                    if (cnt & 1) { //这一位为1，看前面连续的0的个数，如果是奇数（cnt &1为真）则该状态不合法
//                        isValid = false;break;
//                    }
//                    cnt = 0; // 既然该位是1，并且前面不是奇数个0（经过上面的if判断），计数器清零。//其实清不清零没有影响
//                }
//                else cnt++; //否则的话该位还是0，则统计连续0的计数器++。
//            }
//            if (cnt & 1)  isValid = false; //最下面的那一段判断一下连续的0的个数
//
//            st[i] = isValid; //状态i是否有奇数个连续的0的情况,输入到数组st中
//        }
//
//        //第二部分：预处理2
//        // 经过上面每种状态 连续0的判断，已经筛掉一些状态。
//        //下面来看进一步的判断：看第i-2列伸出来的和第i-1列伸出去的是否冲突
//
//        for (int j = 0;j < 1 << n;j++) { //对于第i列的所有状态
//            state[j].clear(); //清空上次操作遗留的状态，防止影响本次状态。
//            for (int k = 0;k < 1 << n;k++) { //对于第i-1列所有状态
//                if ((j & k) == 0 && st[j | k]) // 第i-2列伸出来的 和第i-1列伸出来的不冲突(不在同一行) 
//                //解释一下st[j | k] 
//                //已经知道st[]数组表示的是这一列没有连续奇数个0的情况，
//                //我们要考虑的是第i-1列（第i-1列是这里的主体）中从第i-2列横插过来的，还要考虑自己这一列（i-1列）横插到第i列的
//                //比如 第i-2列插过来的是k=10101，第i-1列插出去到第i列的是 j =01000，
//                //那么合在第i-1列，到底有多少个1呢？自然想到的就是这两个操作共同的结果：两个状态或。 j | k = 01000 | 10101 = 11101
//                //这个 j|k 就是当前 第i-1列的到底有几个1，即哪几行是横着放格子的
//
//                    state[j].push_back(k);  //二维数组state[j]表示第j行， 
//                    //j表示 第i列“真正”可行的状态，如果第i-1列的状态k和j不冲突则压入state数组中的第j行。
//                    //“真正”可行是指：既没有前后两列伸进伸出的冲突；又没有连续奇数个0。
//            }
//
//        }
//
//        //第三部分：dp开始
//
//        memset(f, 0, sizeof f);  //全部初始化为0，因为是连续读入，这里是一个清空操作。类似上面的state[j].clear()
//
//        f[0][0] = 1;// 这里需要回忆状态表示的定义，按定义这里是：前第-1列都摆好，且从-1列到第0列伸出来的状态为0的方案数。
//        //首先，这里没有-1列，最少也是0列。其次，没有伸出来，即没有横着摆的。即这里第0列只有竖着摆这1种状态。
//
//        for (int i = 1;i <= m;i++) { //遍历每一列:第i列合法范围是(0~m-1列)
//            for (int j = 0; j < 1 << n; j++) {  //遍历当前列（第i列）所有状态j
//                for (auto k : state[j])    // 遍历第i-1列的状态k，如果“真正”可行，就转移
//                    f[i][j] += f[i - 1][k];    // 当前列的方案数就等于之前的第i-1列所有状态k的累加。
//            }
//        }
//
//        //最后答案是什么呢？
//        //f[m][0]表示 前m-1列都处理完，并且第m-1列没有伸出来的所有方案数。
//        //即整个棋盘处理完的方案数
//
//        cout << f[m][0] << endl;
//
//    }
//}



//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int N = 1e5 + 10;
//long long s[N], a[N], aa[N];
//bool st[N];
//
//int main()
//{
//    memset(aa, 0x3f, sizeof aa);
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> s[i];
//    long long res = 1e9 + 10, ans = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        ans = s[i];
//        for (int j = i + 1; j <= n; j++)
//        {
//            if (a[j] > a[i])
//            {
//                ans += s[j];
//                aa[j] = min(ans, aa[j]);
//                ans -= s[j];
//            }
//        }
//    }
//    int f = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (aa[i])
//        {
//            ans = aa[i];
//            for (int j = i + 1; j <= n; j++)
//            {
//                if (a[j] > a[i])
//                {
//                    ans += s[j];
//                    res = min(res, ans);
//                    ans -= s[j];
//                    f = 1;
//                    st[i] = true;
//                }
//            }
//        }
//    }
//    if (f)
//    {
//        cout << res << endl;
//    }
//    else cout << -1 << endl;
//    return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int N = 15;
//int s[N], a[N];
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> s[i];
//    int res = 0, ans = 1e9 + 10, f = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        res = s[i];
//        for (int j = i + 1; j <= n; j++)
//        {
//            if (a[j] > a[i])
//            {
//                res += s[j];
//                for (int k = j + 1; k <= n; k++)
//                {
//                    if (a[k] > a[j])
//                    {
//                        res += s[k];
//                        ans = min(ans, res);
//                        f = 1;
//                        res -= s[k];
//                    }
//                }
//                res -= s[j];
//            }
//        }
//    }
//    if (!f) cout << -1 << endl;
//    else cout << ans << endl;
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//int a[5], ans, res = 1e9 + 10;
//char op[5][2];
//
//void dfs(int u, int i, int j)
//{
//    if (u == 4)
//    {
//        res = min(res, ans);
//        return;
//    }
//    if (a[i] == -1 || a[j] == -1 || u > 3) return;
//    if (*op[u] == '*')
//    {
//        int x = a[i], y = a[j];
//        if(u == 3)
//            ans = a[i] * a[j];
//        a[i] = a[i] * a[j];
//        a[j] = -1;
//        for (int i = 1; i <= 4; i++)
//        {
//            for (int j = i + 1; j <= 4; j++)
//            {
//                dfs(u + 1, i, j);
//            }
//        }
//        a[i] = x, a[j] = y;
//    }
//    else
//    {
//        int x = a[i], y = a[j];
//        if(u == 3)
//            ans = a[i] + a[j];
//        a[i] = a[i] + a[j];
//        a[j] = -1;
//        for (int i = 1; i <= 4; i++)
//        {
//            for (int j = i + 1; j <= 4; j++)
//            {
//                dfs(u + 1, i, j);
//            }
//        }
//        a[i] = x, a[j] = y;
//        ans = ans - x + y;
//    }
//}
//
//int main()
//{
//    for (int i = 1; i <= 4; i++) cin >> a[i];
//    cin >> op[1] >> op[2] >> op[3];
//    for (int i = 1; i <= 4; i++)
//    {
//        for (int j = i + 1; j <= 4; j++)
//        {
//            dfs(1, i, j);
//        }
//    }
//    cout << res << endl;
//    return 0;
//}




//const int N = 110;
//int g[N][N], level[N];
//int dist[N];
//bool st[N];
//int n, m;
//
//int dijkstra(int l, int r)
//{
//    memset(dist, 0x3f, sizeof dist);
//    memset(st, 0, sizeof st);
//
//    dist[0] = 0;
//
//    for (int i = 0; i <= n; i++)
//    {
//        int t = -1;
//
//        for (int j = 0; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//
//        st[t] = true;
//
//        for (int j = 1; j <= n; j++)
//            if (level[j] >= l && level[j] <= r)
//                dist[j] = min(dist[j], dist[t] + g[t][j]);
//    }
//
//    return dist[1];
//
//}
//
//int main()
//{
//    cin >> m >> n;
//
//    memset(g, 0x3f, sizeof g);
//    for (int i = 0; i <= n; i++) g[i][i] = 0;
//
//    for (int i = 1; i <= n; i++)
//    {
//        int price, cnt;
//        cin >> price >> level[i] >> cnt;
//        g[0][i] = min(g[0][i], price);
//        while (cnt--)
//        {
//            int cost, id;
//            cin >> id >> cost;
//            g[id][i] = min(g[id][i], cost);
//        }
//    }
//
//    int res = 0x3f3f3f3f;
//    for (int i = level[1] - m; i <= level[1]; i++) res = min(res, dijkstra(i, m + i));
//
//    cout << res << endl;
//
//    return 0;
//}





//#include<iostream>
//#include<cstring>
//#include<stdlib.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 25;
//bool st[N], ist[N][N];
//
//struct poeple
//{
//	string name;
//	int x;
//	vector<string>a;
//}P[N];
//
//int main()
//{
//	int n, m;
//	cin >> n;
//	m = n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> P[i].name >> P[i].x;
//		for (int j = 0; j < P[i].x;j++)
//		{
//			string ff;
//			cin >> ff;
//			P[i].a.push_back(ff);
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = i + 1; j < n;j++)
//		{
//			if (!st[i] && !st[j]) {
//				if (P[i].name == P[j].name)
//				{
//					while (P[j].a.size())
//					{
//						string cc = P[j].a.back();
//						P[i].a.push_back(cc);
//						P[j].a.pop_back();
//						P[i].x++;
//					}
//					m--;
//					st[j] = true;
//				}
//			}
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (!st[i])
//		{
//			for (int j = 0; j < P[i].a.size();j++)
//			{
//				for (int k = j + 1; k < P[i].a.size();k++)
//				{
//					if (!ist[i][k] && !ist[i][j]) 
//					{
//						if (P[i].a[k].size() < P[i].a[j].size())
//						{
//							int flag = 1;
//							for (int ccc = P[i].a[k].size() - 1,dd = P[i].a[j].size() - 1; ccc >= 0;dd--,ccc--)
//							{
//								if (P[i].a[k][ccc] != P[i].a[j][dd]) flag = 0;
//							}
//							if (flag)
//							{
//								ist[i][k] = true;
//								P[i].x--;
//							}
//						}
//						else
//						{
//							int flag = 1;
//							for (int ccc = P[i].a[j].size() - 1,dd = P[i].a[k].size() - 1; ccc >= 0;dd--,ccc--)
//							{
//								if (P[i].a[k][dd] != P[i].a[j][ccc]) flag = 0;
//							}
//							if (flag)
//							{
//								ist[i][j] = true;
//								P[i].x--;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << m << endl;
//	for (int i = 0; i < n;i++)
//	{
//		if (st[i])continue;
//		cout << P[i].name << ' ' << P[i].x << ' ';
//		for (int j = 0;j < P[i].a.size();j++)
//		{
//			if (ist[i][j])continue;
//			cout << P[i].a[j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//int bfs(string st)
//{
//    string end = "12345678x";
//    queue<string>q;
//    unordered_map<string, int>dist;
//    q.push(st);
//    dist[st] = 0;
//
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        int d = dist[t];
//        if (t == end) return d;
//        int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
//        for (int i = 0; i < 4; i++)
//        {
//            int k = t.find('x');
//            int x = k / 3, y = k % 3;
//            int a = x + dx[i], b = y + dy[i];
//            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
//            swap(t[k], t[a * 3 + b]);
//            if (!dist.count(t))
//            {
//                q.push(t);
//                dist[t] = d + 1;
//            }
//            swap(t[k], t[a * 3 + b]);
//        }
//    }
//
//    return -1;
//}
//
//int main()
//{
//    string st;
//    for (int i = 0; i < 9; i++)
//    {
//        char c;
//        cin >> c;
//        st += c;
//    }
//
//    cout << bfs(st) << endl;
//
//    return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<deque>
//using namespace std;
//typedef pair<int, int>PII;
//
//const int N = 510;
//int dist[N][N];
//bool st[N][N];
//char g[N][N];
//int n, m;
//
//int bfs()
//{
//    memset(st, 0, sizeof st);
//    memset(dist, 0x3f, sizeof dist);
//    deque<PII>q;
//    q.push_back({ 0, 0 });
//    dist[0][0] = 0;
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop_front();
//        if (t.first == n && t.second == m) return dist[n][m];
//        if (st[t.first][t.second]) continue;
//        st[t.first][t.second] = true;
//
//        int dx[4] = { -1, 1, 1, -1 }, dy[4] = { -1, -1, 1, 1 };
//        int ix[4] = { -1, 0, 0, -1 }, iy[4] = { -1, -1, 0, 0 };
//        char ss[5] = "\\/\\/";
//        for (int i = 0; i < 4; i++)
//        {
//            int x = t.first + dx[i], y = t.second + dy[i];
//            int a = t.first + ix[i], b = t.second + iy[i];
//            if (x < 0 || y < 0 || x > n || y > m) continue;
//            int w = (ss[i] != g[a][b]);
//            int d = dist[t.first][t.second] + w;
//            if (d < dist[x][y])
//            {
//                dist[x][y] = d;
//                if (!w) q.push_front({ x, y });
//                else q.push_back({ x, y });
//            }
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        cin >> n >> m;
//        for (int i = 0; i < n; i++) cin >> g[i];
//        if ((n + m) % 2 == 1) cout << "NO SOLUTION" << endl;
//        else cout << bfs() << endl;
//    }
//    return 0;
//}




//#include<iostream>
//#include<algorithm>
//#include<stack>
//#include<queue>
//using namespace std;
//
//typedef pair<int, int>PII;
//const int N = 1010;
//PII a[N][N];
//int g[N][N];
//bool st[N][N];
//int n;
//
//void bfs(int sx, int sy)
//{
//    queue<PII>q;
//    q.push({ sx, sy });
//    st[sx][sy] = true;
//    int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++)
//        {
//            int x = t.first + dx[i], y = t.second + dy[i];
//            if (x < 0 || y < 0 || x >= n || y >= n) continue;
//            if (st[x][y]) continue;
//            if (g[x][y]) continue;
//            q.push({ x, y });
//            st[x][y] = true;
//            a[x][y] = t;
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cin >> g[i][j];
//        }
//    }
//    bfs(0, 0);
//    stack<PII>s;
//    s.push({ n - 1, n - 1 });
//    int x = n - 1, y = n - 1;
//    while (a[x][y].first || a[x][y].second)
//    {
//        auto t = a[x][y];
//        x = t.first, y = t.second;
//        s.push({ x,y });
//    }
//    s.push({ 0,0 });
//    while (!s.empty())
//    {
//        auto t = s.top();
//        s.pop();
//        cout << t.first << ' ' << t.second << endl;
//    }
//    return 0;
//}



//#include<iostream>
//#include<queue>
//using namespace std;
//
//const int N = 1010;
//typedef pair<int, int>PII;
//int a[N][N];
//bool st[N][N];
//int n;
//
//void bfs(int sx, int sy, bool& has_greater, bool& has_lower)
//{
//    has_greater = false, has_lower = false;
//    queue<PII>q;
//    q.push({ sx, sy });
//    st[sx][sy] = true;
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        for (int i = -1; i <= 1; i++)
//        {
//            for (int j = -1; j <= 1; j++)
//            {
//                int x = t.first + i, y = t.second + j;
//                if (x < 0 || x >= n || y < 0 || y >= n) continue;
//                if (a[x][y] != a[t.first][t.second])
//                {
//                    if (a[x][y] > a[t.first][t.second])
//                    {
//                        has_greater = true;
//                    }
//                    else has_lower = true;
//                }
//                else if(!st[x][y])
//                {
//                    q.push({ x, y });
//                    st[x][y] = true;
//                }
//
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cin >> a[i][j];
//        }
//    }
//    int sf = 0, sg = 0;
//    bool has_greater = false, has_lower = false;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (!st[i][j])
//            {
//                bfs(i, j, has_greater, has_lower);
//                if (!has_greater) sf++;
//                if (!has_lower) sg++;
//            }
//        }
//    }
//    cout << sf << ' ' << sg << endl;
//    return 0;
//}

//int main()
//{
//	char a1[10] = "1111111";
//	char a2[10] = "0000000";
//	char arr[110];
//	cin >> arr;
//	if (strstr(arr, a1) && strstr(arr, a2))cout << "Yes";
//	else cout << "No";
//	return 0;
//}