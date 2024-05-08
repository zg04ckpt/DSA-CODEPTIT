#include<bits/stdc++.h>
#define ll long long

using namespace std;

void prev(string &s)
{
    int i = s.size()-1;
    while(i >= 0 && s[i] == '0')
    {
        s[i] = '1';
        i--;
    }

    if(i >= 0)
    {
        s[i]= '0';
    }
    else
    {
        for(char &c : s) c = '1';
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        prev(s);
        cout<<s<<"\n";
    }
}