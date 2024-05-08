#include<bits/stdc++.h>
#define ll long long

using namespace std;

string s, x;
char c[] = {'+', '-', '*', '/'};
bool ok;

bool validCheck()
{
    int a = (x[0]-'0')*10 + x[1]-'0';
    int b = (x[5]-'0')*10 + x[6]-'0';
    int c = (x[10]-'0')*10 + x[11]-'0';

    if(x[3] == '+') return a+b == c;
    if(x[3] == '-') return a-b == c;
    if(x[3] == '*') return a*b == c;
    return a/b == c;
}

void tryAt(int i)
{
    if(ok) return;

    if(i == s.size())
    {
        if(validCheck())
        {
            ok = 1;
            cout<<x<<"\n";
        }
        return;
    }

    if(s[i] != '?') tryAt(i+1);
    else if(i == 3)
    {
        for(int j=0; j<4; ++j)
        {
            x[i] = c[j];
            tryAt(i+1);
        }
    }
    else
    {
        for(int j=0; j<=9; ++j)
        {
            if(j == 0)
                if(i==0 || i==5 || i==10)
                    continue;
            
            x[i] = '0'+j;
            tryAt(i+1);
        }
    }
}

int main()
{
    int t; cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        x = s;

        ok = 0;
        tryAt(0);

        if(!ok) cout<<"WRONG PROBLEM!\n";
    }
}