#include<bits/stdc++.h>
using namespace std;
char a[5024];
char b[5024<<2];
 
void update(int x)
{
    if(b[2*x]==b[2*x+1])b[x]=b[2*x+1];
    else b[x]='F';
    printf("%c",b[x]);
}
 
void build(int x,int l,int r)
{
    if(l==r)
    {
        a[l-1]=='0'? b[x]='B':b[x]='I';
        printf("%c",b[x]);
        return ;
    }
    int mid=(l+r)>>1;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
    update(x);
}
 
int main()
{
    int n;
    while(cin>>n)
    {
    	scanf("%s",a);
    	memset(b,0,sizeof(b));
    	build(1,1,1<<n);
    	cout<<endl;
	}
    
    return 0;
}
