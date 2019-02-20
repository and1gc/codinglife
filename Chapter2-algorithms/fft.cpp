#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

double PI = acos(-1);
using FS = complex<double>;

vector<FS> recursive_fft(vector<FS> &a,int n,int flag)
{
    if (n == 1)
        return vector<FS>(1,a[0]);

    vector<FS> y(n);
    FS wn(cos(2 * PI / n), sin(2 * PI*flag / n));
    FS w(1, 0);
    vector<FS> a0(n / 2), a1(n / 2);
    for (int i = 0; i < a.size(); ++i)
    {
        if (i % 2 == 0)
            a0[i / 2] = a[i];
        else
            a1[i / 2 ] = a[i];
    }
    vector<FS> y0 = recursive_fft(a0,n/2,flag);
    vector<FS> y1 = recursive_fft(a1,n/2,flag);
    for (int k = 0; k < n / 2; ++k)
    {
        y[k] =y0[k]+w*y1[k] ;
        y[k + n / 2] =y0[k]-w*y1[k] ;
        w = w * wn;
    }
    
    return y;
}

int main()
{
    vector<FS> a = { 0,1 ,2,3};
    vector<FS> b = { 1,0,0,1 };
    //找到n+m最接近的2的幂次方
    int n = a.size(), m = b.size();
    m += n, n = 1;
    while (n < m) 
        n=n << 1;

    vector<FS> c(n);//结果
    vector<FS> y1 = recursive_fft(a, n,1);
    vector<FS> y2 = recursive_fft(b, n, 1);
    vector<FS> y3(n);
    for (int i = 0; i < n; ++i)
        y3[i] = y1[i] * y2[i];

    y3 = recursive_fft(y3, n, -1);
    for (auto &p : y3)
        p /= FS(n);
    for_each(y3.begin(), y3.end(), [](const auto &p) {cout << p << " "; });
    while (1);
    return 0;
}