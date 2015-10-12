package PA4;

public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int mid = (nums1.length + nums2.length)/2;
        int low = 0;
        int high = Math.min(nums1.length, mid);
        while (true){
        	int lo = low + (high - low)/2;
        	int hi = mid - lo;
        	if (newGet(nums1, lo) >= newGet(nums2, hi-1)){
        		if (newGet(nums2, hi) >= newGet(nums1, lo-1)){
        			if ((nums1.length+nums2.length) % 2 == 1){
        				double ret = Math.min(newGet(nums1, lo), newGet(nums2, hi));
        				return ret;
        			}
        			else{
        				double right = Math.min(newGet(nums1, lo), newGet(nums2, hi));
        				double left = Math.max(newGet(nums1, lo-1), newGet(nums2, hi-1));
        				double ret = (right + left)/2;
        				return ret;
        			}
        		}
        		else high = lo - 1;
        	}
        	else low = lo + 1;
        }
    }
    private int newGet(int[] nums, int pos){
    	if (pos < 0) return 0x80000000;
    	if (pos >= nums.length) return 0x7fffffff;
    	return nums[pos];
    }
}