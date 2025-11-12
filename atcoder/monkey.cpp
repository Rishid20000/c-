#include<bits/stdc++.h>
using namespace std;
bool caneat(int x,int ban,int pea,int totban,int totp,int n){
            int banana = totban/ban;
            int peanut = x-banana;
            // cout<<banana<<" "<<peanut<<" "<<x<<"\n ";
            return banana*ban<=totban && peanut*pea<=totp;
}


int main(){
    int n,k,j,m,p;
    cin>>n>>k>>j>>m>>p;
    int low = 0, high = n;
    int ans=0;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(caneat(mid,k,j,m,p,n)){
            low = mid+1;
            ans = mid;
        }else{
            high =mid-1;
        }
    }
    cout<<ans<<"\n";
}