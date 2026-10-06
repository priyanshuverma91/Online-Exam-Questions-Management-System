
#include <iostream>
#include <string>
using namespace std;

struct Question {
    int id;
    string question;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;
    string difficulty;
    Question* next;
};

Question* head = NULL;

// Add a new question
void addQuestion() {
    Question* newQuestion = new Question();

    cout << "\nEnter Question ID: ";
    cin >> newQuestion->id;
    cin.ignore();

    cout << "Enter Question: ";
    getline(cin, newQuestion->question);

    cout << "Enter Option A: ";
    getline(cin, newQuestion->optionA);

    cout << "Enter Option B: ";
    getline(cin, newQuestion->optionB);

    cout << "Enter Option C: ";
    getline(cin, newQuestion->optionC);

    cout << "Enter Option D: ";
    getline(cin, newQuestion->optionD);

    cout << "Enter Correct Answer (A/B/C/D): ";
    cin >> newQuestion->correctAnswer;

    cout << "Enter Difficulty (Easy/Medium/Hard): ";
    cin >> newQuestion->difficulty;

    newQuestion->next = NULL;

    if (head == NULL) {
        head = newQuestion;
    } else {
        Question* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newQuestion;
    }

    cout << "\nQuestion added successfully!\n";
}

// Display all questions
void displayQuestions() {
    if (head == NULL) {
        cout << "\nNo questions available.\n";
        return;
    }

    Question* temp = head;

    cout << "\n========== ALL QUESTIONS ==========\n";

    while (temp != NULL) {
        cout << "\nQuestion ID: " << temp->id;
        cout << "\nQuestion: " << temp->question;
        cout << "\nA. " << temp->optionA;
        cout << "\nB. " << temp->optionB;
        cout << "\nC. " << temp->optionC;
        cout << "\nD. " << temp->optionD;
        cout << "\nCorrect Answer: " << temp->correctAnswer;
        cout << "\nDifficulty: " << temp->difficulty;
        cout << "\n-----------------------------------";

        temp = temp->next;
    }
}

// Search question by ID
void searchQuestion() {
    if (head == NULL) {
        cout << "\nNo questions available.\n";
        return;
    }

    int id;
    cout << "\nEnter Question ID to search: ";
    cin >> id;

    Question* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\nQuestion Found!\n";
            cout << "Question ID: " << temp->id;
            cout << "\nQuestion: " << temp->question;
            cout << "\nA. " << temp->optionA;
            cout << "\nB. " << temp->optionB;
            cout << "\nC. " << temp->optionC;
            cout << "\nD. " << temp->optionD;
            cout << "\nCorrect Answer: " << temp->correctAnswer;
            cout << "\nDifficulty: " << temp->difficulty << "\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nQuestion not found.\n";
}

// Delete question
void deleteQuestion() {
    if (head == NULL) {
        cout << "\nNo questions available.\n";
        return;
    }

    int id;
    cout << "\nEnter Question ID to delete: ";
    cin >> id;

    Question* temp = head;
    Question* previous = NULL;

    while (temp != NULL && temp->id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nQuestion not found.\n";
        return;
    }

    if (previous == NULL) {
        head = temp->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nQuestion deleted successfully!\n";
}

// Update question
void updateQuestion() {
    if (head == NULL) {
        cout << "\nNo questions available.\n";
        return;
    }

    int id;
    cout << "\nEnter Question ID to update: ";
    cin >> id;
    cin.ignore();

    Question* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {

            cout << "Enter New Question: ";
            getline(cin, temp->question);

            cout << "Enter New Option A: ";
            getline(cin, temp->optionA);

            cout << "Enter New Option B: ";
            getline(cin, temp->optionB);

            cout << "Enter New Option C: ";
            getline(cin, temp->optionC);

            cout << "Enter New Option D: ";
            getline(cin, temp->optionD);

            cout << "Enter New Correct Answer (A/B/C/D): ";
            cin >> temp->correctAnswer;

            cout << "Enter New Difficulty: ";
            cin >> temp->difficulty;

            cout << "\nQuestion updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nQuestion not found.\n";
}

// Sort questions by ID
void sortQuestions() {
    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough questions to sort.\n";
        return;
    }

    Question* current;
    Question* index;

    for (current = head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {

            if (current->id > index->id) {
                swap(current->id, index->id);
                swap(current->question, index->question);
                swap(current->optionA, index->optionA);
                swap(current->optionB, index->optionB);
                swap(current->optionC, index->optionC);
                swap(current->optionD, index->optionD);
                swap(current->correctAnswer, index->correctAnswer);
                swap(current->difficulty, index->difficulty);
            }
        }
    }

    cout << "\nQuestions sorted successfully!\n";
}

// Main function
int main() {

    int choice;

    do {
        cout << "\n\n========================================";
        cout << "\n   ONLINE EXAM QUESTIONS MANAGEMENT";
        cout << "\n========================================";
        cout << "\n1. Add Question";
        cout << "\n2. Display All Questions";
        cout << "\n3. Search Question";
        cout << "\n4. Update Question";
        cout << "\n5. Delete Question";
        cout << "\n6. Sort Questions";
        cout << "\n7. Exit";
        cout << "\n========================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addQuestion();
                break;

            case 2:
                displayQuestions();
                break;

            case 3:
                searchQuestion();
                break;

            case 4:
                updateQuestion();
                break;

            case 5:
                deleteQuestion();
                break;

            case 6:
                sortQuestions();
                break;

            case 7:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
