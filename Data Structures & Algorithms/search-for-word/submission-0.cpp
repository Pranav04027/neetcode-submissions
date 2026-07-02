class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c, vector<vector<bool>>& visited){
        if(index == word.size()){
            return true;
        }

        //Bounds check
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()){
            return false;
        }

        if(visited[r][c]){
            return false;
        }

        // check word miss match
        if(word[index] != board[r][c]){
            return false;
        }

        visited[r][c] = true;

        bool ans =  dfs(board, word, index + 1, r+1, c, visited)||
                    dfs(board, word, index + 1, r, c+1, visited)||
                    dfs(board, word, index + 1, r-1, c, visited)||
                    dfs(board, word, index + 1, r, c-1, visited);

        visited[r][c] = false;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        bool ans = false;
        int index = 0;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i< board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                ans = ans || dfs(board, word, 0, i, j, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};