//ͼ����ɫ 
//ʱ�临�Ӷȣ�O(n^2) 
//���ڵĵ㲻��Ϳͬһ��ɫ�������ü�����ɫ 
//��ʼ���� ͼG ������n 
//�ڵ�p[i]:num=i;color=0;de=�ܶ��� 
int G[MAXN][MAXN];
struct Node{
   int num,de,color; //��� �� �ڵ���ɫ
}p[MAXN];
bool cmp(Node p1,Node p2) //���ȴӸߵ�������
{ return p1.de > p2.de; }
int PaintColor(int n)
{
	sort(p,p+n,cmp);
	int k=0;
	while(1)
	{
		k++;
		int i;
		for (i = 0; i < n; i++)
			if (!p[i].color) 
			{ p[i].color=k; break; }
		if (i == n) break;
		for(int j=0; j<n; j++)
			if(!p[j].color && !G[ p[i].num ][ p[j].num ] && i!=j)
				p[j].color = k;
	}
	return k-1; 
}



