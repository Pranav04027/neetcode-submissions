class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;

        for(auto it : wordList){
            st.insert(it);
        }

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        st.erase(beginWord);

        while(!q.empty()){

            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == endWord){
                return dist;
            }


            for(int i = 0; i < curr.size(); i++){

                string temp = curr;

                for(int j = 0; j < 26; j++){

                    temp[i] = 'a' + j;

                    if(st.find(temp) != st.end()){

                        q.push({temp, dist + 1});

                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};