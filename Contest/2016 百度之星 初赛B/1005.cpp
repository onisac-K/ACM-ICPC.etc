#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define PII pair<int,int>
int a[100010];
ll sum[100010];
PII edge[100010];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,k;
    while(cin>>n>>m>>k){
        for(int i=1;i<=n;++i)
		{
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        int u,v;
        for(int i=0;i<m;++i)
		{
            scanf("%d%d",&u,&v);
            edge[i].first = u;
            edge[i].second = v;
        }
        sort(edge,edge+m);
        ll ans = 0;
        int j = 0;
        while(!q.empty())q.pop();
        for(int i=1;i<=n;++i)
		{
            while(j < m && edge[j].first <= i)
			{
                q.push(edge[j].second);
                j++;
            }
            while(q.size() > k)q.pop();
            if(q.size() == k){
                ans = max(ans , sum[q.top()] - sum[i-1]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
