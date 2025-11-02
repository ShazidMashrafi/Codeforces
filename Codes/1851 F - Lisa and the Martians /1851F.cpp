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

class Trie {
public:
    struct TrieNode {
        TrieNode* children[2];
        int index;
        
        TrieNode() {
            index = -1;
            for (int i = 0; i < 2; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num, int idx, int k) {
        TrieNode* node = root;
        for(int i = k - 1; i >= 0; --i) {
            bool bit = (num >> i) & 1;
            if(!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
        node->index = idx;
    }

    pair<int, int> find(int num, int k) {
        TrieNode* node = root;
        int x = 0;
        for(int i = k - 1; i >= 0; --i) {
            bool bit = (num >> i) & 1;
            bool opposite = bit ^ 1;
            if(node->children[bit]) {
                x |= (opposite << i);
                node = node->children[bit];
            } else {
                x |= (bit << i);
                node = node->children[opposite];
            }
        }

        return {node->index, x};
    }
};

void solve()
{
    int n, k;
    cin >> n >>k;
    vector<int>a(n);
    for(auto &i : a) {
        cin >> i;
    }

    Trie trie;
    int mx = -1, bestI = 0, bestJ = 1, bestX = 0;

    for(int i = 0; i < n; ++i) {
        if(i) {
            auto [j, x] = trie.find(a[i], k);
            int val = (a[i] ^ x) & (a[j] ^ x);

            if(val > mx) {
                mx = val;
                bestI = i;
                bestJ = j;
                bestX = x;
            }
        }
        trie.insert(a[i], i, k);
    }
    cout << bestI + 1 << " " << bestJ + 1 << " " << bestX << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}