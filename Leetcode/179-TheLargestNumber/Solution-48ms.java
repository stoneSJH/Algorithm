package PA179;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
    public String largestNumber(int[] nums) {
    	List<String> numbers = new ArrayList<String>();
    	int zeros = 0;
        for (int i = 0; i < nums.length; i++){
        	if (nums[i] == 0) zeros++;
        	numbers.add(String.valueOf(nums[i]));
        }
        if (zeros == nums.length) return "0";
        Collections.sort(numbers, new NewStringComparator());
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < numbers.size(); i++)
        	result.append(numbers.get(i));
        return result.toString();     
    }
}