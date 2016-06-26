#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;

int a[10000];
int b[10000];
int kx,ex;
 
int bfs()
{
    queue<int> q;
    q.push(kx);
    b[kx]=0;
    while(!q.empty())
    {
        int m=q.front();
        q.pop();
        if(m==ex)return b[ex];
        int aa=m%10,bb=(m/10)%10,c=(m/100)%10,d=m/1000;
        //cout<<aa<<' '<<bb<<' '<<c<<' '<<d<<endl;
        for(int i=0;i<=9;++i)
        {
            if(i!=aa&&i%2==1)
            {
                int tx=i+bb*10+c*100+d*1000;
                if(a[tx]==0&&b[tx]==0)
                {
                    //cout<<tx<<endl;
                    b[tx]=b[m]+1;
                    q.push(tx);
                }
            }
            if(i!=bb)
            {
                int tx=aa+i*10+c*100+d*1000;
                if(a[tx]==0&&b[tx]==0)
                {
                    //cout<<tx<<endl;
                    b[tx]=b[m]+1;
                    q.push(tx);
                }
            }
            if(i!=c)
            {
                int tx=aa+bb*10+i*100+d*1000;
                if(a[tx]==0&&b[tx]==0)
                {
                    //cout<<tx<<endl;
                    b[tx]=b[m]+1;
                    q.push(tx);
                }
            }
            if(i!=d&&i!=0)
            {
                int tx=aa+bb*10+c*100+i*1000;
                if(a[tx]==0&&b[tx]==0)
                {
                    //cout<<tx<<endl;
                    b[tx]=b[m]+1;
                    q.push(tx);
                }
            }
        }
    }
    return 0;
}
 
int main()
{
    for(int i=2;i<=100;++i)
    {
        if(a[i]==0)
        for(int j=i*i;j<=10000;j+=i)
        {
            a[j]=1;
        }
    }
    //for(int i=1;i<100;++i)if(a[i]==0)cout<<i<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>kx>>ex;
        memset(b,0,sizeof(b));
        cout<<bfs()<<endl;      
    }
    return 0;
}

