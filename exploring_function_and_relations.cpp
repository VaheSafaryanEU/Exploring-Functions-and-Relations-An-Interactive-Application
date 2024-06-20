#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

bool isInjective(const std::vector<std::pair<int, int>>& function) {
    std::unordered_set<int> values;
    for (const auto& pair : function) {
        if (values.find(pair.second) != values.end()) {
            return false;
        }
        values.insert(pair.second);
    }
    return true;
}

bool isSurjective(const std::vector<std::pair<int, int>>& function, const std::vector<int>& codomain) {
    std::unordered_set<int> values;
    for (const auto& pair : function) {
        values.insert(pair.second);
    }
    for (const auto& value : codomain) {
        if (values.find(value) == values.end()) {
            return false;
        }
    }
    return true;
}

bool isBijective(const std::vector<std::pair<int, int>>& function, const std::vector<int>& codomain) {
    return isInjective(function) && isSurjective(function, codomain);
}

int main() {
    std::vector<std::pair<int, int>> function = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    
    std::vector<int> domain = {1, 2, 3, 4};
    std::vector<int> codomain = {2, 3, 4, 5};

    std::vector<int> range;
    for (const auto& pair : function) {
        range.push_back(pair.second);
    }

    std::sort(range.begin(), range.end());
    range.erase(std::unique(range.begin(), range.end()), range.end());

    std::cout << "Function as ordered pairs: " << std::endl;
    for (const auto& pair : function) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    std::cout << "Domain: ";
    printVector(domain);

    std::cout << "Codomain: ";
    printVector(codomain);

    std::cout << "Range: ";
    printVector(range);

    std::cout << "Is the function injective? " << (isInjective(function) ? "Yes" : "No") << std::endl;
    std::cout << "Is the function surjective? " << (isSurjective(function, codomain) ? "Yes" : "No") << std::endl;
    std::cout << "Is the function bijective? " << (isBijective(function, codomain) ? "Yes" : "No") << std::endl;

    return 0;
}
