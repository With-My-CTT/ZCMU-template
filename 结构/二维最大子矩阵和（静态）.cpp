/*	��ά����Ӿ���ͣ���̬��	 
	ʱ�临�Ӷȣ�n*n*m 
*/

const int maxn=102;  
int G[maxn][maxn];  
int main()  
{  
    int ans,T,n,m,Max,temp;  
    scanf("%d",&T);  
    while(T--)  
    {  
        memset(G,0,sizeof(G));
        scanf("%d%d",&n,&m);  
        for(int i=1; i<=n; i++)  
        {  
            for(int j=0; j<m; j++)  
            {  
                scanf("%d",&G[i][j]);  
                G[i][j]+=G[i-1][j];  
            }  //��G���ͬһ���ڵ�ǰ׺�;��� 
        }  
        ans=G[1][0];
        for(int i=1; i<=n; i++)  
            for(int j=i; j<=n; j++)  
            {  
                for(int k=Max=0; k<m; k++)  
                {  
                    int temp=G[j][k]-G[i-1][k];  
                    if(Max<0) Max=0;
                    Max+=temp;
                    ans=Max>ans?Max:ans;  
                }  
            }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
