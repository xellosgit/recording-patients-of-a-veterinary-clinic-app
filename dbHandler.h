#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#include <functional>
#include <algorithm>
#include <memory>
#include <vector>

#include "animals.hpp"

typedef std::vector< std::unique_ptr<Animal> > AnimalList;
typedef std::unique_ptr<Animal> AnimalPtr;
typedef std::vector<size_t> idList;


class Database
{
    using searchFunctor = std::function<idList(std::string)>;
    AnimalList list;
    size_t notesCount;
    std::string dbname;
    std::string paswdHash;

    idList searchName(std::string name);
    idList searchAge(std::string age);
    idList searchSpecie(std::string specie);

    void searchHandler(searchFunctor cr1);
    void searchHandler(searchFunctor cr1, searchFunctor cr2);
    void searchHandler(searchFunctor cr1, searchFunctor cr2, searchFunctor cr3);
    
    friend class DatabaseManager;

    public:
    Database();
    void addNode(std::vector<std::string> params);
    void deleteNode(size_t pos);
    void editNode(size_t pos, uint8_t flag, std::string& value);
    const AnimalPtr& getNode(size_t pos);
    idList search(uint8_t flag, std::string& value);
};

#endif