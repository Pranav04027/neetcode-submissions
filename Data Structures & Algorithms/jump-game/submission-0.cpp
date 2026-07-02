class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> targets;
        if(nums.size() == 1){
            return true;
        }

        if(nums.size() == 2 && nums[0]>0){
            return true;
        }

        int target = nums.size() - 1;

        int i = nums.size() - 2;
        while(i>=0){
            if(nums[i]>=(target - i)){
                target = i;
            }
            i--;
        }

        if(target == 0){
            return true;
        }else{
            return false;
        }
    }
};