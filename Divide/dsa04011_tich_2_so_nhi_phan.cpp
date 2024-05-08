#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
10 -> k=2
dư của 10:2
7:2 -> 1
3:2 -> 1
1:2 -> 1
111
*/

ll kToDecimal(string &s, int k)
{
    ll res = 0;
    for(char &c : s)
        res = res*k + c-'0';
    return res;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s1,s2; cin>>s1>>s2;
        cout<<kToDecimal(s1, 2)*kToDecimal(s2, 2)<<"\n";
    }
}