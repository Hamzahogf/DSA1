#include <iostream>
#include <stack>

class Et{
    private:
    struct Node
    {
        Node* firstchild;
        Node* secondchild;
        char x;
        Node(char x) : firstchild(nullptr) , secondchild(nullptr), x(x) {} ;
    };
    Node* head;

    public: 
    Et(): head(nullptr) {};
    Et(char x) : head(new Node(x)) {} // Constructor to create a single node

    // Add children to a node
    void addChildren(Et* left, Et* right) {
        if (head) {
            head->firstchild = left ? left->head : nullptr;
            head->secondchild = right ? right->head : nullptr;
        }
    }

    void print(Node* now = nullptr) const {
        if (!now) now = head;
        if (!now) return;
        if (now->firstchild) print(now->firstchild);
        std::cout << now->x << " ";
        if (now->secondchild) print(now->secondchild);
    }

    // Access the root node (for external usage)
    Node* getHead() const {
         return head; 
    }
};

void Expressiontree(std::string& postfix) {
    std::stack<Et*> s;

    for (char ch : postfix) {
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            // If the character is an operand, push it as a new tree
            s.push(new Et(ch));
        } else {
            // If the character is an operator, pop two trees from the stack
            Et* right = s.top(); s.pop();
            Et* left = s.top(); s.pop();

            // Create a new tree with the operator
            Et* opNode = new Et(ch);
            opNode->addChildren(left, right);

            // Push the new tree back onto the stack
            s.push(opNode);
        }
    }
        if (!s.empty()) {
        Et* tree = s.top();
        std::cout << "Expression Tree (in-order traversal): ";
        tree->print();
        std::cout << std::endl;
    }
}

int main() {
    std::string postfix = "ab+c*"; // Example postfix expression
    Expressiontree(postfix);
    return 0;
}
