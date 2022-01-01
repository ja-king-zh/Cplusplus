#pragma once
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

const int N = 1010;
static int e[N], ne[N], h[N], idx;
typedef struct Mtree {
	int e[N];
	int ne[N];
	int h[N];
	int idx;
}Mtree;
//菜单
void menu();
//链接边
void add(int a, int b);
//创建m叉树
char CreateMtree();
//m叉树的后序遍历
void MtreePostTraversal(int root);