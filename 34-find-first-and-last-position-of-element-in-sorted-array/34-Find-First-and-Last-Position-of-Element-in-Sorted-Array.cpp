class Solution {

    private:
    
    int findBound(const vector<int>& nums, int target, bool findFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; // Save the index
                if (findFirst) {
                    right = mid - 1; // Continue searching left
                } else {
                    left = mid + 1;  // Continue searching right
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bound;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // int l=0,r=nums.size()-1;
        // vector<int> ans(2,-1);
        // while(l<r){
        //     if(target==nums[l]&&target==nums[r]){
        //         ans[0]=l;
        //         ans[1]=r;
        //         return ans;
        //     }
        //     else if(target!=nums[l]&&target==nums[r]){
        //         l++;
        //     }
        //     else r--;
        // }
        // return ans;

        int start = findBound(nums, target, true);
        if (start == -1) return {-1, -1}; // Optimization: if not found, end is also not found
        
        int end = findBound(nums, target, false);
        return {start, end};
    }


    
};