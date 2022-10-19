#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
#define print(x) cc[cnt]+=x;
using namespace std;
int cnt=0;
string cc[500];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i=0;i<500;i++) cc[i]="";
        cnt=0;
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for (int i=1;i<=2*b;i++){
            cnt++;
            int aa=2*b+1-i;
            for (int i=1;i<=aa;i++) cc[cnt]+=".";//printf(".");
            if (i%2==1) {
                for (int j=1;j<=a;j++) cc[cnt]+="+-";//printf("+-");
                for (int j=1;j<=(i-1)/2;j++) cc[cnt]+="+.";//printf("+.");
                cc[cnt]+="+";//printf("+\n");
            }
            else {
            for (int j=1;j<=a;j++)
            cc[cnt]+="/.";//printf("/.");
            for (int j=1;j<=i/2;j++) cc[cnt]+="/|";//printf("/|");
        //  printf("\n");
            }
        }
         
        for (int i=1;i<=c-b;i++){
            cnt++;
            for (int j=1;j<=a;j++) print("+-");
            for (int j=1;j<=b;j++) print("+.");
            print("+");
            cnt++;
            for (int j=1;j<=a;j++) print("|.");
            for (int j=1;j<=b;j++) print("|/");
            print("|");
        }
        cnt++;
        for (int j=1;j<=a;j++) print("+-");
            for (int j=1;j<=b;j++) print("+.");
            print("+");
        for (int i=2*b;i>=1;i--){cnt++;
                    int aa=2*b+1-i;
                    if (i%2==1) {
                        for (int j=1;j<=a;j++) print("+-");
                        for (int j=1;j<=(i-1)/2;j++) print("+.");
                        print("+");
                    }
                    else {
                    for (int j=1;j<=a;j++)
                    print("|.");
                    for (int j=1;j<=i/2;j++) print("|/");
                     
                    }
                    for (int i=1;i<=aa;i++) print(".");
                }
                int o=0;
            for (int i=2*c+2;i<=2*c+1+2*b;i++){
                o++;
                int v=cc[i].length();
                for (int j=v-1;j>=v-o;j--)
                cc[i][j]='.';
            }
        for (int i=1;i<=min(cnt,2*c+1+2*b);i++) cout<<cc[i]<<'\n';
    }
} 
