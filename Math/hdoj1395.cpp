#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int nm=0; nm<t; nm++)
    {
        string judge;
        int s[100]= {0};
        int tot,st;
        while(cin >> judge)
        {
            if(judge=="End") break;
            if (judge=="Create")
            {
                int n,m;
                cin >> n >> m;
                tot=0;
                st=0;
                for (int i=0; i<100; i++)
                {
                    if (s[i]==0) tot++;
                    else
                    {
                        st=i+1;
                        tot=0;
                    }
                    if (tot>=m)
                    {
                        for (int j=st; j<=i; j++)
                            s[j]=n;
                        cout <<"Create process "<<n<<" of size "<<m<<" successfully!"<<endl;
                        break;
                    }
                }
                if (tot<m) cout <<"No enough memory!"<<endl;
            }
            else
            {
                if (judge=="Delete")
                {
                    int n;
                    cin >> n ;
                    tot=0;
                    int z=-1;
                    for (int i=0; i<100; i++)
                    {
                        if (s[i]==n)
                        {
                            tot++;
                        }
                        else if (tot!=0)
                        {
                            z=i-1;
                            break;
                        }
                    }



                    if (tot==0) cout <<"No such process!"<<endl;
                    else
                    {
                        if (z==-1) z=99;
                        while ((z>=0)&&(s[z]==n)) s[z--]=0;
                        cout << "Delete process " << n << " of size " << tot << " successfully!" << endl;
                    }

                }
                else
                {
                    if (judge=="Print")
                    {
                        st=s[0];
                        tot=0;
                        for (int i=0; i<100; i++)
                        {
                            if (s[i]==st) tot++;
                            else
                            {
                                if (st==0)
                                    cout << "H "<<tot<< endl;
                                else
                                    cout << "P "<<st << " "<<tot << endl;
                                st=s[i];
                                tot=1;
                            }
                        }
                        if (st==0)
                            cout << "H "<<tot<< endl;
                        else
                            cout << "P "<<st << " "<<tot << endl;
                    }
                }
            }

        }
    }
    return 0;
}
