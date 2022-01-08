#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 25;
bool st[N], ist[N][N];

struct poeple
{
	string name;
	int x;
	vector<string>a;
}P[N];

int main()
{
	int n, m;
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].name >> P[i].x;
		for (int j = 0; j < P[i].x;j++)
		{
			string ff;
			cin >> ff;
			P[i].a.push_back(ff);
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1; j < n;j++)
		{
			if (!st[i] && !st[j]) {
				if (P[i].name == P[j].name)
				{
					while (P[j].a.size())
					{
						string cc = P[j].a.back();
						P[i].a.push_back(cc);
						P[j].a.pop_back();
						P[i].x++;
					}
					m--;
					st[j] = true;
				}
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		if (!st[i])
		{
			for (int j = 0; j < P[i].a.size();j++)
			{
				for (int k = j + 1; k < P[i].a.size();k++)
				{
					if (!ist[i][k] && !ist[i][j]) 
					{
						if (P[i].a[k].size() < P[i].a[j].size())
						{
							int flag = 1;
							for (int ccc = P[i].a[k].size() - 1,dd = P[i].a[j].size() - 1; ccc >= 0;dd--,ccc--)
							{
								if (P[i].a[k][ccc] != P[i].a[j][dd]) flag = 0;
							}
							if (flag)
							{
								ist[i][k] = true;
								P[i].x--;
							}
						}
						else
						{
							int flag = 1;
							for (int ccc = P[i].a[j].size() - 1,dd = P[i].a[k].size() - 1; ccc >= 0;dd--,ccc--)
							{
								if (P[i].a[k][dd] != P[i].a[j][ccc]) flag = 0;
							}
							if (flag)
							{
								ist[i][j] = true;
								P[i].x--;
							}
						}
					}
				}
			}
		}
	}
	cout << m << endl;
	for (int i = 0; i < n;i++)
	{
		if (st[i])continue;
		cout << P[i].name << ' ' << P[i].x << ' ';
		for (int j = 0;j < P[i].a.size();j++)
		{
			if (ist[i][j])continue;
			cout << P[i].a[j] << ' ';
		}
		cout << endl;
	}
	return 0;
}



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