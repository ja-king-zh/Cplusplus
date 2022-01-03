#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
char a[50], b[50];
int arr[50];
int main()
{
	cin >> a >> b;
	int lena = strlen(a), lenb = strlen(b);
	for (int i = 0; i < lena; i++)
	{
		a[i] = '1' - a[i] + '0';
		for (int j = 0; j < lena; j++)
		{
			arr[i] += (a[j] - '0') * pow(2, lena - 1 - j);
		}
		a[i] = '1' - a[i] + '0';
	}
	while (lena--)
	{
		int f = 0;
		while(1)
		{
			int cnt = 0, i = 0, ans = arr[lena];
			while (arr[lena])
			{
				if (arr[lena] % 3 != b[lenb - 1 - i] - '0')cnt++;
				arr[lena] /= 3;
				i++;
			}
			if (lenb - i)cnt += lenb - i;
			if (cnt == 1)
			{
				cout << ans;
				f = 1;
				
			}
			break;
		}
		if (f)break;
	}
	return 0;
}