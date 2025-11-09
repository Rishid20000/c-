#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int n = arr.size();

        int sum = accumulate(arr.begin(), arr.end(), 0);

        if ((sum + diff) & 1 || diff > sum)
            return 0;

        int tar = (sum + diff) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= tar; j++)
            {
                int notake = dp[i - 1][j];
                int take = 0;
                if (j - arr[i - 1] >= 0)
                {
                    // dp[i][j] = dp[i][j] || dp[i][j-arr[i-1]];
                    take = dp[i - 1][j - arr[i - 1]];
                }

                dp[i][j] = take + notake;
            }
        }

        for(auto i:dp){
            for(auto j:i) cout<<j<<" ";
            cout<<"\n";
        }

        return dp[n][tar];
    }
};

int main(){
    string s = "0 1 2 2 2 3 0 3 0 1";
    int d = 12;
    stringstream ss(s);
    vector<int>vec;
    string word;
    while(getline(ss,word,' ')){
        vec.push_back(stoi(word));
    }

    Solution obj;

    int ans = obj.countPartitions(vec,d);
}
