#include<iostream>
using namespace std;

typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;

int Select(HuffmanTree HT, int area, int &s1, int &s2)
{

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
}

int main()
{
	int n;
	HuffmanTree *HT;
	cin >> n;
}