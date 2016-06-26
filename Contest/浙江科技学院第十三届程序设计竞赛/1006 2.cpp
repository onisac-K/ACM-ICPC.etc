#include<iostream>
#include<algorithm>
using namespace std;
bool ran(int x,int y)
{
     return x<y;
}
int main()
{
    int k,i,j;
    while(cin>>k)
    {
                 if(k==0) break;
                 int tj[1001],king[1001];
                 for(i=0;i<k;i++) cin>>tj[i];
                 for(i=0;i<k;i++) cin>>king[i];
                 sort(tj,tj+k,ran);
                 sort(king,king+k,ran);
                 long int count=0;
                 int tj_min=0,tj_max=k-1;
                 int king_min=0,king_max=k-1;
                 while(tj_min<=tj_max)
                 {
                    if(tj[tj_max]>king[king_max])
                    {
                            count++;
                            tj_max--;king_max--;
                    }
                else if(tj[tj_min]>king[king_min])
                    {
                        	count++;
                            tj_min++;king_min++;
                	}
                                      else
                                      {
                                            if(tj[tj_min]<king[king_max])
                                            count--;
                                            tj_min++;king_max--;
                                      }   
                 }
                 cout<<count*100<<endl;
    }
   
    return 0;
}
