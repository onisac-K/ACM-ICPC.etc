#include<bits/stdc++.h>
using namespace std;

struct stu{
	string name;
	int grade;
}win[10005][3];

int main()
{
	int n,m;
	string a;
	int b,c;
	cin>>n>>m;
	for(int i=0;i<=10005;++i)for(int j=0;j<3;++j)win[i][j].grade=-1;
	while(n--)
	{
		cin>>a;
		scanf("%d%d",&b,&c);
		if(c>win[b][0].grade)
		{
			win[b][2].name=win[b][1].name;
			win[b][2].grade=win[b][1].grade;
			win[b][1].name=win[b][0].name;
			win[b][1].grade=win[b][0].grade;
			
			win[b][0].name=a;
			win[b][0].grade=c;
			
		}
		else if(c>win[b][1].grade) 
		{
			win[b][2].name=win[b][1].name;
			win[b][2].grade=win[b][1].grade;
			win[b][1].name=a;
			win[b][1].grade=c;
		}
		else if(c>win[b][2].grade)
		{
			win[b][2].name=a;
			win[b][2].grade=c;
		}
	}
	for(int i=1;i<=m;++i)
	{
		//cout<<win[i][1].grade<<' '<<win[i][2].grade<<endl;
		if(win[i][1].grade==win[i][2].grade)
		{
			printf("?\n");
		}
		else 
		{
			cout<<win[i][0].name<<' '<<win[i][1].name<<endl;
		}
	}
}
