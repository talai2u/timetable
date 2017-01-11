#ifndef SALLE_H
#define SALLE_H

#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"

class salle
{
public:
    salle();
    ~salle();
    salle(const int numero);

void ajouter();
    void supprimer() const;
    void modifier() const;
    void charger();
    
    vector<salle> getAll() const;

    //--Setters && Getters
    int id() const; 
    void set_id(const int id);
    
    int numero() const; 
    void set_numero(const int numero);
    
    //--------------------------------
    

private:
    int _id;
    int _numero;

};

#endif // SALLE_H
