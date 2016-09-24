package PA164;

public class SolutionByRADIX {
    public int maximumGap(int[] nums) {
        if (nums.length < 2)
        	return 0;
        int max = nums[0];
        for (int i = 1; i < nums.length; i++){
        	if (nums[i] > max)
        		max = nums[i];
        }
        int exp = 1;
        int[] radix = new int[nums.length];
        while (max / exp > 0){
        	int[] tmp = new int[10];
        	for (int i = 0; i < nums.length; i++) {
                tmp[(nums[i] / exp) % 10]++;
            }

            for (int i = 1; i < 10; i++) {
                tmp[i] += tmp[i - 1];
            }

            for (int i = nums.length - 1; i >= 0; i--) {
                radix[--tmp[(nums[i] / exp) % 10]] = nums[i];
            }

            for (int i = 0; i < nums.length; i++) {
                nums[i] = radix[i];
            }
            exp *= 10;
        }
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < radix.length - 1; i++){
        	result = Math.max(result, radix[i + 1] - radix[i]);
        }
        return result;
    }
}