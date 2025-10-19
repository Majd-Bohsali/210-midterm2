// COMSC210 | Midterm 2 | Majd Bohsali
// IDE used: Visual Studio Code     
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime> 
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void insert_after(string value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    string getName(int pos) { 
        if (!head) {
            cout << "List is empty." << endl;
            return "no name";
        }
    
        if (pos < 1) {
            cout << "invalid postion"; 
            return "no name";
        }

        Node* temp = head; 

        for(int i = 1; i < pos; i ++) { 
            if(!temp) { 
                cout << "Position doesn't exist." << endl;
                return "no name"; 
            } else { 
                temp = temp->next; 
            }
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return "no name";
        }
        return temp->data; 

    } 

    void delete_val(string value) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(string v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(string v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));
    ifstream inputFile("names.txt"); // opens file
    string person; 
    DoublyLinkedList* list = new DoublyLinkedList(); 
    cout << "Store Opens: " << endl; 
    if(inputFile.is_open()) { 
        for(int i = 0; i < 20; i++) { // looks through 20 time periods
            if (i == 0) { // handles the first time period
                for(int j = 0; j < 5; j++) { 
                    getline(inputFile, person); 
                    list->push_back(person);
                    cout << "\t" << person << " joins the line" << endl;
                }
                cout << "\tResulting line: ";
                list->print(); 
            } else { // handles every subsequent time period after the first
                cout << "Time Step #" << (i + 1) << ": " << endl; 
                // defines all the propabilities
                int probServed = rand() % 100 + 1; 
                int probJoin = rand() % 100 + 1; 
                int probLeaveEnd = rand() % 100 + 1; 
                int probLeaveAny = rand() % 100 + 1; 
                int probVIP = rand() % 100 + 1; 

                if (probServed <= 40) { // person at front is served
                    
                } else if (probJoin <= 60) {

                } else if (probLeaveEnd <= 20) {
                    
                } else if (probLeaveAny <= 10) {
                    
                } else if (probVIP <= 10) {
                    
                }

            }
        }

        inputFile.close(); 
    } else {
        cout << "File not Found";
    }

    return 0;
}