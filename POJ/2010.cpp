#include<queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long

struct node{
	int score;
	int money;
	bool operator< (const node &x)const{
		return money<x.money;
	}
}s[100005];

int ans[100005];

bool cmp(node x,node y){
	return x.score<y.score;
}

ll l[100005];
ll r[100005];

int main()
{
	int n,c,f;
	cin>>n>>c>>f;
	if(n%2==0)n++;
	priority_queue<node> q;
	for(int i=0;i<c;++i)scanf("%d%d",&s[i].score,&s[i].money);
	sort(s,s+c,cmp);
	ll sum = 0;
	for(int i=0;i<n/2;++i){
		q.push(s[i]);
		sum += s[i].money;
	}
	for(int i=n/2;i<=c-n/2-1;++i){
		l[i] = sum;
		//cout<<sum<<endl;
		q.push(s[i]);
		sum -= q.top().money;
		sum += s[i].money;
		q.pop();
	}
	while(!q.empty())q.pop();
	sum = 0;
	for(int i=c-n/2;i<c;++i){
		//cout<<s[i].money<<endl;
		q.push(s[i]);
		sum += s[i].money;
	}
	for(int i=c-n/2-1;i>=n/2;--i){
		r[i] = sum;
		//cout<<sum<<endl;
		q.push(s[i]);
		//cout<<s[i].money<<' '<<q.top().money<<endl;
		sum -= q.top().money;
		sum += s[i].money;
		q.pop();
	}
	int ans ;
	for(int i=c-n/2-1;i>=n/2;--i)
	{
		//cout<<i<<' '<<s[i].score<<endl;
		if(n&1 && l[i]+r[i]+s[i].money<=f){	
			ans = s[i].score;
			break;
		}
		else if(n%2==0 && l[i]+r[i]<=f){
			ans = s[i].score;
			break;	
		}
	}
	cout<<ans<<endl;
	return 0;
}
