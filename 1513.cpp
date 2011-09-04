#include <iostream>
#include <string>

void orderSplit(const std::string& direct, const std::string& center) {
    std::string root = direct.substr(0, 1);
    size_t rootCenterPos = center.find(root);
    
    std::string leftCenter = center.substr(0, rootCenterPos);
    std::string rightCenter = center.substr(rootCenterPos + 1);

    size_t leftCenterSize = leftCenter.size();
    
    std::string leftDirect = direct.substr(1, leftCenterSize);
    std::string rightDirect = direct.substr(leftCenterSize + 1);
    
    if(!leftDirect.empty() && !leftCenter.empty()) {
        //std::cout << leftCenter << " " << rightCenter << "\n";    
        orderSplit(leftDirect, leftCenter);
    }
    
    if(!rightDirect.empty() && !rightCenter.empty()) {
        //std::cout << leftDirect << " " << rightDirect << "\n";
        orderSplit(rightDirect, rightCenter);
    }

    //std::cout << "Root: " << root << "\n";
    std::cout << root;
}

void runSplit(const std::string& direct, const std::string& center) {
    orderSplit(direct, center);
    std::cout << "\n";
}

int main() {
    //runSplit("ABCDEF", "CBAEDF");
    //runSplit("xYz", "Yxz");
    //runSplit("abc", "cba");
    
    unsigned int inputNum;
    std::cin >> inputNum;

    for(unsigned int i = 0; i < inputNum; i++) {
        unsigned int len;
        std::string direct, center;
        std::cin >> len;
        std::cin >> direct >> center; 
        runSplit(direct, center);
    }

    return 0;
}
