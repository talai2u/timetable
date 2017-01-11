#ifndef FILIERE_H
#define FILIERE_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"
#include "niveau.h"
#include "administration.h"

class filiere: public administration
{
public:
    filiere();
    filiere(const string libelle, niveau* niv);
    ~filiere();
    
    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    
    vector<filiere> getAll() const;
    
    //--Setters && Getters
    int id() const; 
    void set_id(const int id);
    
    string libelle() const; 
    void set_libelle(const string libelle);
    
    niveau get_niveau() const; 
    void set_niveau(niveau* niv);
    
    //--------------------------------
    

private:
    int _id;
    string _libelle;
    niveau* _niveau;

};

#endif // FILIERE_H
