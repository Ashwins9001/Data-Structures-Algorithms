class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length <= 1) //base case
        {
            return intervals;
        }
        
        //Ensure sorted so checking adj vals works 
        //Lambda func: params before arrow and body after
        //Sort arr by type defn by Comparator (lambda func) & first elem
        Arrays.sort(intervals, (arr1, arr2) -> Integer.compare(arr1[0], arr2[0]));
        
        List<int[]> output_arr = new ArrayList(); //unknown arr size post-merge, list used 
        int[] curr_interval = intervals[0]; //instantiate first interval of 2d arr
        
        output_arr.add(curr_interval); //if var added to list changes, so does list-val
        
        for(int[] interval : intervals) //for each arr inside 2d arr, loop
        {
            //Ref single elem of adj intervals
            int current_begin = curr_interval[0];
            int current_end = curr_interval[1];
            int next_begin = interval[0]; //iterator per each elem
            int next_end = interval[1];
            
            //check for overlap & merge
            if(current_end >= next_begin) //sort by current_begin already
            {
                //ref list, direct change second val of interval tuple
                //"add" merged elem by ref it, changing contents 
                //no need to remove adj elem, by bounding check, already contained in list
                //continue this for all elem w continuous overlapping range 
                curr_interval[1] = Math.max(current_end, next_end); 
            }
            
            else 
            {
                //set equal to iterator to update position in ArrayList
                //next iteration will inc interval iterator to adj elem
                //add next elem, no merge 
                curr_interval = interval; //no merge, ref curr elem & add
                output_arr.add(curr_interval);
            }
        }
        
        //defn rows dep on num elem after merge
        return output_arr.toArray(new int[output_arr.size()][]); 
    }
}