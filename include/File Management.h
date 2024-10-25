#pragma once

#include <string>
#include <vector>
#include <fstream>

class FileManagement {

public:
    static std::vector<std::string> GetList() {
        std::vector<std::string> output;
        std::string line = "";
        std::ifstream inFile;
        inFile.open("saved_files.txt");
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                output.push_back(line);
            }
        }
        if (output.empty()) {
            std::ofstream myfile;
            myfile.open("saved_files.txt");
            myfile << "";
            myfile.close();
        }
        return output;
    }

    static bool CheckExists(const std::string& fileName) {
        std::vector<std::string> files = GetList();
        for (const auto& file : files) {
            if (file == fileName) {
                return true;
            }
        }
        return false;
    }

    static std::string ReadFile(const std::string& fileName) {
        if (!CheckExists(fileName)) {
            return "";
        }
        std::string contents = "";
        std::string line = "";
        std::ifstream inFile;
        inFile.open(fileName + ".dti");
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                if (!contents.empty()) {
                    contents += "\n";
                }
                contents += line;
            }
        }
        return contents;
    }

    static void WriteFile(const std::string& fileName, const std::string& content) {
        if (!CheckExists(fileName)) {
            std::vector<std::string> files = GetList();
            files.push_back(fileName);
            std::string fileString;
            for (const auto& file : files) {
                if (!fileString.empty()) {
                    fileString += "\n";
                }
                fileString += file;
            }
            std::ofstream fileListOutput("saved_files.txt");
            fileListOutput << fileString;
        }
        std::ofstream myfile(fileName + ".dti");
        myfile << content;
        myfile.close();
    }

    static void DeleteFile(const std::string& fileName) {
        if (CheckExists(fileName)) {
            WriteFile(fileName, "");
            std::vector<std::string> list = GetList();
            std::string listText;
            for (const auto& file : list) {
                if (file != fileName) {
                    if (!listText.empty()) {
                        listText += "\n";
                    }
                    listText += file;
                }
            }
            std::ofstream fileListOutput("saved_files.txt");
            fileListOutput << listText;
        }
    }
};
