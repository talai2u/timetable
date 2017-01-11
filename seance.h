#ifndef SEANCE_H
#define SEANCE_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"
#include "filiere.h"
#include "cours.h"
#include "salle.h"
#include "administration.h"
#include "date_.h"
#include "time_.h"


class seance : public administration
{
public:
    seance();
    seance( date_* d,  time_* heure_debut,  time_* heure_fin, cours* c, salle* s);
    ~seance();
    
    virtual void ajouter() override;
    virtual void supprimer() const override;
    virtual void modifier() const override;
    virtual void charger() override;
    
    //--Setters && Getters
    int id() const; 
    void set_id(const int id);
    
    date_ date() const; 
    void set_date ( date_* d);
    
    time_ heure_debut() const; 
    void set_heure_debut ( time_* h_debut);
    
    time_ heure_fin() const; 
    void set_heure_fin ( time_* h_fin);
    
    cours get_cours() const; 
    void set_cours(cours* c);
    
    salle get_salle() const; 
    void set_salle(salle* s);
    
    //--------------------------------
    vector<seance> getAll() const;
    vector<seance> seancesByFiliere(int id_filiere) const;

private:
    int _id;
    date_* _date;
    time_* _heure_debut;
    time_* _heure_fin;
    cours* _cours;
    salle* _salle;
    
};

#endif // SEANCE_H
