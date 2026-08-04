#include <iostream>
#include <string>
#include <CLI/CLI.hpp>
#include "header.h"

int main(int argc, char **argv) {
    CLI::App csmt{"csmt - small utility that will help you run your scripts (in bash, python, etc.) more conveniently and quickly"};

    std::string script_name, script_ext;

    auto *run = csmt.add_subcommand("run", "run your script");
    run -> add_option("script_to_run", script_name, "script you need to run (with extension)"); 
    auto *add = csmt.add_subcommand("add", "add your script");
    add -> add_option("script_to_add", script_name, "script you need to add (with extension)");
    auto *rm = csmt.add_subcommand("rm", "remove your script");
    rm -> add_option("script_to_remove", script_name, "script you need to remove (with extension)");

    CLI11_PARSE(csmt, argc, argv);

    if(!fs::is_regular_file(script_name)) {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET
                  << script_name << " isn't a file or doesn't exist\n";
        std::exit(1);
    }

    auto pos = script_name.find('.');
    script_ext = script_name.substr(pos);
    if(pos == std::string::npos) script_ext = ".bin";

    std::string command;
    if(*run) {
        if(script_ext == ".sh" || script_ext == ".bin") {
            command = "./" + script_name;
            system(command.c_str());
        } else if(script_ext == ".py") {
            command = "python3 " + script_name;
            system(command.c_str());
        } else {
            std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET
                      << script_ext << " is not a supported script extension\n";
            std::exit(1);
        }
    } else if (*add) {
        std::cout << "you selected 'add' and typed " << script_name << "\n";
    } else if (*rm) {
        std::cout << "you selected 'rm' and typed " << script_name << "\n";
    }

    std::cout << "success\n";
    return 0;
}
