#include <iostream>

using namespace std;

struct Node {
    double value{};
    Node* next{};
};

struct Review {
    double rating{};
    string comment{};
};

Review askReviewRating();
void addFront(Node*& head, double value);
void printNode(Node* head);
void addTail(Node*& head, double value);

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






    // Node* head{nullptr};
    // addFront(head, 51);
    // addTail(head, 20);
    // printNode(head);

    return 0;
}

Review askReviewRating() {
    double userInput{};
    cout << "Enter review rating 0-5: ";
    cin >> userInput;
    cin.ignore();
    cout << "Enter review comments: ";
    string userComments{};
    getline(cin, userComments);
}

// Adds node at the head
void addFront(Node*& head, const double value) {
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
void addTail(Node*& head, const double value) {
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
        cout << current->value << '\n';
        current = current->next;
    }
}