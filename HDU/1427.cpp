#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
using namespace std;
int flag;
int b[4];
 
void dfs(int ans,int ext,int p)
{
    //if(!ans||!next)return ;
    if(flag)
     return;
    if(p==3)
    {
        if(ans+ext==24||ans*ext==24||ans-ext==24)
        flag=1;
        if(ext!=0&&ans%ext==0&&ans/ext==24)
        flag=1;
        return;
    }
    dfs(ans+ext,b[p+1],p+1);
    dfs(ans-ext,b[p+1],p+1);
    dfs(ans*ext,b[p+1],p+1);   
    if(ext!=0&&ans%ext==0)
    dfs(ans/ext,b[p+1],p+1);
    dfs(ans,ext+b[p+1],p+1);
    dfs(ans,ext-b[p+1],p+1);
    dfs(ans,ext*b[p+1],p+1);   
    if(b[p+1]!=0&&ext%b[p+1]==0)
    dfs(ans,ext/b[p+1],p+1);
}
  
int main()
{
    int i;
    char str[5];
    while(cin>>str)
    {
    	i=0;
		if(strlen(str)==2)
            b[i]=10;
        else
        {
            if(str[0]=='A')
            b[i]=1;
            else if(str[0]=='J')
            b[i]=11;
            else if(str[0]=='Q')
            b[i]=12;
            else if(str[0]=='K')
            b[i]=13;
            else
            b[i]=str[0]-'0';
        }
        for(i=1;i<=3;i++)
        {
            scanf("%s",str);
            if(strlen(str)==2)
            b[i]=10;
            else
            {
               if(str[0]=='A')
               b[i]=1;
               else if(str[0]=='J')
               b[i]=11;
               else if(str[0]=='Q')
               b[i]=12;
               else if(str[0]=='K')
               b[i]=13;
               else
               b[i]=str[0]-'0';
            }
        }
    //cout<<f<<endl;
    //qsort(b,4,sizeof(b[0]),cmp);
    //for(int i=0;i<4;++i)cout<<b[i]<<endl;
    sort(b,b+4);
    flag=0;
    do
    {
        //cout<<b[0]<<' '<<b[1]<<endl;
        dfs(b[0],b[1],1);
    }while(next_permutation(b,b+4)&&!flag);
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	}
    return 0;
} 
