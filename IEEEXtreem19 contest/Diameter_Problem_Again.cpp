#include <bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

const int MAXN=300005;
const int MAXM=300005;
const ll INF=2e18;

vector<pair<int,ll>>adj[MAXN];
int parent[MAXN];
ll dist_from_root[MAXN];
int depth[MAXN];
int up[MAXN][20];
int cdt_parent[MAXN];
int subtree_size[MAXN];
bool is_removed[MAXN];

struct SegNode
{
    ll max_dist=-INF;
    int left=0,right=0;
};
vector<SegNode>node_pool;
int root[MAXN];
vector<int>list_A;
ll last_ans=0;
int n,m;

int get_lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i=19; i>=0; --i)
    {
        if(depth[u]-(1<<i)>=depth[v])u=up[u][i];
    }
    if(u==v)return u;
    for(int i=19; i>=0; --i)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

ll get_dist(int u, int v)
{
    int lca=get_lca(u, v);
    return dist_from_root[u]+dist_from_root[v]-2*dist_from_root[lca];
}

void dfs_lca(int u, int p, ll d, int dep)
{
    parent[u]=p;
    dist_from_root[u]=d;
    depth[u]=dep;
    up[u][0]=p;
    for(int i=1; i<20; ++i)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(auto edge:adj[u])
    {
        int v=edge.first;
        ll w=edge.second;
        if(v!=p)dfs_lca(v, u, d+w, dep+1);
    }
}

void dfs_size(int u, int p, int &total_size)
{
    subtree_size[u]=1;
    total_size++;
    for(auto edge:adj[u])
    {
        int v=edge.first;
        if(v!=p&&!is_removed[v])
        {
            dfs_size(v, u, total_size);
            subtree_size[u]+=subtree_size[v];
        }
    }
}

int find_centroid(int u, int p, int total_size)
{
    for(auto edge:adj[u])
    {
        int v=edge.first;
        if(v!=p&&!is_removed[v]&&subtree_size[v]*2>total_size)return find_centroid(v, u, total_size);
    }
    return u;
}

void build_cdt(int u, int p)
{
    int total_size=0;
    dfs_size(u, 0, total_size);
    int c=find_centroid(u, 0, total_size);
    cdt_parent[c]=p;
    is_removed[c]=true;
    for(auto edge:adj[c])
    {
        int v=edge.first;
        if(!is_removed[v])build_cdt(v,c);
    }
}

void init_dynamic_seg_trees()
{
    node_pool.reserve(40*MAXM);
    node_pool.emplace_back();
}

int update_seg(int current_node_idx, int start, int end, int idx, ll val)
{
    if(current_node_idx==0)
    {
        node_pool.emplace_back();
        current_node_idx=node_pool.size()-1;
    }
    if(start==end)
    {
        node_pool[current_node_idx].max_dist=val;
        return current_node_idx;
    }
    int mid=(start+end)/2;
    if(idx<=mid) node_pool[current_node_idx].left=update_seg(node_pool[current_node_idx].left, start, mid, idx, val);
    else node_pool[current_node_idx].right=update_seg(node_pool[current_node_idx].right, mid+1, end, idx, val);
    ll left_max=node_pool[node_pool[current_node_idx].left].max_dist;
    ll right_max=node_pool[node_pool[current_node_idx].right].max_dist;
    node_pool[current_node_idx].max_dist=max(left_max, right_max);
    return current_node_idx;
}

ll query_seg(int node_idx, int start, int end, int l, int r)
{
    if(node_idx==0 || r<start || end<l || l>r)
        return -INF;
    if(l<=start && end<=r)
        return node_pool[node_idx].max_dist;
    int mid=(start+end)/2;
    ll p1=query_seg(node_pool[node_idx].left, start, mid, l, r);
    ll p2=query_seg(node_pool[node_idx].right, mid+1, end, l, r);
    return max(p1, p2);
}

void op1_append(int x)
{
    list_A.push_back(x);
    int current_idx=list_A.size();
    int curr_node=x;
    while(curr_node!=0)
    {
        ll dist=get_dist(curr_node, x);
        root[curr_node]=update_seg(root[curr_node], 1, MAXM, current_idx, dist);
        curr_node=cdt_parent[curr_node];
    }
}

void op2_remove()
{
    if(list_A.empty())return;
    int x=list_A.back();
    int last_idx=list_A.size();
    list_A.pop_back();
    int curr_node=x;
    while(curr_node!=0)
    {
        root[curr_node]=update_seg(root[curr_node], 1, MAXM, last_idx, -INF);
        curr_node=cdt_parent[curr_node];
    }
}

void op3_query(int l, int r, int x)
{
    int list_size=list_A.size();
    if(list_size==0)return;
    x=(x^(last_ans<0?-last_ans:last_ans))%n+1;
    l=(l^(last_ans<0?-last_ans:last_ans))%list_size+1;
    r=(r^(last_ans<0?-last_ans:last_ans))%list_size+1;
    if(l>r)swap(l, r);
    ll max_dist=-INF;
    int curr_node=x;
    while(curr_node!=0)
    {
        ll max_dist_to_c=query_seg(root[curr_node], 1, MAXM, l, r);
        if(max_dist_to_c>-INF/2)
        {
            ll current_max=get_dist(x, curr_node)+max_dist_to_c;
            if(current_max>max_dist)
                max_dist=current_max;
        }
        curr_node=cdt_parent[curr_node];
    }
    cout<<max_dist<<endl;
    last_ans=max_dist;
}

int main()
{
    shihab
    cin>>n;
    for(int i=0; i<n-1; ++i)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    init_dynamic_seg_trees();
    dfs_lca(1, 0, 0, 0);
    build_cdt(1, 0);
    cin>>m;
    for(int i=0; i<m; ++i)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int x_in;
            cin>>x_in;
            int x=(x_in^(last_ans<0?-last_ans:last_ans))%n+1;
            op1_append(x);
        }
        else if (q==2)op2_remove();
        else if (q==3)
        {
            int l_in, r_in, x_in;
            cin>>l_in>>r_in>>x_in;
            op3_query(l_in, r_in, x_in);
        }
    }
    return 0;
}