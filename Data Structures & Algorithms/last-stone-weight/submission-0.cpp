class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // initial heap
        priority_queue<int> heap;
        int size = stones.size();
        for(int i = 0; i<stones.size(); i++){
            heap.push(stones[i]);
        }

        while(heap.size() > 1){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if (x>y){
                heap.push(x-y);
            }else if(y>x){
                heap.push(y-x);
            }
        }
        if(heap.size()){
            return heap.top();
        }else{
            return 0;
        }
    }
};