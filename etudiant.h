#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "individu.h"
#include "niveau.h"
#include "filiere.h"

class etudiant : public individu
{
public:
    etudiant();
    etudiant(const string nom,const string prenom, const string adresse, const string telephone,const string email, filiere* fil);
    ~etudiant();
    
    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    

    //--Setters && Getters
    
    filiere get_filiere(); 
    void set_filiere(filiere* fil);
    
    
    //--------------------------------
    
    vector<etudiant> getAll() const;
    

private:

    filiere* _filiere;

};

#endif // ETUDIANT_H
