#include<bits/stdc++.h>
#define ll long long

using namespace std;

//4/5 -> 1/(5:4) = 1/2
//p/q - 1/newQ = (p*newQ - 1*q)/q.newQ;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll p,q; cin>>p>>q;
        while(q%p)
        {
            ll newQ = q/p+1;
            cout<<"1/"<<newQ<<" + ";
            p = p*newQ - q;
            q = q*newQ;
        }
        cout<<"1/"<<q/p<<"\n";
    }
}