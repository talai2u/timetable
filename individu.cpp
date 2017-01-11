#include "individu.h"

individu::individu()
{
}

individu::~individu()
{
}

individu::individu(const string nom,const string prenom, const string adresse, const string telephone,const string email)
:_nom{nom},_prenom{prenom}, _adresse{adresse}, _telephone{telephone}, _email{email}
{
    
}


//-------- Setters end getters ---------------
int individu::id() const{
    return _id;
}

void individu::set_id(const int id){
    _id = id;
}

string individu::nom() const{
    return _nom;
}

void individu::set_nom(const string nom){
    _nom = nom;
}

string individu::prenom() const{
    return _prenom;
}

void individu::set_prenom(const string prenom){
    _prenom = prenom;
}

string individu::adresse() const{
    return _adresse;
}

void individu::set_adresse(const string adresse){
    _adresse = adresse;
}

string individu::telephone() const{
    return _telephone;
}

void individu::set_telephone(const string telephone){
    _telephone = telephone;
}

string individu::email() const{
    return _email;
}

void individu::set_email(const string email){
    _email = email;
}
//---------------------------------------------


