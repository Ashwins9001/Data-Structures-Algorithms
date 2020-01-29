package arrayLists;

import java.util.List;
import java.util.ArrayList;

public class arrayListClass {
	//for a list of size n, there will be n levels in state space tree 
	//no constraints therefore all solns covered
	//for n params, n! possible solns
	
	public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        backtrack(list, new ArrayList<>(), nums);
        return list;
    }
	public static void backtrack(List<List<Integer>> allPermutations, 
			List<Integer> templist, int[] nums)
	{
		//create separate instance of templist so upon data changes it is unaffected
		//check that list size equals that of org set, if so order found, add to it collection
		if(templist.size() == nums.length)
			allPermutations.add(new ArrayList<>(templist));
		else
		{
			for(int i = 0; i < nums.length; i++)
			{
				//move onto following iteration for backtracking
				//upon recursion break, and reversal, for loop continues 
				//onto next unique order
				if(templist.contains(nums[i])) continue;
				templist.add(nums[i]);
				backtrack(allPermutations, templist, nums);
				
				//after break condition, remove last remaining element
				//continue iterations of for loop from where they left off
				//allows for a diff order
				templist.remove(templist.size() - 1);
			}
			
		}
	}
	public static void main(String[] args) {
		int[] nums = {1, 2,3 };
		List<List<Integer>> outPermutations = permute(nums);
		System.out.println(outPermutations);
	}

}