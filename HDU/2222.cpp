#include<bits/stdc++.h>
using namespace std;

#define MAXNUM 26
//�����ֵ����ṹ��
typedef struct Trie
{
    int flag;//�Ӹ������Ƿ�Ϊһ������
    Trie *next[MAXNUM];
}Trie;
//����һ����
Trie *root;
//��ʼ���ø�
void init()
{
    root = (Trie *)malloc(sizeof(Trie));
    root->flag=false;
    for(int i=0;i<MAXNUM;i++)
    root->next[i]=NULL;
}
//�Ը��ֵ����Ĳ��뵥�ʲ���
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
//��ѯһ�����ʵĲ���
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

// �ж����Ӵ��ǵ��� 
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
//�ͷ��ֵ����ڴ���������ڱ���������ݺ�����Զ���������������ûд�ͷ��ڴ溯��
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
