#include<iostream>  
#include<cstdio>  
#include<cstring> 
#include<string> 
#include<queue>  
using namespace std;  

struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
    	//cout<<123<<endl;
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
            //end[now]=1;
        }
        end[now]=1;
    }
    void dele(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i=0;i<len;++i)
        {
            if(next[now][buf[i]-'a'] == -1)return ;
            now = next[now][buf[i]-'a'];
        }
        queue<int> q;
        q.push(now);
        end[now]=0;
        while(!q.empty())
        {
            int t = q.front();
            q.pop(); 
            for(int i=0;i<26;++i)
            {
                if(next[t][i] != -1)
                {
                    q.push(next[t][i]); 
					next[t][i]=-1;   
                    end[next[t][i]]=0;
                }
            }
        }
        return ;
    }
    
    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
        	//cout<<buf[i]<<endl;
            now = next[now][buf[i]-'a'];
            if(now == -1)return 0;
        }
        queue<int> q;
        q.push(now);
        while(!q.empty())
        {
            int t = q.front();
            q.pop(); 
            if(end[t]==1)return 1;
            for(int i=0;i<26;++i)
            {
                if(next[t][i] != -1)
                {
                    q.push(next[t][i]); 
                }
            }
        }
        return 0;
    }
    /*void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }*/
};

Trie s;
char b[1005];
char a[1005];
int main()
{
	int n;
	//cout<<123<<endl;
	cin>>n;
	getchar();
	s.init();
	for(int i=0;i<n;++i)
	{
		scanf("%s%s",a,b);
		if(strcmp(a,"insert")==0)s.insert(b);
		else if(strcmp(a,"delete")==0)s.dele(b);
		else {
			int ans = s.query(b);
			if(ans==1)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}


