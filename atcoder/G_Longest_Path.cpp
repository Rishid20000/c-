#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7, inf = 1e9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

void solve() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    


}

int main() {
    fast_io;
    int t;
    // cin >> t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}