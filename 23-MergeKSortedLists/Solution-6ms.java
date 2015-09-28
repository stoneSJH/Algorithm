package PA23;

public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
    	if (lists.length == 0)
    		return null;
    	ListNode list1, list2;
    	int pos = lists.length - 1;
    	int cur_pos = 0;
    	while (pos > 0){
    		list1 = null;
    		list2 = null;
    		cur_pos = 0;
    		for (int i = 0; i <= pos; i++){
    			if (lists[i] == null)
    				continue;
    			else if (list1 == null)
    				list1 = lists[i];
    			else if (list2 == null)
    				list2 = lists[i];
    			if (list1 != null && list2 != null){
    				lists[cur_pos] = _merge(list1, list2);
    				cur_pos++;
    				list1 = null;
    				list2 = null;
    			}
    		}
    		if (list1 != null && list2 == null){
    			   lists[cur_pos++] = list1;
    		}
    		pos = cur_pos - 1;
    	}
    	return lists[0];
    }
    private ListNode _merge(ListNode list1, ListNode list2){
    	if (list1 == null) return list2;
    	else if (list2 == null) return list1;
    	else{
    		if (list1.val < list2.val){
    			list1.next = _merge(list1.next, list2);
    			return list1;
    		}
    		else{
    			list2.next = _merge(list1, list2.next);
    			return list2;
    		}
    	}
    }
}