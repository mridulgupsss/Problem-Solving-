class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq= new PriorityQueue<>();
        int i=0;
        while(i <nums.length)
        {
           if(i<k)
           {
               pq.add(nums[i]);
               
           }
            else
            {
                if(nums[i]>pq.peek())
                {
                    pq.remove();
                    pq.add(nums[i]);
                }
            }
            i++;
        }
        return pq.peek();
    }
}