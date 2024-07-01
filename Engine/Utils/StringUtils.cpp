//
// Created by liyun on 24-6-29.
//

#include "Engine/Utils/StringUtils.h"

#include <algorithm>
#include <ranges>

namespace influx {
    std::string StringUtils::ToLower(const std::string &str) {
        std::string lower_str = str;
        std::ranges::transform(lower_str, lower_str.begin(), ::tolower);
        return lower_str;
    }

    std::string StringUtils::ToUpper(const std::string &str) {
        std::string upper_str = str;
        std::ranges::transform(upper_str, upper_str.begin(), ::toupper);
        return upper_str;
    }

    std::string StringUtils::Trim(const std::string &str) {
        auto start = std::ranges::find_if_not(str, ::isspace);
        auto end = std::ranges::find_if_not(str | std::views::reverse, ::isspace).base();
        return {start, end};
    }

    std::vector<std::string> StringUtils::Split(const std::string &str, const std::string &delim) {
        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = str.find(delim, start)) != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + delim.length();
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }

    std::string StringUtils::Replace(const std::string &str, const std::string &from, const std::string &to) {
        std::string replaced_str = str;
        size_t start_pos = 0;
        while ((start_pos = replaced_str.find(from, start_pos)) != std::string::npos) {
            replaced_str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return replaced_str;
    }

    std::string StringUtils::Remove(const std::string &str, const std::string &to_remove) {
        std::string removed_str = str;
        size_t start_pos = 0;
        while ((start_pos = removed_str.find(to_remove, start_pos)) != std::string::npos) {
            removed_str.erase(start_pos, to_remove.length());
        }
        return removed_str;
    }

    std::string StringUtils::Remove(const std::string &str, const char &to_remove) {
        std::string removed_str = str;
        removed_str.erase(std::ranges::remove(removed_str, to_remove).begin(), removed_str.end());
        return removed_str;
    }

    std::string StringUtils::Join(const std::vector<std::string> &strings, const std::string &delim) {
        std::string joined_str;
        for (size_t i = 0; i < strings.size(); i++) {
            joined_str += strings[i];
            if (i != strings.size() - 1) {
                joined_str += delim;
            }
        }
        return joined_str;
    }
}
