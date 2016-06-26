#include<bits/stdc++.h>
using namespace std;

#define MAXNUM 26
//定义字典树结构体
typedef struct Trie
{
    int flag;//从根到此是否为一个单词
    Trie *next[MAXNUM];
}Trie;
//声明一个根
Trie *root;
//初始化该根
void init()
{
    root = (Trie *)malloc(sizeof(Trie));
    root->flag=false;
    for(int i=0;i<MAXNUM;i++)
    root->next[i]=NULL;
}
//对该字典树的插入单词操作
void insert(char *word)
{
    Trie *tem = root;
    while(*word!='\0')
    {
        if(tem->next[*word-'a']==NULL)
        {
            Trie *cur = (Trie *)malloc(sizeof(Trie));
            for(int i=0;i<MAXNUM;i++)
            cur->next[i]=NULL;
            cur->flag=0;
            tem->next[*word-'a']=cur;
        }
        tem = tem->next[*word-'a'];
        word++;
    }
    tem->flag++;
}
//查询一个单词的操作
bool search(char *word)
{
    Trie *tem = root;
    for(int i=0;word[i]!='\0';i++)
    {
        if(tem==NULL||tem->next[word[i]-'a']==NULL)
        return false;
        tem=tem->next[word[i]-'a'];
    }
    return tem->flag;
}

// 有多少子串是单词 
int search2(char *word)
{
	Trie *temp = root;
	int sum=0;
	for(int i=0;word[i]!='\0';++i)
	{
		int k=word[i]-'a';
		temp=root;
		for(int j=i;word[j]!='\0';++j)
		{
			k=word[j]-'a';
			if(temp->next[k])
			{
				//char m=k+'a';cout<<m<<endl;
				sum=sum+(temp->next[k]->flag);
				temp=temp->next[k];
				temp->flag=0;				
				//cout<<sum<<endl;
			}
			else break;
		}
	}
	return sum;
}
//释放字典树内存操作，由于本题测试数据后程序自动跳出，所以这里没写释放内存函数
void del(Trie *cur)
{
    for(int i=0;i<MAXNUM;i++)
    {
        if(cur->next[i]!=NULL)
        del(cur->next[i]);
    }
    free(cur);
}

char w[55],d[1000005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		init();
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s",w);
			insert(w);
		}
		scanf("%s",d);
		printf("%d\n",search2(d));
		del(root);
	}
	return 0;
}
