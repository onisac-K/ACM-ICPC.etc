#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x = _x;y = _y;
	}
	Point operator -(const Point &b)const
	{
		return Point(x - b.x,y - b.y);
	}
	//叉积
	double operator ^(const Point &b)const
	{
		return x*b.y - y*b.x;
	}
	//点积
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//绕原点旋转角度B（弧度值），后x,y的变化
	void transXY(double B)
	{
		double tx = x,ty = y;
		x = tx*cos(B) - ty*sin(B);
		y = tx*sin(B) + ty*cos(B);
	}
};

const int MAXN = 1010;
Point L[MAXN],Ans[MAXN];
int Stack[MAXN],top;

double dist(Point a,Point b)
{
	return sqrt((a-b)*(a-b));
}

bool _cmp(Point p1,Point p2)
{
	double tmp = (p1-L[0])^(p2-L[0]);
	if(sgn(tmp) > 0)return true;
	else if(sgn(tmp) == 0 && sgn(dist(p1,L[0]) - dist(p2,L[0])) <= 0) return true;
	return false;
}

void Graham(int n)
{
	Point p0;
	int k = 0;
	p0 = L[0];
	for(int i = 1;i < n;i++)
	{
		if( (p0.y > L[i].y) || (p0.y == L[i].y && p0.x > L[i].x) )
		{
			p0 = L[i];
			k = i;
		}
	}
	swap(L[k],L[0]);
	sort(L+1,L+n,_cmp);
	if(n == 1)
	{
		top = 1;
		Stack[0] = 0;
		return;
	}
	if(n == 2)
	{
		top = 2;
		Stack[0] = 0;
		Stack[1] = 1;
		return ;
	}
	Stack[0] = 0;
	Stack[1] = 1;
	top = 2;
	for(int i = 2;i < n;i++)
	{
		while(top > 1 && sgn((L[Stack[top-1]]-L[Stack[top-2]])^(L[i]-L[Stack[top-2]])) <= 0)
		top--;
		Stack[top++] = i;
	}
}

int main()
{
	int n;
	while(cin>>n && n){
		int x,y;
		memset(Stack,-1,sizeof Stack);
		for(int i=0;i<n;++i){
			scanf("%d%d",&x,&y);
			L[i].x = x;
			L[i].y = y;
		}
		Graham(n);
		
		//cout<<endl;
		double ans = 0;
		//for(int i=0;i<top;++i)cout<<L[Stack[i]].x<<' '<<L[Stack[i]].y<<endl; 
		if(n == 2){
			ans = dist(L[0],L[1]);
			printf("%.2f\n",ans);
			continue;
		}
		
		for(int i=0;i<top-1;++i){
			ans += dist(L[Stack[i]],L[Stack[i+1]]);
		}
		ans += dist(L[Stack[0]],L[Stack[top-1]]);
		printf("%.2f\n",ans);
	}
	return 0;
}
