class Solution {
public:
    int compareVersion(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int i=0,j=0;
        
        while(i < n1 or j < n2){
            int val1 = 0, val2 = 0;
            
			// creating first value
            while(i < n1 and str1[i] != '.'){
                int temp = str1[i] - '0';
                val1 *= 10; val1 += temp;
                i++;
            }
            
			// creating 2nd value
            while(j < n2 and str2[j] != '.'){
                int temp = str2[j] - '0';
                val2 *= 10; val2 += temp;
                j++;
            }
            
            if(val1 > val2) return 1;
            if(val1 < val2) return -1;
            
			// don't worry about i pointer to cross n1 it doesn't matter so chill
            i++; j++;
        }
        
        return 0;
    }
};