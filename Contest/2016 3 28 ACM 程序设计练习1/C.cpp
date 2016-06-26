#include<bits/stdc++.h>
using namespace std;
char a[15];
char b[105];
char c[15][105];
char ans[15][105];
int main()
{
    while(~scanf("%s",a))
    {
        //cout<<strcmp(a,"THEEND");
        if(strcmp(a,"THEEND")==0)break;
        scanf("%s",b);
        memset(ans,0,sizeof(ans));
        int len=strlen(a);
        int l=strlen(b);
        int n=l/len;
        int k=0;
        for(int i=0;i<len;++i)
        {
            for(int j=0;j<n;++j)c[j][i]=b[k++];
        }
        /*for(int i=0;i<n;++i)
        {
            for(int j=0;j<len;++j)cout<<c[i][j];
            cout<<endl;
        }*/
        char aa[15];
        strcpy(aa,a);
        //cout<<aa<<endl;
        sort(aa,aa+len);
        //cout<<aa<<endl;
        int p=0;
        for(int i=0;i<len;++i)
        {
            char q=aa[i];
            for(int j=0;j<len;++j)
            {
                if(a[j]==q)
                {
                    a[j]='.';
                    //cout<<aa[i]<<' '<<j<<endl;
                    for(int kk=0;kk<n;++kk)
                    {
                        ans[kk][j]=c[kk][p];
                    }
                    p++;
                }
            }
        }
        //cout<<b<<endl;
        k=0;
        //cout<<endl;
        /*for(int i=0;i<len;++i)
        {
            for(int j=0;j<n;++j)ans[j][i]=b[k++];
        }*/
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<len;++j)cout<<ans[i][j];
             
        }
        cout<<endl;
    }
}
