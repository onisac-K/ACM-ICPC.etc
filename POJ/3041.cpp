#include <iostream>  
#include <cstring> 
#include <cstdio>
using namespace std;  
#define MAXV 505  
  
int n,m,use[MAXV],link[MAXV],map[MAXV][MAXV];  
  
int dfs(int cap){  
    int i,j;  
    for(i=1;i<=n;i++)  
        if(map[cap][i] && !use[i]){  
            use[i]=1;  
            j=link[i];  
            link[i]=cap;  
            if(j==-1 || dfs(j)) return true;  
            link[i]=j;  
        }  
        return false;  
}  
  
int hungary(){  
    int num=0;  
    int i,j;  
    memset(link,-1,sizeof(link));  
    for(i=1;i<=n;i++){  
        for(j=1;j<=n;j++) use[j]=0;  
        if(dfs(i)) num++;  
    }  
    return num;  
}  
  
int main(){  
    int i,a,b;  
    while(~scanf("%d%d",&n,&m)){  
        memset(map,0,sizeof(map));  
  
        for(i=1;i<=m;i++){  
            scanf("%d%d",&a,&b);  
            map[a][b]=1;  
        }  
  
        printf("%d\n",hungary());  
    }  
    return 0;  
}  
