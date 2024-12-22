#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#define LOG_DEBUG(x) (std::cout << x << std::endl)

struct TestSuit
{
    public:
        std::vector<int> node;
};

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right)
        {}
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input)
{
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input)
{
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

TreeNode *ConstructBinaryTree(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }

    TreeNode *root  = new TreeNode(arr[0]);
    auto node_queue = std::queue<TreeNode *>();
    node_queue.push(root);
    int level = 1;
    while (level < arr.size())
    {
        TreeNode *curr = node_queue.front();
        node_queue.pop();
        if (level < arr.size())
        {
            curr->left = new TreeNode(arr[level++]);
            node_queue.push(curr->left);
        }
        if (level < arr.size())
        {
            curr->right = new TreeNode(arr[level++]);
            node_queue.push(curr->right);
        }
    }

    return root;
}

void bft(TreeNode *root)
{
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        std::cout << current->val << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    std::cout << "\n";
}

class Solution
{
    public:
        TreeNode *reverseOddLevels(TreeNode *root)
        {
            LevelSwitch(root->left, root->right, 0);
            return root;
        }

    private:
        void LevelSwitch(TreeNode *left, TreeNode *right, int level)
        {
            if (!left || !right)
                return;

            if (level % 2 == 0)
            {
                int tmp    = left->val;
                left->val  = right->val;
                right->val = tmp;
            }

            LevelSwitch(left->left, right->right, level + 1);
            LevelSwitch(left->right, right->left, level + 1);
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{2, 3, 5, 8, 13, 21, 34}},
        {{7, 13, 11}},
        {{0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mBefore Testcase " + std::to_string(i + 1) +
                      "\033[0m")
                  << std::endl;
        TreeNode *root = ConstructBinaryTree(testcase[i].node);
        bft(root);
        auto r = s.reverseOddLevels(root);
        std::cout << ("\033[1;32mAfter Testcase " + std::to_string(i + 1) +
                      "\033[0m")
                  << std::endl;
        bft(r);
    }

    return 1;
}

//          foreground background
// black        30         40
// red          31         41
// green        32         42
// yellow       33         43
// blue         34         44
// magenta      35         45
// cyan         36         46
// white        37         47
