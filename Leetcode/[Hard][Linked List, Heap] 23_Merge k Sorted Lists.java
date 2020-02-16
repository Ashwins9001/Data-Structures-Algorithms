package arrayLists;

public class arrayListClass {
	/**
	 * Definition for singly-linked list.
	 * public class ListNode {
	 *     int val;
	 *     ListNode next;
	 *     ListNode(int x) { val = x; }
	 * }
	 */
	class Solution {
	    public ListNode mergeKLists(ListNode[] lists) {
	        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
	        //Passed in an array of ListNode items 
	        //Take head element of each ListNode, add to minHeap
	        //Again extending to K items heap > ptrs for tracking 
	        //Populating entire minHeap with all items, then simply polling in order
	        //Results in larger tree structure, longer runtime of nlog(n)
	        //ALL n items are added, and restructuring tree can take log(n) per item
	        //If iterators are used, can reduce runtime to nlog(k), as depth reduced to one item from each array, works more like MergeSort
	        for(ListNode head: lists)
	        {
	            //Add val to minHeap, iterate through remaining list items
	            //On following for loop iteration, next list in array is searched
	            while(head != null)
	            {
	                minHeap.add(head.val);
	                head = head.next;
	            }
	        }
	        //Dummy is a linked list created in heap
	        ListNode dummy = new ListNode(-1);
	        //Point result to dummy, which is a single ListNode in stack
	        ListNode result = dummy;
	        while(!minHeap.isEmpty())
	        {
	            //Add minimum val from heap to final linked list
	            result.next =  new ListNode(minHeap.remove());
	            //Iterate to following elem and continue 
	            result = result.next;
	        }
	        //Next as we skip initial value, return linked list, returning 
	        //result only equals final ListNode item
	        return dummy.next;
	    }
	}
}