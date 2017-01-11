#include "niveau.h"
#include <vector>
niveau::niveau()
{
}

niveau::~niveau()
{
}

niveau::niveau(const string libelle)
:_libelle{libelle}
{
    
}

niveau::niveau(const niveau& niv)
:_id{niv.id()}, _libelle{niv.libelle()}
{
    
}

//-------- Setters end getters ---------------
int niveau::id() const{
    return _id;
}

void niveau::set_id( int id){
    _id = id;
}

string niveau::libelle() const{
    return _libelle;
}

void niveau::set_libelle(const string libelle){
    _libelle = libelle;
}

//---------------------------------------

void niveau::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO niveaux (`id`, `libelle`) VALUES ( NULL, '"+_libelle+"')";
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

void niveau::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM niveaux WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void niveau::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE niveaux set libelle='"+_libelle+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void niveau::charger(){
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM niveaux WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        if(db.row[1] != NULL) _libelle = db.row[1];
    }
    
    
    
    mysql_close(db.conn);
}

vector<niveau> niveau::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM niveaux";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<niveau> niveaux;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
       
        niveau n ;
        n.set_id(atoi(db.row[0]));
        n.set_libelle(db.row[1]);
        niveaux.push_back(n);
        
    }
    
    mysql_close(db.conn);
    
    return niveaux;
    
    
    
}



