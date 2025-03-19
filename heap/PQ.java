package heap;

class MinHeap {
    int sz;
    int[] heap;
    int capacity;

    MinHeap(int capacity) {
        this.capacity = capacity;
        this.sz = 0;
        this.heap = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    boolean empty() { return sz == 0; }
    boolean full() { return sz == capacity; }
    int size() { return sz; }

    void insert(int x) {
        if(sz == capacity) throw new IllegalStateException("Heap is full");

        heap[sz] = x;
        int i = sz;
        sz++;

        while(i > 0 && heap[i] < heap[parent(i)]) {
            int tmp = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = tmp;
            i = parent(i);
        }
    }
    
    int pop() {
        if(sz == 0) throw new IllegalStateException("Heap is empty");
        int min = heap[0];
        heap[0] = heap[sz-1];
        sz--;

        heapify(0);
        return min;
    }

    void heapify(int i) {
        int j = i;
        int leftI = left(i);
        int rightI = right(i);

        if(leftI < sz && heap[leftI] < heap[j]) j = leftI;
        if(rightI < sz && heap[rightI] < heap[j]) j = rightI;

        if(i == j) return;
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
        heapify(j);
    }

    int top() {
        if(sz == 0) throw new IllegalStateException("Heap is empty");
        return heap[0];
    }

    void println() {
        for(int i = 0; i < sz; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}

public class PQ {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        MinHeap pq = new MinHeap(10);
        pq.insert(10);
        pq.insert(9);
        pq.insert(8);
        pq.insert(7);
        pq.insert(6);
        pq.insert(5);
        pq.println();
        System.out.println("top: " + pq.top());
        System.out.println("size: " + pq.size());

        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
        System.out.println(pq.pop());
        pq.println();
    }
}