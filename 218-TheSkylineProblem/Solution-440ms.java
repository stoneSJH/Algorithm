import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        return getSkyline(buildings, 0, buildings.length-1);
    }
    private List<int[]> getSkyline(int[][] buildings, int low, int high){
        List<int[]> result = new ArrayList<>();
        if(low > high)
        	return result;
        if(low == high){
            result.add(new int[]{buildings[low][0], buildings[low][2]});
            result.add(new int[]{buildings[low][1], 0});
            return result;
        }
        int mid = (low + high) / 2;
        List<int[]> left = getSkyline(buildings, low, mid);
        List<int[]> right = getSkyline(buildings, mid+1, high);
        int leftMax = 0,
        		rightMax = 0,
        		max = 0;
        for(int i = 0, j = 0; i < left.size() || j < right.size(); ){
            int currentMax = 0;
            if(i < left.size() && j < right.size() &&
            		left.get(i)[0] == right.get(j)[0]){
                leftMax = left.get(i)[1];
                rightMax = right.get(j)[1];
                currentMax = Math.max(leftMax, rightMax);
                if(currentMax != max){
                    result.add(new int[]{left.get(i)[0], currentMax});
                    max = currentMax;
                }
                i++;
                j++;
            }
            else if(j >= right.size() || i < left.size() &&
            		j < right.size() && left.get(i)[0] < right.get(j)[0]){
                leftMax = left.get(i)[1];
                currentMax = Math.max(leftMax, rightMax);
                if(currentMax != max){
                    result.add(new int[]{left.get(i)[0], currentMax});
                    max = currentMax;
                }
                i++;
            }
            else if(i >= left.size() || i < left.size() &&
            		j < right.size() && left.get(i)[0] > right.get(j)[0]){
                rightMax = right.get(j)[1];
                currentMax = Math.max(leftMax, rightMax);
                if(currentMax != max){
                    result.add(new int[]{right.get(j)[0], currentMax});
                    max = currentMax;
                }
                j++;
            }
        }
        return result;
    }
}