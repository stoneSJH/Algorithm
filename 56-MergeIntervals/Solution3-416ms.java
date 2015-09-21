import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Solution3 {
    public List<Interval> merge(List<Interval> intervals) {
    	List<Interval> result = new ArrayList<Interval>();
    	if (intervals.size() < 2)
    		return intervals;
    	Collections.sort(intervals, new IntervalComparator());
    	Interval tmp = intervals.get(0);
    	int i = 1;
    	while (i < intervals.size()){
    	    Interval cur = intervals.get(i);
    		if (tmp.end >= cur.start){
    			if (tmp.end < cur.end) 
    				tmp.end = cur.end;
    		}
    		else{
    			result.add(tmp);
    			tmp = cur;
    		}
    		i++;
    	}
    	result.add(tmp);
    	return result;
    }
}