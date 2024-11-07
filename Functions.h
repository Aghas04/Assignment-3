#include <iostream>
#include <vector>
#include <list>
using namespace std;


int menu() {
    int choice;
    cout << "welcome to Assignment 3" << endl;
    cout << "enter the number for the desired question to exicute" << endl;
    cout << "enter 0 to exit" << endl;
    cout << "Question 1" << endl;
    cout << "Question 2" << endl;
    cout << "Question 3" << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}

int recursiveLinearSearch(const vector<int>& vec, int target, int index) {
    
    if (index < 0) {
        return -1;
    }

    // Recursive step: check if the current element matches the target
    if (vec[index] == target) {
        return index; // Return the current index if a match is found
    }

    // Recursive call: move to the previous index
    return recursiveLinearSearch(vec, target, index - 1);
}



void insertion_sort(list<int> &num) 
{
    //sort from the second item
    auto iterator = ++num.begin();
    while (iterator != num.end()) {
        int current_value = *iterator;


        //find the correct position
        auto sorted_it = iterator;
        auto insertion_position = num.begin();

        //go from begging to end
        while (insertion_position != sorted_it && *insertion_position <= current_value) {
            insertion_position++;
        }
        //move to correct position
        if (insertion_position != iterator) {
            num.insert(insertion_position, current_value);
            iterator = num.erase(iterator);
        }
        else {
            ++iterator;
        }
    }
}