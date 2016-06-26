#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

  
int n,m;  
int map[55][55];
int to[4][2] = {1,0,-1,0,0,1,0,-1};  
int cnt,l;  
  
struct node  
{  
    int x,y;  
}a[20];  
  
int judge(int x,int y)  
{  
    if(x<0 || y<0 || x>=n || y>=n)  
    return -1;  
    return map[x][y];  
}  
  
int check(int k)  
{  
    int flag = 0;  
    int x,y;  
    for(int i = 0;i<4;i++)  
    {  
        if(flag)  
        break;  
        x = a[k].x+to[i][0];  
        y = a[k].y+to[i][1];  
        while(x>=0 && y>=0 && x<n && y<m)
        {  
            int t = judge(x,y);  
            if(t == -1)  
            break;  
            if(t == 1)
            {  
                flag =1;  
                break;  
            }  
            x+=to[i][0];  
            y+=to[i][1];  
        }  
    }  
    return flag;  
}  
  
void dfs(int x,int turn)  
{  
    int i,j;  
    if(turn>cnt) cnt = turn;  
    if(x==l)  
    return;  
    dfs(x+1,turn);  
    if(!check(x))  
    {  
        map[a[x].x][a[x].y] = 1;  
        dfs(x+1,turn+1);  
        map[a[x].x][a[x].y] = 0;  
    }  
  
}  
  
int main()  
{  
    int i,j;  
    int t;
	cin>>t; 
    while(t--)  
    {  
    	cin>>n>>m;
        char s[10];  
        l = 0;  
        for(i = 0; i<n; i++)  
        {  
            scanf("%s",s);  
            for(j = 0;j<m; j++)  
            {  
                if(s[j] == '*')  
                {  
                    map[i][j] = 0;  
                    a[l].x = i;  
                    a[l].y = j;  
                    l++;  
                }  
                else  
                    map[i][j] = -1;  
            }  
        }  
        cnt = 0;  
        dfs(0,0);  
        printf("%d\n",cnt);  
    }  
  
    return 0;  
}  
