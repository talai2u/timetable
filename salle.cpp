#include "salle.h"

salle::salle()
{
}

salle::~salle()
{
}

salle::salle(const int numero)
:_numero{numero}
{
    
}

//-------- Setters end getters ---------------
int salle::id() const{
    return _id;
}

void salle::set_id(const int id){
    _id = id;
}

int salle::numero() const{
    return _numero;
}

void salle::set_numero(const int numero){
    _numero = numero;
}

//---------------------------------------


void salle::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO salles (`id`, `numero`) VALUES ( NULL, '"+std::to_string(_numero)+"')";
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

void salle::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM salles WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void salle::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE salles set numero='"+std::to_string(_numero)+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void salle::charger(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM salles WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    db.row = mysql_fetch_row(db.res);
    
    _numero = atoi(db.row[1]);
    
    mysql_close(db.conn);
}

vector<salle> salle::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM salles";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<salle> salles;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        salle s ;
        s.set_id(atoi(db.row[0]));
        s.charger();
        salles.push_back(s);
        
    }
    
    mysql_close(db.conn);
    
    return salles;
    
    
    
}

