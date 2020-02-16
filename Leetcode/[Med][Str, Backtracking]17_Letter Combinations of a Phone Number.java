package arrayLists;

import java.util.List;
import java.util.ArrayList;

public class arrayListClass {
	//pass in phone number digits given as input, each one corresponding to sequence of letters
	public static List<String> letterPermutations(String digits) {
		//blank list to store permutations
        List<String> result = new ArrayList<String>();
        //if null string, return it 
        if(digits == null || digits.length() == 0)
        {
        	return result;
        }
        
        //array of strings for letter-to-number mapping
        //0, 1 are unused, set them to invalids (nums)
        String[] mappings = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        //start off nullstr at zero-index
        backtrack(result, digits, "", 0, mappings);
        //final callback, end and return list 
        return result;
    }
	
	//pass in current list of perms (result),
	//digits to be decoded
	//current sequence
	//mapping for letters
	//map one letter per num at a time as branch down tree, then backtrack at final, try another seq, repeat
	
	public static void backtrack(List<String> result, String digits, String current, int index, String[] mapping)
	{
		//stop recursion at correct combination (length)
		//on every break condition, recursion goes back and continues for loop for index it left off at 
		if(index == digits.length())
		{
			result.add(current);
			return;
		}
		//get current num, index references possible set of letters at a given num
		//charAt returns current character (3), convert to int by sub '0'
		//subtract out ascii encodings to get true decimal value 
		String letters = mapping[digits.charAt(index) - '0'];
		for(int i = 0; i < letters.length(); i++)
		{
			//pass in current seq, plus letter added 
			backtrack(result, digits, current + letters.charAt(i), index + 1, mapping);
		}
	}
	public static void main(String[] args) {
		String nums = "23";
		List<String> numDigits = letterPermutations(nums);
		System.out.println(numDigits);
	}

}