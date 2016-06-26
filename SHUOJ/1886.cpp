#include<iostream>
using namespace std;
int num[100001];
struct node
{
    int sum;
    int maxm;
    int minm;
};
node t[400010];
void creat(int x, int left, int right)
{
    if (left == right){     
        t[x].sum   =num[left];
        t[x].minm= t[x].maxm=num[left];
        return;
    }
    creat(x * 2, left, (left + right) / 2);     
    creat(x * 2 + 1, (left + right) / 2 + 1, right);    
    t[x].maxm = max(t[x * 2].maxm , t[x * 2 + 1].maxm);
    t[x].minm= min(t[x * 2].minm , t[x * 2 + 1].minm);
    t[x].sum=t[x * 2].sum + t[x * 2 + 1].sum;
}
void add(int x, int left, int right, int lb, int rb, int q)
{
    if (left == lb && right == rb)      
    {
        t[x].sum += q;
        t[x].maxm+=q;
        t[x].minm+=q;
        return;
    }
    if (rb <= (left + right) / 2)        
        add(x * 2, left, (left + right) / 2, lb, rb, q);
    else if(lb > (left+right) / 2 )      
        add(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb, q);
    else{
        add(x*2, left, (left+right)/2, lb, (left+right)/2, q);
        add(x*2+1,(left+right)/2+1, right, (left+right)/2+1 , rb, q); 
    }   
    t[x].maxm = max(t[x * 2].maxm , t[x * 2 + 1].maxm);
    t[x].minm= min(t[x * 2].minm , t[x * 2 + 1].minm);
    t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
}
/*
int count(int x, int left, int right, int lb, int rb,int &Max,int &Min)
{
    if (left == lb && right == rb){
        Max=t[x].maxm;
        Min=t[x].minm;
        return t[x].sum;
    }       
    if (rb <= (left + right) / 2)        
        return count(x * 2, left, (left + right) / 2, lb, rb,Max,Min);
    else if (lb > (left + right) / 2)        
        return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb,Max,Min);
    else{
        Max=max(count(x * 2, left, (left + right) / 2, lb, (left + right) / 2,Max,Min),count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb,Max,Min));
        Min=min(count(x * 2, left, (left + right) / 2, lb, (left + right) / 2,Max,Min),count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb,Max,Min));    
        return count(x * 2, left, (left + right) / 2, lb, (left + right) / 2,Max,Min) + count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb,Max,Min);
    }
}
*/
int count(int x, int left, int right, int lb, int rb)
{
    if (left == lb && right == rb)      
        return t[x].sum;
    if (rb <= (left + right) / 2)        
        return count(x * 2, left, (left + right) / 2, lb, rb);
    else if (lb > (left + right) / 2)        
        return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
    else      
        return count(x * 2, left, (left + right) / 2, lb, (left + right) / 2) + count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);
}
  
int big(int x,int left,int right, int lb,int rb){
    if (left == lb && right == rb)      
        return t[x].maxm;
    if (rb <= (left + right) / 2)        
        return big(x * 2, left, (left + right) / 2, lb, rb);
    else if (lb > (left + right) / 2)        
        return big(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
    else{
        int a=big(x * 2, left, (left + right) / 2, lb, (left + right) / 2);
        int b=big(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);
        return max( a,b );
    }   
}
  
int small(int x,int left,int right, int lb,int rb){
    if (left == lb && right == rb)      
        return t[x].minm;
    if (rb <= (left + right) / 2)        
        return small(x * 2, left, (left + right) / 2, lb, rb);
    else if (lb > (left + right) / 2)        
        return small(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
    else{
        int a=small(x * 2, left, (left + right) / 2, lb, (left + right) / 2) ;
        int b=small(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);  
        return min(a,b);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    creat(1,1,n);
    while(m--){
        int q,l,r;
        scanf("%d%d%d",&q,&l,&r);
        if(q==1){
            add(1,1,n,l,l,r);
        //  for(int i=1;i<=2*n;i++){
        //      cout<<t[i].sum<<' '<<t[i].maxm<<' '<<t[i].minm<<',';
        //  }
        //  cout<<endl;
        }
        if(q==2){
            int Max=big(1,1,n,l,r);
            int Min=small(1,1,n,l,r);
            int sum=count(1,1,n,l,r);
            printf("%d %d %d\n",Max,sum,Min);
        }
    }
      
    return 0;
}
