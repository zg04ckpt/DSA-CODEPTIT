#include<bits/stdc++.h>
#define ll long long

using namespace std;

string s;

void tryAt(int i, int pre, string x)
{
    for(int j=pre+1; j<s.size(); ++j)
    {
        cout<<x+s[j]<<" ";
        tryAt(i+1, j, x+s[j]);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n>>s;
        tryAt(1, -1, "");
        cout<<"\n";
    }
}