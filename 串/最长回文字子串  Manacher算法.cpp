//��������Ӵ�  Manacher�㷨 
//ʱ�临�Ӷȣ�O(N)
//ʹ�ã�����Ŀ�괮������������ִ��ĳ��� 
int p[MAXN*2+10];  //��¼��������
char h[MAXN*2+10]; //��Ӽ��������ַ��� 
int Manacher(const char * s)  //���Ӷ�Ϊ N 
{  
    int mx=0,id=0;
	int l=strlen(s),len=0;
    clr(p,0);
    h[len++]='&';
    for(int i=0;i<l;i++)
    {
    	h[len++]='#';
    	h[len++]=s[i];
	}
	h[len++]='#';
	h[len]='@';  
	//ע���β�ַ����������ַ���ͬ 
    for(int i=1;i<=len;i++)  
    {  
        if(mx>i) p[i]=min(mx-i,p[2*id-i]);  
        else p[i]=1;  
        while(h[i+p[i]]==h[i-p[i]])  
            p[i]++;  //���������� �ɸ����������� 
        if(p[i]+i>mx)  
        {  
            mx=p[i]+i;  
            id=i;  
        }  
    }  
    int ans=0;  
    for(int i=1;i<=len;i++)  
        ans=max(ans,p[i]-1);  
    return ans;  
}
