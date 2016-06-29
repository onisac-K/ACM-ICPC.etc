#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define X first
#define Y second
#define MAXN 400005

int l[MAXN],r[MAXN];
ll Max[MAXN],Min[MAXN];
int a[MAXN];

void push_up(int x)
{
	Max[x]=max(Max[x<<1],Max[x<<1|1]);
	Min[x]=min(Min[x<<1],Min[x<<1|1]);
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		Max[i]=a[L];
		Min[i]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

ll maxquery(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return Max[i];
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return maxquery(i<<1,L,R);
	else if(L>=mid)
		return maxquery(i<<1|1,L,R);
	else
		return max(maxquery(i<<1,L,mid),maxquery(i<<1|1,mid,R));
}

ll minquery(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return Min[i];
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return minquery(i<<1,L,R);
	else if(L>=mid)
		return minquery(i<<1|1,L,R);
	else
		return min(minquery(i<<1,L,mid),minquery(i<<1|1,mid,R));
}

int main()
{
	int t;
	cin>>t;
	int f = 1;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		build(1,1,1+n);
		int ans = 0;
		for(int i=1;i<=n-d;++i)
		{
			int Ma = maxquery(1,i,i+d);
			int Mi = minquery(1,i,i+d);
			ans = max(ans,Ma-Mi);
		}
		cout<<"Case "<<f++<<": "<<ans<<endl;
	}
	return 0;
} 
