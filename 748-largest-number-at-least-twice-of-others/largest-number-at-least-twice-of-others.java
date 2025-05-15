class Solution {
    public int dominantIndex(int[] nums) {
        
        int largest = Integer.MIN_VALUE;
        int index = 0;
        for(int i = 0; i < nums.length; i++){
            if(largest < nums[i]) {
            largest = nums[i];
                 index = i;
            }
            }
            for(int i = 0; i < nums.length; i++){
                if(nums[i] == largest) continue;
                if(nums[i] * 2 > largest)  return -1;
            }

            return index;

    }
}