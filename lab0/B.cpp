#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
#define print(x) cc[cnt]+=x;
using namespace std;
char a[2],b[22];
int main()
{
    scanf(" %s\n",a,b);
    fgets(b,100,stdin);
    if (b[0]==a[0]||b[3]==a[0]||b[6]==a[0]||b[9]==a[0]||b[12]==a[0]||b[2]==a[1]||b[5]==a[1]||b[8]==a[1]||b[11]==a[1]||b[14]==a[1])
    printf("All in");
    else printf("Fold");
     
}
