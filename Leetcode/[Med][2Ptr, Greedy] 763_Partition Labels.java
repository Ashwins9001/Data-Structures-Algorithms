package arrayLists;

import java.util.List;
import java.util.ArrayList;

//assume wherever last time a char appears, substring has ended and a new begins
//two cannot contain same letter and must be large thus condition works
public class arrayListClass {
	public static List<Integer> partitionLabels(String s)
	{
		List<Integer> partitionLengths = new ArrayList<Integer>();
		//array indexed by alphabetic pos of letters, at each one is 
		//string pos (s) of char's appearance, "size" or "end" point
		int[] lastIndices = new int[26];
		for(int i = 0; i < s.length(); i++)
		{
			//subtract 'a' to keep ASCII referencing relative to 0
			//at index=0->a, index=1->b, index=2->c,...
			lastIndices[s.charAt(i) - 'a'] = i;
		}
		int i = 0;
		//want to make sure end is correct (another letter may lengthen substring)
		while(i < s.length())
		{
			//reference letters of string iteratively, check array for endpoints
			int end = lastIndices[s.charAt(i) - 'a'];
			//check other letters using j
			int j = i+1;
			while(j != end) //continue until j reaches ending pos
			{
				//scan string iteratively, taking maxes
				end = Math.max(end, lastIndices[s.charAt(j++) - 'a']);
			}
			//add current substring and move onto the next
			partitionLengths.add(j - i + 1);
			i = j + 1;
		}
		return partitionLengths;
	}
	public static void main(String[] args) {
		String test = "ababcbacadefegdehijhklij";
		List<Integer> actualParts = partitionLabels(test);
		System.out.println(actualParts);
	}

}