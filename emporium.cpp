#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

unsigned long line = 0;

void raise_error(const std::string &error_name, const std::string &description);

int main(const int argc, const char** argv) {
    if (argc == 1) {
        raise_error("Source error", "The source file was not specified");
    }

    const std::string source_file_name = argv[1];
    std::ifstream source_file(source_file_name);

    if (!source_file) {
        raise_error("Source error", "The source file was not found");
    }

    if (source_file_name.substr(source_file_name.find_last_of('.') + 1) != "emp") {
        raise_error("Source error", "The source file has an incorrect extension");
    }

    std::stringstream buffer;
    buffer << source_file.rdbuf();
    source_file.close();

    std::string code = buffer.str();
    code.erase(std::remove_if(code.begin(), code.end(), isspace), code.end());

    return 0;
}

void raise_error(const std::string &error_name, const std::string &description) {
    std::cout << error_name + " in line " << line << ":\n\t" + description;
    exit(1);
}
