#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s;
        bool check[10] = {};
        while(n--)
        {
            cin>>s;
            for(char &c : s) check[c-'0'] = 1;
        }

        for(int i=0; i<=9; ++i)
            if(check[i]) cout<<i<<" ";
        cout<<"\n";
    }
}