#include "filiere.h"

filiere::filiere()
{
}

filiere::~filiere()
{
    _niveau = nullptr;
}

filiere::filiere(const string libelle, niveau* niv)
:_libelle{libelle}, _niveau{niv}
{
    
}

//-------- Setters end getters ---------------
int filiere::id() const{
    return _id;
}

void filiere::set_id(const int id){
    _id = id;
}

string filiere::libelle() const{
    return _libelle;
}

void filiere::set_libelle(const string libelle){
    _libelle = libelle;
}

niveau filiere::get_niveau() const {
    return *_niveau;
}

void filiere::set_niveau(niveau* niv){
    _niveau = niv;
}

//---------------------------------------

void filiere::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO filieres (`id`, `libelle`, `id_niveau`) VALUES ( NULL, '"+_libelle+"', '"+std::to_string(_niveau->id())+"')";
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

void filiere::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM filieres WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void filiere::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE filieres set libelle='"+_libelle+"', id_niveau='"+std::to_string(_niveau->id())+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void filiere::charger(){
    database db;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM filieres WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        if(db.row[1] != NULL) _libelle = db.row[1];
        if(db.row[2] != NULL){ 
            niveau* niv = new niveau;
            niv->set_id(atoi(db.row[2]));
            niv->charger();
            set_niveau(niv);
        }
        
    }
    
    mysql_close(db.conn);
}

vector<filiere> filiere::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM filieres";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<filiere> filieres;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        filiere f ;
        f.set_id(atoi(db.row[0]));
        f.set_libelle(db.row[1]);
        
        niveau* niv = new niveau;
        niv->set_id(atoi(db.row[2]));
        niv->charger();
        f.set_niveau(niv);
            
        filieres.push_back(f);
        
    }
    
    mysql_close(db.conn);
    
    return filieres;
    
    
    
}


