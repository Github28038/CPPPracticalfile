#include <iostream>
#include <cstring>

void showAddress(const char* str) {
    std::cout << "Address of each character in the string:\n";
    for (int i = 0; i < strlen(str); i++) {
        std::cout << str[i] << ": " << static_cast<const void*>(&str[i]) << std::endl;
    }
    std::cout << std::endl;
}

char* concatenateStrings(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1];

    int i, j;

    for (i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    for (j = 0; j < len2; j++) {
        result[i + j] = str2[j];
    }

    result[i + j] = '\0';

    return result;
}

int compareStrings(const char* str1, const char* str2) {
    int result = strcmp(str1, str2);
    if (result == 0) {
        return 0;
    } else if (result < 0) {
        return -1;
    } else {
        return 1;
    }
}

int calculateLength(const char* str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

void convertToLowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        std::swap(str[i], str[j]);
    }
}

void insertString(char* str, const char* insertStr, int position) {
    int length = strlen(str);
    int insertLength = strlen(insertStr);

    if (position < 0 || position > length) {
        std::cout << "Invalid position\n";
        return;
    }

    char* result = new char[length + insertLength + 1];

    // Copy characters before the insertion position
    for (int i = 0; i < position; i++) {
        result[i] = str[i];
    }

    // Copy the inserted string
    for (int i = 0; i < insertLength; i++) {
        result[position + i] = insertStr[i];
    }

    // Copy characters after the insertion position
    for (int i = position; i < length; i++) {
        result[i + insertLength] = str[i];
    }

    result[length + insertLength] = '\0';

    // Update the original string with the modified result
    strcpy(str, result);

    delete[] result;
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Show address of each character in a string\n";
        std::cout << "2. Concatenate two strings\n";
        std::cout << "3. Compare two strings\n";
        std::cout << "4. Calculate length of a string\n";
        std::cout << "5. Convert lowercase characters to uppercase\n";
        std::cout << "6. Reverse a string\n";
        std::cout << "7. Insert a string in another string at a specified position\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter a string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                showAddress(str1);
                break;
            }
            case 2: {
                std::cout << "Enter the first string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                std::cout << "Enter the second string: ";
                std::cin.getline(str2, 100);
                char* concatenated = concatenateStrings(str1, str2);
                std::cout << "Concatenated string: " << concatenated << std::endl;
                delete[] concatenated;
                break;
            }
            case 3: {
                std::cout << "Enter the first string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                std::cout << "Enter the second string: ";
                std::cin.getline(str2, 100);
                int result = compareStrings(str1, str2);
                if (result == 0) {
                    std::cout << "Strings are equal\n";
                } else if (result < 0) {
                    std::cout << "String 1 is less than String 2\n";
                } else {
                    std::cout << "String 1 is greater than String 2\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter a string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                int length = calculateLength(str1);
                std::cout << "Length of the string: " << length << std::endl;
                break;
            }
            case 5: {
                std::cout << "Enter a string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                convertToLowercase(str1);
                std::cout << "Converted string: " << str1 << std::endl;
                break;
            }
            case 6: {
                std::cout << "Enter a string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                reverseString(str1);
                std::cout << "Reversed string: " << str1 << std::endl;
                break;
            }
            case 7: {
                std::cout << "Enter the base string: ";
                std::cin.ignore();
                std::cin.getline(str1, 100);
                std::cout << "Enter the string to be inserted: ";
                std::cin.getline(str2, 100);
                int position;
                std::cout << "Enter the position (0-based index) to insert the string: ";
                std::cin >> position;
                insertString(str1, str2, position);
                std::cout << "Modified string: " << str1 << std::endl;
                break;
            }
            case 8:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << std::endl;
    }
}
