#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*����Ȼ������һ�£����ֽ��ٵ�����ĸ����ĺ�
�Ƿ�С���������ĸ�����һ�룬��С�ڣ���ÿ��
�����������������������ټ���������������
����һ�����ɣ�����С�ڣ������ֵΪ���������
�ܸ�����ƽ������*/

int main()
{
	ll r,g,b;
	while(cin>>r>>g>>b)
	{
		ll y = max(r,max(g,b));
		ll x = r+g+b-y; 
		if(y/2 > x)cout<<x<<endl;
		else cout<<(r+g+b)/3<<endl;
	}
	return 0;
}
