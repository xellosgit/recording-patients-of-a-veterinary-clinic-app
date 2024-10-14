/*
 *  Task: 
 *  Develop vet-patient accounting application
 *  
 *  Must have: 
 *  1) constructors & destructors
 *  2) reactions to user & admin actions
 *  3) inheritance
 *  4) incapsulation
 * 
 *  Should use:
 *  1) delegate methods
 *  2) polymorphism
 *  3) friend methods
 */


#include <iostream>
#include <map>

#include "animals.hpp"
#include "dbManager.h"
#include "dbHandler.h"

namespace fs = std::experimental::filesystem;

std::map<Species, std::string> species_names = {
    {Species::SPECIE_CAT, "Cat"},
    {Species::SPECIE_DOG, "Dog"},
    {Species::SPECIE_HAMSTER, "Hamster"},
    {Species::SPECIE_PARROT, "Parrot"},
    {Species::SPECIE_OTHER, "Other"}
};

void debug_printSVector(const std::vector<std::string>& vec)
{
    std::for_each(vec.begin(), vec.end(), [](const auto& item) { 
        std::cout<<item<<"_";
    });
    std::cout<<"\n";
}

void debug_printAnimal(const AnimalPtr& animal)
{
    std::cout<<"\t\tAnimal\n"
        <<"Name: "<<animal->getName()<<"\n"
        <<"Specie: "<<species_names[animal->getSpecies()]<<"\n"
        <<"Age: "<<(int)animal->getAge()<<"\n"
        <<"Photo: "<<animal->getPhoto()<<"\n"
        <<"Notes: "<<animal->getNotes()<<"\n";
}

int main(int argc, char** argv)
{
    Database db = Database();
    DatabaseManager dbl("data.txt");
    std::string search_for_name = "Barsik";
    std::string search_for_age = "2";
    std::string search_for_specie = "Dog";
    dbl.loadFromFile(db);
    debug_printAnimal(db.getNode(db.search(1, search_for_name)[0]));
    debug_printAnimal(db.getNode(db.search(4, search_for_age)[0]));
    debug_printAnimal(db.getNode(db.search(2, search_for_specie)[0]));
    db.deleteNode(2);
    dbl.saveToFile(db);
    return 0;
}