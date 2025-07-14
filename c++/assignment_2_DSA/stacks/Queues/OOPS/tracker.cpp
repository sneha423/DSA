#include <iostream>
using namespace std;

class Tracker {
    private:
        int PersonId;
        int step_count;
        int stair_count;
        static int objectCount;

    public:
        // Parameterized constructor with default arguments
        Tracker(int id, int steps = 0, int stairs = 0) : PersonId(id), step_count(steps), stair_count(stairs) {
            objectCount++;
        }

        // Function to increment counts
        void incrementCount(int n);

        // Function to display count
        void displayCount() const;

        // Static function to get the number of objects
        static int getObjectCount() {
            return objectCount;
        }

        // Friend function to convert stair_count to step_count
        friend void convertStep(Tracker &t);
};

// Define the static member
int Tracker::objectCount = 0;

// Definition of incrementCount outside the class
void Tracker::incrementCount(int n) {
    step_count += n;
    stair_count += n;
}

// Definition of displayCount outside the class
void Tracker::displayCount() const {
    cout << "Person ID: " << PersonId << endl;
    cout << "Steps Count: " << step_count << endl;
}

// Non-member function to convert stair_count to step_count
void convertStep(Tracker &t) {
    t.step_count += t.stair_count * 2;
    t.stair_count = 0;
}

int main() {
    int size;
    cout << "Enter the number of users: ";
    cin >> size;

    Tracker** trackers = new Tracker*[size];

    // Input data for each user
    for (int i = 0; i < size; ++i) {
        int id, steps = 0, stairs = 0;
        cout << "Enter details for user " << i + 1 << ": " << endl;
        cout << "ID: ";
        cin >> id;
        cout << "step count: ";
        cin>>steps;
        cout << "stair count: ";
        cin>>stairs;
        trackers[i] = new Tracker(id, steps, stairs);
    }

    // Increment data for each user
    for (int i = 0; i < size; ++i) {
        int n;
        cout << "Increment steps and stairs for user " << i + 1 << " by: ";
        cin >> n;
        trackers[i]->incrementCount(n);
    }

    // Convert stair_count to step_count and display data
    for (int i = 0; i < size; ++i) {
        convertStep(*trackers[i]);
        trackers[i]->displayCount();
    }

    // Display the number of objects created
    cout << "Total Tracker objects created: " << Tracker::getObjectCount() << endl;

    // Deallocate memory
    for (int i = 0; i < size; ++i) {
        delete trackers[i];
    }
    delete[] trackers;

    return 0;
}


