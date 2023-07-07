#include <iostream>
#include <map>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide text as command line argument.\n";
        return 0;
    }

    std::map<char, int> alphabetCount;

    // Iterate through each argument
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        // Iterate through each character in the argument
        for (char& c : arg) {
            // Convert character to uppercase
            c = std::toupper(c);

            // Increment count for alphabets only
            if (std::isalpha(c)) {
                alphabetCount[c]++;
            }
        }
    }

    // Print the table of alphabet occurrences
    std::cout << "Alphabet\tOccurrences\n";
    for (const auto& pair : alphabetCount) {
        std::cout << pair.first << "\t\t" << pair.second << std::endl;
    }

    return 0;
}
