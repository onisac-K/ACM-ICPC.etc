#include<bits/stdc++.h>
using namespace std;

string num[1000];
 
//compare�ȽϺ�������ȷ���0�����ڷ���1��С�ڷ���-1
int compare(string str1,string str2)
{
    if(str1.length()>str2.length()) return 1;
    else if(str1.length()<str2.length())  return -1;
    else return str1.compare(str2);
}
//�߾��ȼӷ�
//ֻ���������������
string add(string str1,string str2)//�߾��ȼӷ�
{
    string str;

    int len1=str1.length();
    int len2=str2.length();
    //ǰ�油0��Ū�ɳ�����ͬ
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}
//�߾��ȼ���
//ֻ���������������������Ҫ���С
string sub(string str1,string str2)//�߾��ȼ���
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//ȥ������ж����ǰ��0
    return str;
}
//�߾��ȳ˷�
//ֻ���������������
string mul(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    string tempstr;
    for(int i=len2-1;i>=0;i--)
    {
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0)
        {
            for(int j=1;j<=len2-1-i;j++)
              tempstr+="0";
            for(int j=len1-1;j>=0;j--)
            {
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}



int main()
{
	int i=0;
	num[0] = "1";
	string s = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	while(compare(num[i],s) == -1){
		cout<<num[i]<<endl;
		string k = add(num[i],"1");
		//cout<<mul(k,k)<<endl;
		num[i+1] = mul(k,k);
		i++;
	}
	cout<<123<<endl;
	return 0;
 } 
