#include <bits/stdc++.h> 
using namespace std;
char a1[10000];
char a[2005];
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		gets(a);
		int L=strlen(a);
		int n=0;
		int num=0;

		for(int i=0;i<L;++i)
		{
			if(a[i]==' ')continue;
			if(isdigit(a[i]))
			{
				int j=0;
				int q=0;
				num=0;
				for(j=i;j<L;++j)
				{
					if(isdigit(a[j]))
					{
						num=num*10+(a[j]-'0');
						a1[q++]=a[j];
					}
					else break;
				}
				a1[q]='\0';
				i=j-1;
				if(a[j]!='d'||j==L-1)
				{
					printf("%s",a1);
					num=0;
				}
			}
			else if(a[i]=='d')
			{
				int q=0;
				if(num==0||num==1)
				{
					printf("[d");
					for(q=i+1;q<L;++q)
					{
						if(isdigit(a[q]))cout<<a[q];
						else break;
					}
					printf("]");
				}
				else 
				{
                    cout<<"(";
					for(int j=0;j<num;++j)
					{
						printf("[d");
						for(q=i+1;q<L;++q)
						{
							if(isdigit(a[q]))cout<<a[q];
							else break;
						}
						printf("]");
						if(j<num-1)cout<<" + ";
					}
					cout<<")";
				}
				num=0;
				i=q-1;
				/*string s;
				int j;
				for(j=i+1;j<L&&isdigit(a[j]);++j)
				{
					s+=a[j];
				}
				//cout<<s<<endl;
				j--;
				i=j;
				if(num==0||num==1)
					cout<<"[d"<<s<<"]";
				else
				{
					for(int k=0;k<num;++k)
					{
						if(k==0)
							cout<<"([d"<<s<<']';
						else cout<<" + [d"<<s<<"]";
					}
					cout<<")";
				} 
				num = 0;*/
			}
			else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
			{
				cout<<" "<<a[i]<<' ';
			}
			else if(a[i]=='('||a[i]==')')cout<<a[i];
		}
		cout<<" = [Result]"<<endl;
	}
	return 0;
}
