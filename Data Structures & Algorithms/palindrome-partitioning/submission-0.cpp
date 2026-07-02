class Solution {
public:
    bool isPallindrome(string& currstr){
        if(currstr.size() == 1){
            return true;
        }

        int i = 0;
        int j = currstr.size()-1;

        while(i<j){
            if(currstr[i] != currstr[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

   void dfs(string s, vector<vector<string>>& ans, int index, vector<string>& temp){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 1; i<= s.size()-index; i++){
            string substring = s.substr(index, i);
            if(isPallindrome(substring)){
                temp.push_back(substring);
                dfs(s, ans, index + i, temp);
                temp.pop_back();
            }
        }

   }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string currstr = "";
        vector<string> temp;

        dfs(s, ans, 0, temp);

        return ans;
    }
};