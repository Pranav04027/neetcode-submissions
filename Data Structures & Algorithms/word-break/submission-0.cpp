class Solution {
public:

    bool rec(string& s, unordered_set<string> & st, int i, int n, vector<int> &  dp){
        if(i == n){
            return true;
        }

        string currword = "";

        if(dp[i] != -1){
            if(dp[i] == 1){
                return true;
            }else{
                return false;
            }
        }

        for(int j = i; j<n;j++){
            currword += s[j];

            if(st.count(currword) && rec(s, st, j+1, n, dp)){
                dp[i] = 1;
                return true;
            }
        }

        dp[i] = 0;

        return false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();

        vector<int> dp(n,-1);

        for(string it : wordDict){
            st.insert(it);
        }

        return rec(s, st, 0, n, dp);
    }
};