#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

struct Review {
    double rating{};
    string comment{};
};

struct Node {
    Review value{};
    Node* next{};
};

Review askReviewRating();
void addFront(Node*& head, const Review& value);
void printNode(Node* head);
void addTail(Node*& head, const Review& value);
double calcAvg(Node* head);
void deleteList(Node*& head);

int main() {
    cout << "Which linked list method should we use?\n"
         << "\t[1] New nodes are added at the head of the linked list\n"
         << "\t[2] New nodes are added at the tail of the linked list\n"
         << "Choice: ";
    int userChoice{};
    cin >> userChoice;
    while (userChoice < 1 || userChoice > 2) {
        cerr << "Wrong input! Choose 1 or 2. Try again: ";
        cin >> userChoice;
    }
    Node* head{nullptr};

    char yesNoChoice{'y'};
    do {
        Review review = askReviewRating();
        if (userChoice == 1)
            addFront(head, review);
        else
            addTail(head, review);
        cout << "Enter another review? Y/N: ";
        cin >> yesNoChoice;
        yesNoChoice = static_cast<char>(tolower(yesNoChoice)); // int to char
    } while (yesNoChoice == 'y');

    printNode(head);
    deleteList(head);
    return 0;
}

// asks the user for a review rating and comment
// returns: Review struct with rating and comment
Review askReviewRating() {
    Review userInput{};
    cout << "Enter review rating 0-5: ";
    cin >> userInput.rating;
    cin.ignore();
    cout << "Enter review comments: ";
    getline(cin, userInput.comment);
    return userInput;
}

// Adds node at the head
// arguments: head pointer, review value to add
void addFront(Node*& head, const Review& value) {
    Node* newNode{new Node};
    if (!head) {
        head = newNode;
        newNode->value = value;
        newNode->next = nullptr;
    } else {
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }
}

// Adds node at the tail
// arguments: head pointer, review value to add
void addTail(Node*& head, const Review& value) {
    Node* newNode{new Node};
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// calcs the avg rating of all reviews in the list
// returns: avg rating as a double
double calcAvg(Node* head) {
    double sum{};
    int count{0};

    const Node* current = head;
    while (current) {
        sum += current->value.rating;
        current = current->next;
        ++count;
    }
    if (count == 0) return 0;
    return sum / count; // Return avg
}

// outputs all nodes
void printNode(Node* head) {
    Node* current{head};
    int count{1};
    const double avg = calcAvg(head);
    cout << "Outputting all reviews:\n";
    while (current) {
        cout << "\t > Review #" << count << ": "
                                << current->value.rating << ": "
                                << current->value.comment << '\n';
        current = current->next;
        ++count;
    }
    cout << fixed << setprecision(2)
         << "\t > Average rating: " << avg << '\n';
}

// deletes all nodes in the list and frees memory
// arguments: head pointer to the list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
