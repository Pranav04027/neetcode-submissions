class Solution {
public:
    void recursion(int n , vector<string>& ans, string& temp, int opencount, int closecount){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }

        if(opencount == closecount){
            temp += '(';
            recursion(n,ans, temp, opencount + 1, closecount);

            temp.pop_back();
        }

        if(opencount > closecount && opencount < n){
            temp += '(';
            recursion(n,ans, temp, opencount + 1, closecount);

            temp.pop_back();
            
            temp += ')';
            recursion(n,ans, temp, opencount, closecount +1);
            temp.pop_back();

        }

        if(opencount > closecount && opencount == n){
            temp += ')';
            recursion(n,ans, temp, opencount, closecount +1);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        recursion(n, ans, temp, 0 , 0);

        return ans;
    }
};