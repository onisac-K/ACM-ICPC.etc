#include <bits/stdc++.h>
using namespace std;
#define REP(X,N) for(int X=0;X<N;X++)
#define CLR(A,X) memset(A,X,sizeof(A))
#define MAXN 100010
#define INF 0x3f3f3f3f
 
char str[3*MAXN],s[MAXN];
int p[3*MAXN];
int n,len;
 
void manacher()
{
    len=n=strlen(s);
    str[0]='$';
    str[1]='#';
    for(int i=0;i<n;i++)
        str[2*i+2]=s[i],str[2*i+3]='#';
    n=n*2+2;
    str[n]=0;
    int mx=0,id;
    for(int i=1;i<n;i++)
    {
        if(mx>i)
            p[i]=min(p[2*id-i],mx-i);
        else
            p[i]=1;
        for(;str[i+p[i]]==str[i-p[i]];p[i]++)
            ;
        if(p[i]+i>mx)
            mx=p[i]+i,id=i;
    }
}
int res[MAXN];
 
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    while(gets(s))
    {
        manacher();
        CLR(res,-1);
        for(int i=1;i<n;i++)
        {
        	cout<<p[i]<<' ';
            if(str[i]=='#' && p[i]==1)
                continue;
            int left=i-p[i]+2;
            res[left/2-1]=max(res[left/2-1],p[i]-1);
        }
        cout<<endl;
        int Max=res[0];
        for(int i=0;i<len;i++)
        {
            if(res[i]>Max)
                Max=res[i];
            else
                res[i]=Max;
            Max-=2;
        }
        for(int i=0;i<len;i++)
            printf("%d%c",res[i],i==len-1?'\n':' ');
    }
    return 0;
}
