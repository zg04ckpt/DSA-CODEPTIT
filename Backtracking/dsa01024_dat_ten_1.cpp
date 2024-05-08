#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
string x[16], a[31];

void print()
{
    for(int i=1; i<=k; ++i) cout<<x[i]<<" ";
    cout<<"\n";
}

void tryAt(int i, int pre)
{
    for(int j=pre+1; j<=n-k+i; j++)
    {
        x[i] = a[j];
        if(i == k) print();
        else tryAt(i+1, j);
    }
}

int main()
{
    cin>>n>>k;
    set<string> st;
    string temp;
    while(n--)
    {
        cin>>temp;
        st.insert(temp);
    }

    int c = 0;
    for(string s : st)
    {
        c++;
        a[c] = s;
    }
    n = c;

    tryAt(1, 0);
}