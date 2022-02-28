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
    //Ԥ����Ϸ�״̬
    for (int i = 0; i < 1 << m; i++)
    {
        int flag = 1;
        for (int j = 0; j < m - 1; j++)
        {
            if ((i >> j) & 1 && (i >> (j + 1)) & 1) flag = 0;
        }
        if (flag) st[i] = true, state.push_back(i);
    }
    //Ԥ�����ת��״̬
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
//���Ķ�  if((j&k )==0 && st[ j| k] )  �������Ľ��ͣ�����
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
//long long f[N][M];// ��һά��ʾ�У� �ڶ�ά��ʾ���п��ܵ�״̬
//
//bool st[M];  //�洢ÿ��״̬�Ƿ���������������0�����������0����Ч״̬�������ż��������Ϊtrue��
//
////vector<int > state[M];  //��ά�����¼�Ϸ���״̬
//vector<vector<int>> state(M);  //����д���ȼ�:��ά����
//int m, n;
//
//int main() {
//
//    while (cin >> n >> m, n || m) { //����n��m�����Ҳ�������0���Ϸ�����ͼ�������
//
//        //��һ���֣�Ԥ����1
//        //����ÿ��״̬����Ԥ����ÿ�в�����������������0
//
//        for (int i = 0; i < 1 << n; i++) {
//
//            int cnt = 0;//��¼������0�ĸ���
//
//            bool isValid = true; // ĳ��״̬û��������������0����Ϊtrue
//
//            for (int j = 0;j < n;j++) { //������һ�У����ϵ���
//
//                if (i >> j & 1) {  //i>>jλ���㣬��ʾi��i�ڴ˴���һ��״̬���Ķ��������ĵ�jλ�� &1Ϊ�жϸ�λ�Ƿ�Ϊ1�����Ϊ1����if
//                    if (cnt & 1) { //��һλΪ1����ǰ��������0�ĸ����������������cnt &1Ϊ�棩���״̬���Ϸ�
//                        isValid = false;break;
//                    }
//                    cnt = 0; // ��Ȼ��λ��1������ǰ�治��������0�����������if�жϣ������������㡣//��ʵ�岻����û��Ӱ��
//                }
//                else cnt++; //����Ļ���λ����0����ͳ������0�ļ�����++��
//            }
//            if (cnt & 1)  isValid = false; //���������һ���ж�һ��������0�ĸ���
//
//            st[i] = isValid; //״̬i�Ƿ���������������0�����,���뵽����st��
//        }
//
//        //�ڶ����֣�Ԥ����2
//        // ��������ÿ��״̬ ����0���жϣ��Ѿ�ɸ��һЩ״̬��
//        //����������һ�����жϣ�����i-2��������ĺ͵�i-1�����ȥ���Ƿ��ͻ
//
//        for (int j = 0;j < 1 << n;j++) { //���ڵ�i�е�����״̬
//            state[j].clear(); //����ϴβ���������״̬����ֹӰ�챾��״̬��
//            for (int k = 0;k < 1 << n;k++) { //���ڵ�i-1������״̬
//                if ((j & k) == 0 && st[j | k]) // ��i-2��������� �͵�i-1��������Ĳ���ͻ(����ͬһ��) 
//                //����һ��st[j | k] 
//                //�Ѿ�֪��st[]�����ʾ������һ��û������������0�������
//                //����Ҫ���ǵ��ǵ�i-1�У���i-1������������壩�дӵ�i-2�к������ģ���Ҫ�����Լ���һ�У�i-1�У���嵽��i�е�
//                //���� ��i-2�в��������k=10101����i-1�в��ȥ����i�е��� j =01000��
//                //��ô���ڵ�i-1�У������ж��ٸ�1�أ���Ȼ�뵽�ľ���������������ͬ�Ľ��������״̬�� j | k = 01000 | 10101 = 11101
//                //��� j|k ���ǵ�ǰ ��i-1�еĵ����м���1�����ļ����Ǻ��ŷŸ��ӵ�
//
//                    state[j].push_back(k);  //��ά����state[j]��ʾ��j�У� 
//                    //j��ʾ ��i�С����������е�״̬�������i-1�е�״̬k��j����ͻ��ѹ��state�����еĵ�j�С�
//                    //��������������ָ����û��ǰ�������������ĳ�ͻ����û������������0��
//            }
//
//        }
//
//        //�������֣�dp��ʼ
//
//        memset(f, 0, sizeof f);  //ȫ����ʼ��Ϊ0����Ϊ���������룬������һ����ղ��������������state[j].clear()
//
//        f[0][0] = 1;// ������Ҫ����״̬��ʾ�Ķ��壬�����������ǣ�ǰ��-1�ж��ںã��Ҵ�-1�е���0���������״̬Ϊ0�ķ�������
//        //���ȣ�����û��-1�У�����Ҳ��0�С���Σ�û�����������û�к��Űڵġ��������0��ֻ�����Ű���1��״̬��
//
//        for (int i = 1;i <= m;i++) { //����ÿһ��:��i�кϷ���Χ��(0~m-1��)
//            for (int j = 0; j < 1 << n; j++) {  //������ǰ�У���i�У�����״̬j
//                for (auto k : state[j])    // ������i-1�е�״̬k����������������У���ת��
//                    f[i][j] += f[i - 1][k];    // ��ǰ�еķ������͵���֮ǰ�ĵ�i-1������״̬k���ۼӡ�
//            }
//        }
//
//        //������ʲô�أ�
//        //f[m][0]��ʾ ǰm-1�ж������꣬���ҵ�m-1��û������������з�������
//        //���������̴�����ķ�����
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