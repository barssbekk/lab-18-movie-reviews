#include <iostream>

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
void addFront(Node*& head, Review& value);
void printNode(Node* head);
void addTail(Node*& head, Review& value);

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

    Node* head{nullptr};
    Review review = askReviewRating();
    addFront(head, review);

    printNode(head);

    // Node* head{nullptr};
    // addFront(head, 51);
    // addTail(head, 20);
    // printNode(head);

    return 0;
}

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
void addFront(Node*& head, Review& value) {
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

void printNode(Node* head) {
    Node* current{head};
    while (current) {
        cout << current->value.c << '\n';
        current = current->next;
    }
}