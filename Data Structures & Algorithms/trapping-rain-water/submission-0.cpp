class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int maxi = 0;
        int maxm = 0;
        for(int i = 0; i<n; i++){
            if(height[i]>maxm){
                maxi = i;
                maxm = height[i];
            }
        }

        //from left
        int i = 0;
        int leftmax = 0;
        int leftwater = 0;
        while(i<maxi){
            int currwater = leftmax - height[i];
            if(currwater > 0){
                leftwater += currwater;
            }
            leftmax = max(leftmax, height[i]);
            i++;
        }

        //from right
        int j = n-1;
        int rightmax = 0;
        int rightwater = 0;
        while(j>maxi){
            int currwater = rightmax - height[j];
            if(currwater > 0){
                rightwater += currwater;
            }
            rightmax = max(rightmax, height[j]);
            j--;
        }

        return leftwater + rightwater;
    }
};