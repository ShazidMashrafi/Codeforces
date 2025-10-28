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
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }

    multiset<ll>dfs(TrieNode* node, ll depth) {
        multiset<ll>res;
        if(node->isEnd) {
            res.insert(depth);
        }

        for(int i = 0; i < 26; ++i) {
            if(node->children[i]) {
                multiset<ll> child = dfs(node->children[i], depth + 1);

                if(sz(child) > sz(res)) {
                    swap(res, child);
                }

                for(int d : child) {
                    res.insert(d);
                }
            }
        }

        if(!node->isEnd && !res.empty() && depth) {
            auto it = res.rbegin();
            res.erase(res.find(*it));
            res.insert(depth);
        }

        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    Trie trie;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    multiset<ll> st = trie.dfs(trie.root, 0);
    ll tot = 0;
    for(int x : st) {
        tot += x;
    }

    cout << tot << endl;
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