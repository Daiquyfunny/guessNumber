#include <iostream>
#include <random>
#include <chrono>
#include "../include/userinput.h"

using std::cout, std::string;
int main() {
    std::mt19937 mt{static_cast<std::mt19937::result_type>(
                            std::chrono::steady_clock::now().time_since_epoch().count()
                    )};
    int init = userinputI("\nInitial number: ");
    int end = userinputI("\nEnd number: ");

    std::uniform_int_distribution range{init, end};
    int randX = range(mt);
    cout << "Guess the number is between " << init << " to " << end;
    int guess = userinputI("\n\nguess the number: ");
    if (guess == randX) {
        cout << "Correct";
    } else {
        cout << "You dumbo. It's: " << randX;
    }

    return 0;
}
