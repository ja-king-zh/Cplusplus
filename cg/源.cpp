#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<deque>
#include<map>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	deque<int>q;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (q.empty() || a[i] <= 2 * a[q.front()])
		{
			q.push_back(i);
			ans = max(ans, (int)q.size());
			continue;
		}
		while (a[i] > 2 * a[q.front()]) q.pop_front();
		q.push_back(i);
		ans = max(ans, (int)q.size());
	}
	cout << ans << endl;
	return 0;
}
