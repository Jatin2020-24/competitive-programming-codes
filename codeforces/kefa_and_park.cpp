#include<bits/stdc++.h>

#define vi vector<int>
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define ll long long int
using namespace std;

int n = 1e5 + 5,m;
vector<vi> adj(n);
vi a(n);
int ans = 0;

// u -- current node
// p -- parent node
// numC -- number of continuous nodes with cat
// maxC -- maximum no. of consecutive nodes with cat
void dfs(int u, int p, int numC, int maxC)
{
    if(a[u])
        numC++;
    else
        numC=0;
    maxC = max(numC, maxC);  // now we know for each node the max # of 
    // consecutive cats in the path from 1 to that node.
    int numChild = 0;
    for(int v:adj[u]){
        if(v != p){
            dfs(v,u,numC,maxC);
            numChild++;
        }
    }
    // if current node is leaf node and maxC <= m 
    // increase ans by 1.
    if(numChild == 0 && maxC <=m)
        ans++;
}

int main()
{
    optimize();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,0,0);
    cout<<ans<<endl;
    return 0;
}