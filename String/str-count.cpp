#include<cstdio>
#include<cstring>

char str[1000005],s[6];
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%s%s",str,s);
        int len1=strlen(str);
        int len2=strlen(s);
        int res=0;
        for(int i=0; i+len2-1<len1; i++){
            int flag=1;
            for(int j=0; j<len2; j++){
                if(str[i+j]!=s[j]) {
                    flag=0;
                    break;
                }
            }
            if(flag) {
                res++;
                i=i+len2-1;
            }
        }
        printf("%d\n",res);
    }
}
