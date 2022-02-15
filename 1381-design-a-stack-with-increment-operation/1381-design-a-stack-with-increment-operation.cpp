class CustomStack {
public:
    int *arr;
    int size;
    int i=0;
    CustomStack(int maxSize) {
        size=maxSize;
        arr= new int[maxSize];
    }
    
    void push(int x) {
        if(i<size){
            arr[i++]=x;
        }
    }
    
    int pop() {
        if(i==0){
            return -1;
        }
        else{
            return arr[--i];
        }
    }
    
    void increment(int k, int val) {
        int j=0;
        while(j<=k-1 && j<i){
            arr[j++]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */