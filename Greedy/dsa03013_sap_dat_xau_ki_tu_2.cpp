#include<bits/stdc++.h>
#define ll long long

using namespace std;

//k = số lần xuất hiện của kí tự xh max
//k không thể lớn hơn (n-k)/(D-1) 2 đơn vị
//k - (n-k)/(D-1) <= 1

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int d; cin>>d;
        string s; cin>>s;
        map<char, int> mp;
        for(char &c : s) mp[c]++;

        int k = 0;
        for(auto p : mp) k = max(k, p.second);

        int n = s.size();
        if(k-(n-k)/(d-1) <= 1) cout<<"1\n";
        else cout<<"-1\n";
    }
}