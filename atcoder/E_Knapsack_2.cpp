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
    ll n;
    ll wt;
    cin>>n>>wt;
    vector<pair<ll,ll>>vec(n);
    ll maxval = 0;

    for(auto &i:vec) {
        cin >> i.first >> i.second; // wt and value;
        maxval += i.second;
    }

    vector<ll>dp(maxval+1,1e15);

    dp[0] =0;

    for(auto [wt,val]:vec){
            for(ll i=maxval;i>=val;i--){
                dp[i]  = min(dp[i],wt+dp[i-val]);
            }
    }

    ll ans=0;

    for(int i=0;i<=maxval;i++){
        if(dp[i]<=wt){
            ans = i;
        }
    }

    cout<<ans<<"\n";
    
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