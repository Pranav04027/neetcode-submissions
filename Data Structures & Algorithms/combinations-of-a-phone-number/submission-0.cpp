class Solution {
public:

    void dfs(string& digits, vector<string>& mp, string& current, vector<string>& ans, int index){
        if(current.length() == digits.length()){
            ans.push_back(current);
            return;
        }

        if(index >= digits.size()){
            return;
        }

        string s = mp[digits[index] - '0'];

        for(int i = 0; i<s.size(); i++){
            current += s[i];
            dfs(digits, mp, current, ans, index + 1);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string current = "";

        dfs(digits, mp, current, ans, 0);

        return ans;
        
    }
};