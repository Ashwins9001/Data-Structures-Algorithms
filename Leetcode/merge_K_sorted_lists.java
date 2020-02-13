package arrayLists;

import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;

//assume wherever last time a char appears, substring has ended and a new begins
//two cannot contain same letter and must be large thus condition works
public class arrayListClass {
	public List<Integer> mergeSortedArrays(List<List<Integer>> sortedArrays) {
		//Create list of iterators, one per each list, therefore k iterators
	    List<Iterator<Integer>> iters = new ArrayList<>(sortedArrays.size());

	   //Add iterator to beginning of each list 
	    for (List<Integer> array : sortedArrays) {
	      iters.add(array.iterator());
	    }

	    //Implement priority queue, edit comparator interface to ensure it acts as minHeap
	    //Inline defn of anonymous class, and override as defn exists in parent 
	    Queue<ArrayEntry> minHeap = new PriorityQueue<>(
	      ((int) sortedArrays.size()), new Comparator<ArrayEntry>() {
	        @Override
	        public int compare(ArrayEntry o1 , ArrayEntry o2) {
	          return Integer.compare(o1.value , o2.value);
	        }
	      });

	    //Add first item from each list to minHeap
	    //For merging two sorted lists, we would use pointers
	    //Given there are k-sorted lists, it's simpler to implement a heap 
	    for (int i = 0; i < iters.size(); i++) {
	      if (iters.get(i).hasNext()) {
	        minHeap.add(new ArrayEntry(iters.get(i).next(), i));
	      }
	    }

	    List<Integer> result = new ArrayList<>();
	    while(!minHeap.isEmpty()){

	      //Get minimum item by polling
	      ArrayEntry ejectedMinItem = minHeap.poll();

	      //Add that to final merged list, require only its value
	      result.add(ejectedMinItem.value);

	      //If ejectedItem has a following element, add that to minHeap and let it automatically sort it
	      //Ensure arrayId is passed in as well, to keep track of index position in that list 
	      //On every check, arrayId will be incremented and item added 
	      if(iters.get(ejectedMinItem.arrayId).hasNext()){
	        minHeap.add(new ArrayEntry(iters.get(ejectedMinItem.arrayId).next(), ejectedMinItem.arrayId));
	      }

	    }

	    return result; // result now holds all k sorted arrays merged into one sorted array
	  }

	//defn private class to contain annotations for arrayId and values 
	  private class ArrayEntry {
	    public Integer value;
	    public Integer arrayId;

	    public ArrayEntry(Integer value, Integer arrayId) {
	      this.value = value;
	      this.arrayId = arrayId;
	    }
	  }
}