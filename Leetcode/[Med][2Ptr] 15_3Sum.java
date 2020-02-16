class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //Instantiate adt as linked list
        List<List<Integer>> results = new LinkedList<>();
        
        Arrays.sort(nums);
        
        //Sort and have three pointers, first one will be represented by for loop
        //Last two: start, end are enclosed in while loop
        //Point is to create a subset and search for an inverse pair from arr[i]
        for(int i = 0; i < nums.length - 3; i++)
        {
            if(i == 0 || nums[i] > nums[i-1]) {
                int start = i+1;
                int end = nums.length - 1;
                
                //Ensure pointers don't cross, else func fails
                while(start < end)
                {
                    //If sum == 0, add to list
                    if(nums[i] + nums[start] + nums[end] == 0) {
                        List<Integer> elem = new ArrayList<>();
                        elem.add(nums[i]);
                        elem.add(nums[start]);
                        elem.add(nums[end]);
                        results.add(elem);
                    }
                    //If sum < 0, must increase it, go right given sorted order to attempt
                    if(nums[i] + nums[start] + nums[end] < 0) {
                        int currentStart = start;
                        //Ensure no duplicates by inc if exist
                        while(nums[start] == nums[currentStart] && start < end)
                        {
                            //Inc init, if duplicate exists, loop continues
                            start++;
                        }
                    }
                    //Do opposite if sum > 0, dec from greatest elem in attempt to reduce it
                    else {
                        int currentEnd = end;
                        while(nums[currentEnd] == nums[end] && start < end)
                        {
                            end--;
                        }
                    }                    
                }
            }
        }
        return results;
    }
}