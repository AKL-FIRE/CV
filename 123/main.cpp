//
//  main.cpp
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#include "extendedChain.hpp"

int main()
{
    extendedChain<int> a(10);
    a.push_back(1);
    a.push_back(2);
    a.insert(2,13);
    std::cout << a;
    a.push_back(15);
    a.erase(2);
    std::cout << a;
}
