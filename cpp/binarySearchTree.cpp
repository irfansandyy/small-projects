#include <iostream>

struct BST {
    public:
        BST() : root(nullptr), size(0) {}

        bool isEmpty() const {
            return !root;
        }

        bool find(int value) const {
            return searchUtil(root, value);
        }

        void insert(int value) {
            if (!find(value)) {
                root = insertUtil(root, value);
                size++;
            }
        }

        void remove(int value) {
            if (find(value)) {
                root = removeUtil(root, value);
                size--;
            }
        }

        void traverseInOrder() const {
            inOrder(root);
        }

        void traversePreOrder() const {
            preOrder(root);
        }

        void traversePostOrder() const {
            postOrder(root);
        }

    private:
        struct Node {
            int key;
            Node *left, *right;
            Node(int k) : key(k), left(nullptr), right(nullptr) {}
        };

        Node *root;
        unsigned int size;

        Node* searchUtil(Node *root, int value) const {
            while (root) {
                if (value < root->key) root = root->left;
                else if (value > root->key) root = root->right;
                else return root;
            }
            return nullptr;
        }

        Node* insertUtil(Node *root, int value) {
            if (!root) return new Node(value);

            if (value < root->key) root->left = insertUtil(root->left, value);
            else if (value > root->key) root->right = insertUtil(root->right, value);

            return root;
        }

        Node* findMinNode(Node *node) const {
            Node *currNode = node;
            while (currNode && currNode->left) currNode = currNode->left;

            return currNode;
        }

        Node* removeUtil(Node *root, int value) {
            if (!root) return nullptr;

            if (value > root->key) root->right = removeUtil(root->right, value);
            else if (value < root->key) root->left = removeUtil(root->left, value);
            else {
                if (!root->left) {
                    Node *rightChild = root->right;
                    delete root;
                    return rightChild;
                }
                else if (!root->right) {
                    Node *leftChild = root->left;
                    delete root;
                    return leftChild;
                }

                Node *temp = findMinNode(root->right);
                root->key = temp->key;
                root->right = removeUtil(root->right, temp->key);
            }
            return root;
        }

        void inOrder(Node *root) const {
            if (root) {
                inOrder(root->left);
                std::cout << root->key << " ";
                inOrder(root->right);
            }
        }

        void postOrder(Node *root) const {
            if (root) {
                postOrder(root->left);
                postOrder(root->right);
                std::cout << root->key << " ";
            }
        }

        void preOrder(Node *root) const {
            if (root) {
                std::cout << root->key << " ";
                preOrder(root->left);
                preOrder(root->right);
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