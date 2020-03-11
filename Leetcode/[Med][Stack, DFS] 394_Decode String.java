class Solution {
    public void sortColors(int[] nums) {
        //In-place sorting, no addl space requirements (such as quicksort)
        //Idea: shift all zeros to left, all twos to right & ones fall in place between
        if(nums.length == 0 || nums.length == 1)
        {
            return;
        }
        int start = 0; //add zero here
        int end = nums.length - 1; //add two here 
        int index = 0; //goto curr num
        while(index <= end && start < end) { //ensure index & start in bounds
            if(nums[index] == 0) //inc start on cond, sits at index where zero goes 
            {
                nums[index] = nums[start]; //curr elem equal to first elems arr
                nums[start] = 0; //swap, but we know zero found, can hardcode it in
                start++; //inc start ptr to adj
                index++; //inc index 
            }
            else if(nums[index] == 2) //dec end on cond, sits on index where two goes
            {
                //don't inc index, check after swap if zero replaces it then rerun
                nums[index] = nums[end];
                nums[end] = 2; //two found, hardcode in swap
                end--;
            }
            else //if 1, shift index fwd 
            {
                index++; 
            }
        }
        
    }
}