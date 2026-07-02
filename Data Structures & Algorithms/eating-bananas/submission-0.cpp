class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxpile = 0;
        for(int i = 0; i< n; i++){
            if(piles[i]>maxpile){
                maxpile = piles[i];
            }
        }

        if(n == h){
            return maxpile;
        }

        int low = 1;
        int high = maxpile;

        while(low<=high){
            int mid = high - (high - low)/2;

            int time = 0;
            for(int i = 0; i<n; i++){
                time += ceil((double)piles[i]/mid); //imp
            }

            if(time > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return low;
    }
};