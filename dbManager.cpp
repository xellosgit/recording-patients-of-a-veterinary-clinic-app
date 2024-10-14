#include "dbManager.h"

DatabaseManager::DatabaseManager(const char* filename)
{
    istream.open(filename, std::ios_base::in);
    ostream.open(std::string(filename).append(".new"), std::ios_base::out);
    if(istream.fail() || ostream.fail())
    {
        throw std::runtime_error(std::string("[DatabaseLoader] Error opening file : ").append(filename));
    }
}

DatabaseManager::~DatabaseManager()
{
    istream.close();
    ostream.close();
}

bool DatabaseManager::loadFromFile(Database& db)
{
    std::cout<<"["<<__PRETTY_FUNCTION__<<"] Loading from file started.\n";
    std::vector<std::string> params;
    std::string buffer;
    if(!istream.eof())
    {
        std::cout<<"["<<__PRETTY_FUNCTION__<<"] Istream is not empty.Start reading...\n";
        std::getline(istream, buffer);
        params = splitString(buffer, ';');
        db.dbname = params[0];
        db.paswdHash = params[1];
        db.notesCount = std::stol(params[2]);
        //debug_printSVector(params);
        while(!istream.eof())
        {
            std::getline(istream, buffer);
            params = splitString(buffer, ';');
            db.addNode(params);
            debug_printSVector(params);
        }
        std::cout<<"["<<__PRETTY_FUNCTION__<<"] Reading successfull.\n";
        return true;
    }
    else {
        return false;
    }
}

bool DatabaseManager::saveToFile(Database& db)
{
    std::string buffer = db.dbname.append("; ") + db.paswdHash.append("; ") + std::to_string(db.notesCount);
    ostream<<buffer<<"\n";

    auto pushNote = [this, &buffer](auto& item)
    {
        buffer = std::string(item->getName()).append("; ") +
                 std::to_string(item->getAge()).append("; ") +
                 species_names.at(item->getSpecies()).append("; ") +
                 std::string(item->getPhoto()).append("; ") +
                 std::string(item->getNotes());
        ostream<<buffer<<"\n";
    };

    std::for_each(db.list.begin(), db.list.end(), pushNote);
    return true;
}

void DatabaseManager::strip(std::string& str)
{
    auto it1 = std::find_if(str.rbegin(), str.rend(), 
        [](char ch){ return !std::isspace<char>(ch, std::locale::classic() ); } );
    str.erase(it1.base(), str.end());

    auto it2 = std::find_if(str.begin(), str.end(), 
        [](char ch){ return !std::isspace<char>(ch, std::locale::classic() ); } );
    str.erase(str.begin(), it2);

}

std::vector<std::string> DatabaseManager::splitString(std::string& str, char delim)
{
    std::vector<std::string> retval;
    size_t prev = 0, next = 0;

    for(; next < str.size(); next++)
    {
        prev = next;
        next = str.find(delim, next);
        if(next != std::string::npos)
        {
            retval.push_back(str.substr(prev, next - prev));
        }
        else break;
    }
    retval.push_back(str.substr(
        (next == std::string::npos) ? prev : next,
        str.size() - ( (next == std::string::npos) ? prev : next)
    ));
    std::for_each(retval.begin(), retval.end(), [this](auto& string){strip(string); });
    return std::move(retval);
}