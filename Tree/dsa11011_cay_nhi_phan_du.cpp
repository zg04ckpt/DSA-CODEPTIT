#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    int d;
    node *l = NULL, *r = NULL;
    node(int d)
    {
        this->d = d;
    }
};

int par, chi;
char c;

void build(node *root)
{
    if(root == NULL) return;
    if(root->d == par)
    {
        if(c == 'L') root->l = new node(chi);
        else root->r = new node(chi);
    }
    else
    {
        build(root->l);
        build(root->r);
    }
}

bool ok;
void traversal(node *root)
{
    if(!ok || root==NULL) return;
    if(root->l==NULL && root->r==NULL)
        return;
    if(root->l==NULL || root->r==NULL)
    {
        ok = 0;
        return;
    }
    traversal(root->l);
    traversal(root->r);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        node *root = NULL;
        while(n--)
        {
            cin>>par>>chi>>c;
            if(root == NULL)
                root = new node(par);
            build(root);
        }

        ok = 1;
        traversal(root);
        cout<<ok<<"\n";
    }
}