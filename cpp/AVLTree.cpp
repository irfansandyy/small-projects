#include <iostream>

struct AVL {
    public:
        AVL() {
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
            int data;
            int height;
            Node *left, *right;
            Node(int d) {
                this->data = d;
                this->height = 1;
                this->left = this->right = nullptr;
            }
        };

        Node *root;
        unsigned size;

        Node* searchUtil(Node *node, int value) const {
            while (node) {
                if (value < node->data) node = node->left;
                else if (value > node->data) node = node->right;
                else return node;
            }
            return nullptr;
        }

        int getHeight(Node* node) const {
            if(!node) return 0; 
            return node->height;
        }

        int max(int a, int b) const {
            return (a > b)? a : b;
        }

        Node* rightRotate(Node* pivotNode) {
            Node* newParent = pivotNode->left;
            pivotNode->left = newParent->right;
            newParent->right = pivotNode;

            pivotNode->height = 
                max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
            newParent->height = 
                max(getHeight(newParent->left), getHeight(newParent->right)) + 1;

            return newParent;
        }

        Node* leftRotate(Node* pivotNode) {
            Node* newParent = pivotNode->right;
            pivotNode->right = newParent->left;
            newParent->left = pivotNode;

            pivotNode->height = 
                max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
            newParent->height = 
                max(getHeight(newParent->left), getHeight(newParent->right)) + 1;

            return newParent;
        }

        Node* leftCaseRotate(Node* node) {
            return rightRotate(node);
        }

        Node* rightCaseRotate(Node* node) {
            return leftRotate(node);
        }

        Node* leftRightCaseRotate(Node* node) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        Node* rightLeftCaseRotate(Node* node) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        int getBalanceFactor(Node* node) const {
            if(!node) return 0;
            return getHeight(node->left) - getHeight(node->right);
        }

        Node* insertUtil(Node* node, int value) {
            if(!node) return new Node(value);
            if(value < node->data) node->left = insertUtil(node->left, value);
            else if(value > node->data) node->right = insertUtil(node->right, value);

            node->height = max(getHeight(node->left), getHeight(node->right)) + 1; 
            int balanceFactor = getBalanceFactor(node);

            if(balanceFactor > 1 && value < node->left->data)
                return leftCaseRotate(node);
            if(balanceFactor > 1 && value > node->left->data)
                return leftRightCaseRotate(node);
            if(balanceFactor < -1 && value > node->right->data)
                return rightCaseRotate(node);
            if(balanceFactor < -1 && value < node->right->data)
                return rightLeftCaseRotate(node);

            return node;
        }

        Node* findMinNode(Node *node) const {
            Node *currNode = node;
            while (currNode && currNode->left) currNode = currNode->left;
            return currNode;
        }

        Node* removeUtil(Node* node, int value) {
            if(!node) return node;
            if(value > node->data) node->right = removeUtil(node->right, value);
            else if(value < node->data) node->left = removeUtil(node->left, value);
            else {
                Node *temp;
                if(!node->left || !node->right) {
                    temp = nullptr;
                    if(!node->left) temp=node->right;  
                    else if(!node->right) temp=node->left;

                    if(!temp){
                        temp = node;
                        node = nullptr;
                    }
                    else *node = *temp;   

                    delete temp;
                } else {
                    temp = findMinNode(node->right);
                    node->data = temp->data;
                    node->right = removeUtil(node->right, temp->data);
                }    
            }

            if(!node) return node;
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
            int balanceFactor = getBalanceFactor(node);

            if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0) 
                return leftCaseRotate(node);
            if(balanceFactor > 1 && getBalanceFactor(node->left) < 0) 
                return leftRightCaseRotate(node);
            if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0) 
                return rightCaseRotate(node);
            if(balanceFactor < -1 && getBalanceFactor(node->right) > 0) 
                return rightLeftCaseRotate(node);

            return node;
        }

        void inOrder(Node *node) const {
            if (node) {
                inOrder(node->left);
                std::cout << node->data << " ";
                inOrder(node->right);
            }
        }

        void postOrder(Node *node) const {
            if (node) {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->data << " ";
            }
        }

        void preOrder(Node *node) const {
            if (node) {
                std::cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
};

int main() {
    AVL set;

    set.insert(6);
    set.insert(611);
    set.insert(7);
    set.insert(612);
    set.insert(12);
    set.insert(4);

    set.traversePreOrder();
    std::cout << "\n";
    set.traverseInOrder();
    std::cout << "\n";
    set.traversePostOrder();
    std::cout << "\n";

    set.remove(4);
    set.remove(612);
    set.traversePostOrder();
    std::cout << "\n";

    std::cout << set.find(6) << "\n";
    set.remove(6);
    set.traversePostOrder();
    std::cout << "\n";
    std::cout << set.find(12) << "\n";
    set.remove(12);
    set.remove(611);
    set.remove(7);
    std::cout << set.isEmpty() << "\n";
    return 0;
}