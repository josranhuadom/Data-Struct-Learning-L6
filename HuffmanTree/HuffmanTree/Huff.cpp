#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

typedef char **HuffmanCode;
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;

void InsertSearch(HuffmanTree &HT, int n)
{
	int i, j;
	for (i = 2; i <=n ; ++i)
	{
		if (HT[i].weight < HT[i -1].weight)
		{
			HT[0] = HT[i];
			HT[i] = HT[i - 1];
			for (j = i - 2; HT[0].weight < HT[j].weight; --j)
				HT[j + 1] = HT[j];
			HT[j + 1] = HT[0];
		}
	}
}

void Select(HuffmanTree &HT, int area, int &s1, int &s2)
{
	int i, flag = 1;
	for (i = 1; (i <= area) || (flag == 1); i++)
	{
		if (HT[i].parent = 0)
		{
			s1 = i;
			s2 = i + 1;
			flag = 0;
		}
		else continue;
	}
}

void CreateHuffmanTree(HuffmanTree &HT, int n)
{
	int m, i, s1, s2;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (i = 1; i <= m; ++i)
	{
		HT[i].parent = 0; 
		HT[i].lchild = 0; 
		HT[i].rchild = 0;
	}
	for (i = 1; i <= n; ++i)
		cin >> HT[i].weight;

	InsertSearch(HT, n);

	for (i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
	int i, c, start, f;
	char *cd;
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i; f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lchild == 0)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy_s(HC[i], 20, &cd[start]);
	}
	delete cd;
}


int main()
{
	int n;
	cout << "请输入 即将输入的叶子节点个数" << endl;
	cin >> n;
	HuffmanTree *HT = new char *[n + 1];
	HuffmanCode *HC = new char *[n + 1];
	CreateHuffmanTree(*HT, n);
	CreateHuffmanCode(*HT, *HC, n);
}