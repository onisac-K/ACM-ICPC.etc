7.	splay������棩
/*
splay����汾
���Ǽ����������
*/
/*
bzoj1500 ά������
����һ����pos�������tot����
����������pos����ɾ��tot����
����������pos����tot����ȫ���c
�����ģ���pos����tot������ת
�����壺��pos����tot�����ĺ�
����������ȫ���е�����Ӷκ�
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

//�·�rev��ת��� 
void update_rev(int x)
{
	if(x!=null)
	{
		swap(ts[x].cld[0],ts[x].cld[1]);
		swap(ts[x].maxl,ts[x].maxr);
		ts[x].rev^=1;
	}
}

//�·�same������ͬ��� 
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
 
//��ת��0������1���� 
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

//��x��չ��S�·� 
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

//��ȡ���������kλ�Ľڵ��� 
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
 
//��p�²���l��r���� 
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

//ɾ���ڵ㣬�����ڴ� 
void erasenode(int x)
{
	if(x!=null)
	{
		St[top++]=x;
		erasenode(ts[x].cld[0]);
		erasenode(ts[x].cld[1]);
	}
}

//��ȡ��pos��ʼ����tot�����ĺ� 
int get_sum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].sum;
}

//��ȡ��pos��ʼ����tot�������������� 
int get_maxsum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].maxm;
}

//��pos�󷽲�������tot���� 
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

//��pos��ɾ������tot���� 
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

//pos��ʼ����tot�������c 
void make_same(int pos,int tot,int c)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	update_same(key_value,c);
	push_up(ts[root].cld[1]);
	push_up(root);
}

//pos��ʼ����tot������ת
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
����
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
����һ����x�ڵ���y�ڵ�����
����������x��Ϊ���������ĸ�������ȥy���丸�ڵ������
��������x��y��·����ȫ����w
�����ģ����x��y·���ϵ����Ȩֵ
�Ƿ��������-1
*/

const int null=-1;

struct node
{
    int par,cld[2];
    int val;
    bool rev;  //��ת���
    int inc;   //�ɶθ��±��
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

//�жϽڵ��Ƿ�Ϊ��ǰ���ĸ�
inline bool isroot(int x)
{
    int y=ts[x].par;
    return (y==null) || (ts[y].cld[0]!=x && ts[y].cld[1]!=x);
}

//����rev��ת���
inline void update_rev(int x)
{
    if(x!=null)
    {
        swap(ts[x].cld[0],ts[x].cld[1]);
        ts[x].rev^=1;
    }
}

//���³ɶ����ӱ��
inline void update_inc(int x,int inc)
{
    if(x!=null)
    {
        ts[x].inc+=inc;
        ts[x].val+=inc;
        ts[x].mx+=inc;
    }
}

//���ϸ��µ�ǰ�ڵ�
inline void push_up(int x)
{
    int l=ts[x].cld[0],r=ts[x].cld[1];
    int temp=max((l==null?-1:ts[l].mx),(r==null?-1:ts[r].mx));
    ts[x].mx=max(temp,ts[x].val);
}

//�·ű��
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

//*ע���˴���rotate��ԭsplay���в�ͬ�����ܽ�z�ĺ��Ӹ���x
//��ת��0������1����
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

int St[MAXN],top;   //���ڴ����Ҫ�·ű�ǵĽڵ�

//��x��չ���������ڵĸ�
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

//��ͨx��ɭ�ֵĸ���ͨ·
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

//ʹʵ������ת��xΪ��
inline void make_root(int x)
{
    access(x);
    splay(x);
    update_rev(x);
}

//��ȡx���ڵ����ĸ�
inline int get_root(int x)
{
    access(x);
    splay(x);
    for(;ts[x].cld[0]!=null;x=ts[x].cld[0]);
    return x;
}

//��x���丸�׽ڵ�Ͽ�
inline void cut(int x)
{
    access(x);
    splay(x);
    ts[x].cld[0]=ts[ts[x].cld[0]].par=null;
    push_up(x);
}

//��x�ӵ�y�·�
inline void link(int x,int y)
{
    make_root(x);
    ts[x].par=y;
}

//�ж������ڵ��Ƿ���ͬһ������
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
