class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        
        for(auto &x: s){
            if(x>=65 && x<=90){
                clean.push_back(x+32);
            }
            if((x>=97 && x<=122) || (x>=48 && x<=57)){
                clean.push_back(x);
            }
        }

        int i = 0;
        int j = clean.size()-1;

        while(i<j){
            if(clean[i] != clean[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;

    }
};