#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tree[100005];

#define X first
#define Y second
#define MAXN 100005*4
int l[MAXN],r[MAXN];
ll ma[MAXN];
int a[MAXN];
int pos[MAXN];

void push_up(int x)
{
	ma[x]=max(ma[x<<1],ma[x<<1|1]);
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		ma[i]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

void update(int i,int L,int R,int x)
{
	if(L==l[i] && R==r[i])
	{
		ma[i]=x;
		return;
	}
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update(i<<1,L,R,x);
	else if(L>=mid)
		update(i<<1|1,L,R,x);
	else
	{
		update(i<<1,L,mid,x);
		update(i<<1|1,mid,R,x);
	}
	push_up(i);
}

ll query(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return ma[i];
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	else
		return max(query(i<<1,L,mid),query(i<<1|1,mid,R));
	push_up(i);
}
 
 
void add(int k,int num,int n)  
{  
    while(k<=n)  
    {  
        tree[k]+=num;  
        k+=k&-k;  
    }  
}  

int read(int k)//1~k的区间和  
{  
    int sum=0;  
    while(k)  
    {  
        sum+=tree[k];  
        k-=k&-k;  
    }  
    return sum;  
}  

void init(int n)
{
	for(int i = 0;i<=2*n;++i)tree[i]=0;
	for(int i = 0;i<=4*n;++i)
	{
		l[i]=0;
		r[i]=0;
		ma[i]=0;
		pos[i]=0;
	}
} 

int getright(int k,int n)
{
	if(1+k>=n-read(n))return n;
	int l = 1;
	int r = n;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(mid-read(mid)==1+k)return mid;
		if(mid-read(mid)>1+k){
			r=mid-1;
		}
		else if(mid-read(mid)<k+1)
		{
			l=mid+1;
		}
	}	
	return l;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		init(n);
		for(int i = 1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i; 
		}
		
		build(1,1,n+1);
		vector<int> ans;
		int st=1;
		while(k>0 && ans.size()<n)
		{
			int r = getright(k,n);
			int x = query(1,1,r+1);
			ans.push_back(x);
			int p = pos[x];
			//cout<<x<< ' '<< p<<endl;
			pos[x]=-1;
			update(1,p,p+1,-1);
			add(p,1,n);
			k-=(p-read(p));
		}
		for(int i=1;i<=n;++i)
		{
			if(pos[a[i]]>=1)
			{
				ans.push_back(a[i]);
			}
		}
		for(int i=0;i<n;++i)
		{
			printf("%d%c",ans[i],(i==n-1? '\n':' '));
		}
	}
	return 0;
}

