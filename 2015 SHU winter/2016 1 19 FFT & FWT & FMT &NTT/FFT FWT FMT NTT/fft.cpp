// KuangbinÄ£°å 

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

void FFT(Complex y[],int len,int on) {
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

// ºìÊéÄ£°å 

/*
const double pi=acos(-1.0);
typedef complex<double> Complex;
 
void build(Complex _P[], Complex P[], int n, int m, int curr, int &cnt) {
    if(m==n) {
        _P[curr]=P[cnt++];
    }else{
        build(_P,P,n,m*2,curr,cnt);
        build(_P,P,n,m*2,curr+m,cnt);
    }
}
void FFT(Complex P[], int n ,int oper) {
    static Complex _P[200000];
    int cnt=0;
    build(_P,P,n,1,0,cnt);
    copy(_P,_P+n,P);
    for(int d=0;(1<<d)<n;d++) {
        int m=1<<d;
        int m2=m*2;
        double p0=pi/m*oper;
        Complex unit_p0=Complex(cos(p0), sin(p0));
        for(int i=0;i<n;i+=m2) {
            Complex unit=1;
            for(int j=0;j<m;j++) {
                Complex &P1=P[i+j+m], &P2=P[i+j];
                Complex t=unit*P1;
                P1=P2-t;
                P2=P2+t;
                unit=unit*unit_p0;
            }
        }
    }
}
*/
