#ifndef COURS_H
#define COURS_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"
#include "filiere.h"
#include "enseignant.h"

class cours : public administration
{
public:
    cours();
    cours(const string libelle, filiere* fil, enseignant* ens);
    ~cours();

    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    
    vector<cours> getAll() const;
    
    //--Setters && Getters
    int id() const; 
    void set_id(const int id);
    
    string libelle() const; 
    void set_libelle(const string libelle);
    
    filiere get_filiere() const; 
    void set_filiere(filiere* fil);
    
    enseignant get_enseignant() const; 
    void set_enseignant(enseignant* ens);
    
    //--------------------------------
    
private:
    int _id;
    string _libelle;
    filiere* _filiere;
    enseignant* _enseignant;

};

#endif // COURS_H
