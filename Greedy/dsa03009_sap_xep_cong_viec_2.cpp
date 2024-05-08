#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct cv{
    int id,dl,pro;
    bool operator<(cv o)
    {
        return pro < o.pro;
    }
};

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cv a[n];
        for(cv &i : a)
            cin>>i.id>>i.dl>>i.pro;

        sort(a, a+n);

        int cnt = 0, p = 0;
        bool busy[1001] = {};
        for(int i=n-1; i>=0; i--)
        {
            for(int j=a[i].dl; j>=1; j--)
            {
                if(!busy[j])
                {
                    cnt++;
                    p += a[i].pro;
                    busy[j] = 1;
                    break;
                }
            }
        }

        cout<<cnt<<" "<<p<<"\n";
    }
}