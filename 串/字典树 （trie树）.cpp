//�ֵ��� trie��
//���� �������ַ�������һ��ǰ׺����
//		ʵ�ֶ��ַ����Ŀ��ٲ��� 
//ʱ�临�Ӷ� ������ O(l)  ���� O(l)
//�ռ临�Ӷ� ���ַ����ܳ��� * �ַ������� 
//�ص㣺ʡʱ�����ռ俪���ϴ�  

const int Max_node = 41000;  //���������ַ����ĳ��Ⱥ� 
const int Sigma_size = 26;   //�ַ��������� 
int ch[Max_node][Sigma_size];
int val[Max_node];
int L; 
void Init() //Ԥ����
{ L=1; memset(ch[0],0,sizeof(ch[0])); } 
inline int idx(char c) { return c-'a'; }
//�ַ����������ֵĺ���
void Insert(char *s, int vv)
{	//vv:�ò�����ַ���Ȩֵ������,��ʡ��,������Ϊ 0  
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0) //empty
        {
            memset(ch[L],0,sizeof(ch[L]));
            val[L]=0; //not a word
            ch[u][c]=L++;
        }
        u=ch[u][c];
    }
    val[u]+=vv; //vv ����� 0,һ���ַ����Ľ��� 
}

bool Search(char *s)
{	
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0)
            return false;
        u=ch[u][c];
    }
    if (val[u]==0) return false; 
    return true; 
}



//�ֵ������������  
//    ��ѯ�ַ�����'��'���滻�����ַ���ɾȥ
//	  �������ѯ���ַ�������

//������ �ݹ� ��չ��ѯ�ַ��� 
//��ʼ���͹����ֵ�����ͬ
 
char s[55];   //������ѯ���ĳ��� 
int vis[Max_node];	
//��Ǹ��ַ����ڸò�ѯ���Ƿ��Ѿ��ù� 
int l,flag;
void Search(int now,int k)
{	//now:���ֵ����е�λ��  
	//k:��ѯ�ַ�����ǰ������λ�� 
	if(k==l)
	{
		if(val[now]&&vis[now]!=flag) 
		{
			ans+=val[now];
			vis[now]=flag;
		}
		return ;	
	}
	if(s[k]=='?')
	{
		Search(now,k+1); //��'��'ɾ��������ѯ 
		for(int i=0;i<5;i++) //��'��'�滻�������ַ���ѯ 
			if(ch[now][i])
				Search(ch[now][i],k+1);
	}
	else
	{
		int u=idx(s[k]);
		if(ch[now][u])
			Search(ch[now][u],k+1);
	}
}

int n,m;
int main()
{
	cin>>n>>m;
	Init();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		Insert(s,1); 
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		ans=0;
		flag=i;  
		Search(0,0);
		printf("%d\n",ans);
	}
	return 0;
}

 
