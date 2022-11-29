#include<cstdio>
#include<cstring>
int now, go[100010][27];
char s[100010];
int main()
{
    scanf("%s",s);
    go[0][s[0]-'a']=1;
    int len=strlen(s);
    now=0;
    for (int i=1;i<len;i++) {
        for (int j=0;j<26;j++) {
            if (j==s[i]-'a') go[i][j]=i+1;
            else go[i][j]=go[now][j];
        }
        now=go[now][s[i]-'a'];
    }
    for (int i=0;i<len;i++) {
        for (int j=0;j<26;j++)
        printf("%d ",go[i][j]);
        printf("\n");
    }
}
