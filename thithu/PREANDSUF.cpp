#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 1 << 18;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
vector<string> s(maxN);
vector<pair<int, int>> queries;
vector<int> res;
struct Trie
{
    struct Node
    {
        unordered_map<char, Node *> children;
        bool is_end = false;
    };

    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(const string &str)
    {
        Node *node = root;
        for (char c : str)
        {
            if (!node->children.count(c))
            {
                node->children[c] = new Node();
            }
            node = node->children[c];
        }
        node->is_end = true;
    }

    void collect(Node *node, string current, unordered_set<string> &result)
    {
        if (node->is_end)
        {
            result.insert(current);
        }
        for (auto &[c, child] : node->children)
        {
            collect(child, current + c, result);
        }
    }

    unordered_set<string> get_all_strings()
    {
        unordered_set<string> result;
        collect(root, "", result);
        return result;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("PREANDSUF");
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries.emplace_back(l, r);
    }

    for (auto [l, r] : queries)
    {
        Trie prefix_trie, suffix_trie;

        for (int i = l; i <= r; i++)
        {
            string cur = "";
            for (char c : s[i])
            {
                cur += c;
                prefix_trie.insert(cur);
            }
            cur = "";
            for (int j = s[i].size() - 1; j >= 0; j--)
            {
                cur = s[i][j] + cur;
                suffix_trie.insert(cur);
            }
        }

        unordered_set<string> unique_strings;
        auto prefixes = prefix_trie.get_all_strings();
        auto suffixes = suffix_trie.get_all_strings();

        for (auto &pre : prefixes)
        {
            for (auto &suf : suffixes)
            {
                unique_strings.insert(pre + suf);
            }
        }

        res.pb(unique_strings.size());
    }

    for (int it : res)
    {
        cout << it << endl;
    }
    return 0;
}
