//STL��ʹ��

//�������ȼ��Ŀ��� 
struct stop{
	int dis,gas;
	stop(int x,int y):dis(x),gas(y){}
	friend bool operator<(const stop &a,const stop &b)
	{ return a.dis<b.dis; }   //�Ӵ�С���� 
};
struct cmp{
	bool operator()(int x,int y)
	{ return x<y; }    //�Ӵ�С���� 
};
//�ṹ���ڲ� 
priority_queue<int,vector<int>,cmp> pq;
priority_queue<stop> s;

//set
set<int> s;//����set�� ����Ԫ�� 
s.insert(1); s.insert(3); s.insert(5);         
//����setָ��                                  
set<int>::iterator it;                         
//����                                         
it=s.find(1);                                  
if(it==s.end()) puts("Not found\n");           
else puts("Found!\n");                         
//ɾ��                                         
s.erase(3);                                    
//���Ҽ���                                     
if( s.count(3) != 0 ) puts("Found!\n");        
else puts("Not found\n");                      
//��������Ԫ��                                 
for(it=s.begin();it!=s.end();++it)             
	printf("%d\n",*it);                        
	              
				                               
//map������intΪ����stringΪֵ	               
map<int,const char*> m;                        
//����Ԫ��                                     
m.insert(make_pair(1,"One"));                  
m.insert(make_pair(2,"Two"));                  
m[100]="Hundred";                              
//����Ԫ��                                     
map<int,const char*>::iterator its;            
it=m.find(1);                                 
puts(it->second);                             
it=m.find(2);                                 
if(it==m.end()) puts("Not found!\n");         
else puts(it->second);                        
puts(m[10]);                                   
//ɾ��Ԫ��                                     
m.erase(10);                                   
//��������Ԫ��                                 
for(it=m.begin();it!=m.end();it++)          
printf("%d:%s\n",it->first,it->second);  	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
