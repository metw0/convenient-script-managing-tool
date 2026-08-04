#pragma once
namespace ansi {
    constexpr const char *BOLD_RED = "\033[1;31m";
    constexpr const char *RESET = "\033[0m";
}
namespace dirs { 
    const std::string scripts_dir = "~/.csmt/scripts/"; 
}
namespace fs = std::filesystem;