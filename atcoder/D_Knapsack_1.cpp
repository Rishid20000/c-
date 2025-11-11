#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// // vector<vector<ll>>dp;
// ll knap(vector<pair<ll,ll>>&vec,ll n,ll index,ll wt){
        
//         if(index>=n) return 0;  
//         if(wt==0) return 0;
//         if(dp[index][wt]!=-1) return dp[index][wt];
//         ll take=0;
        
//         if(wt-vec[index].first>=0){
//             take = vec[index].second + knap(vec,n,index+1,wt-vec[index].first);
//         }
//         ll notake = knap(vec, n, index + 1, wt);

//         ll ans = max(take,notake);
//         return  dp[index][wt] =  ans;
// }

void solve()
{   
    ll n;
    ll wt;
    cin>>n>>wt;
    vector<pair<ll,ll>>vec(n);
    for(auto &i:vec){
        cin>>i.first>>i.second;
    }

    // dp.resize(n+1,vector<ll>(wt+1,0));
    // cout<<knap(vec,n,0,wt)<<"\n";
    vector<ll>dp(wt+1,0);

    for(int i=0;i<n;i++){
        int curr = vec[i].first;
        int val  = vec[i].second;
        for(int j=wt;j>=curr;j--){
            dp[j] = max(dp[j],val+dp[j-curr]);
        }
    }

    cout<<dp[wt]<<"\n";

    // for(int i=1;i<=n;i++){
    //     vector<ll>temp(wt+1,0);
    //     temp[0] = newdp[0];
    //     for(int j=wt;j>=0;j--){
    //         temp[j]  = newdp[j-1];
    //         ll currwt = vec[i-1].first;
    //         ll val = vec[i-1].second;
    //         if(j-currwt>=0){
    //             temp[j] = max(temp[j], val + newdp[j - currwt]);
    //         }
    //     }
    //     newdp = temp;
    // }

    // for(auto i:newdp) cout<<i<<" ";
    // cout<<"\n";

    // cout<<newdp[wt]<<"\n";

}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}