
#include <iostream>
using namespace std;


void evaluateGrade(int score){

    if (score < 10) {
        cout << "Fail" << endl;
    }
    else if (score < 14) {
        cout << "Pass" << endl;
    }
    else {
        cout << "Excellent" << endl;
    }
}

enum class State {
    Idle, Processing, Success, Error
};

void evaluateState(State state) {
    switch (state) {
        case State::Idle:
            cout << "idle state" << endl;
            break;

        case State::Processing:
            cout << "processing state" << endl;
            break;

        case State::Success:
            cout << "successful state" << endl;
            break;

        case State::Error:
            cout << "error" << endl;
            break;
    }
}

int main() {

    // Test evaluateGrade()
    evaluateGrade(7);
    evaluateGrade(12);
    evaluateGrade(16);

    cout << endl;

    // Test every State
    evaluateState(State::Idle);
    evaluateState(State::Processing);
    evaluateState(State::Success);
    evaluateState(State::Error);

    return 0;
}
