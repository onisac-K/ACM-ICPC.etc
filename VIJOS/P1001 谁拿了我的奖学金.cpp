#include<bits/stdc++.h>
using namespace std;

struct student
{
	char name[50];
	double final;
	double appraise;
	char cadre[2];
	char west[2];
	int num;
	double money;
}p[105];

int main()
{
	int n;
	scanf("%d",&n);
	char bestman[100];
	double max=0;
	double sum=0;
	for(int i=0;i<n;++i)
	{
		scanf("%s %lf %lf %s %s %d",p[i].name,&p[i].final,&p[i].appraise,p[i].cadre,p[i].west,&p[i].num);
		p[i].money=0;
		if(p[i].final>80 && p[i].num>=1)p[i].money+=8000;
		if(p[i].final>85 && p[i].appraise>80)p[i].money+=4000;
		if(p[i].final>90)p[i].money+=2000;
		if(p[i].final>85 && p[i].west[0]=='Y')p[i].money+=1000;
		if(p[i].appraise>80 && p[i].cadre[0]=='Y')p[i].money+=850;
		sum+=p[i].money;
		if(p[i].money>max)
		{
			max=p[i].money;
			strcpy(bestman,p[i].name);
		}
	}
	printf("%s\n",bestman);
	cout<<max<<endl;
	cout<<sum<<endl;
	return 0;
}
