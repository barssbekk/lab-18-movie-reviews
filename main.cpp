#include <iostream>

using namespace std;

void askReviewRating();
int main() {
    cout << "Which linked list method should we use?'\n"
         << "\t[1] New nodes are added at the head of the linked list\n"
         << "\t[2] New nodes are added at the tail of the linked list\n"
         << "Choice: ";
    double userChoice{};
    cin >> userChoice;
    while (userChoice < 1 || userChoice > 2) {
        cerr << "Wrong input! Choose 1 or 2. Try again: ";
        cin >> userChoice;
    }

    askReviewRating();

    return 0;
}

void askReviewRating() {
    double userInput{};
    cout << "Enter review rating 0-5: ";
    cin >> userInput;
    cin.ignore();
    cout << "Enter review comments: ";
    string userComments{};
    getline(cin, userComments);
}