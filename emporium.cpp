// These lines include the necessary header files for input/output operations, string manipulation, file handling, and stream operations
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

// This line declares an unsigned long variable named line and initializes it to 0. This variable will be used to keep track of the line number in case an error occurs
unsigned long line = 0;

// This is a function definition for raise_error. It takes two parameters: error_name and description, both of type std::string. This function is responsible for displaying an error message along with the line number where the error occurred and then exiting the program
void raise_error(const std::string &error_name, const std::string &description) {
    std::cout << error_name << " in line " << line << ":\n\t" << description;
    exit(1);
}

// This is the main function of the program. It takes two parameters: argc (the number of command-line arguments) and argv (an array of strings containing the command-line arguments). The if statement checks if the number of arguments is equal to 1, which means that no source file was specified. If this condition is true, the raise_error function is called with the appropriate error message
int main(int argc, char** argv) {
    if (argc == 1) {
        raise_error("Source file error", "The source file was not specified");
    }

    // This code block creates an std::ifstream object named source_file and opens the file specified by the command-line argument argv[1]. If the file cannot be opened (i.e., !source_file), the raise_error function is called with the appropriate error message
    std::ifstream source_file(argv[1]);

    if (!source_file) {
        raise_error("Source file error", "The source file was not found");
    }

    // These lines create an std::stringstream object named buffer and read the contents of the source_file into it using the rdbuf() function. After reading the contents, the source_file is closed
    std::stringstream buffer;
    buffer << source_file.rdbuf();
    source_file.close();

    // This code block creates a std::string object named code and assigns it the contents of the buffer using the str() function. Then, the erase function is used to remove all whitespace characters from the code string using the remove_if function and the isspace function
    std::string code = buffer.str();
    code.erase(std::remove_if(code.begin(), code.end(), isspace), code.end());

    // Finally, the main function returns 0, indicating successful program execution
    return 0;
}
