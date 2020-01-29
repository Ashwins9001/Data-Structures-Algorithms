package arrayLists;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class arrayListClass {
	public static boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        //iterate through all elements of array using for-each
        for(int i : arr)
        {
        	//array elems are keys, repeated keys get incremented by 1 each
        	//store occurrences per key as a value 
        	map.put(i, map.getOrDefault(i, 0) + 1);
        }
        //check if size of map (number of tuples) equivalent to set's size
        //of occurrences, if all are unique should be no discrepancy
        //as key-val pairs and vals should be equal in number
        return map.size() == new HashSet<>(map.values()).size();
    }
	public static void main(String[] args) {

		int[] arr = new int[]{1, 2, 2, 3, 3, 3};
		int[] arr2 = new int[] {1, 2};
		boolean isTrue = false;
		
		isTrue = uniqueOccurrences(arr);
		System.out.println(isTrue);
		isTrue = uniqueOccurrences(arr2);
		System.out.println(isTrue);
	}

}