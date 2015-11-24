public class Solution {
    public int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int[] ugly = new int[n];
        for (int i = 1; i < n; i++)
        	ugly[i] = 0;
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int pos = 1;
        while (pos < n){
        	int v2 = ugly[p2] * 2;
        	int v3 = ugly[p3] * 3;
        	int v5 = ugly[p5] * 5;
        	if (v2 <= v3 && v2 <= v5){
        	    if (ugly[pos-1] != v2){
        	        ugly[pos] = v2;
        	        pos++;
        	    } 
        		p2++;
        	}
        	else if (v3 <= v2 && v3 <= v5){
        		if (ugly[pos-1] != v3){
        		    ugly[pos] = v3;
        		    pos++;
        		} 
        		p3++;
        	}
        	else if (v5 <= v2 && v5 <= v2){
        	    if (ugly[pos-1] != v5){
        	        ugly[pos] = v5;
        	        pos++;
        	    }
        		p5++;
        	}
        }
        return ugly[n-1];
    }
}