#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int arr[10000];
	cin >> arr[0];
	int i = 0;
	while (arr[i] != -1) {
		i++;
		cin >> arr[i];
	}
	sort(arr, arr + i);
	*lower_bound(arr, arr + i, 3) = 4;
	for (int j = 0;j < i;j++)cout << arr[j] << ' ';
	return 0;
}