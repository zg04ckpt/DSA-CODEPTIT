#include<bits/stdc++.h>
#define ll long long

using namespace std;

string tree[1001];

int calc(int i)
{
    if(tree[i] == "+")
        return calc(2*i+1) + calc(2*i+2);
    else if(tree[i] == "-")
        return calc(2*i+1) - calc(2*i+2);
    else if(tree[i] == "*")
        return calc(2*i+1) * calc(2*i+2);
    else if(tree[i] == "/")
        return calc(2*i+1) / calc(2*i+2);
    else
        return stoi(tree[i]);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        for(int i=0; i<n; ++i)
            cin>>tree[i];
        
        cout<<calc(0)<<"\n";
    }
}