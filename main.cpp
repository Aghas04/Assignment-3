#include <iostream>

#include "Queue.h"
#include "Functions.h"

using namespace std;

int main() {
    int choice;
    while (true) {
        
        choice = menu();
        if (choice == 0) {
            break;
        } 
        else if (choice == 1) {
            cout << "Question 1" << endl;
            Queue<int> q;
            // Push 10 integer values into the queue
            for (int i = 1; i <= 10; ++i) {
                q.push(i);
            }
            //cout << q.front() << endl;
            cout << "Queue: " << endl;
            // Display all elements using queue functions
            while (!q.empty()) {
                cout << q.front() << " ";
                q.pop();
            }
            cout << endl;

            // Refill the queue for testing `move_to_rear()`
            for (int i = 1; i <= 10; ++i) {
                q.push(i);
            }

            // Move the front element to the rear
            q.move_to_rear();

            // Display the queue again after `move_to_rear()`
            cout << "Queue after moving front to rear:" << endl;
            while (!q.empty()) {
                cout << q.front() << " ";
                q.pop();
            }
            cout << endl;
        } 
        else if (choice == 2) {
            cout << "Question 2" << endl;
            vector<int> data = {1, 2, 3, 4, 3, 5, 3, 6};
            int target = 3;

            cout << "Data" << endl;
            for (int i = 0; i < data.size(); i++) {
                cout << data[i] << " ";
            }
            cout << endl;
            cout << "Desired index: " << target << endl;
            int lastOccurrenceIndex = recursiveLinearSearch(data, target, data.size() - 1);

            if (lastOccurrenceIndex != -1) {
                cout << "Last occurrence of " << target << " found at index " << lastOccurrenceIndex << endl;
            } else {
                cout << "Target not found in the vector." << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Question 3" << endl;
            list<int> numbers = {5,3,8,1,7};

            cout << "origional list: ";
            for (int num : numbers) {
                cout << num << " ";
            }
            cout << endl;
            //sort
            insertion_sort(numbers);
            cout << "sorted list: ";
            for (int num : numbers) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    

    
    
    
    

    
    
    return 0;
}