#include <iostream>
#include <cstdio>
using namespace std;
struct missile
{
    int height;
    missile *next;
};
int main()
{
    int n,count,Max,a;
    missile *head,*p1,*p2,*p3;
    while(scanf("%d",&n)!=EOF)
    {
        count=0;
        Max=-1;
        head=NULL;
        p2=head;
        p1=p2;
        for(int i=0;i<n;i++)
        {
            p1=new missile;
            scanf("%d",&p1->height);
            if(i==0) head=p1;
            else p2->next=p1;
            p2=p1;
            p1->next=NULL;
        }
        while(head)
        {
            count++;
            p1=head;
            p2=head;
            Max=head->height;
            while(p1->next)
            {
                if(p1->next->height<=Max)
                {
                    Max=p1->next->height;
                    p2=p1->next;
                    p1->next=p1->next->next;
                    delete p2;
                }
                else
                {
                    p1=p1->next;
                }
            }
            p1=head->next;
            delete head;
            head=p1;
        }
        printf("%d\n",count);
    }
}
