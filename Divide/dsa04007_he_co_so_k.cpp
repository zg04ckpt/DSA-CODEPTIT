#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int k; cin>>k;
        string a,b; cin>>a>>b;

        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";

        while(i>=0 && j>=0)
        {
            int sum = (a[i]-'0')+(b[j]-'0')+carry;
            ans = to_string(sum%k)+ans;
            carry = sum/k;
            i--; j--;
        }

        while(i>=0)
        {
            int sum = (a[i]-'0')+carry;
            ans = to_string(sum%k)+ans;
            carry = sum/k;
            i--;
        }

        while(j>=0)
        {
            int sum = (b[j]-'0')+carry;
            ans = to_string(sum%k)+ans;
            carry = sum/k;
            j--;
        }

        if(carry) ans = to_string(carry)+ans;

        cout<<ans<<'\n';
    }
}