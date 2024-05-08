#include<bits/stdc++.h>
#define ll long long

using namespace std;

//   
// num1: 2 4 6 
// num2: 3 5 8

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int &i : a) cin>>i;

        sort(a, a+n);

        ll num1 = 0, num2 = 0;
        for(int i=0; i<n; i++)
        {
            if(i%2) num1 = num1*10+a[i];
            else num2 = num2*10+a[i];
        }

        cout<<num1+num2<<"\n";
    }
}