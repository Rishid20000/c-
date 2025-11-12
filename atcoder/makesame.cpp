#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if(a==b==c){
        cout<<0<<"\n";
    }

    else if(a==b){
            if(a>c){
                cout<<-1<<"\n";
            }else{
                int diff = abs(a-c);
                if(diff%2!=0){
                    cout<<-1<<"\n";
                }else{
                        cout<<diff/2<<"\n";
                }
            }
    }
    else if(b==c) // same
    else if(c==a) // same logi
    else{
        cout<<-1<<"\n";
    }
}