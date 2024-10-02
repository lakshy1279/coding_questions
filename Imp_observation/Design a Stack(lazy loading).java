// Design a stack that supports increment operations on its elements.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.


class CustomStack {
    private int [] stack;
    private int currIndex;
    // for lazy loading only incr the value when pop
    private int incr[];
    private int size;
    public CustomStack(int maxSize) {
        stack = new int[maxSize];
        incr = new int[maxSize];
        currIndex = 0;
        size = maxSize;
    }
    
    public void push(int x) {
        if(currIndex >= size)
        return;
        stack[currIndex++] = x;
    }
    
    public int pop() {
        if(currIndex <= 0)
        return -1;
        currIndex--;
        int value = stack[currIndex] + incr[currIndex];
        if(currIndex > 0)
        {
            incr[currIndex - 1] += incr[currIndex];
        }
        incr[currIndex] = 0;
        return value;
    }
    
    public void increment(int k, int val) {
        int index = Math.min(k, currIndex);
        if(index == 0)
        return;
        incr[index - 1] += val;
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */