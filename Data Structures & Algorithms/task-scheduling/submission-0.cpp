class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // freq, time
        queue<pair<int,int>> q;
        priority_queue<int> heap;
        map<char, int> mp;

        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        for(auto& [sym, count] : mp){
            heap.push(count);
        }

        int time = 0;

        while(q.size() || heap.size()){
            while(!q.empty() && q.front().second == time){
                heap.push(q.front().first);
                q.pop();
            }

            if(heap.size()){
                int temp = heap.top();
                heap.pop();

                temp--; 
                if(temp > 0){
                q.push({temp, time + n + 1});
                }
            }

            time++;
        }

        return time;
    }
};