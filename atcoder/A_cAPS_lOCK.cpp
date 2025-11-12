#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    
    bool ok=1;
    for(int i=1;i<n;i++) ok&=isupper(s[i]);

    if(ok){
        for(auto &i:s)i^=32;
        cout<<s<<"\n";
    }else{
        cout<<s<<"\n";
    }


}