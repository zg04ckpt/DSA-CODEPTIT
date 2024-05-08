#include<bits/stdc++.h>
#define ll long long

using namespace std;

string s;
int x[11], n;
bool check[11];

void print()
{
    for(int i=1; i<=n; ++i) cout<<s[x[i]];
    cout<<" ";
}

void tryAt(int i)
{
    for(int j=1; j<=n; ++j)
    {
        if(check[j]) continue;
        x[i] = j;
        check[j] = 1;

        if(i == n) print();
        else tryAt(i+1);

        check[j] = 0;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.size();
        s = " " + s;
        tryAt(1);
        cout<<"\n";

        memset(check, 0, sizeof check);
    }
}