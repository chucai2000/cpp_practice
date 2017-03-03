#include "common.h"

namespace circular_queue{

class circular_queue
{
public:
    circular_queue(int capacity): m_data(nullptr), m_start(0), m_end(0), m_capacity(capacity) {
        if (m_data) {
            delete[] m_data;
        }
        m_data = new int[capacity];
    }

    ~circular_queue() {
        if (m_data) {
            delete [] m_data;
            m_data = nullptr;
        }
    }

    int get_size() {
        if (m_start > m_end) {
            return m_end + m_capacity - m_start;
        }
        else {
            return m_end - m_start;
        }
    }

    bool is_empty() {
        return (m_start == m_end);
    }

    bool is_full() {
        return (get_size() == m_capacity - 1);
    }

    void push(int val) {
        if (is_full()) {
            throw std::runtime_error("This queue has been full.");
        }
        m_data[m_end] = val;
        m_end = (m_end+1) % m_capacity;
    }

    int front() {
        return m_data[m_start];
    }

    void pop() {
        if (is_empty()) {
            throw std::runtime_error("This queue has been empty.");
        }
        m_start = (m_start+1) % m_capacity;
    }

    void print_out() {
        std::cout << "m_data: " << "m_start = " << m_start << " m_end = " << m_end << std::endl;
        for (int i = m_start; i != m_end; i=(i+1)%m_capacity) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }



    int binary_search(int val) {
        int low = m_start;
        int high = m_end;

        if (low > high) {
            while (low > high) {
                int mid = ((low+high+m_capacity) / 2) % m_capacity;
                if (m_data[mid] == val)
                    return mid;
                if (m_data[mid] < val)
                    low = (mid+1) % m_capacity;
                if (m_data[mid] > val)
                    high = mid-1<0 ? m_capacity-1 : mid-1;
            }
        }

        return regular_bs(val, low, high);
    }

private:

    int regular_bs(int val, int low, int high) {
        if (low > high) {
            throw std::runtime_error("not proper for regular binary search");
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (m_data[mid] == val)
                return mid;
            if (m_data[mid] < val)
                low = mid + 1;
            if (m_data[mid] > val)
                high = mid - 1;
        }

        return -1;
    }

    int *m_data;
    int m_start;
    int m_end;
    int m_capacity;
};

}

