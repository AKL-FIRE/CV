//
//  Exception.h
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#ifndef Exception_h
#define Exception_h

#include <iostream>

class illegalParameterValue
{
public:
    illegalParameterValue();
    illegalParameterValue(const char *theMessage);
    illegalParameterValue(std::string str);
    void outputMessage();
private:
    std::string message;
};

class illegalIndex
{
public:
    illegalIndex();
    illegalIndex(const char *theMessage);
    illegalIndex(std::string str);
    void outputMessage();
private:
    std::string message;
};

#endif /* Exception_h */
