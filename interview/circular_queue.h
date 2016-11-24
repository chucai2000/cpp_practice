#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "CommonDataStructure.h"

namespace CIRCULAR_QUEUE{

class CircularQueue
{
public:
    CircularQueue(int capacity): mData(nullptr), mStart(0), mEnd(0), mCapacity(capacity) {
        if (mData) {
            delete[] mData;
        }
        mData = new int[capacity];
    }

    ~CircularQueue() {
        if (mData) {
            delete [] mData;
            mData = nullptr;
        }
    }

    int getSize() {
        if (mStart > mEnd) {
            return mEnd + mCapacity - mStart;
        }
        else {
            return mEnd - mStart;
        }
    }

    bool isEmpty() {
        return (mStart == mEnd);
    }

    bool isFull() {
        return (getSize() == mCapacity - 1);
    }

    void push(int val) {
        if (isFull()) {
            throw std::runtime_error("This queue has been full.");
        }
        mData[mEnd] = val;
        mEnd = (mEnd+1) % mCapacity;
    }

    int front() {
        return mData[mStart];
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("This queue has been empty.");
        }
        mStart = (mStart+1) % mCapacity;
    }

    void printOut() {
        std::cout << "mData: " << "mStart = " << mStart << " mEnd = " << mEnd << std::endl;
        for (int i = mStart; i != mEnd; i=(i+1)%mCapacity) {
            std::cout << mData[i] << " ";
        }
        std::cout << std::endl;
    }



    int binarySearch(int val) {
        int low = mStart;
        int high = mEnd;

        if (low > high) {
            while (low > high) {
                int mid = ((low+high+mCapacity) / 2) % mCapacity;
                if (mData[mid] == val)
                    return mid;
                if (mData[mid] < val)
                    low = (mid+1) % mCapacity;
                if (mData[mid] > val)
                    high = mid-1<0 ? mCapacity-1 : mid-1;
            }
        }

        return regularBS(val, low, high);
    }

private:

    int regularBS(int val, int low, int high) {
        if (low > high) {
            throw std::runtime_error("not proper for regular binary search");
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (mData[mid] == val)
                return mid;
            if (mData[mid] < val)
                low = mid + 1;
            if (mData[mid] > val)
                high = mid - 1;
        }

        return -1;
    }

    int *mData;
    int mStart;
    int mEnd;
    int mCapacity;
};

void run() {
    CircularQueue queue(9);
    queue.push(0);
    queue.push(2);
    queue.push(4);
    queue.push(6);
    queue.push(8);
    queue.push(10);
    queue.push(12);
    queue.push(14);

    int val;
    val = queue.front();
    queue.pop();
    val = queue.front();
    queue.pop();
    val = queue.front();
    queue.pop();

    queue.push(21);
    queue.push(23);
    queue.push(25);

    queue.printOut();

    for (int n = 5; n <= 26; n++) {
        std::cout << "Find " << n << " at " << queue.binarySearch(n) << std::endl;
    }

    int ep = 0;
}

}
#endif
