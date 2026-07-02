class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxwater = 0;
        int water = 0;
        int i = 0;
        int j = n-1;

        while(i<j){
            water = (j-i)*(min(height[i], height[j]));
            maxwater = max(water, maxwater);
            if(height[i]>height[j]){
                j--;
            }else if(height[i]<height[j]){
                i++;
            }else{
                i++;
            }
        }
        return maxwater;
    }
};