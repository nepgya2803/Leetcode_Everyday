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
#include <unordered_set>
#include <vector>
#include <string_view>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit
{
    public:
        int n;
        int k;
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

class Solution
{
    public:
        std::string getHappyString(int n, int k)
        {
            std::string currentString = "";
            std::vector<std::string> happyCollection;

            GenerateHappyString(happyCollection, n, currentString);

            if (happyCollection.size() < k) {
                return "";
            }

            std::sort(happyCollection.begin(), happyCollection.end());

            return happyCollection[k - 1];
        }

    private:
        void GenerateHappyString(std::vector<std::string> &collection, int &n, std::string current)
        {
            if (current.size() == n) {
                collection.push_back(current);
                return;
            }

            for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
                if (current.size() > 0 && current.back() == currentChar)
                    continue;

                GenerateHappyString(collection, n, current + currentChar);
            }
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        { 1, 3 },
        { 1, 4 },
        { 3, 9 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.getHappyString(testcase[i].n, testcase[i].k);
        std::cout << std::boolalpha << r << std::endl;
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
