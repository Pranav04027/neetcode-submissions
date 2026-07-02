class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> arrs(26,0);
        vector<int> arrt(26,0);
    

        for(auto x:s){
            arrs[x-'a'] += 1;
        }
        for(auto x:t){
            arrt[x-'a'] += 1;
        }

        if(arrs == arrt){
            return true;
        }

        return false;
    }
};