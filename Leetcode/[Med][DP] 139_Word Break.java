class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] isWordBreak = new boolean[s.length() + 1];//add 1, substr last ind exclusive
        isWordBreak[0] = true;
        for(int i = 0; i < s.length() + 1; i++) //must be able to break word into two smaller
        { //req only one word upto j, then another from (j,i) to be substr of s
            for(int j = 0; j < i; j++)
            {
                if(!isWordBreak[j])
                {
                    continue; //only check jth instance if i has set that index-char true
                }
                //check if wordBreak is false, continue on next sub-prob
                if(wordDict.contains(s.substring(j, i))) {
                    isWordBreak[i] = true; //each true is a substr of dict word
                    break;
                }
            }
        }
        return isWordBreak[s.length()]; //if end on true, all substr of s contained in dict
    } //else some random seq leftover, meaning s cant be broken down into seq dict words
} //no memoization used, thus O(N^2)
// if memoization used, may not need to iterate entire seq of found dict words 
//essentially for every length i, check all sub-problems from j = 0 to j = i for substr soln