#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string b; cin>>b;
        string g = "";
        g += b[0];
        for(int i=1; i<b.size(); ++i)
        {
            g += ((b[i]-'0') ^ (b[i-1]-'0')) + '0';
        }
        cout<<g<<"\n";
    }
}