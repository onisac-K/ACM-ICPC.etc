#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define ll long long

struct node{
	int u;
	int v;
	int val;
}s[1000005];

vector<pair<int,int> >GG[100005];

int root;
int son[100005];
int vis[100005];

bool cmp(node a,node b)
{
	return a.val<b.val;
}

int ra[100005],pa[100005];  
int vec[100005];  

void init(int n)  
{  
	memset(vec,0,sizeof(vec));
    for(int i=0;i<=n;++i)  
    {  
    	GG[i].clear();
    	son[i]=0;
        ra[i]=0;  
        pa[i]=i;   
    }  
}  
  
int find(int x)  
{  
    if(x!=pa[x])pa[x]=find(pa[x]);  
    return pa[x];  
}  
  
void unite(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x==y)return;  
    if(ra[x]>ra[y])  
    {  
        pa[y]=x;  
    }  
    else   
    {  
        pa[x]=y;  
        if(ra[x]==ra[y])ra[y]++;  
    }  
    return ;  
}  
  
bool same(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x==y)return 1;  
    else return 0;  
}  

int dfs(int i)
{
	if(son[i]!=0)return son[i];
	if(GG[i].size()==0)return son[i]=1;
	int ans = 1;
	vis[i]=1;
	for(int j=0;j<GG[i].size();++j){
		if(vis[GG[i][j].first]==0)ans += dfs(GG[i][j].first);
	}
	return son[i]=ans;
}

ll ans ;

void getans(int i,int n){
	if(vis[i]==1)return ;
	vis[i] = 1;
	for(int j=0;j<GG[i].size();++j){
		if(vis[GG[i][j].first]==0){
			ans += 1LL*GG[i][j].second*(son[GG[i][j].first])*(n-son[GG[i][j].first]);
			getans(GG[i][j].first,n);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		init(n);
		int num = 0;
		ll V = 0;
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].val);
		sort(s,s+m,cmp);
		for(int i=0;i<m;++i){
			if(same(s[i].u,s[i].v))continue;
			else {
				vec[s[i].u]++;
				vec[s[i].v]++;
				unite(s[i].u,s[i].v);
				GG[s[i].u].push_back(make_pair(s[i].v,s[i].val));
				GG[s[i].v].push_back(make_pair(s[i].u,s[i].val));
				V += s[i].val;
				num++;
			}
			if(num == n-1)break;
		}
		for(int i=1;i<=n;++i){
			if(vec[i]==1){
				root = i;
				break;
			}
		}
		memset(vis,0,sizeof(vis));
		dfs(root);
		memset(vis,0,sizeof(vis));
		ans = 0;
		getans(root,n);
		//cout<<ans<<endl;
		double s = ans*1.0/(1LL*n*(n-1)/2);
		if(ans == 0)s=0;
		cout<<V<<' ';
		printf("%.2f\n",s);
	}
	return 0;
}

/*
2
4 6
1 2 100000000
2 3 200000000
3 4 300000000
4 1 400000000
1 3 500000000
2 4 600000000
4 6
1 2 1
2 3 2
3 4 3
4 1 4
1 3 5
2 4 6
*/
