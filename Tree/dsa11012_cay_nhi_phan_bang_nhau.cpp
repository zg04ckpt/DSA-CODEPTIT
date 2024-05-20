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

bool check(node *root1, node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1!=NULL && root2!=NULL)
    {
        return root1->d == root2->d &&
        check(root1->l, root2->l) &&
        check(root1->r, root2->r);
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n1; cin>>n1;
        node *root1 = NULL;
        while(n1--)
        {
            cin>>par>>chi>>c;
            if(root1 == NULL)
                root1 = new node(par);
            build(root1);
        }

        int n2; cin>>n2;
        node *root2 = NULL;
        while(n2--)
        {
            cin>>par>>chi>>c;
            if(root2 == NULL)
                root2 = new node(par);
            build(root2);
        }

        cout<<check(root1, root2)<<"\n";
    }
}