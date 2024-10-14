#include "animals.hpp"

const char* Animal::pathToSpeciesInfo;
const char* Cat::pathToSpeciesInfo;
const char* Dog::pathToSpeciesInfo;
const char* Parrot::pathToSpeciesInfo;
const char* Hamster::pathToSpeciesInfo;

Animal::Animal(std::string& nm, Species sp, uint8_t _age, char* photo_path, char* notes_path)
{
    this->name = nm;
    this->species = sp;
    this->age = _age;
    this->photo = photo_path;
    this->notes = notes_path;
}

void Animal::setName(const char* name){ this->name = name; }
void Animal::setSpecies(Species sp){ this->species = sp; }
void Animal::setPhoto(char* photo_path){ this->photo = photo_path; }
void Animal::setNotes(char* notes_path){ this->notes = notes_path; }
void Animal::setAge(uint8_t _age) { this->age = _age; }

const char* Animal::getName(){ return (this->name).c_str(); }
Species Animal::getSpecies(){ return this->species; }
const char* Animal::getPhoto(){ return this->photo; }
const char* Animal::getNotes(){ return this->notes; }
uint8_t Animal::getAge() { return this->age; }
const char* Animal::getSpeciesInfo(){ return pathToSpeciesInfo; }
void Animal::makeSound(){}
void Animal::showSpeciesInfo(){}

Cat::Cat(std::string& _name, Species sp, uint8_t _age, char* photo_path, char* notes_path)
    :Animal(_name, sp, _age, photo_path, notes_path)
{}
Dog::Dog(std::string& _name, Species sp, uint8_t _age, char* photo_path, char* notes_path)
    :Animal(_name, sp, _age, photo_path, notes_path)
{}
Parrot::Parrot(std::string& _name, Species sp, uint8_t _age, char* photo_path, char* notes_path)
    :Animal(_name, sp, _age, photo_path, notes_path)
{}
Hamster::Hamster(std::string& _name, Species sp, uint8_t _age, char* photo_path, char* notes_path)
    :Animal(_name, sp, _age, photo_path, notes_path)
{}

void Cat::makeSound(){ std::cout<<"Miau\n"; }
void Dog::makeSound(){ std::cout<<"Gav\n"; }
void Parrot::makeSound(){ std::cout<<"Privet\n"; }
void Hamster::makeSound(){ std::cout<<"Peee\n"; }

void checkPathValue(const char* path)
{
    if(!std::experimental::filesystem::exists(path))
    {
        throw std::runtime_error("[Animal::setupSpeciesInfo] Incorrect path provided.");
    }
}
void Animal::setupSpeciesInfoPath(const char* path)
{ 
    try { checkPathValue(path); this->pathToSpeciesInfo = path; }catch(...){pathToSpeciesInfo = nullptr; throw;}
}
void Cat::setupSpeciesInfoPath(const char* path)
{ 
    try { checkPathValue(path); this->pathToSpeciesInfo = path; }catch(...){pathToSpeciesInfo = nullptr; throw;}
}
void Dog::setupSpeciesInfoPath(const char* path)
{ 
    try { checkPathValue(path); this->pathToSpeciesInfo = path; }catch(...){pathToSpeciesInfo = nullptr; throw;}
}
void Hamster::setupSpeciesInfoPath(const char* path)
{ 
    try { checkPathValue(path); this->pathToSpeciesInfo = path; }catch(...){pathToSpeciesInfo = nullptr; throw;}
}
void Parrot::setupSpeciesInfoPath(const char* path)
{ 
    try { checkPathValue(path); this->pathToSpeciesInfo = path; }catch(...){pathToSpeciesInfo = nullptr; throw;}
}

const char* Cat::getSpeciesInfo(){ return pathToSpeciesInfo; }
const char* Dog::getSpeciesInfo(){ return pathToSpeciesInfo; }
const char* Hamster::getSpeciesInfo(){ return pathToSpeciesInfo; }
const char* Parrot::getSpeciesInfo(){ return pathToSpeciesInfo; }