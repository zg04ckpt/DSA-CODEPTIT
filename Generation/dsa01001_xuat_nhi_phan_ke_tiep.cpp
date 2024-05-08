#include<bits/stdc++.h>
#define ll long long

using namespace std;

void next(string &s)
{
    int i = s.size()-1;
    while(i > 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }

    if(i != 0)
    {
        s[i] = '1';
    }
    else for(char &c : s) c = '0';
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        next(s);
        cout<<s<<"\n";
    }
}