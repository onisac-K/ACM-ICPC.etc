#include <iostream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3f3f3f3f
#define MAXN 4*100010
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define ll long long 

int l[MAXN],r[MAXN];
int sum0[MAXN];
int a[MAXN];
int b[MAXN];
int x[MAXN],y[MAXN];
int c[10000005];
 

 
void build(int i,int L,int R)
{
    l[i]=L;r[i]=R;
    if(R==L+1)
    {
        sum0[i]=0;
        a[i]=0;
        return;
    } 
    int mid=(L+R)>>1;
    build(i<<1,L,mid);
    build(i<<1|1,mid,R);
    //push_up(i);
}
 
void update_node(int x,int f)
{
	//ll k=f*(r[x]-l[x]);
	//cout<<(r[x]-l[x])<<' '<<f<<endl;
    sum0[x]=f;
    a[x]=f;
}
 
void push_down(int x)
{
    //cout<<x<<' '<<a[x]<<endl;
    update_node(x<<1,a[x]);
    update_node(x<<1|1,a[x]);
    a[x]=0;
}
 
void update(int i,int L,int R,int x)
{
    if(L==l[i] && R==r[i])
    {
        //cout<<i<<endl;
        sum0[i]=x;
        a[i]=x;
       // cout<<x<<endl;
        return;
    }
    if(a[i]!=0)push_down(i);
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
    //push_up(i);
}
 
int query(int i,int L,int R)
{
	//for(int j=1;j<=30;++j)cout<<l[j]<<' '<<r[j]<<' '<<sum0[j]<<' '<<a[j]<<endl;
    //cout<<endl;
    if(L==l[i] && R==r[i])      
    {
    	return sum0[i];
    }
    if(a[i]!=0)push_down(i);
    int mid=(l[i]+r[i])>>1;
    if(R<=mid)
        return query(i<<1,L,R);
    else if(L>=mid)
        return query(i<<1|1,L,R);
    else
        return query(i<<1,L,mid)+query(i<<1|1,mid,R);
    //push_up(i);
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	//memset(a,0,sizeof(a));
    	scanf("%d",&n);
    	int k=0;
    	for(int i=0;i<n;++i)
    	{
    		scanf("%d%d",&x[i],&y[i]);
    		b[k++]=x[i];
    		b[k++]=y[i];
		}
		sort(b,b+k);
		k=unique(b,b+k)-b;
		for(int i=0;i<k;++i)
		{
			c[b[i]]=i+1;
		}
		int q=0;
		for(int i=0;i<n;++i)
		{
			//cout<<c[x[i]]<<' '<<c[y[i]]<<endl;
			x[i]=c[x[i]];
			y[i]=c[y[i]];
			q=max(q,y[i]);
			q=max(q,x[i]);
		}
		//cout<<q<<endl;
		//for(int i=0;i<n;++i)cout<<x[i]<<' '<<y[i]<<endl;
		build(1,1,q+1);
		for(int i=0;i<n;++i)
		{
			update(1,x[i],y[i]+1,i+1);
			//for(int j=0;j<2*q;++j)cout<<l[j]<<' '<<r[j]<<' '<<sum0[j]<<' '<<a[j]<<endl;
			//cout<<endl;
		}
		memset(b,0,sizeof(b));
		for(int i=1;i<=q;++i)
		{
			//cout<<query(1,i,1+i)<<endl;
			b[query(1,i,1+i)]=1;
		}
		int ans=0;
		for(int i=1;i<10005;++i)ans+=b[i];
		printf("%d\n",ans);
	}
    return 0;
}
