package PA164;

public class SolutionByPigoenHole {
    public int maximumGap(int[] nums) {
        if (nums.length < 2)
        	return 0;
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++){
        	if (nums[i] > max){
        		max = nums[i];
        	}
        	if (nums[i] < min){
        		min = nums[i];
        	}
        }
        double dis = (double)(max - min) / (double)(nums.length - 1);
        int[] maxhole = new int[nums.length];
        int[] minhole = new int[nums.length];
        for (int i = 0; i < nums.length; i++){
        	minhole[i] = Integer.MAX_VALUE;
        	maxhole[i] = Integer.MIN_VALUE;
        }
        for (int i = 0; i < nums.length; i++){
        	int index = (int)((nums[i]-min) / dis);
            maxhole[index] = Math.max(maxhole[index],nums[i]);
            minhole[index] = Math.min(minhole[index],nums[i]);
        }
        int result = 0;//must be 0 to deal with all the same such as [1,1,1,1]
        int pmax = maxhole[0];
        for (int i = 1; i < nums.length; i++){
        	if (minhole[i] != Integer.MAX_VALUE){
        		result = Math.max(result, minhole[i] - pmax);
        		pmax = maxhole[i];
        	}
        }
        return result;
    }
}
