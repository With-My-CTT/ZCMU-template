//��С������ Kruskal �߼� 
//ʱ�临�Ӷȣ�o(mlogn) 
//���룺 ����m  �߼�es[] 
//���أ� ������Ȩֵ��ͼ���ܲ���ͨ�� 
//��ע�����в��䲢�鼯���� 
struct edge{ int x,y,cost }; 
bool cmp(const edge &e1,edge &e2)
{ return e1.cost<e1.cost; }
edge es[MAX_E]; //�����еı�
int n,m;
int Kruskal()
{
	sort(es,es+m,cmp);
	Init_find();  //��ʼ�����鼯 
	int res=0;
	for(int i=0;i<m;i++)
	{
		edge e=es[i];
		if(find(e.x)!=find(e.y)) 
		{  //���鼯
			merge(e.x,e.y);
			res+=e.cost;
		 } 
	}
	return ans;
 } 
 
 
