#include <iostream>
#include <string>
using namespace std;

int binarySearch(int ids[], string grades[], int size, int id) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Searching range: ids[" << left << "] to ids[" << right << "]\n";
        cout << "Middle index: " << mid << ", Middle ID: " << ids[mid] << endl;

        if (ids[mid] == id) {
            cout << "******************************************\n";
            cout << "Found ID at index " << mid << "\n";
            cout << "******************************************\n";
            return mid;
        } else if (ids[mid] < id) {
            cout << "Searching right half since " << ids[mid] << " < " << id << endl;
            left = mid + 1;
        } else {
            cout << "Searching left half since " << ids[mid] << " > " << id << endl;
            right = mid - 1;
        }
        cout << "------------------------------------------\n";
    }
    cout << "******************************************\n";
    cout << "ID not found in the array.\n";
    cout << "******************************************\n";
    return -1; // Student ID not found
}

int main() {
    int ids[100];
    string grades[100];

    // Generate IDs and grades
    for (int i = 0; i < 100; ++i) {
        ids[i] = 100 + i + 1;
        grades[i] = (i % 5 == 0) ? "A" : (i % 5 == 1) ? "B" : (i % 5 == 2) ? "C" : (i % 5 == 3) ? "D" : "E";
    }

    int size = sizeof(ids) / sizeof(ids[0]);

    cout << "******************************************\n";
    cout << "Available student IDs:\n";
    for (int i = 0; i < size; ++i) {
        cout << ids[i] << ((i != size - 1) ? ", " : "\n");
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }
    cout << "******************************************\n";

    int searchId;
    cout << "Enter the student ID to search: ";
    cin >> searchId;

    cout << "******************************************\n";

    // Perform binary search
    int index = binarySearch(ids, grades, size, searchId);

    if (index != -1) {
        cout << "******************************************\n";
        cout << "Student ID: " << ids[index] << ", Grade: " << grades[index] << endl;
        cout << "******************************************\n";
    } else {
        cout << "******************************************\n";
        cout << "Student ID not found." << endl;
        cout << "******************************************\n";
    }

    return 0;
}
