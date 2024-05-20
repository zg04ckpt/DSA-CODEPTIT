#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    char d;
    node *l = NULL, *r = NULL;
    node(char d)
    {
        this->d = d;
    }
};

void inOrder(node *root)
{
    if(root == NULL) return;
    inOrder(root->l);
    cout<<root->d;
    inOrder(root->r);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<node*> st;
        for(char c :s )
        {
            if(isalpha(c))
                st.push(new node(c));
            else
            {
                node *sign = new node(c);
                sign->r = st.top(); st.pop();
                sign->l = st.top(); st.pop();
                st.push(sign);
            }
        }

        inOrder(st.top());
        cout<<"\n";
    }
}