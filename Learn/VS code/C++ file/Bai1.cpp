#include <iostream>
#include <limits>

using namespace std;

struct Model {
    long mComputer;
    int bQuantity;
    int sQuantity;
    float bPrice;
    float sPrice;
    double profit;
};

struct Node {
    Model data;
    Node* next;
};

Node* initializeList() {
    return nullptr;
}

void addModel(Node* &head, Model model) {
    Node* newNode = new Node;
    newNode->data = model;
    newNode->next = head;
    head = newNode;
}

void removeModel(Node* &head, long mComputer) {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr) {
        if (current->data.mComputer == mComputer) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

double calculateTotalProfit(Node *head) {
    double totalProfit = 0.0;
    Node *current = head;
    while (current != nullptr) {
        totalProfit += current->data.profit;
        current = current->next;
    }
    return totalProfit;
}

double getProfitById(Node *head, long mComputer) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data.mComputer == mComputer) {
            return current->data.profit;
        }
        current = current->next;
    }
    return numeric_limits<double>::quiet_NaN(); 
}

void displayHighestProfitModels(Node *head) {
    double maxProfit = numeric_limits<double>::min();
    Node *current = head;
    while (current != nullptr) {
        if (current->data.profit > maxProfit) {
            maxProfit = current->data.profit;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        if (current->data.profit == maxProfit) {
            cout << "Model: " << current->data.mComputer << endl;
            cout << "Quantity Bought: " << current->data.bQuantity << endl;
            cout << "Quantity Sold: " << current->data.sQuantity << endl;
            cout << "Buying Price: " << current->data.bPrice << endl;
            cout << "Selling Price: " << current->data.sPrice << endl;
            cout << "Profit: " << current->data.profit << endl << endl;
        }
        current = current->next;
    }
}

void freeList(Node *head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = initializeList();

    int numModels;
    cout << "Enter the number of models: ";
    cin >> numModels;

    for (int i = 0; i < numModels; ++i) {
        Model newModel;
        cout << "Enter model number: ";
        cin >> newModel.mComputer;
        cout << "Enter quantity bought: ";
        cin >> newModel.bQuantity;
        cout << "Enter quantity sold: ";
        cin >> newModel.sQuantity;
        cout << "Enter buying price: ";
        cin >> newModel.bPrice;
        cout << "Enter selling price: ";
        cin >> newModel.sPrice;
        newModel.profit = newModel.sPrice - newModel.bPrice;

        addModel(head, newModel);
    }

    Node *current = head;
    while (current != nullptr) {
        cout << "Model: " << current->data.mComputer << endl;
        cout << "Quantity Bought: " << current->data.bQuantity << endl;
        cout << "Quantity Sold: " << current->data.sQuantity << endl;
        cout << "Buying Price: " << current->data.bPrice << endl;
        cout << "Selling Price: " << current->data.sPrice << endl;
        cout << "Profit: " << current->data.profit << endl << endl;
        current = current->next;
    }

    return 0;
}
