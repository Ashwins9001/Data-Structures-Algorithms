class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if(matrix.length == 0) return ans;
        
        //total matrix size
        int R = matrix.length, C = matrix[0].length;
        
        //iterators and direction arrays for CW movement if needed
        //di defines current direction 
        int r = 0, c = 0, di = 0;
        
        //define matrix to track visited elem
        boolean[][] seen = new boolean[R][C];
        
        //dr defines movement along rows: 
        //dr[1] = inc row, go down 
        //dr[3] = dec row, go up
        //dc[0] = inc col, go right
        //dc[2] = dec col, go left
        int[] dr={0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
                
        //iterate across entire matrix
        for(int i = 0; i < R*C; i++)
        {
            //update list with val at given elem
            ans.add(matrix[r][c]);
            seen[r][c] = true;
            
            //potential next row and col respectively
            //go in dir and check
            int cr = r + dr[di];
            int cc = c + dc[di];
            
            //ensure within bounds and unseen to continue
            //tracking visited elem key as some may be within bounds, but have been visited
            //causes loop and spiral fails
            if(0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc])
            {r = cr; c = cc;} else{
                di = (di + 1) % 4; //ensure di in range of [0,3]
                //set row, cols to inc/dec in dir of clockwise movement
                r += dr[di];
                c += dc[di];
            }
        }
        return ans;
        
    }
}