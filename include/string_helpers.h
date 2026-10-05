//
// Created by fakys on 05.10.2026.
//

#ifndef AVRDEVICECONTROLLER_STRING_HELPERS_H
#define AVRDEVICECONTROLLER_STRING_HELPERS_H

#include <string>
#include <algorithm>
#include <cctype>

void trimInPlace(std::string& s) {
    // Trim left
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    // Trim right
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

#endif //AVRDEVICECONTROLLER_STRING_HELPERS_H
