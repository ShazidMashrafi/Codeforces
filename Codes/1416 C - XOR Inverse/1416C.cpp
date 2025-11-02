#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

const int MAXBIT = 29;

class Trie {
public:
    struct TrieNode {
        TrieNode* children[2];
        vector<int>indices;
        
        TrieNode() {
            for (int i = 0; i < 2; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num, int index) {
        TrieNode* node = root;
        node->indices.pb(index);

        for(int i = MAXBIT; i >= 0; --i) {
            bool bit = (num >> i) & 1;
            if(!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->indices.pb(index);
        }
    }
};

ll countInversions(auto &left, auto &right) {
    ll inv = 0;
    int j = 0;
    
    for(int i = 0; i < sz(left); ++i) {
        while(j < sz(right) && right[j] < left[i]) {
            j++;
        }
        inv += j;
    }
    return inv;
}

void dfs(auto &dp, Trie::TrieNode* node, int depth)
{
    if(!node || depth < 0) return;
    
    if(node->children[0] && node->children[1]) {
        vector<int>&left = node->children[0]->indices;
        vector<int>&right = node->children[1]->indices;

        dp[depth][0] += countInversions(left, right);
        dp[depth][1] += countInversions(right, left);
    }

    if(node->children[0])   dfs(dp, node->children[0], depth - 1);
    if(node->children[1])   dfs(dp, node->children[1], depth - 1);
}

void solve()
{
    Trie trie;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        trie.insert(a, i);
    }

    vector<vector<ll>> dp(MAXBIT + 1, vector<ll>(2, 0));
    dfs(dp, trie.root, MAXBIT);

    ll inversions = 0;
    ll x = 0;
    for(int depth = MAXBIT; depth >= 0; --depth) {
        if(dp[depth][0] <= dp[depth][1]) {
            inversions += dp[depth][0];
        } else {
            inversions += dp[depth][1];
            x |= (1LL << depth);
        }
    }
    cout << inversions << " " << x << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}