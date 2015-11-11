
public class Solution {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int[] a = new int[nums.length];
        for(int i = 0; i < a.length; i++)
        	a[i] = nums[i];
        for(int i = 1; i < a.length; i++){
        	if (a[i] < a[i-1] + nums[i])
        		a[i] = a[i-1] + nums[i];
        	if (a[i] > result)
        		result = a[i];
        }
        return result;
    }
}