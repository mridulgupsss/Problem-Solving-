class Solution {
    public int fourSumCount(int[] arr1, int[] arr2, int[] arr3, int[] arr4) {
        HashMap<Integer, Integer> map=new HashMap<>();
        int count=0;
        for(int e1: arr1){
            for(int e2: arr2)
            {
                int sum=e1+e2;
                map.put(sum, map.getOrDefault(sum, 0)+1);
            }
        }
            int target=0;
        for(int e3: arr3){
            for(int e4: arr4)
            {
                int sum=e3+e4;
                count+=map.getOrDefault(target-sum, 0);
            }
        }
            return count;
    }
}