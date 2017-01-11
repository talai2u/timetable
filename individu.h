#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "administration.h"

class individu : public administration 
{
public:
    individu();
    individu(const string nom,const string prenom, const string adresse,const string telephone,const string email);
    
    ~individu();
    
    virtual void ajouter() = 0;
    virtual void supprimer() const = 0;
    virtual void modifier() const = 0;
    virtual void charger() = 0;
    
    
    //--Setters && Getters
    int id() const; 
    void set_id(const int id);
    
    string nom() const; 
    void set_nom(const string nom);
    
    string prenom() const; 
    void set_prenom(const string prenom);
    
    string adresse() const; 
    void set_adresse(const string adresse);
    
    string telephone() const; 
    void set_telephone(const string telephone);
    
    string email() const; 
    void set_email(const string email);
    
    //--------------------------------

protected:
    int _id;
    string _nom;
    string _prenom;
    string _adresse;
    string _telephone;
    string _email;

};

#endif // INDIVIDU_H
