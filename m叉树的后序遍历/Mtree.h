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
//�˵�
void menu();
//���ӱ�
void add(int a, int b);
//����m����
char CreateMtree();
//m�����ĺ������
void MtreePostTraversal(int root);