#include "command_line_parser.hpp"

#include <algorithm>
#include <string>

bool CommandLineParser::IsFilterName(const std::string& s) {
    return s.size() > 1 && s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return islower(c); });
}

void CommandLineParser::Parse(int argc, char* argv[], ApplicationSettings& app_settings) {
    if (argc < 3) {

        throw std::invalid_argument("Input or output file is not specified.\nUsage: " + std::string(argv[0]) +
                                    " {input_file_path} {output_file_path}\n" +
                                    "[-{filter_name_1} [filter_argument_1] [filter_argument_2] ...]\n" +
                                    "[-{filter_name_2} [filter_argument_1] [filter_argument_2] ...] ...\n");
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
        } else {
            throw std::invalid_argument("Incorrect argument format.\nUsage: " + std::string(argv[0]) +
                                        " {input_file_path} {output_file_path}\n" +
                                        "[-{filter_name_1} [filter_argument_1] [filter_argument_2] ...]\n" +
                                        "[-{filter_name_2} [filter_argument_1] [filter_argument_2] ...] ...\n");
        }
    }
}