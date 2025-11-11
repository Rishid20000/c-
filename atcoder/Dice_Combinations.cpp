#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector<ll> dp;

ll fun(int n)
{
    if (n == 0)
        return 1; 
    if (n < 0)
        return 0; 
    if (dp[n] != -1)
        return dp[n];

    ll cnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        cnt = (cnt + fun(n - i)) % mod;
    }
    return dp[n] = cnt;
}

void solve()
{
    int n;
    cin >> n;
    dp.assign(n +1, 0);
    dp[0] =1;
    for(int i=1;i<=n;i++){
        ll cnt=0;
        for(int j=1;j<=6;j++){
             if(i-j>=0) cnt= (cnt+dp[i-j])%mod;
        }
        dp[i]  = (dp[i]+cnt)%mod;
    }

    cout <<dp[n]<< "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
