#pragma once

#include <iostream>
#include <stdexcept>

#include "error_code.hpp"
#include "application_settings.hpp"

class CommandLineParser {

public:
    ErrorCode Parse(int argc, char* argv[], ApplicationSettings& app_settings);

protected:
    bool IsFilterName(const std::string& s);
};