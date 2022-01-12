#include <iostream>
#include <cstdlib>
using namespace std;
 
// Xác định số phần tử mặc định của hàng đợi (queue)
#define SIZE 1000
 
// Một lớp để lưu trữ hàng đợi
class Queue {
    int *arr;       // mảng để lưu trữ các phần tử của hàng đợi
    int capacity;   // sức chứa tối đa của hàng đợi
    int front;      // điểm đến phần tử phía trước trong hàng đợi 
    int rear;       // điểm phía sau đến phần tử cuối cùng trong hàng đợi
    int count;      // kích cỡ hiện tại của hàng đợi
 
public:
    Queue(int size = SIZE);     // hàm khởi tạo
    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
 
// hàm để khởi tạo một hàm đợi
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
} 
// Xóa phần tử phía trước trong hàng đợi
int Queue::dequeue() {
    // check for queue underflow
    if (isEmpty()) {
        cout << "Underflow\n";
        exit(EXIT_FAILURE);
    }
 
    int x = arr[front];
    cout << "Removing " << x << endl;
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Thêm một phần tử vào cuối hàng đợi
void Queue::enqueue(int item) {
    // kiểm tra hàng đợi đã đầy hay chưa
    if (isFull()) {
        cout << "Overflow\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Trả về phần tử phía trước của hàng đợi
int Queue::peek() {
    if (isEmpty()) {
        cout << "Program Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Hàm trả về kích cỡ hàng đợi
int Queue::size() {
    return count;
}
 
// Hàm kiểm tra hàng đợi có trống hay không
bool Queue::isEmpty() {
    return (size() == 0);
}
 
// Hàm kiểm tra hàng đợi có đầy hay không
bool Queue::isFull() {
    return (size() == capacity);
}
 
int main() {
    // tạo một hàm đợi với kích cỡ bằng 5
    Queue q(5);
 
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << "Front in linkedlist : " << q.peek() << endl;
    q.dequeue();
 
    q.enqueue(4);
 
    cout << "Queue size : " << q.size() << endl;
 
    q.dequeue();
    q.dequeue();
    q.dequeue();
 
    if (q.isEmpty()) {
        cout << "Empty Queue\n";
    }
    else {
        cout << "The quêue is not empty\n";
    }
 
    return 0;
}
