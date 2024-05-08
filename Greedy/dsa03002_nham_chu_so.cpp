#include<bits/stdc++.h>
#define ll long long

using namespace std;

int sToInt(string s, char from, char to)
{
    int num = 0;
    for(char &c : s)
    {
        if(c == from) c = to;
        num = num*10 + c-'0';
    }
    return num;
}

int main()
{
    string a, b; cin>>a>>b;
    cout<<sToInt(a, '6', '5')+sToInt(b, '6', '5')<<" ";
    cout<<sToInt(a, '5', '6')+sToInt(b, '5', '6');
}