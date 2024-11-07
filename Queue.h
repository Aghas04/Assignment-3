#include <iostream>
using namespace std;


template <typename T>
class Queue {
private:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue
    int count;        // Number of elements in the queue

public:
    // Constructor
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    // Destructor to free allocated memory
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    // Function to push an element into the queue
    void push(T value);

    // Function to remove the front element from the queue
    void pop();

    // Function to get the front element of the queue
    T front();

    // Function to get the current size of the queue
    int size();

    // Function to check if the queue is empty
    bool empty();

    // Function to move the front element to the rear of the queue
    void move_to_rear();

    //print the queue
    void display();
};

// Function implementations

template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = newNode;
        rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty. Cannot pop." << std::endl;
    } else {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;
    }
}

template <typename T>
T Queue<T>::front() {
    if (empty()) {
        cout << "Queue is empty. No front element." << std::endl;
        return frontNode->data;
    }
    else {
        return frontNode->data;
    }
}

template <typename T>
int Queue<T>::size() {
    return count;
}

template <typename T>
bool Queue<T>::empty() {
    return count == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty()) {
        cout << "Queue is empty. Cannot move to rear." << endl;
    } else {
        push(front());
        pop();
    }
}

template <typename T>
void Queue<T>::display() {

    int n = size(); // Store the initial size of the queue

    for (int i = 0; i < n; ++i) {
        T frontItem = front(); // Get the front item
        cout << frontItem << " "; // Print the item
        pop(); // Remove the front item from the queue
        push(frontItem); // Add it back to the rear of the queue
    }
    cout << endl;
    }