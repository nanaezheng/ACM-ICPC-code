#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

#define UNUSE -1;

char sourStr[1000];
char destStr[1000];
int outputStr[2000];
stack<char> *st;
int sourPos,destPos;
int inputLen;

void output()
{
    int i;
    for(i=0;i<inputLen*2;i++)
        printf("%c ",outputStr[i]==0?'o':'i');
    printf("\n");
}

void dfs(int k)
{
    if(destPos==inputLen)
        output();
    else
    {
        //入栈操作分枝
        if(sourPos<inputLen)
        {
            outputStr[k]=1;
            st->push(sourStr[sourPos]);
            sourPos++;
            dfs(k+1);
            //还原状态
            sourPos--;
            st->pop();
            outputStr[k]=UNUSE;
        }
        //出栈操作分枝
        if(!st->empty() && st->top()==destStr[destPos])
        {
            outputStr[k]=0;
            st->pop();
            destPos++;
            dfs(k+1);
            //还原状态
            destPos--;
            st->push(destStr[destPos]);
            outputStr[k]=UNUSE;
        }
    }
}

int main()
{
    st=new stack<char>;
    while(scanf("%s\n%s",&sourStr,&destStr)!=EOF)
    {
        printf("[\n");
        sourPos=destPos=0;
        inputLen=strlen(sourStr);
        dfs(0);
        printf("]\n");
    }
    return 0;
}
