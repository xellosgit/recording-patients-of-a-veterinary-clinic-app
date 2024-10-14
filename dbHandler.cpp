#include "dbHandler.h"

Database::Database()
{
    notesCount = 0;
    dbname = "";
    paswdHash = "";
}

Species getKeyOfSpecie(const std::string& str_repr)
{
        for(const auto& it : species_names)
        {
            if(it.second == str_repr) return it.first;
        }
        return Species::SPECIE_OTHER;
}

const AnimalPtr& Database::getNode(size_t pos)
{
    if(pos < list.size())
    {
        return list[pos];
    }
    else throw std::out_of_range("[Database::getNode] Index of element is out of range.");
}

void Database::addNode(std::vector<std::string> params)
{
    Species sp = getKeyOfSpecie(params[2]);
    
    switch (sp)
    {
    case Species::SPECIE_OTHER:
        list.push_back(
            std::unique_ptr<Animal>(
                new Animal(params[0], sp, static_cast<uint8_t>(std::stoi(params[1])), const_cast<char*>(params[3].c_str()), const_cast<char*>(params[4].c_str()))
                ));
        break;
    case Species::SPECIE_CAT:
        list.push_back(
            std::unique_ptr<Animal>(
                new Cat(params[0], sp, static_cast<uint8_t>(std::stoi(params[1])), const_cast<char*>(params[3].c_str()), const_cast<char*>(params[4].c_str()))
                ));
        break;
    case Species::SPECIE_DOG:
        list.push_back(
            std::unique_ptr<Animal>(
                new Dog(params[0], sp, static_cast<uint8_t>(std::stoi(params[1])), const_cast<char*>(params[3].c_str()), const_cast<char*>(params[4].c_str()))
                ));
        break;
    case Species::SPECIE_HAMSTER:
        list.push_back(
            std::unique_ptr<Animal>(
                new Hamster(params[0], sp, static_cast<uint8_t>(std::stoi(params[1])), const_cast<char*>(params[3].c_str()), const_cast<char*>(params[4].c_str()))
                ));
        break;
    case Species::SPECIE_PARROT:
        list.push_back(
            std::unique_ptr<Animal>(
                new Parrot(params[0], sp, static_cast<uint8_t>(std::stoi(params[1])), const_cast<char*>(params[3].c_str()), const_cast<char*>(params[4].c_str()))
                ));
        break;
    default:
        throw std::runtime_error("[Database::addNote] Undefined specie type.");
        break;
    }

}
void Database::deleteNode(size_t pos)
{
    if(pos < list.size())
    {
        list.erase(list.begin() + pos);
        notesCount--;
    }
    else throw std::out_of_range("[Database::deleteNode] Index of element is out of range.");
}
void Database::editNode(size_t pos, uint8_t flag, std::string& value)
{
    if(pos < list.size())
    {
        switch (flag)
        {
        case 0:
            list[pos]->setupSpeciesInfoPath(value.c_str());
        case 1:
            list[pos]->setName(value.c_str());
            break;
        case 2:
            list[pos]->setAge(std::stoi(value));
            break;
        case 4:
            list[pos]->setSpecies(getKeyOfSpecie(value));
            break;
        case 8:
            list[pos]->setPhoto(const_cast<char*>(value.c_str()));
            break;
        case 16:
            list[pos]->setNotes(const_cast<char*>(value.c_str()));
            break;
        default:
            throw std::runtime_error("[Database:::editNode] Improper change flag has been provided.");
            break;
        }
    }
    else throw std::out_of_range("[Database::editNode] Index of element is out of range.");
}
idList Database::search(uint8_t flag, std::string& value)
{
    switch(flag)
    {
        case 1: return this->searchName(value);
        case 2: return this->searchSpecie(value);
        case 4: return this->searchAge(value);
        default:
            throw std::runtime_error("[Database::search] Improper search flag has been provided.");
            break;
    }
}

idList Database::searchName(std::string name)
{
    idList retval;
    for(size_t cu = 0, en = list.size(); cu < en; cu++)
    {
        if(std::string(list[cu]->getName()) == name) retval.push_back(cu);
    }
    return std::move(retval);
}
idList Database::searchAge(std::string age)
{
    idList retval;
    for(size_t cu = 0, en = list.size(); cu < en; cu++)
    {
        if(std::to_string(list[cu]->getAge()) == age) retval.push_back(cu);
    }
    return std::move(retval);
}
idList Database::searchSpecie(std::string specie)
{
    idList retval;
    for(size_t cu = 0, en = list.size(); cu < en; cu++)
    {
        if(species_names[list[cu]->getSpecies()] == specie) retval.push_back(cu);
    }
    return std::move(retval);
}   
void Database::searchHandler(searchFunctor cr1)
{

}
void Database::searchHandler(searchFunctor cr1, searchFunctor cr2)
{   

}
void Database::searchHandler(searchFunctor cr1, searchFunctor cr2, searchFunctor cr3)
{

}