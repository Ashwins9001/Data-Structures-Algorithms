import java.util.LinkedList;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //create array equal to size of courses, used to track prerequisites per course
        int[] inDegree = new int[numCourses];
        int count = 0;
        //iterate through all rows, 0th col for courses with pre-reqs, inc
        for(int i = 0; i < prerequisites.length; i++)
        {
            inDegree[prerequisites[i][0]]++;
        }
        //create stack used for maintaining order of topological sort
        LinkedList<Integer> stack = new LinkedList<>();
        //iterate through all courses, add ones to stack with no pre-reqs to begin sort
        for(int i = 0; i < inDegree.length; i++)
        {
            if(inDegree[i] == 0)
                stack.push(i);
        }
        //continue top sort until stack hopefully empties 
        while(!stack.isEmpty())
        {
            int curr = stack.pop();
            count++;
            for(int i = 0; i < prerequisites.length; i++)
            {
                //check if popped course is a prerequisite for another
                if(prerequisites[i][1] == curr)
                {
                    //find ith course, sub a prereq from it as it has been met
                    inDegree[prerequisites[i][0]]--;
                    //if no prereqs left, push onto stack then repeat for remaining courses
                    if(inDegree[prerequisites[i][0]] == 0)
                    {
                        stack.push(prerequisites[i][0]);
                    }
                }
            }
        }
        //if count (popped items made to final list) equals numCourses, topsort finished
        //all course prereqs can be met
        return count == numCourses;
    }
}
	