class Solution {
public:

    // f(i) = number of ways to decode the substring starting from index i to the end.

    int rec(string s, int n, int i, vector<int> & dp){
        if(i == n){
            return 1;
        }

        int left = 0;

        if(dp[i] != -1){
            return dp[i];
        }

        if(s[i] != '0'){
            left = rec(s, n, i+1, dp);
        }

        int right = 0;

        if(i+1<n){
          int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
          if(num >=10 && num <=26){
            right = rec(s, n, i+2, dp);
        }
        }

        return dp [i] = left + right;

    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        dp[n] = 1;
        return rec(s,n,0, dp);
    }
};
