class Solution {
public:

    string encode(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }

        string s = "";

        for(int i = 0; i<strs.size(); i++){
            int strsize = strs[i].size();
            s += to_string(strsize);
            s += '#';
            s += strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        if(!s.length()){
            return {};
        }

        int n = s.size();
        vector<string> ans;

        int i = 0;

        while(i<n){
            int sizei = 0;
            string sizes = "";
            while(s[i] != '#'){
                sizes += s[i];
                i++;
            }
            sizei = stoi(sizes);
            string temp = "";
            for(int j = i + 1; j< i + sizei + 1; j++){
                temp += s[j];
            }
            ans.push_back(temp);
            i = i + sizei + 1;
        }

        return ans;
    }
};
