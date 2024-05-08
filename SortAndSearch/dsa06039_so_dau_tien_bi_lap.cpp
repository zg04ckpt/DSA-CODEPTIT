#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int &i : a) cin>>i;

        map<int,int> cnt;
        for(int i : a) cnt[i]++;

        bool ok = 0;
        for(int i : a)
            if(cnt[i]>1)
            {
                cout<<i<<"\n";
                ok = 1;
                break;
            }
        
        if(!ok) cout<<"NO\n";
    }
}