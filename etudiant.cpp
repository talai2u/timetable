#include "etudiant.h"
#include "niveau.h"
#include "filiere.h"

etudiant::etudiant()
{
}

etudiant::~etudiant()
{
}

etudiant::etudiant(const string nom,const string prenom, const string adresse, const string telephone,const string email, filiere* fil)
:_filiere{fil},individu{nom,prenom,adresse,telephone,email}
{
    
}

//-------- Setters end getters ---------------

filiere etudiant::get_filiere(){
    return *_filiere;
}

void etudiant::set_filiere(filiere* fil){
    _filiere = fil;
}

//---------------------------------------------


void etudiant::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO etudiants (`id`, `nom`, `prenom`, `adresse`, `telephone`, `mail`, `id_niveau`, `id_filiere`) VALUES ( NULL, '"+_nom+"', '"+_prenom+"', '"+_adresse+"', '"+_telephone+"', '"+_email+"','"+std::to_string(_filiere->get_niveau().id())+"', '"+std::to_string(_filiere->id())+"')";
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

void etudiant::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM etudiants WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void etudiant::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE etudiants set nom='"+_nom+"', prenom='"+_prenom+"', adresse='"+_adresse+"', telephone='"+_telephone+"', mail='"+_email+"', id_niveau='"+std::to_string(_filiere->get_niveau().id())+"', id_filiere='"+std::to_string(_filiere->id())+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void etudiant::charger(){
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM etudiants WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    db.row = mysql_fetch_row(db.res);
    if(db.row[1] != NULL) _nom = db.row[1];
    if(db.row[2] != NULL) _prenom = db.row[2];
    if(db.row[3] != NULL) _adresse = db.row[3];
    if(db.row[4] != NULL) _telephone = db.row[4];
    if(db.row[5] != NULL) _email = db.row[5];
    if(db.row[6] != NULL){
        filiere* f = new filiere;
        f->set_id(atoi(db.row[6]));
        f->charger();
        set_filiere(f);
    }
    
    mysql_close(db.conn);
}

vector<etudiant> etudiant::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM etudiants";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    vector<etudiant> etudiants;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        etudiant e ;
        filiere f;
        e.set_id(atoi(db.row[0]));
//        e.set_nom(db.row[1]);
//        e.set_prenom(db.row[2]);
//        e.get_filiere().set_id(db.row[6])
        e.charger();
        etudiants.push_back(e);
        
    }
    
    mysql_close(db.conn);
    
    return etudiants;
    
    
    
}




