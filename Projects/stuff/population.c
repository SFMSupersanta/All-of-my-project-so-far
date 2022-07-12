// Năm 1993 dân số nước ta là a=72 triệu người.
// Tốc độ tăng dân số là k% mỗi năm. Hỏi đến năm nào dân số nước ta tăng gấp s lần so với năm 1993, chạy chương trình với k = 2,3 %, s = 1,5 lần.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long tinhtoan(double k, double s, long long a)
{
    long long a2s = a * s;
    long long atb = a;
    // printf("k,s,a,a2s,atb:%lf %lf %lld %lld %lld\n",k,s,a,a2s,atb);
    int count = 0;
    while (atb < a2s)
    {
        atb = atb + (atb * k) / 100;
        count++;
    }
    return count;
}

int main()
{
    int year = 1993;
    long long a = 73000000;
    double k;
    double s;

    printf("Nhap toc do tang dan so: \n");
    scanf("%lf", &k);
    printf("So lan gap so voi nam 1993: \n");
    scanf("%lf", &s);

    int ketqua = tinhtoan(k, s, a);
    printf("So nam can tim la: %d", year + ketqua);
    return 0;
}