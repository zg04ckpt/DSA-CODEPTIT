#include<bits/stdc++.h>
#define ll long long

using namespace std;

void send(int n, char a, char b, char c)
{
    if(n == 1) 
    {
        cout<<a<<" -> "<<c<<"\n";
        return;
    }

    send(n-1, a, c, b);
    send(1, a, b, c);
    send(n-1, b, a, c);
}

int main()
{
    int n; cin>>n;
    send(n, 'A', 'B', 'C');
}