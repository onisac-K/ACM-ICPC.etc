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
int ans[MAXN];
 
void build(int i,int L,int R)
{
    l[i]=L;r[i]=R;
    if(R==L+1)
    {
        sum0[i]=-1;
        a[i]=-1;
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
    a[x]=-1;
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
    if(a[i]!=-1)push_down(i);
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
    if(a[i]!=-1)push_down(i);
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
    int n;

    int f=1;
    while(cin>>n)
    {	
    	memset(sum0,0,sizeof(sum0));
    	memset(a,0,sizeof(a));
    	memset(l,0,sizeof(l));
    	memset(r,0,sizeof(r));
    	memset(b,0,sizeof(b));
    	memset(ans,0,sizeof(ans));
    	build(1,1,8000+1);
    	int q;
    	int aa,bb,cc;
    	while(n--)
    	{
    		scanf("%d%d%d",&aa,&bb,&cc);
    		update(1,aa+1,bb+1,cc+1);
		}
		int k=1;
		for(int i=1;i<=8000;++i)
		{
			int q=query(1,i,i+1);
			//if(q==0)cout<<123<<endl;
			if(q==-1)break;
			b[k++]=q;
		}
		//for(int i=1;i<=k;++i)cout<<b[i]<<' ';
		//cout<<endl;
		for(int i=2;i<k;++i)
		{
			if(b[i]==b[i-1])b[i-1]=-1;
		}
		int m=0;
		for(int i=1;i<k;++i)
		{
			m=max(m,b[i]);
			if(b[i]!=-1)ans[b[i]]++;
		}
		for(int i=1;i<=m;++i)
		{
			//cout<<i<<' '<<ans[i]<<endl;
			if(ans[i]!=0)printf("%d %d\n",i-1,ans[i]);
		}
		cout<<endl;
	}
    return 0;
}
