//�ַ���ƥ��  KMP   
//ʱ�临�Ӷȣ�O(n+m) 
/*���� 
	�ַ�����Сѭ���ڳ��� �� 
	cir = len - next[len] ;  */ 

int next[MAXN];
void getnext(const char *s)
{
    int i = 0, j = -1,len=strlen(s);
    next[0] = -1;
    while(i != len)
    {
        if(j == -1 || s[i] == s[j])
            next[++i] = ++j;
        else  j = next[j];
    }
}
int Find(char *T,char *P)
{
    int len1=strlen(T),len2=strlen(P);
    getnext(P); //���next���� 
    int j = 0, ans=0 ;
	int ok=1,First=0;
    for(int i = 0; i < len1; i++)
    {
        while(j && P[j] != T[i])
            j = next[j];
        if(P[j] == T[i]) j++;
        if(j == len2) 
		{
			if(ok) { First=i;ok=0; }
			ans++;
		}
    }
    return ans;     //����Ŀ�괮������ 
    return First;   //��һ��Ŀ�괮��λ�� 
}
