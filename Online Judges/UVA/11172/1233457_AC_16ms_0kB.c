#include<stdio.h>

int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b) printf(">\n");
        if(a<b) printf("<\n");
        if(a==b) printf("=\n");
    }

    return 0;
}
