#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int age;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Masukkan node diawal
    void insertFirst(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

    // Masukkan node setelah node spesifik
    void insertAfter(string prevName, string name, int age) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == prevName) {
                Node* newNode = new Node;
                newNode->name = name;
                newNode->age = age;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node with name " << prevName << " not found!" << endl;
    }

    // Hapus node berdasarkan nama
    void deleteNode(string name) {
        Node* temp = head;
        Node* prev = nullptr;

        // Jika head node memegang kunci yang akan dihapus
        if (temp != nullptr && temp->name == name) {
            head = temp->next;
            delete temp;
            return;
        }

        // Cari kunci yang akan dihapus, pantau node sebelumnya karena perlu mengubah 'prev->next'
        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        // Jika kunci tidak ada dalam linked list
        if (temp == nullptr) {
            cout << "Node with name " << name << " not found!" << endl;
            return;
        }

        // Putuskan node dari linked list
        prev->next = temp->next;
        delete temp;
    }

    // Ubah node berdasarkan nama
    void modifyNode(string name, string newName, int newAge) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                current->name = newName;
                current->age = newAge;
                return;
            }
            current = current->next;
        }
        cout << "Node with name " << name << " not found!" << endl;
    }

    // Tampilkan semua node
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << "\t" << current->age << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Masukkan data sesuai urutan
    list.insertFirst("John", 19);
    list.insertAfter("John", "Jane", 20);
    list.insertAfter("Jane", "Michael", 18);
    list.insertAfter("Michael", "Yusuke", 19);
    list.insertAfter("Yusuke", "Akechi", 20);
    list.insertAfter("Akechi", "Hoshino", 18);
    list.insertAfter("Hoshino", "Karin", 18);

    // Tampilkan data
    cout << "Data before modifications:" << endl;
    list.display();
    cout << endl;

    // Lakukan operasi
    list.deleteNode("Akechi"); // Delete Akechi
    list.insertAfter("John", "Futaba", 18); // Insert Futaba between John and Jane
    list.insertFirst("Igor", 20); // Insert Igor at the beginning
    list.modifyNode("Michael", "Reyn", 18); // Modify Michael to Reyn

    // Tampilan setelah di modifikasi
    cout << "Data after modifications:" << endl;
    list.display();

    return 0;
}
