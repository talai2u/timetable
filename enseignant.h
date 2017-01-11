#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H


#include "individu.h"

using namespace std;

class enseignant : public individu
{
public:
    enseignant();
    
    enseignant(const string nom,const string prenom, const string specialite, const string adresse, const string telephone,const string email);
    
    ~enseignant();
    
    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    
    
    vector<enseignant> getAll() const;
    
    //--Setters && Getters
    
    string specialite() const; 
    void set_specialite(const string specialite);
    
    
    //--------------------------------
    

private:
    string _specialite;

};

#endif // ENSEIGNANT_H
