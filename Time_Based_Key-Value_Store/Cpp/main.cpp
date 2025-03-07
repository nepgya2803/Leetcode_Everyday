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
#include <list>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::vector<int> nums;
    int target;
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class TimeMap {
public:
    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
        omap[key].insert({ timestamp, value });
    }

    std::string get(std::string key, int timestamp) {
        auto it = omap[key].upper_bound(timestamp);
        return it == omap[key].begin() ? "" : std::prev(it)->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> omap;
};

int main() {

    TimeMap timeMap;
    timeMap.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);        // return "bar"
    timeMap.get("foo", 3); // return "bar", since there is no value corresponding to foo at timestamp 3 and
                           // timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);         // return "bar2"

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
