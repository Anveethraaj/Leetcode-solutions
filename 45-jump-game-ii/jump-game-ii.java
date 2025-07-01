class Solution {
    public int jump(int[] nums) {
        int far = 0,current = 0,jump = 0;
        for(int i=0;i<nums.length - 1; ++i){
            far = Math.max(far, i + nums[i]);
            if(i == current){
                jump++;
                current = far;
            }

        }
        return jump;
    }
}