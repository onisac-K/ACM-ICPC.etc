#include<iostream>

using namespace std;
char a[18];
int b,sum;
int main()
{
//freopen("p.in","r",stdin);
//freopen("p.out","w",stdout);
cin>>a;
b=((a[0]-'0')+(a[2]-'0')*2+(a[3]-'0')*3+(a[4]-'0')*4+(a[6]-'0')*5+(a[7]-'0')*6+(a[8]-'0')*7+(a[9]-'0')*8+(a[10]-'0')*9)%11;

if (b==10&&a[12]=='X')
{
cout<<"Right";
return 0;
}
if(a[12]-'0'==b)
{
cout<<"Right";
return 0;
}
else
{
for(int i=0;i<12;i++) cout<<a[i];
if (b==10) cout<<'X';
else cout<<b;
}
return 0;
}
