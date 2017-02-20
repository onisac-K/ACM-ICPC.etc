#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=200100;
int t1[MAXN],t2[MAXN],c[MAXN];
bool cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int ra[],int height[],int n,int m)
{
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0;i < m;i++)c[i] = 0;
	for(i = 0;i < n;i++)c[x[i] = str[i]]++;
	for(i = 1;i < m;i++)c[i] += c[i-1];
	for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
	for(j = 1;j <= n; j <<= 1)
	{
		p = 0;
		for(i = n-j; i < n; i++)y[p++] = i;
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
		for(i = 0; i < m; i++)c[i] = 0;
		for(i = 0; i < n; i++)c[x[y[i]]]++;
		for(i = 1; i < m;i++)c[i] += c[i-1];
		for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1; x[sa[0]] = 0;
		for(i = 1;i < n;i++)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n)break;
		m = p;
	}
	int k = 0;
	n--;
	for(i = 0;i <= n;i++)ra[sa[i]] = i;
	for(i = 0;i < n;i++)
	{
		if(k)k--;
		j = sa[ra[i]-1];
		while(str[i+k] == str[j+k])k++;
		height[ra[i]] = k;
	}
}
int ra[MAXN],height[MAXN];
int sa[MAXN],num[MAXN];

bool ok(int num,int n)
{
	int Max,Min;
	for(int i=2;i<=n;++i){
		if(height[i]<num){
			Max = Min = sa[i];
		}
		else{
			Max = max(Max,sa[i]);
			Min = min(Min,sa[i]);
			if(Max-Min>=num)return true;
		}
	}
	return false;
}

int a[MAXN];

int main()
{
	int n;
	while(cin>>n && n){
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i)a[i] = a[i+1] - a[i] + 90; 
		a[n-1] = 0;
		//for(int i=0;i<n;++i)cout<<a[i]<<' ';cout<<endl;
		da(a,sa,ra,height,n-1,190);
		int l=0,r = n-1;
		while(l<=r){
			int mid = (l+r)>>1;
			if(ok(mid,n-1))l = mid+1;
			else r = mid -1;
		}
		int ans = 0;
		if(l>=5)ans = l; 
		cout<<ans<<endl;
	}
	return 0;
 } 
 
