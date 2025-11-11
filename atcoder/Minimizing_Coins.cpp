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
    cin>>n;
    ll sum;
    cin>>sum;
    vector<ll>vec(n);
    for(auto &i:vec) cin>>i;
    vector<ll>dp(sum+1,1e15);
    dp[0]=0;
    for(ll num:vec){
        
        for(ll i=num;i<=sum;i++){
            dp[i] = min(dp[i],(1+dp[i-num]));
        }
    }
    
    ll ans = dp[sum];
    if(ans==1e15) {
        cout<<-1<<"\n";
        return;
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