#pragma once

#include <iostream>

#include "application_settings.hpp"
#include "error_code.hpp"

class CommandLineParser {

public:
    static ErrorCode Parse(int argc, char* argv[], ApplicationSettings& app_settings);

protected:
    static bool IsFilterName(const std::string& s);
};