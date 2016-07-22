#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

struct node{
	int st;
	int ed;
	bool operator< (const node & a)const{
		return ed>a.ed;
	}
}bull[3000];

bool cmp(node a,node b){
	return a.st<b.st;
}

struct point{
	int cnt;
	int spf;
	bool operator< (const point & a)const{
		return spf<a.spf;
	}
}cre[3000];

int main()
{
	int c,l;
	cin>>c>>l;
	for(int i=0;i<c;++i)
		scanf("%d%d",&bull[i].st,&bull[i].ed);
	sort(bull,bull+c,cmp);
	priority_queue<node> q;
	for(int i=0;i<l;++i){
		scanf("%d%d",&cre[i].spf,&cre[i].cnt);
	}
	sort(cre,cre+l);
	int j=0,ans=0;
	for(int i=0;i<l;++i){
		//cout<<"cre"<<cre[i].spf<<' '<<cre[i].cnt<<endl;
		while(j<c && bull[j].st<=cre[i].spf){	
			//cout<<"bull"<<bull[j].st<<' '<<bull[j].ed<<endl;
			q.push(bull[j]);
			j++;
		}
		while(!q.empty() && cre[i].cnt){
			node s = q.top();
			q.pop();
			//cout<<s.st<<' '<<s.ed<<endl;
			if(s.ed>=cre[i].spf){
				cre[i].cnt--;
				ans++;
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}

/*
*/
