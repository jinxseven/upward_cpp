#include <iostream>
#include <string>

class Node {
    public:
        std::string map;
        int data;
        Node *next;

    Node(std::string map, int data) {
        this->map = map;
        this->data = data;
        next = nullptr;
    }
};

class Hash {
    private:
        static const int SIZE = 7;
        Node *dataMaps[SIZE];

    int hashIndex(std::string map) {
        int hashx {0};
        for (char x : map) {
            hashx = (hashx + x) * 23;
        }
        return hashx % SIZE;
    }

    public:
        void addHash(std::string map, int data) {
            Node *new_node = new Node(map, data);
            int index = hashIndex(map);
            if (dataMaps[index] != nullptr) {
                Node *current = dataMaps[index];
                while (current->next) {
                    current = current->next;
                }
                current->next = new_node;
            } else {
                dataMaps[index] = new_node;
            }
        }

        int getHash(std::string map) {
            int index = hashIndex(map);
            Node *current = dataMaps[index];
            while (map.compare(current->map)) {
                current = current->next;
            }
            return current->data;
        }
};

int main() {
    Hash one;
    one.addHash("beetroot", 545);
    one.addHash("carrot", 445);
    one.addHash("pumpkin", 345);

    one.getHash("carrot");
    
}