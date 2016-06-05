/*----------------------------------------------------------------------------------------*/
/*�˴������н����ʵ��ָ���������룬�����������ű��������г��Ľ���ǶԵ�*/
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
	//s1����
	//��������ڵ�һ��˫��Ϊ���Ԫ�أ�������weight��ֵ��check
	for (a = 1; a <= area; a++)
	{
		if (HT[a].parent == 0)
		{
			check = HT[a].weight;
			s1 = a;
			break;
		}
	}
	//check�������ÿһ��Ԫ�ص�weight���жԱȣ�����weight��checkС��weight��ֵ��check��a��ֵ��s1��Ȼ��������жԱ������
	for (a = 1; a <= area; a++)
	{
		if (check > HT[a].weight && HT[a].parent == 0)
		{
			check = HT[a].weight;
			s1 = a;
		}
	}
	HT[s1].parent = 1;    //�Ƚ��Ѿ�����s1��Ԫ�ص�parent��Ϊ1���Է�s2�ظ���ֵ
	//s2���֣��ظ����ϲ���
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
		cout << "����������� 1 ����" << endl;
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
	cout << "������Ҷ�ӽڵ��Ȩֵ��" << endl;
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
	cout << "�����뼴�������Ҷ�ӽڵ����" << endl;
	cin >> n;
	HuffmanTree HT;
	HuffmanCode HC;
	CreateHuffmanTree(HT, n);
	CreateHuffmanCode(HT, HC, n);

	for (int i = 1; i <= n; i++) 
		cout << i << "�ı���Ϊ��" << HC[i] << " " << endl;

	system("pause");
}