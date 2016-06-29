#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4+5;

int a[N];
int num[N],sum[N],l[N*2],r[N*2];
int b[N];

int main()
{
	int n;
    while(cin>>n)
	{
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        memset(b,0,sizeof(b));
		for(int j=1;j<=n;++j)
        {
        	int p,ans=0;
		    memset(sum,0,sizeof(sum));
		    memset(l,0,sizeof(l));
		    memset(r,0,sizeof(r));
		    for(int i=1;i<=n;i++)
		    {
		        if(a[i]>a[j])num[i]=1;
		        else if(a[i]==a[j]){
		            num[i]=0;
		            p=i;
		        }
		        else num[i]=-1;
		    }
		    l[n]=1;r[n]=1;
		    for(int i=p-1;i>=1;i--)
		    {
		        sum[i]=sum[i+1]+num[i];
		        l[sum[i]+n]++;
			}
		    for(int i=p+1;i<=n;i++)
		    {
		        sum[i]=sum[i-1]+num[i];
		        r[sum[i]+n]++;
			}
		    for(int i=0;i<=2*n-1;i++)
		        ans+=l[i]*r[2*n-i];
		    b[j]=ans;
		}
        for(int i=1;i<=n;++i)
        {
        	if(i<n)printf("%d ",b[i]);
        	else cout<<b[i]<<endl;
		}
    }
    return 0;
}

