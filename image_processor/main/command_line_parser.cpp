#include "command_line_parser.hpp"
#include <stdexcept>

bool CommandLineParser::IsFilterName(const std::string& s) {
    return s.size() > 1 && s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return islower(c); });
}

ErrorCode CommandLineParser::Parse(int argc, char* argv[], ApplicationSettings& app_settings) {
    if (argc < 3) {
        std::cerr << "Input or output file is not specified. Usage" << argv[0] << " <input.bmp> <output.bmp>\n";
        return ErrorCode::INVALID_ARGUMENTS;
    }

    app_settings.input_file_path_ = argv[1];
    app_settings.output_file_path_ = argv[2];

    for (size_t i = 3; i < argc; ++i) {
        if (IsFilterName(argv[i])) {
            FilterSettings filter_settings;
            filter_settings.name_ = std::string(argv[i]).substr(1);

            size_t ptr = i + 1;
            while (ptr < argc && !IsFilterName(argv[ptr])) {
                filter_settings.arguments_.push_back(argv[ptr]);
                ++ptr;
            }

            i = ptr - 1;
            app_settings.filters_settings_.push_back(filter_settings);
        }
    }
    return ErrorCode::SUCCESS;
}