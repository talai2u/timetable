#ifndef NIVEAU_H
#define NIVEAU_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"
#include "administration.h"


class niveau : public administration
{
public:
    niveau();
    niveau(const string libelle);
    niveau(const niveau& niv);
    
    ~niveau();
    
    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    
    vector<niveau> getAll() const;

    //--Setters && Getters
    int id() const; 
    void set_id(int id);
    
    string libelle() const; 
    void set_libelle(const string libelle);
    
    //--------------------------------
    

private:
    int _id;
    string _libelle;

};

#endif // NIVEAU_H
