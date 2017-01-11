#include "cours.h"

cours::cours()
{
}

cours::~cours()
{
}

cours::cours(const string libelle, filiere* fil, enseignant* ens)
:_libelle{libelle}, _filiere{fil}, _enseignant{ens}
{
}


//-------- Setters end getters ---------------
int cours::id() const
{
    return _id;
}

void cours::set_id(const int id)
{
    _id = id;
}

string cours::libelle() const
{
    return _libelle;
}

void cours::set_libelle(const string libelle)
{
    _libelle = libelle;
}

filiere cours::get_filiere() const 
{
    return *_filiere;
}

void cours::set_filiere(filiere* fil)
{
    _filiere = fil;
}

enseignant cours::get_enseignant() const 
{
    return *_enseignant;
}

void cours::set_enseignant(enseignant* ens)
{
    _enseignant= ens;
}

//---------------------------------------


void cours::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO cours (`id`, `libelle`, `id_filiere`, `id_enseignant`) VALUES ( NULL, '"+_libelle+"', '"+std::to_string(_filiere->id())+"', '"+std::to_string(_enseignant->id())+"')";
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

void cours::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM cours WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void cours::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE filieres set libelle='"+_libelle+"', id_filiere='"+std::to_string(_filiere->id())+"', id_filiere='"+std::to_string(_enseignant->id())+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void cours::charger(){
    database db;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM cours WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
     while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        if(db.row[1] != NULL) _libelle = db.row[1];
        if(db.row[2] != NULL){ 
            filiere* f = new filiere;
            f->set_id(atoi(db.row[2]));
            f->charger();
            set_filiere(f);
        }
        
        if(db.row[3] != NULL){ 
            enseignant* e = new enseignant;
            e->set_id(atoi(db.row[3]));
            e->charger();
            set_enseignant(e);
        }
        
    }
    
    mysql_close(db.conn);
}

vector<cours> cours::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM cours";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<cours> _cours;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        cours c ;
        c.set_id(atoi(db.row[0]));
        c.charger();
        _cours.push_back(c);
        
    }
    
    mysql_close(db.conn);
    
    return _cours;
    
    
    
}
