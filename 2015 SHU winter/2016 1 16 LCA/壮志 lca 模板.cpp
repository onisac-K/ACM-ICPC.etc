7.	splay（区间版）
/*
splay区间版本
打标记加区间操作版
*/
/*
bzoj1500 维修数列
操作一：在pos后面插入tot个数
操作二：在pos后面删除tot个数
操作三：将pos后面tot个数全变成c
操作四：将pos后面tot个数翻转
操作五：求pos后面tot个数的和
操作六：求全数列的最大子段和
*/
#define key_value ts[ts[root].cld[1]].cld[0]

int n;
int a[MAXN];
int St[MAXN],top;

const int null=-1;
int cnt,root;
 
struct node
{
    int par,cld[2];
    int val,sum;
    int size;
    bool rev,same;
    int maxl,maxr,maxm;
} ts[MAXN];
 
int newnode(int key,int par)
{
	int r;
	if(top)
		r=St[--top];
	else
		r=cnt++;
    ts[r].val=ts[r].sum=key;
    ts[r].par=par;
    ts[r].size=1;
    ts[r].cld[0]=ts[r].cld[1]=null;
    ts[r].rev=ts[r].same=0;
    ts[r].maxl=ts[r].maxr=ts[r].maxm=key;
    return r;
}

//下放rev翻转标记 
void update_rev(int x)
{
	if(x!=null)
	{
		swap(ts[x].cld[0],ts[x].cld[1]);
		swap(ts[x].maxl,ts[x].maxr);
		ts[x].rev^=1;
	}
}

//下放same区间相同标记 
void update_same(int x,int v)
{
	if(x!=null)
	{
		ts[x].val=v;
		ts[x].sum=ts[x].size*v;
		ts[x].maxl=ts[x].maxr=ts[x].maxm=max(v,v*ts[x].size);
		ts[x].same=1;
	}
}

void push_up(int x)
{
	int l=ts[x].cld[0],r=ts[x].cld[1];
    if(l!=null && r==null)
    {
    	ts[x].sum=ts[x].val+ts[l].sum;
    	ts[x].size=1+ts[l].size;
    	ts[x].maxl=max(ts[l].maxl,ts[l].sum+ts[x].val);
    	ts[x].maxr=ts[x].val+max(0,ts[l].maxr);
    	ts[x].maxm=max(ts[l].maxm,ts[x].val+max(0,ts[l].maxr));
    }
    else if(l==null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[r].sum;
    	ts[x].size=1+ts[r].size;
    	ts[x].maxl=ts[x].val+max(0,ts[r].maxl);
    	ts[x].maxr=max(ts[r].maxr,ts[r].sum+ts[x].val);
    	ts[x].maxm=max(ts[r].maxm,ts[x].val+max(0,ts[r].maxl));
    }
    else if(l!=null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[l].sum+ts[r].sum;
    	ts[x].size=1+ts[l].size+ts[r].size;
    	ts[x].maxl=max(ts[l].maxl,ts[l].sum+ts[x].val+max(0,ts[r].maxl));
    	ts[x].maxr=max(ts[r].maxr,ts[r].sum+ts[x].val+max(0,ts[l].maxr));
    	ts[x].maxm=max(ts[l].maxm,ts[r].maxm);
    	ts[x].maxm=max(ts[x].maxm,max(0,ts[l].maxr)+ts[x].val+max(0,ts[r].maxl));
    }
    else
    {
    	ts[x].sum=ts[x].maxl=ts[x].maxr=ts[x].maxm=ts[x].val;
    	ts[x].size=1;
    }
}

void push_down(int x)
{
	int l=ts[x].cld[0],r=ts[x].cld[1];
	if(ts[x].same)
	{
		update_same(l,ts[x].val);
		update_same(r,ts[x].val);
		ts[x].same=0;
	}
	if(ts[x].rev)
	{
		update_rev(l);
		update_rev(r);
		ts[x].rev=0;
	}
}
 
//旋转，0左旋，1右旋 
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
    push_down(y);push_down(x);
    ts[y].cld[!k]=ts[x].cld[k];
    push_up(y); 
    if(ts[x].cld[k]!=null)
        ts[ts[x].cld[k]].par=y;
    ts[x].par=z;
    if(z!=null)
        ts[z].cld[(y==ts[z].cld[1])]=x;
    ts[y].par=x;
    ts[x].cld[k]=y;
}

//将x伸展至S下方 
void splay(int x,int S)
{
    for(push_down(x);ts[x].par!=S;)
    {
        int y=ts[x].par,z=ts[y].par;
        if(ts[y].par==S)
		    rotate(x,ts[y].cld[0]==x);
        else
        {
            int d=(ts[ts[y].par].cld[0]==y);
            if(ts[y].cld[d]==x)
                rotate(x,!d),rotate(x,d);
            else
                rotate(y,d),rotate(x,d);
        }
    }
    push_up(x);
    if(S==null)
        root=x;
}

//获取中序遍历第k位的节点编号 
int get_kth(int x,int k)
{
	push_down(x);
	int ls=(ts[x].cld[0]==null?0:(ts[ts[x].cld[0]].size));
	if(k==ls+1)
		return x;
	else if(k<=ls)
		return get_kth(ts[x].cld[0],k);
	else
		return get_kth(ts[x].cld[1],k-ls-1);
}
 
//在p下插入l到r个数 
int build(int p,int l,int r)
{
    if(r<l)
        return null;
    int mid=(l+r)>>1;
    int t=newnode(a[mid],p);
    if(p==null)
        root=t;
    ts[t].cld[0]=build(t,l,mid-1);
    ts[t].cld[1]=build(t,mid+1,r);
    push_up(t);
    return t;
}

void init()
{
	REP2(i,1,n)
		scanf("%d",&a[i]);
	top=cnt=0;
	root=null;
	root=newnode(-1,null);
	ts[root].cld[1]=newnode(-1,root);
	key_value=build(ts[root].cld[1],1,n);
	push_up(ts[root].cld[1]);
	push_up(root);
}

void printMess(int x)
{
	printf("id:%2d ",x);
	printf("fa:%2d ",ts[x].par);
	printf("lc:%2d ",ts[x].cld[0]);
	printf("rc:%2d ",ts[x].cld[1]);
	printf("va:%2d ",ts[x].val);
	printf("sum:%2d ",ts[x].sum);
	printf("sz:%2d ",ts[x].size);
	printf("rev:%2d ",ts[x].rev);
	printf("same:%2d ",ts[x].same);
	printf("ml:%2d ",ts[x].maxl);
	printf("mr:%2d ",ts[x].maxr);
	printf("mm:%2d ",ts[x].maxm);
	puts("");
}

void track(int x)
{
	if(x!=null)
	{
		track(ts[x].cld[0]);
		printMess(x);
		track(ts[x].cld[1]);
	}
}

void debug()
{
	printf("root : %2d\n",root);
	track(root);
	puts("");
}

//删除节点，回收内存 
void erasenode(int x)
{
	if(x!=null)
	{
		St[top++]=x;
		erasenode(ts[x].cld[0]);
		erasenode(ts[x].cld[1]);
	}
}

//获取从pos开始连续tot个数的和 
int get_sum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].sum;
}

//获取从pos开始连续tot个数的区间最大和 
int get_maxsum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].maxm;
}

//在pos后方插入连续tot个数 
void insert(int pos,int tot) 
{
	REP2(i,1,tot)
		scanf("%d",&a[i]);
	splay(get_kth(root,pos+1),null);
	splay(get_kth(root,pos+2),root);
	key_value=build(ts[root].cld[1],1,tot);
	push_up(ts[root].cld[1]);
	push_up(root);
}

//在pos后方删除连续tot个数 
void erase(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	erasenode(key_value);
	ts[key_value].par=null;
	key_value=null;
	push_up(ts[root].cld[1]);
	push_up(root);
}

//pos开始连续tot个数变成c 
void make_same(int pos,int tot,int c)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	update_same(key_value,c);
	push_up(ts[root].cld[1]);
	push_up(root);
}

//pos开始连续tot个数翻转
void make_rev(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	update_rev(key_value);
	push_up(ts[root].cld[1]);
	push_up(root);
}

char opt[20];

int main()
{
	//freopen("sequence2.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		REP(i,m)
		{
			int x,y;
			scanf("%s",&opt);
			if(opt[2]=='S')
			{
				scanf("%d%d",&x,&y);
				insert(x,y);
			}
			else if(opt[2]=='L')
			{
				scanf("%d%d",&x,&y);
				erase(x,y);
			}
			else if(opt[2]=='V')
			{
				scanf("%d%d",&x,&y);
				make_rev(x,y);
			}
			else if(opt[2]=='T')
			{
				scanf("%d%d",&x,&y);
				if(y==0)
					puts("0");
				else
					printf("%d\n",get_sum(x,y));
			}
			else if(opt[2]=='K')
			{
				int c;
				scanf("%d%d%d",&x,&y,&c);
				make_same(x,y,c);
			}
			else if(opt[2]=='X')
			{
				if(ts[root].size==2)
					puts("0");
				else
					printf("%d\n",get_maxsum(1,ts[root].size-2));
			}
		}
	}
	return 0;
}

/*
样例
9 11
2 -6 3 5 1 -5 -3 6 3
GET-SUM 5 4
MAX-SUM
INSERT 8 3 -5 7 2
DELETE 12 1
MAKE-SAME 3 3 2
REVERSE 3 6
GET-SUM 5 4
MAX-SUM
REVERSE 7 4
MAKE-SAME 7 3 1
GET-SUM 4 6
*/
8.	LCT
/*
hdu 4010 Query on The Trees
操作一：将x节点与y节点连接
操作二：将x变为其所在树的根，并剪去y与其父节点的连接
操作三：x到y的路径上全加上w
操作四：输出x到y路径上的最大权值
非法操作输出-1
*/

const int null=-1;

struct node
{
    int par,cld[2];
    int val;
    bool rev;  //翻转标记
    int inc;   //成段更新标记
    int mx;
} ts[MAXN];

int cnt;

inline int newnode(int val)
{
    ts[cnt].val=ts[cnt].mx=val;
    ts[cnt].par=ts[cnt].cld[0]=ts[cnt].cld[1]=null;
    ts[cnt].rev=ts[cnt].inc=0;
    return cnt++;
}

//判断节点是否为当前树的根
inline bool isroot(int x)
{
    int y=ts[x].par;
    return (y==null) || (ts[y].cld[0]!=x && ts[y].cld[1]!=x);
}

//更新rev翻转标记
inline void update_rev(int x)
{
    if(x!=null)
    {
        swap(ts[x].cld[0],ts[x].cld[1]);
        ts[x].rev^=1;
    }
}

//更新成段增加标记
inline void update_inc(int x,int inc)
{
    if(x!=null)
    {
        ts[x].inc+=inc;
        ts[x].val+=inc;
        ts[x].mx+=inc;
    }
}

//向上更新当前节点
inline void push_up(int x)
{
    int l=ts[x].cld[0],r=ts[x].cld[1];
    int temp=max((l==null?-1:ts[l].mx),(r==null?-1:ts[r].mx));
    ts[x].mx=max(temp,ts[x].val);
}

//下放标记
void push_down(int x)
{
    if(ts[x].rev)
    {
        update_rev(ts[x].cld[0]);
        update_rev(ts[x].cld[1]);
        ts[x].rev=0;
    }
    if(ts[x].inc)
    {
        update_inc(ts[x].cld[0],ts[x].inc);
        update_inc(ts[x].cld[1],ts[x].inc);
        ts[x].inc=0;
    }
}

//*注：此处的rotate与原splay略有不同，不能将z的孩子改向x
//旋转，0左旋，1右旋
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
    push_down(y);push_down(x);
    ts[y].cld[!k]=ts[x].cld[k];
    push_up(y);
    if(ts[x].cld[k]!=null)
        ts[ts[x].cld[k]].par=y;
    if(z!=null)
    {
        if(y==ts[z].cld[0])
            ts[z].cld[0]=x;
        else if(y==ts[z].cld[1])
            ts[z].cld[1]=x;
    }
    ts[x].par=z;
    ts[y].par=x;
    ts[x].cld[k]=y;
}

int St[MAXN],top;   //用于存放需要下放标记的节点

//将x伸展至该树所在的根
void splay(int x)
{
    top=0;
    St[top++]=x;
    int t=x;
    while(!isroot(t))
        St[top++]=ts[t].par,t=ts[t].par;
    while(top) push_down(St[--top]);
    while(!isroot(x))
    {
        int y=ts[x].par,z=ts[y].par;
        if(isroot(y))
            rotate(x,ts[y].cld[0]==x);
        else
        {
            int d=(ts[ts[y].par].cld[0]==y);
            if(ts[y].cld[d]==x)
                rotate(x,!d),rotate(x,d);
            else
                rotate(y,d),rotate(x,d);
        }
    }
    push_up(x);
}

void debug()
{
    REP2(i,1,cnt-1)
    {
        printf("id:%2d ",i);
        printf("val:%2d ",ts[i].val);
        printf("mx:%2d ",ts[i].mx);
        printf("par:%2d ",ts[i].par);
        printf("lcd:%2d ",ts[i].cld[0]);
        printf("rcd:%2d ",ts[i].cld[1]);
        printf("rev:%2d ",ts[i].rev);
        printf("inc:%2d ",ts[i].inc);
        puts("");
    }
    puts("");
}

//打通x到森林的根的通路
inline int access(int x)
{
    int u=x,v=null;
    do{
        splay(u);
        if(v!=null)
            ts[v].par=u;
        ts[u].cld[1]=v;
        push_up(u);v=u;u=ts[u].par;
    }while(u!=null);
    return v;
}

//使实际树旋转至x为根
inline void make_root(int x)
{
    access(x);
    splay(x);
    update_rev(x);
}

//获取x所在的树的根
inline int get_root(int x)
{
    access(x);
    splay(x);
    for(;ts[x].cld[0]!=null;x=ts[x].cld[0]);
    return x;
}

//将x与其父亲节点断开
inline void cut(int x)
{
    access(x);
    splay(x);
    ts[x].cld[0]=ts[ts[x].cld[0]].par=null;
    push_up(x);
}

//将x接到y下方
inline void link(int x,int y)
{
    make_root(x);
    ts[x].par=y;
}

//判断两个节点是否在同一颗树中
inline bool judge(int x,int y)
{
    while(ts[x].par!=null) x=ts[x].par;
    while(ts[y].par!=null) y=ts[y].par;
    return (x==y);
}

int edges[MAXN][2];
int w[MAXN];

int main()
{_
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        cnt=1;
        REP(i,n-1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            edges[i][0]=x;
            edges[i][1]=y;
        }
        REP(i,n)
        {
            scanf("%d",&w[i]);
            newnode(w[i]);
        }
        REP(i,n-1)
        {
            int u=edges[i][0],v=edges[i][1];
            link(u,v);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int kind;
            scanf("%d",&kind);
            if(kind==1)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(judge(x,y))
                    puts("-1");
                else
                    link(x,y);
            }
            else if(kind==2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if((x==y) || !judge(x,y))
                    puts("-1");
                else
                {
                    make_root(x);
                    cut(y);
                }
            }
            else if(kind==3)
            {
                int w,x,y;
                scanf("%d%d%d",&w,&x,&y);
                if(!judge(x,y))
                    puts("-1");
                else
                {
                    make_root(x);
                    access(y);
                    splay(y);
                    update_inc(y,w);
                }
            }
            else if(kind==4)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(!judge(x,y))
                    puts("-1");
                else
                {
                    make_root(x);
                    access(y);
                    splay(y);
                    printf("%d\n",ts[y].mx);
                }
            }
        }
        puts("");
    }
    return 0;
}
