int speedup = []{ios::sync_with_stdio(0); cin.tie(0);  return(0);}();

class MedianFinder {
public:
    priority_queue<int> bottomHalf; // max heap
    priority_queue<int, vector<int>, greater<int>> topHalf; // min heap
    MedianFinder() {
    }
    
    void addNum(int num) {
        bottomHalf.push(num);
        topHalf.push(bottomHalf.top());
        bottomHalf.pop();
        if(topHalf.size() > bottomHalf.size()) { // Maintain bottom half to have the higher size, alternatively, could be top half.
            bottomHalf.push(topHalf.top());
            topHalf.pop();
        }
        
    }
    
    double findMedian() {
        if(bottomHalf.size() > topHalf.size()) return bottomHalf.top();
        else return (bottomHalf.top() + topHalf.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
