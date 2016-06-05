/*----------------------------------------------------------------------------------------*/
/*此代码运行结果与实验指导有所出入，但是在下相信本代码运行出的结果是对的*/
/*---------------------------------------------------------------------------------------*/
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

void Select(HuffmanTree &HT, int area, int &s1, int &s2)
{
	int a, check;
	//s1部分
	//检查数组内第一个双亲为零的元素，并将其weight赋值给check
	for (a = 1; a <= area; a++)
	{
		if (HT[a].parent == 0)
		{
			check = HT[a].weight;
			s1 = a;
			break;
		}
	}
	//check对数组的每一个元素的weight进行对比，若有weight比check小，weight赋值于check，a赋值于s1，然后继续进行对比至最后
	for (a = 1; a <= area; a++)
	{
		if (check > HT[a].weight && HT[a].parent == 0)
		{
			check = HT[a].weight;
			s1 = a;
		}
	}
	HT[s1].parent = 1;    //先将已经赋予s1的元素的parent置为1，以防s2重复赋值
	//s2部分，重复以上步骤
	for (a = 1; a <= area; a++)
	{
		if (HT[a].parent == 0)
		{
			check = HT[a].weight;
			s2 = a;
			break;
		}
	}
	for (a = 1; a <= area; a++)
	{
		if (check > HT[a].weight && HT[a].parent == 0)
		{
			check = HT[a].weight;
			s2 = a;
		}
	}
}

void CreateHuffmanTree(HuffmanTree &HT, int n)
{
	int m, i, s1, s2;
	while (n <= 1)
	{
		cout << "请输入个大于 1 的数" << endl;
		cin >> n;
	}
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (i = 1; i <= m; ++i)
	{
		HT[i].parent = 0; 
		HT[i].lchild = 0; 
		HT[i].rchild = 0;
	}
	cout << "请输入叶子节点的权值：" << endl;
	for (i = 1; i <= n; ++i)
		cin >> HT[i].weight;

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
	HC = new char *[n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i; f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy_s(HC[i], n - start, &cd[start]);
	}
	delete cd;
}


int main()
{
	int n;
	cout << "请输入即将输入的叶子节点个数" << endl;
	cin >> n;
	HuffmanTree HT;
	HuffmanCode HC;
	CreateHuffmanTree(HT, n);
	CreateHuffmanCode(HT, HC, n);

	for (int i = 1; i <= n; i++) 
		cout << i << "的编码为：" << HC[i] << " " << endl;

	system("pause");
}