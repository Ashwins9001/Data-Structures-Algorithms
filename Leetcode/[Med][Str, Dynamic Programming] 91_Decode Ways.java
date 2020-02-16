class Solution {
    //init recursion
    public int numDecodings(String s) 
    {
      //create arr to store possible combinations at str index
      //filled reverse-order due to recursion
      int[] dp = new int[s.length()];
      Arrays.fill(dp, -1);
      return numDecodings(s, 0, dp);
    } 
    public int numDecodings(String s, int decodePointer, int[] dp)
    {
        //init running total after pointer out of range
        //break-condition for recursion initially
        if(decodePointer >= s.length())
            return 1;
        //if soln to substring exists, return it
        //break condition for following calls
        //apply memoization to reduce runtime to O(n)
        if(dp[decodePointer] > -1)
            return dp[decodePointer];
        int totalDecomp = 0;
        //only eval 0-26, thus keep i in range of two digits
        //second iteration only continues if two-digit number b/w 0-26
        for(int i = 1; i <= 2; i++)
        {
            if(decodePointer + i <= s.length())
            {
                //take substring (upto two digits)
                String sub = s.substring(decodePointer, decodePointer + i);
                //check range and value, then recursively call
                if(isValid(sub))
                    totalDecomp += numDecodings(s, decodePointer + i, dp);
            }
        }
        //update num possibilities for digit at index decodePointer 
        dp[decodePointer] = totalDecomp;
        return dp[decodePointer];
    }
    public boolean isValid(String s) 
    {
        if(s.length() == 0 || s.charAt(0) == '0')
            return false;
        int value = Integer.parseInt(s);
        return value >= 1 && value <= 26;
    }
}