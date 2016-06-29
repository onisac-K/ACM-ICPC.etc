#include<bits/stdc++.h>
using namespace std;
int L[2000],I[1005];
int a[2000][2000];
int b[2000][2000];
int s[1005];
int f[1005];
struct node{
	int s;
	int l;
}w[1005]; 
void get(int i)
{
	int st=0,fi=0;
	int fa=0;
	for(int j=1;j<=L[i];++j)
	{
		if(b[i][j]<=fa)
		{
			fa++;
		}
		else 
		{
			fa=b[i][j];
			st=fa-(j-1);
			//cout<<st<<' '<<fa<<endl;
			fa++;
		}
	}
	s[i]=st;
	f[i]=fa;
//	cout<<s[i]<<' '<<f[i]<<endl;
}

void debug()
{
	for(int i=1;i<=2;++i)
	{
		for(int j=1;j<=L[i];++j)cout<<b[i][j]<<' ';
		cout<<endl;
	}
}

bool cmp(node a,node b)
{
	if(a.s==b.s)return a.l>b.l;
	else return a.s<b.s;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int n;
		cin>>L[i];
		for(int j=1;j<=L[i];++j)cin>>a[i][j];
	}
	int q;
	cin>>q;
	for(int o=0;o<q;++o)
	{
		int x,y,aa,bb;
		cin>>x>>aa>>y>>bb;
		for(int i=1;i<=n;++i)
		{
			int k=1;
			if(i==x)
			{
				for(int j=1;j<=bb;++j)b[x][k++]=a[y][j];
				for(int j=aa+1;j<=L[x];++j)b[x][k++]=a[x][j];	
			}
			else if(i==y)
			{
				for(int j=1;j<=aa;++j)b[y][k++]=a[x][j];
				for(int j=bb+1;j<=L[y];++j)b[y][k++]=a[y][j];	
			}
			else 
			{
				for(int j=1;j<=L[i];++j)b[i][k++]=a[i][j];
			}
			I[i]=k-1;
		}
		for(int i=1;i<=n;++i)
		{
			L[i]=I[i];
			for(int j=1;j<=L[i];++j)a[i][j]=b[i][j];
		}
		//debug();
		for(int i=1;i<=n;++i)
		{
			get(i);
		}
		for(int i=1;i<=n;++i)
		{
			w[i].s=s[i];
			w[i].l=L[i];
		}
		sort(w+1,w+1+n,cmp);
		int cnt = 0;
        for (int i = 1; i<=n; i++) {
            w[i].s = w[i].s-cnt;
            cnt += w[i].l;
            //cout<<w[i].s<<' '<<cnt<<endl;
        }
        
        int ans = 0;
        for (int i = 1; i<=n; i++) {
        	//cout<<w[i].s<<endl;
            ans = max(w[i].s, ans);
        }
        cout<<ans<<endl;
	}
	return 0;
}
