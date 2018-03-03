/*	ɨ����  ��������ϲ� 
	ԭ�� ���߶��� 
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#define lson id*2
#define rson id*2+1  
using namespace std;
map<double,int>hashx;//��ʾÿһ�������Ӧ��hash���ֵ 
map<double,int>hashy;//��ʾÿһ�������Ӧ��hash���ֵ 
map<int,double>mpx;//��ʾhash���ֵ��Ӧ��ʵ������ 
map<int,double>mpy;//��ʾhash���ֵ��Ӧ��ʵ������ 
struct edge1{
    int val; //��¼���������ʾ�������Ƿ��߶������� 
    double len;//��¼�ڵ������������Ѿ������ǵĳ��� 
}tree[1000];
//ע���ʱÿһ��Ҷ�ӽڵ�Ҫ����ɸ�����Ϊ1������
//����ԭ��Ӧ����λ��1�Ľڵ��ʱӦ����1~2������ 
struct edge2{
    double xnow,yup,ydown;
    //xnow��ʾ��ʵ�ʵĺ����� 
    //yup��ydown�ֱ��ʾ�������������� 
    int id;//��ʾ�Ǿ��εĿ�ǰ�ı߻��ǿ���ı� 
}s[1000];
double px[1000],py[1000];//����hash 
int cmp(edge2 a,edge2 b)
{
    if (a.xnow!=b.xnow)
    return a.xnow<b.xnow;
    else  if (a.ydown!=b.ydown)
    return a.ydown<b.ydown;
    else 
    return a.yup<b.yup; 
}//��x������εı� 
//�߶������� 
void push_up(int id)
{
    tree[id].len=tree[lson].len+tree[rson].len;
    tree[id].val=tree[lson].val+tree[rson].val;
    return ;
}
void build_tree(int id,int l,int r)
{
    if (l==r)
    {
        tree[id].val=0;
        tree[id].len=0;
        return ;
    }
    int mid=(l+r)/2;
    build_tree(lson,l,mid);
    build_tree(rson,mid+1,r);
    push_up(id);
    return ;
}
void add_tree(int id,int l,int r,int L,int R,int v)
{
    if (l==r&&l>=L&&r<=R)
    {
        tree[id].len=0;
        tree[id].val+=v;
        if (tree[id].val>0)
        tree[id].len=mpy[l+1]-mpy[l]; 
        //�����1��ԭ���Ǵ�ʱ��l�������l~l+1��������� 
     return ;
    }
    int mid=(l+r)/2;
    if (mid>=L)
    add_tree(lson,l,mid,L,R,v);
    if (mid+1<=R)
    add_tree(rson,mid+1,r,L,R,v);
    push_up(id);
    return ;
}//�߶����� 
int n,t=0;
double x1,x2,y1,y2;
int main()
{
    while(cin>>n)
    {
        if (n==0)
        return 0;
        t++;//hash��ʼ 
        for (int i=1;i<=n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            s[i].xnow=x1;
            s[i].yup=y2;
            s[i].ydown=y1;
            s[i].id=1;
            s[i+n].xnow=x2;
            s[i+n].yup=y2;
            s[i+n].ydown=y1;
            s[i+n].id=-1;
            px[i]=x1;
            px[i+n]=x2;
            py[i]=y1;
            py[i+n]=y2;
        }
        sort(px+1,px+1+2*n);//ע��˴���2*n����Ϊ ÿһ�����δ������������� 
        sort(py+1,py+1+2*n);
        int numx=0,numy=0;
        for (int i=1;i<=2*n;i++)
        {
            if (px[i]!=px[i+1])
            {
                numx++;
                hashx[px[i]]=numx;
                mpx[numx]=px[i];
            }
            if (py[i]!=py[i+1])
            {
                numy++;
                hashy[py[i]]=numy;
                mpy[numy]=py[i];
            }
        }   //hash���� 
        sort(s+1, s+1+ 2*n ,cmp);//ע��2*n 
        build_tree(1,1,n);
        double ans=0.0;
        for (int i=1;i<=2*n;i++)
        {
            //ÿ�ε���һ���µ�x����ʱ�ȼ����ټӱ� 
            ans+=tree[1].len*(s[i].xnow-s[i-1].xnow);
            while(s[i].xnow==s[i+1].xnow)
            {
                add_tree(1,1,numy,hashy[s[i].ydown],hashy[s[i].yup]-1,s[i].id);
                //Ҫ�� hashy[s[i].yup]��1����Ϊÿһ���ڵ�ԭ���������λ��x������x~x+1 
                i++;
            }
            add_tree(1,1,numy,hashy[s[i].ydown],hashy[s[i].yup]-1,s[i].id);
        }
        printf("Test case #%d\n",t);
        printf("Total explored area: %.2f\n\n",ans);//poj�ϵ������ʽ�ܿ�       
    }
}
