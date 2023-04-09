#include <iostream>
#include <queue>
#include <vector>

class MyClass {
public:
    MyClass(int value) : value(value) {}

    int getValue() const {
        return value;
    }

    bool operator<(const MyClass& other) const {
        return value < other.value;
    }

private:
    int value;
};

int main() {
    std::priority_queue<MyClass, std::vector<MyClass>> pq;

    pq.push(MyClass(5));
    pq.push(MyClass(3));
    pq.push(MyClass(8));
    pq.push(MyClass(2));

    while (!pq.empty()) {
        std::cout << pq.top().getValue() << std::endl;
        pq.pop();
    }

    return 0;
}
