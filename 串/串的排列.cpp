//��������

//����ȫ���к���
#include <algorithm>
int a[MAXN],n;
sort(a,a+n);
do{
	//��������� 
}while(next_permutation(a,a+n));
//��ȡ��һ���ϴ��ֵ��� 
//�������ڳ�ʼ��ʱ���˳�ѭ�� 


//���ַ������/��С�ֵ���
//���룺��ʼ�ַ���s
//���أ���s�����/��С�ֵ������ʼλ��
 
char s[MAXN*2+10];
char S[MAXN*2+10];   //  �����ַ��� 
int MinRepresstation(const char *s)
{//����С��ʾ�����ַ���S����С�ֵ��� 
 //�����ֵ�����С�Ĵ�������ĸλ��
    int i = 0, j = 1, k = 0;
    strcpy(S,s);
    strcat(S,s);  //ʹ��S[]Ϊs[]������ 
	int len = strlen(s);
    while(i < len && j < len)
    {
        k = 0;
        while(k<len&&S[i+k]==S[j+k]) k++;
        if(k >= len)  break;
        if(S[i + k] > S[j + k])
            i = max(i + k + 1, j + 1);
        else
            j = max(i + 1, j + k + 1);
    }
    return min(i ,j);
}
int MaxRepresstation(const char * s)
{//������ʾ�����ַ���S������ֵ��� 
 //�����ֵ�����С�Ĵ�������ĸλ��
    int len = strlen(s);
    int i = 0,j = 1, k = 0;
    while(i<len&&j<len&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(!t)k++;
        else
        {
            if(t>0) j = j + k + 1;
            else i = i + k + 1;
            if(i==j) j++;
            k = 0;
        }
    }
    return min(i, j);
}
