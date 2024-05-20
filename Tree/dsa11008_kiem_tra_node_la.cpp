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
int firstLv;

void traversal(node* root, int lev)
{
    if(root==NULL || !ok) return;
    if(root->l==NULL && root->r==NULL)
    {
        if(firstLv == -1)
            firstLv = lev;
        else if(firstLv != lev)
        {

            ok = 0;
            return;
        }
    }
    else
    {
        traversal(root->l, lev+1);
        traversal(root->r, lev+1);
    }
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
        firstLv = -1;
        traversal(root, 0);

        cout<<ok<<"\n";
    }
}