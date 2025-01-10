
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void listFiles(const fs::path& directory) {
    std::cout << "\nFiles and Directories in " << directory << ":\n";
    for (const auto& entry : fs::directory_iterator(directory)) {
        std::cout << (entry.is_directory() ? "[DIR]  " : "[FILE] ") << entry.path().filename() << "\n";
    }
}

void createDirectory(const fs::path& directory) {
    if (fs::create_directory(directory)) {
        std::cout << "Directory " << directory << " created successfully.\n";
    } else {
        std::cout << "Failed to create directory or it already exists.\n";
    }
}

void createFile(const fs::path& file) {
    std::ofstream ofs(file);
    if (ofs) {
        std::cout << "File " << file << " created successfully.\n";
    } else {
        std::cout << "Failed to create file.\n";
    }
}

void deletePath(const fs::path& path) {
    if (fs::exists(path)) {
        fs::remove_all(path);
        std::cout << "Deleted: " << path << "\n";
    } else {
        std::cout << "Path does not exist.\n";
    }
}

int main() {
    std::string command;
    std::string path;

    std::cout << "Welcome to the Basic File Manager!\n";

    while (true) {
        std::cout << "\nCommands:\n";
        std::cout << "list [path]  - List files and directories\n";
        std::cout << "mkdir [path] - Create a directory\n";
        std::cout << "mkfile [path] - Create a file\n";
        std::cout << "delete [path] - Delete a file or directory\n";
        std::cout << "exit         - Exit the program\n";
        std::cout << "\nEnter command: ";
        std::cin >> command;

        if (command == "list") {
            std::cin >> path;
            listFiles(path);
        } else if (command == "mkdir") {
            std::cin >> path;
            createDirectory(path);
        } else if (command == "mkfile") {
            std::cin >> path;
            createFile(path);
        } else if (command == "delete") {
            std::cin >> path;
            deletePath(path);
        } else if (command == "exit") {
            std::cout << "Exiting File Manager. Goodbye!\n";
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}
