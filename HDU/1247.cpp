#include<bits/stdc++.h>
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
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    bool query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        //int res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
			//while(now != root)now=fail[now];					
            //if(now == root)return false;
        }
    	if(end[now]>0)return true;
        return false;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};

Trie fuck;
char a[50005][1005];

int main()
{
	int n=0;
	fuck.init();
	while(scanf("%s",a[n])!=EOF)
	{
		fuck.insert(a[n++]);
	}
	/*n=6;
	for(int i=0;i<6;++i)
	{
		scanf("%s",a[i]);
		fuck.insert(a[i]);
	}*/
	//fuck.debug();
	//fuck.build();
	for(int i=0;i<n;++i)
	{
		int L=strlen(a[i]);
		for(int j=1;j<L-1;++j)
		{
			char b[50]={"\0"};
			char c[50]={"\0"};
			strncpy(b,a[i],j);
			strncpy(c,a[i]+j,L-j);
			if(fuck.query(b)&&fuck.query(c))
			{
				printf("%s\n",a[i]);
				break;
			}
		}
	}
	return 0;
}

