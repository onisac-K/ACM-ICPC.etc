#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[10];
		cin>>a;
		for(int i=0;i<4;++i)
		{
			if(a[i]=='A'||a[i]=='B'||a[i]=='C'||a[i]=='a'||a[i]=='b'||a[i]=='c')cout<<2;
			else if(a[i]=='G'||a[i]=='H'||a[i]=='I'||a[i]=='g'||a[i]=='h'||a[i]=='i')cout<<4;
		else 	if(a[i]=='M'||a[i]=='N'||a[i]=='O'||a[i]=='m'||a[i]=='n'||a[i]=='o')cout<<6;
		else 	if(a[i]=='T'||a[i]=='U'||a[i]=='V'||a[i]=='t'||a[i]=='u'||a[i]=='v')cout<<8;
		else 	if(a[i]=='D'||a[i]=='E'||a[i]=='F'||a[i]=='d'||a[i]=='e'||a[i]=='f')cout<<3;
		else 	if(a[i]=='J'||a[i]=='K'||a[i]=='L'||a[i]=='j'||a[i]=='k'||a[i]=='l')cout<<5;
		else 	if(a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='S'||a[i]=='p'||a[i]=='q'||a[i]=='r'||a[i]=='s')cout<<7;
		else 	if(a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='Z'||a[i]=='w'||a[i]=='x'||a[i]=='y'||a[i]=='z')cout<<9;
			else cout<<a[i];
		}
		cout<<'-';
		for(int i=4;i<8;++i)
		{
			if(a[i]=='A'||a[i]=='B'||a[i]=='C'||a[i]=='a'||a[i]=='b'||a[i]=='c')cout<<2;
			else if(a[i]=='G'||a[i]=='H'||a[i]=='I'||a[i]=='g'||a[i]=='h'||a[i]=='i')cout<<4;
		else 	if(a[i]=='M'||a[i]=='N'||a[i]=='O'||a[i]=='m'||a[i]=='n'||a[i]=='o')cout<<6;
		else 	if(a[i]=='T'||a[i]=='U'||a[i]=='V'||a[i]=='t'||a[i]=='u'||a[i]=='v')cout<<8;
		else 	if(a[i]=='D'||a[i]=='E'||a[i]=='F'||a[i]=='d'||a[i]=='e'||a[i]=='f')cout<<3;
		else 	if(a[i]=='J'||a[i]=='K'||a[i]=='L'||a[i]=='j'||a[i]=='k'||a[i]=='l')cout<<5;
		else 	if(a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='S'||a[i]=='p'||a[i]=='q'||a[i]=='r'||a[i]=='s')cout<<7;
		else 	if(a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='Z'||a[i]=='w'||a[i]=='x'||a[i]=='y'||a[i]=='z')cout<<9;
			else cout<<a[i];
		}
		cout<<endl;
	}
 } 
