class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char ,int> mp;
        int n = s.size();
        int l = 0;
        int maxf = 0;
        int ans = 0;

        for(int i = 0; i< n; i++){
            mp[s[i]]++;
            maxf = max(maxf, mp[s[i]]);

            while(i-l+1 - maxf > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, i-l+1);
        }

        return ans;
        
    }
};