#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#include "dbHandler.h"

extern void debug_printSVector(const std::vector<std::string>& vec);


class DatabaseManager
{
    std::ifstream istream;
    std::ofstream ostream;
    void strip(std::string& str);
    std::vector<std::string> splitString(std::string& str, char delim);

    public:
    DatabaseManager(const char* filename);
    ~DatabaseManager();
    bool loadFromFile(Database& obj);
    bool saveToFile(Database& obj);
};

#endif