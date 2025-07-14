#include <iostream>
using namespace std;

class Tracker {
private:
    int PersonId;
    int step_count;
    int stair_count;
    static int object_count; // Static member to track the number of objects

public:
    // Parameterized constructor with default arguments
    Tracker(int id, int steps = 0, int stairs = 0) : PersonId(id), step_count(steps), stair_count(stairs) {
        object_count++;
    }

    // Destructor to decrement the object count
    ~Tracker() {
        object_count--;
    }

    // Member function to increment counts
    void incrementCount(int n);

    // Function to display the counts
    void displayCount() {
        cout << "PersonId: " << PersonId << ", Step Count: " << step_count << endl;
    }

    // Static function to get the object count
    static int getObjectCount() {
        return object_count;
    }

    // Friend function to convert stair_count to step_count
    friend void convertStep(Tracker &t);
};

// Initialize static member
int Tracker::object_count = 0;

// Definition of incrementCount outside the class
void Tracker::incrementCount(int n) {
    step_count += n;
    stair_count += n;
}

// Non-member function to convert stair_count to step_count
void convertStep(Tracker &t) {
    t.step_count += t.stair_count * 2;
    t.stair_count = 0; // Reset stair_count after conversion
}

int main() {
    // Array of Tracker objects
    Tracker trackers[] = { Tracker(1), Tracker(2, 80, 50), Tracker(3, 90, 100) };

    // Increment counts for each tracker
    for (int i = 0; i < 3; ++i) {
        trackers[i].incrementCount(0);
        convertStep(trackers[i]);
        trackers[i].displayCount();
    }

    // // Convert stair_count to step_count for each tracker
    // for (int i = 0; i < 3; ++i) {
    //     convertStep(trackers[i]);
    // }

    // // Display counts for each tracker
    // for (int i = 0; i < 3; ++i) {
    //     trackers[i].displayCount();
    // }

    // Display the number of Tracker objects created
    cout << "Total Tracker objects created: " << Tracker::getObjectCount() << endl;

    return 0;
}
