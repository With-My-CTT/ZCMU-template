/*	ŷ��ɸ��������ɸ�� + Ī����˹���� 
	���ܣ� �ڽ���ŷ��ɸ������ͬʱ����Ī����˹���� 
*/ 
int mo[MAXN];  //���ɵ�Ī����˹���� 
int prime[MAXN],primesize,phi[MAXN];
bool isprime[MAXN];	//ɸ�����Ľ�� 
void getlist(int listsize) //ɸ�����ķ�Χ 
{
	mo[1]=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i,mo[i]=-1;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
            {
            	mo[i*prime[j]]=0;
            	break;
			}
			else mo[i*prime[j]]=-1*mo[i];
        }
    }
}


