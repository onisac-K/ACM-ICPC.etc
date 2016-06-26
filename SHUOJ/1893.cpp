#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

struct Complex {
    double r,i;
    Complex(double _r = 0.0,double _i = 0.0) {
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b) {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b) {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b) {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(Complex y[],int len) {
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++) {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void fft(Complex y[],int len,int on) {
    change(y,len);
    for(int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h) {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++) {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

int ans[400010];
char a[100005],b[100005];
//int A[100005],B[100005];
Complex x1[400010],x2[400010];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s %s",a,b);
		int lena=strlen(a);
		int lenb=strlen(b);
		int len=1;
		while(len<(lena+lenb))len<<=1;
		for(int i=0;i<lena;++i)x1[i]=Complex(a[lena-1-i]-'0',0);
		for(int i=lena;i<len;++i)x1[i]=Complex(0,0);
		for(int i=0;i<lenb;++i)x2[i]=Complex(b[lenb-1-i]-'0',0);
		for(int i=lenb;i<len;++i)x2[i]=Complex(0,0);
		fft(x1,len,1);
		fft(x2,len,1);
		for(int i=0;i<len;++i)x1[i]=x1[i]*x2[i];
		fft(x1,len,-1);
		for(int i=0;i<len;++i)ans[i]=(int)(x1[i].r+0.5);
		for(int i=0;i<len;++i)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		len=lena+lenb-1;
		while(ans[len]<=0&&len>0)len--;
		for(int i=len;i>=0;--i)cout<<ans[i];
		cout<<endl;
	}
} 
