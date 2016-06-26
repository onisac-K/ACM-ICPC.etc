/*unfinished*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
// 0 -> right ; 1 -> left

set <string> s;
set <string> vis;

ll ans=0;
void dfs(int num,int z,int fx,int paodao,string value)
{
	if(vis.count(value))return ;
	vis.insert(value);
	if(num>2*n||z>2*k-1)return ;
	if(paodao>n+1||paodao<=0)return ;
	
	if(num==2*n&&z==2*k-1&&paodao==1)
	{
		if(!s.count(value))
		{
			ans++;
			//cout<<value<<endl;
			s.insert(value);
		}
	}
	int x=paodao+1;
	int y=paodao-1;
	int num1[50];
	int c=0;
	while(x>0)
	{
		num1[c++]=x%10;
		x/=10;
	}
	string s1=value;
	int lence1=s1.length();

	
	
	if(fx==0)
	{
		dfs(num+1,z,0,paodao+1,value*10+paodao+1);
		dfs(num+1,z+1,1,paodao-1,value*10+paodao-1);
	}
	if(fx==1)
	{
		dfs(num+1,z+1,0,paodao+1,value*10+paodao+1);
		dfs(num+1,z,1,paodao-1,value*10+paodao-1);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		vis.clear();
		s.clear();
		cin>>n>>k;
		dfs(0,0,0,1,"1");
		cout<<ans<<endl;
	}
}
