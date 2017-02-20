#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define INF 1<<29
#define maxInt 0x7fffffff
#define SUP 0x80000000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=100007;

//父节点,键值，左右(0,1)儿子，根结点，结点数
int pre[N],key[N],ch[N][2],root,tot1;

void newNode(int &r,int father,int k)
{
    r=++tot1;
    pre[r]=father;
    ch[r][0]=ch[r][1]=0;
    key[r]=k;
}

//旋转，kind=0左旋，1右旋，
void rotate_(int x,int kind)
{
    int y=pre[x];
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y]=x;

    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
}

//splay调整，将根为r的子树调整为goal
void splay(int r,int goal)
{
    while(pre[r]!=goal){
        //父节点即是目标结点。goal=0表示父节点是根结点
        if(pre[pre[r]]==goal)
            rotate_(r,ch[pre[r]][0]==r);
        else{
            int y=pre[r];
            int kind=ch[pre[y]][0]==y;

            if(ch[y][kind]==r){//两个方向不同
                rotate_(r,!kind);
                rotate_(r,kind);
            }
            else{//两个方向相同
                rotate_(y,kind);
                rotate_(r,kind);
            }
        }
    }
    if(goal==0) root=r;
}

//插入k，并splay到根
int insert_(int k)
{
    int r=root;
    while(ch[r][key[r]<k]){
        if(key[r]==k){
            splay(r,0);
            return 0;
        }
        r=ch[r][key[r]<k];
    }
    newNode(ch[r][k>key[r]],r,k);
    splay(ch[r][k>key[r]],0);//splay到根
    return 1;
}

//前驱，即左子树的最右结点idx
int getPre(int x)
{
    int tmp=ch[x][0];
    if(tmp==0) return -1;
    while(ch[tmp][1]) tmp=ch[tmp][1];
    return tmp;
}

//后驱，即右子树的最左结点idx
int getNext(int x)
{
    int tmp=ch[x][1];
    if(tmp==0) return -1;
    while(ch[tmp][0]) tmp=ch[tmp][0];
    return tmp;
}

int main()
{
    int n;
    while(cin>>n)
	{
		int x;
		root = tot1 = 0;
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			if(scanf("%d",&x)==EOF) x=0;
			if(i==0)
			{
				ans += x;
				newNode(root,0,x);
				continue;
			}
			else 
			{
				if(insert_(x)==0)continue;
				int ma = getPre(root);
				int mi = getNext(root);
				int num = 0x3f3f3f3f;
				if(ma!=-1)num = x- key[ma];
				if(mi!=-1)num = min(num,(key[mi] - x));
				//int num = min(fabs(ma-x),fabs(mi-x));
				ans += num;
			}
		}
		cout<<ans<<endl;
	} 
    /*while(scanf("%d",&n)==1)
    {
        root=tot1=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int v;
            if(scanf("%d",&v)==EOF) v=0;
            if(!i){
                ans+=v;
                newNode(root,0,v);
                continue;
            }
            //结点已经存在，最小差值为0，so continue！
            if(insert_(v)==0) continue;
            int pre=getPre(root);
            int next=getNext(root);
            int tmp=INF;
            if(pre!=-1)
                tmp=min(tmp,v-key[pre]);
            if(next!=-1)
                tmp=min(tmp,key[next]-v);
            ans+=tmp;
        }
        printf("%d\n",ans);
    }*/
    return 0;
}
