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

// template <typename T>
// void printv(const vector<T> &v) {
//     for (auto &e : v) cout << e << ' ';
//     cout << '\n';
// }

// template <typename T>
// void inputv(vector<T> &v) {
//     for (auto &e : v) cin >> e;
// }

// vector<ll> sieve(ll n) {
//     vector<ll> prime(n + 1, 1);
//     prime[0] = prime[1] = 0;
//     for (ll i = 2; i * i <= n; i++) {
//         if (prime[i]) {
//             for (ll j = i * i; j <= n; j += i)
//                 prime[j] = 0;
//         }
//     }
//     vector<ll> primes;
//     for (ll i = 2; i <= n; i++)
//         if (prime[i]) primes.pb(i);
//     return primes;
// }

// void solve() {
//     int n;
//     cin>>n;
//     vector<ll>vec(n);
//     for(auto &i:vec) cin>>i;

//     unordered_map<int,int>mp;
//     for(auto i:vec){
//         mp[i]++;
//     }

//     vector<int> res(n);

//     int maxi = *max_element(vec.begin(), vec.end());
//     int mini = *min_element(vec.begin(), vec.end());

//     res[0] = mini;
//     mp[mini]--;
//     if (mp[mini] == 0)
//         mp.erase(mini);
//     multiset<pair<int,int>>mst;
//     set<int>unq;
//     for(auto i:mp){
//         if(i.second>1 && i.second%2==0){
//             mst.insert({i.first,i.second});
//         }else{
//                 int f = i.second;
//                 while(f--)
//                     unq.insert(i.first);
//         }
//     }


  

//     for(int i=0;i<n-1;i++){
//         if(i&1){
//             if(mst.size()==0){
//                 cout<<"NO\n";
//                 return;
//             }else{
//                     auto [num,f] = *mst.begin();
//                     mst.erase(mst.begin());
//                     res[i]=num;
//                     res[i+1]=num;
//                     f-=2;
//                     if(f && !(f&1)) mst.insert({num,f});
//             }
//         }
        
//     }

//     for(int i=0;i<n;i++){
//         if(res[i]==0 && unq.size()){
//             res[i] = *unq.begin();
//             unq.erase(unq.begin());
//         }
//     }

//     for(auto i:res) cout<<i<<" ";
//     cout<<"\n";
//     if(is_sorted(res.begin(),res.end())) {
//         cout<<"YES\n";
//     }else{
//         cout<<"NO\n";
//     }
//     cout<<"--\n";
// }

void solve(){
        int n;
        cin>>n;
        vector<ll>vec(n);
        for(auto &i:vec) cin>>i;

        sort(vec.begin(),vec.end());

        for(int i=1;i<n-1;i++){
            
            if(i&1 && vec[i]!=vec[i+1]){
                cout<<"NO\n";
                return;
            }
        }

        cout<<"YES\n";


}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}