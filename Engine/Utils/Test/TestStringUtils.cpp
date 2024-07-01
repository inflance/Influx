//
// Created by liyun on 24-6-27.
//

#include <gtest/gtest.h>

#include "Engine/Utils/StringUtils.h"

TEST(StringUtils, toLower) {
    std::string str = "Hello, World!";
    EXPECT_EQ(influx::StringUtils::ToLower(str), "hello, world!");
}

TEST(StringUtils, toUpper) {
    std::string str = "Hello, World!";
    EXPECT_EQ(influx::StringUtils::ToUpper(str), "HELLO, WORLD!");
}

TEST(StringUtils, trim) {
    std::string str = "   Hello, World!   ";
    EXPECT_EQ(influx::StringUtils::Trim(str), "Hello, World!");
}

TEST(StringUtils, split) {
    std::string str = "Hello, World!";
    EXPECT_EQ(influx::StringUtils::Split(str, ", "), std::vector<std::string>({"Hello", "World!"}));
}

TEST(StringUtils, replace) {
    std::string str = "Hello, World!";
    EXPECT_EQ(influx::StringUtils::Replace(str, ", ", " "), "Hello World!");
}

TEST(StringUtils, remove) {
    std::string str = "Hello, World!";
    EXPECT_EQ(influx::StringUtils::Remove(str, ", "), "HelloWorld!");
    EXPECT_EQ(influx::StringUtils::Remove(str, ','), "Hello World!");
}


