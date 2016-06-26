#include <stdio.h>  
#include <string.h>  
  
#define N 55  
  
int cnt_row, cnt_col;  
int row[N][N], col[N][N], r[N], c[N];  
char map[N][N];  
bool path[N][N], vis[N];  
  
int dfs(int rr)  
{  
    for(int i = 0; i < cnt_col; ++i)  
    {  
        if(path[rr][i] && vis[i] == false)  
        {  
            vis[i] = true;  
            if(c[i] == -1 || dfs(c[i]))
            {   
                c[i] = rr;  
                r[rr] = i;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
int maxmatch()  
{  
    int ans = 0;  
    memset(r, -1, sizeof(r));  
    memset(c, -1, sizeof(c));  
    for(int i = 0; i < cnt_row; ++i)  
    {  
        if(r[i] == -1)  
        {  
            memset(vis, false, sizeof(vis));  
            ans += dfs(i);  
        }  
    }  
    return ans;  
}  
  
int main()  
{  
    int n,m;  
    int t;
    scanf("%d",&t);
    while(t--)  
    {  
    	scanf("%d%d",&n,&m);
        for(int i = 0; i < n; ++i)  
        {  
            for(int j = 0; j < m; ++j)  
                map[i][j] = getchar();  
            getchar();  
        }  
  
        memset(row, -1, sizeof(row));  
        memset(col, -1, sizeof(col));  
        cnt_row = cnt_col = 0;  
        for(int i = 0; i < n; ++i)  
        {  
            for(int j = 0; j < m; ++j)  
            {  
                if(map[i][j] == '*' && row[i][j] == -1)  
                {       
                    for(int k = j; map[i][k] == '*' && k < n; ++k)  
                        row[i][k] = cnt_row; 
                    cnt_row++;  
                }  
  
  
                if(map[j][i] == '*' && col[j][i] == -1)  
                {         
                    for(int k = j; map[k][i] == '*' && k < n; ++k)  
                        col[k][i] = cnt_col;  
                    cnt_col++;  
                }  
            }  
        }  
  
        memset(path, false, sizeof(path));  
        for(int i = 0; i < n; ++i)  
            for(int j = 0; j < m; ++j)  
                if(map[i][j] == '*')    
                    path[ row[i][j] ][ col[i][j] ] = true;  
  
        printf("%d\n", maxmatch());  
    }  
    return 0;  
}  
