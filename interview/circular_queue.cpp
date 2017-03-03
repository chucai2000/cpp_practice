#include "circular_queue.h"

TEST(circular_queue, execution)
{
    circular_queue::circular_queue queue(9);
    queue.push(0);
    queue.push(2);
    queue.push(4);
    queue.push(6);
    queue.push(8);
    queue.push(10);
    queue.push(12);
    queue.push(14);

    int val = queue.front();
    std::cout << "val = " << val << std::endl;
    queue.pop();
    val = queue.front();
    std::cout << "val = " << val << std::endl;
    queue.pop();
    val = queue.front();
    std::cout << "val = " << val << std::endl;
    queue.pop();

    queue.push(21);
    queue.push(23);
    queue.push(25);

    queue.print_out();

    for (int n = 5; n <= 26; n++) {
        std::cout << "Find " << n << " at " << queue.binary_search(n) << std::endl;
    }
}

