#include <stdio.h>
int main()
{ 
    int n; 
    long long factorial =1;
    scanf("%d", &n);
    for(int i=n; i >=1; i--) { factorial = factorial *i;
    }
    printf("%lld", factorial );
}