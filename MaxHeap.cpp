#include <bits/stdc++.h>

using namespace std;
class MaxHeap {
private:
   vector < int > heap;
    int _size;
public:
    void make_heap(vector < int > & nums, int s) {
        heap.assign(nums.begin(), nums.end());
        _size = s;
        for(int i = _size / 2 - 1; i >= 0; i--) {
            down(i);
        }
    }
    void push(int num) {
        heap.push_back(num);
        up(_size++);
    }
    int size() {
        return _size;
    }
    int top() {
        assert(_size > 0);
        return heap[0];
    }
    int pop() {
        assert(_size > 0);
        int result = heap[0];
        heap[0] = heap[_size];
        heap.pop_back();
        --_size;
        down(0);
        return result;
    }
    void down(int index) {
        assert(index >= 0);
        int tmp = index;
        index = index << 1 | 1;
        if(index >= _size) return;
        if(index + 1 < _size && heap[index] < heap[index + 1]) ++index;
        if(heap[index] < heap[tmp]) return;
        else {
            swap(heap[index], heap[tmp]);
            down(index);
        }
    }
    void up(int index) {
        assert(index < _size);
        if(index == 0) return;
        int tmp = index;
        index = (index - 1) >> 1;
        if(heap[tmp] < heap[index]) return;
        else {
            swap(heap[index], heap[tmp]);
            up(index);
        }
    }
};
int main(){
    vector < int > test = {1, 2, 5, 4, 9};
    MaxHeap maxHeap;
    maxHeap.make_heap(test, 5);
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;
    maxHeap.push(99);
    cout << maxHeap.top() << endl;
    return 0;
}
