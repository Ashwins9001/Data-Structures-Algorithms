package arrayLists;

import java.util.HashMap;
import java.util.Map;

public class arrayListClass {
	public static int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int count = 0;
        //iterate through all elements of array using for-each
        for(int i : nums)
        {
        	//array elems are keys, repeated keys get incremented by 1 each
        	//comes in handy when checking for difference of zero (k = 0)
        	map.put(i, map.getOrDefault(i, 0) + 1);
        }
        //iterate through entire map (all its key-val tuples)
        for(Map.Entry<Integer, Integer> entry : map.entrySet())
        {
        	if(k == 0)
        	{
        		//account for multiple unique, repeating keys, such as in {1,1,3,3,3,4,5,6}
        		if(entry.getValue() >= 2) 
        		{count++;}
        	}
        	else
        	{
        		//check if current key added with k-diff amt equals another key from set
        		//accounts for unique values as sum prevents order reversal
        		//for tuple k = 2, tuple = (1, 3), cannot count (3, 1) as 3 + k = 5, won't increment
        		if(map.containsKey(entry.getKey() + k)) {count++;}
        	}
        }
        return count;
    }
	public static void main(String[] args) {

		int[] nums = new int[]{1,2,3,4,5};
		int k = 1;
		int pairs = 0;
	
		pairs = findPairs(nums, k);
		System.out.println(pairs);
	}

}