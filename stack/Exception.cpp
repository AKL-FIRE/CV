//
//  Exception.cpp
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#include "Exception.hpp"

illegalParameterValue::illegalParameterValue() : message("Illegal parameter value")
{
}

illegalParameterValue::illegalParameterValue(const char *theMessage) : message(theMessage)
{
}

illegalParameterValue::illegalParameterValue(std::string str) : message(str)
{
}

void illegalParameterValue::outputMessage()
{
    std::cout << message << std::endl;
}

illegalIndex::illegalIndex() : message("Illegal Index")
{
}

illegalIndex::illegalIndex(const char *theMessage) : message(theMessage)
{
}

illegalIndex::illegalIndex(std::string str) : message(str)
{
}

void illegalIndex::outputMessage()
{
    std::cout << message << std::endl;
}
