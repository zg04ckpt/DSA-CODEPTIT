#include<bits/stdc++.h>
#define ll long long

using namespace std;

string d[101];

string add(string a, string b)
{
    int n = a.size();
    int m = b.size();
    string res = "";
    int carry = 0;
    int i = n-1, j = m-1;
    while(i>=0 && j>=0)
    {
        int sum = (a[i]-'0') + (b[j]-'0') + carry;
        res = to_string(sum%10) + res;
        carry = sum/10;
        i--; j--;
    }
    while(i>=0)
    {
        int sum = (a[i]-'0') + carry;
        res = to_string(sum%10) + res;
        carry = sum/10;
        i--;
    }
    while(j>=0)
    {
        int sum = (b[j]-'0') + carry;
        res = to_string(sum%10) + res;
        carry = sum/10;
        j--;
    }
    if(carry) res = to_string(carry) + res;
    return res;
}

/*
 123
 111

 123
1230
*/
string mul(string a, string b)
{
    string res = "0";
    int n = a.size();
    int m = b.size();
    int carry;
    for(int j=m-1; j>=0; j--)
    {
        string temp = string(m-j-1, '0');
        carry = 0;
        for(int i=n-1; i>=0; i--)
        {
            int m = (b[j]-'0') * (a[i]-'0') + carry;
            temp = to_string(m%10) + temp;
            carry = m/10;
        }
        if(carry) temp = to_string(carry) + temp;
        res = add(res, temp);
    }

    return res;
}

void init()
{
    d[0] = d[1] = "1";
    for(int i=2; i<=100; ++i)
    for(int j=0; j<i; ++j)
        d[i] = add(d[i], mul(d[j], d[i-j-1]));
}

int main()
{
    init();
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cout<<d[n]<<"\n";
    }
}