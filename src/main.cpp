#include <iostream>
#include <string>
#include <CLI/CLI.hpp>

int main(int argc, char **argv) {
    CLI::App csmt{"csmt - small utility that will help you run your scripts (in bash, python, etc.) more conveniently and quickly"};

    std::string script_to_run, script_to_add, script_to_remove;

    auto *run = csmt.add_subcommand("run", "run your script");
    run -> add_option("script_to_run", script_to_run, "script you need to run"); 
    auto *add = csmt.add_subcommand("add", "add your script");
    add -> add_option("script_to_add", script_to_add, "script you need to add (with extension)");
    auto *rm = csmt.add_subcommand("rm", "remove your script");
    rm -> add_option("script_to_remove", script_to_remove, "script you need to remove");

    CLI11_PARSE(csmt, argc, argv);

    if(*run) {
        std::cout << "you selected 'run' and typed " << script_to_run << "\n";
    } else if (*add) {
        std::cout << "you selected 'add' and typed " << script_to_add << "\n";
    } else if (*rm) {
        std::cout << "you selected 'rm' and typed " << script_to_remove << "\n";
    }

    return 0;
}
