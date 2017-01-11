#include "enseignant.h"
#include <string>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "database.h"

enseignant::enseignant()
{
}

enseignant::enseignant(const string nom,const string prenom, const string specialite, const string adresse, const string telephone,const string email)
:_specialite{specialite},individu{nom,prenom,adresse,telephone,email}
{
    
}
    
enseignant::~enseignant()
{
}


//-------- Setters end getters ---------------

string enseignant::specialite() const{
    return _specialite;
}

void enseignant::set_specialite(const string specialite){
    _specialite = specialite;
}

//---------------------------------------------


void enseignant::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO enseignants (`id`, `nom`, `prenom`, `specialite`, `adresse`, `telephone`, `mail`) VALUES ( NULL, '"+_nom+"', '"+_prenom+"', '"+_specialite+"', '"+_adresse+"', '"+_telephone+"', '"+_email+"')";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    mysql_query(db.conn, "SELECT LAST_INSERT_ID()");
    db.res = mysql_store_result(db.conn);
    db.row = mysql_fetch_row(db.res);
    _id =  atoi(db.row[0]);
    
    cout<< "Les données sont bien ajoutées" <<endl<<endl;
    
    mysql_close(db.conn);
    
}

void enseignant::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM enseignants WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void enseignant::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE enseignants set nom='"+_nom+"', prenom='"+_prenom+"', specialite='"+_specialite+"',  adresse='"+_adresse+"', telephone='"+_telephone+"', mail='"+_email+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}



void enseignant::charger(){
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM enseignants WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    while ((db.row = mysql_fetch_row(db.res)))
    {
        if(db.row[1] != NULL) _nom = db.row[1];
        if(db.row[2] != NULL) _prenom = db.row[2];
        if(db.row[3] != NULL) _specialite = db.row[3];
        if(db.row[4] != NULL) _adresse = db.row[4];
        if(db.row[5] != NULL) _telephone = db.row[5];
        if(db.row[6] != NULL) _email = db.row[6];
        
    }
    
    mysql_close(db.conn);
}
vector<enseignant> enseignant::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM enseignants";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<enseignant> enseignants;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        enseignant e ;
        e.set_id(atoi(db.row[0]));
        e.set_nom(db.row[1]);
        e.set_prenom(db.row[2]);
        enseignants.push_back(e);
        
    }
    
    mysql_close(db.conn);
    
    return enseignants;
    
    
    
}


