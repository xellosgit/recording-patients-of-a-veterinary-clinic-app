#ifndef CURS_ANIMALS_HPP
#define CURS_ANIMALS_HPP 1

#include <cstdint>
#include <string>
#include <iostream>
#include <map>
#include <experimental/filesystem>

enum class Species : uint8_t 
{ 
  SPECIE_CAT = 0, SPECIE_DOG, SPECIE_PARROT, 
  SPECIE_HAMSTER, SPECIE_OTHER
};

extern std::map<Species, std::string> species_names;

class IAnimal
{
    public:
    virtual void makeSound()         = 0;
    virtual void showSpeciesInfo()   = 0;
    virtual const char* getName()    = 0;
    virtual Species getSpecies()     = 0;
    virtual const char* getPhoto()   = 0;
    virtual const char* getNotes()   = 0;
    virtual uint8_t getAge()         = 0;
};

class Animal : public IAnimal
{
    static const char* pathToSpeciesInfo;
    protected:
    uint8_t age;
    Species species;
    char* photo;
    char* notes;
    std::string name;

    public:
    Animal(std::string& , Species, uint8_t, char* ,char* );
    ~Animal() = default;

    void setName(const char* name);
    void setSpecies(Species sp);
    void setPhoto(char* photo_path);
    void setNotes(char* notes_path);
    void setAge(uint8_t _age);

    virtual void makeSound();
    virtual void showSpeciesInfo();
    const char* getName();
    Species getSpecies();
    const char* getPhoto();
    const char* getNotes();
    uint8_t getAge();

    virtual void setupSpeciesInfoPath(const char* );
    virtual const char* getSpeciesInfo();
};

class Cat : public Animal
{
    static const char* pathToSpeciesInfo;

    public:
    Cat(std::string& , Species, uint8_t, char* ,char* );
    ~Cat() = default ;

    virtual void makeSound() override ;
    virtual void setupSpeciesInfoPath(const char* ) override;
    virtual const char* getSpeciesInfo() override;
};

class Dog : public Animal
{
    static const char* pathToSpeciesInfo;

    public:
    Dog(std::string& , Species, uint8_t, char* ,char* );
    ~Dog() = default;

    virtual void makeSound() override ;
    virtual void setupSpeciesInfoPath(const char* ) override;
    virtual const char* getSpeciesInfo() override;
};

class Parrot : public Animal
{
    static const char* pathToSpeciesInfo;

    public:
    Parrot(std::string& , Species, uint8_t, char* ,char* );
    ~Parrot() = default;

    virtual void makeSound() override ;
    virtual void setupSpeciesInfoPath(const char* ) override;
    virtual const char* getSpeciesInfo() override;
};

class Hamster : public Animal
{
    static const char* pathToSpeciesInfo;

    public:
    Hamster(std::string& , Species, uint8_t, char* ,char* );
    ~Hamster() = default;

    virtual void makeSound() override ;
    virtual void setupSpeciesInfoPath(const char* ) override;
    virtual const char* getSpeciesInfo() override;
};


#endif