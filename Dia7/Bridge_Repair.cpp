#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    long long value;
    TreeNode* left;  
    TreeNode* right; 

    TreeNode(long long val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& numbers, size_t index, long long current) {
    if (index >= numbers.size()) {
        return new TreeNode(current); 
    }

    TreeNode* node = new TreeNode(current);

    node->left = buildTree(numbers, index + 1, current + numbers[index]);

    node->right = buildTree(numbers, index + 1, current * numbers[index]);

    return node;
}

bool searchTree(TreeNode* node, long long target) {
    if (!node->left && !node->right) { 
        return node->value == target;
    }

    bool foundLeft = node->left ? searchTree(node->left, target) : false;
    bool foundRight = node->right ? searchTree(node->right, target) : false;

    return foundLeft || foundRight;
}

void freeTree(TreeNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

long long solve(const string& input) {
    stringstream ss(input);
    string line;
    long long total = 0;

    while (getline(ss, line)) {
        size_t colonPos = line.find(':');
        long long target = stoll(line.substr(0, colonPos));

        vector<int> numbers;
        stringstream numStream(line.substr(colonPos + 1));
        int num;

        while (numStream >> num) {
            numbers.push_back(num);
        }

        TreeNode* root = buildTree(numbers, 1, numbers[0]);

        if (searchTree(root, target)) {
            total += target;
        }

        freeTree(root);
    }

    return total;
}

int main() {
    string input;
    string line;

    while (getline(cin, line)) {
        input += line + '\n';
    }

    cout << solve(input) << endl;
    return 0;
}
