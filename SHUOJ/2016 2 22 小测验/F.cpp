#include <iostream>  
#include <sstream>  
#include <ios>  
#include <iomanip>  
#include <functional>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <list>  
#include <queue>  
#include <deque>  
#include <stack>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <climits>  
#include <cctype>  
using namespace std;  
#define INF 0x3FFFFFFF;  
#define MP(X,Y) make_pair(X,Y)  
#define PB(X) push_back(X)  
#define MP(X,Y) make_pair(X,Y)  
#define PB(X) push_back(X)  
#define CLR(A,X) memset(A,X,sizeof(A))  
#define Rep(x,n) for(int x=0;x<n;++x)  
#define Rep2(x,l,n) for(int x=l;x<n;++x)  
typedef long long ll;  
typedef pair<int,int> PII;  
typedef vector<PII> VII;  
typedef vector<int> VI;  
const int MAXN = 100010;  
  
int ra[1005],pa[1005];  
int flag[1005];  
  
void init(int n)  
{  
    for(int i=0;i<=n;++i)  
    {  
        ra[i]=0;  
        pa[i]=i;  
        flag[i]=0;  
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
  
int main()  
{  
    int n,m;  
    while(cin>>n>>m)
    {
    	int a,b;
    	init(n*2);
    	int f=0;
    	for(int i=0;i<m;++i)
    	{
    		cin>>a>>b;
    		if(same(a+n,b)){
    			f=1;
    			continue;
			}
			if(f==1)continue;
			unite(a,b+n);
		}
		cout<<((f==1)? "NO":"YES")<<endl;
	}
  
    return 0;  
}  
