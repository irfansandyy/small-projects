#include <iostream>

struct BST {
    public:
        BST() {
            this->root = nullptr;
            this->size = 0;
        }

        bool isEmpty() const {
            return !this->root;
        }

        bool find(int value) const {
            return searchUtil(this->root, value);
        }

        void insert(int value) {
            if (!find(value)) {
                this->root = insertUtil(this->root, value);
                size++;
            }
        }

        void remove(int value) {
            if (find(value)) {
                this->root = removeUtil(this->root, value);
                size--;
            }
        }

        void traverseInOrder() const {
            inOrder(this->root);
        }

        void traversePreOrder() const {
            preOrder(this->root);
        }

        void traversePostOrder() const {
            postOrder(this->root);
        }

    private:
        struct Node {
            int key;
            Node *left, *right;
            Node(int k) {
                this->key = k;
                this->left = this->right = nullptr;
            }
        };

        Node *root;
        unsigned int size;

        Node* searchUtil(Node *node, int value) const {
            while (node) {
                if (value < node->key) node = node->left;
                else if (value > node->key) node = node->right;
                else return node;
            }
            return nullptr;
        }

        Node* insertUtil(Node *node, int value) {
            if (!node) return new Node(value);

            if (value < node->key) node->left = insertUtil(node->left, value);
            else if (value > node->key) node->right = insertUtil(node->right, value);

            return node;
        }

        Node* findMinNode(Node *node) const {
            Node *currNode = node;
            while (currNode && currNode->left) currNode = currNode->left;

            return currNode;
        }

        Node* removeUtil(Node *node, int value) {
            if (!node) return nullptr;

            if (value > node->key) node->right = removeUtil(node->right, value);
            else if (value < node->key) node->left = removeUtil(node->left, value);
            else {
                if (!node->left) {
                    Node *rightChild = node->right;
                    delete node;
                    return rightChild;
                }
                else if (!node->right) {
                    Node *leftChild = node->left;
                    delete node;
                    return leftChild;
                }

                Node *temp = findMinNode(node->right);
                node->key = temp->key;
                node->right = removeUtil(node->right, temp->key);
            }
            return node;
        }

        void inOrder(Node *node) const {
            if (node) {
                inOrder(node->left);
                std::cout << node->key << " ";
                inOrder(node->right);
            }
        }

        void postOrder(Node *node) const {
            if (node) {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->key << " ";
            }
        }

        void preOrder(Node *node) const {
            if (node) {
                std::cout << node->key << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
};

int main() {
    BST set;

    set.insert(6);
    set.insert(1);
    set.insert(8);
    set.insert(12);
    set.insert(1);
    set.insert(3);
    set.insert(7);

    set.traversePreOrder();
    std::cout << "\n";
    set.traverseInOrder();
    std::cout << "\n";
    set.traversePostOrder();
    std::cout << "\n";

    set.remove(1);
    set.remove(6);
    set.remove(8);
    set.traverseInOrder();
    std::cout << "\n";

    std::cout << set.find(3) << "\n";
    set.remove(7);
    std::cout << set.find(12) << "\n";
    set.remove(3);
    set.remove(12);
    std::cout << set.isEmpty() << "\n";
    return 0;
}