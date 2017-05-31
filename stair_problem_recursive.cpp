// Situation: someone can take at most 3 steps up a stairway.
// Problem: How many unique ways can this person go up an n-step stairway.

// Define: x = any positive integer including zero.

// Run with:
//     ./StairProblemBruteForce x

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int count(int n) {
    if (n < 1) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 4;
    }

    return count(n-1) + count(n-2) + count(n-3);
}

void count_steps(int n) {
    int start = clock();
    int traversals = count(n);
    int stop = clock();

    cout << n << " steps: " << traversals << " unique ways. Time: "
         << (stop - start)/double(CLOCKS_PER_SEC)*1000 << "ms." << endl;
}

int main(int argc, char **argv) {
    string temp = argv[argc-1];
    int n_steps = 0;

    if (argc == 2) {
        temp = argv[argc-1];
        n_steps = atoi(temp.c_str());
        count_steps(n_steps);
    }
    else {
        cout << "Error" << endl;
    }

    return 0;
}
