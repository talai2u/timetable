#include "seance.h"

seance::seance()
{
}

seance::~seance()
{
}

seance::seance( date_* d,  time_* heure_debut,  time_* heure_fin, cours* c, salle* s)
:_date{d}, _heure_debut{heure_debut}, _heure_fin{heure_fin}, _cours{c}, _salle{s}
{}

//-------- Setters end getters ---------------
int seance::id() const{
    return _id;
}

void seance::set_id(const int id){
    _id = id;
}

date_ seance::date() const{
    return *_date;
}

void seance::set_date( date_* d){
    _date = d;
}

time_ seance::heure_debut() const{
    return *_heure_debut;
}

void seance::set_heure_debut( time_* h_debut){
    _heure_debut = h_debut;
}

time_ seance::heure_fin() const{
    return *_heure_fin;
}

void seance::set_heure_fin( time_* h_fin){
    _heure_fin = h_fin;
}

cours seance::get_cours() const {
    return *_cours;
}

void seance::set_cours(cours* c){
    _cours = c;
}

salle seance::get_salle() const {
    return *_salle;
}

void seance::set_salle(salle* s){
    _salle = s;
}


//---------------------------------------

void seance::ajouter(){
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query="INSERT INTO seances (`id`, `date_seance`, `heure_debut`, `heure_fin`, `id_cours`, `id_salle`) VALUES ( NULL, '"+_date->getDate()+"', '"+_heure_debut->getTime()+"', '"+_heure_fin->getTime()+"', '"+std::to_string(_cours->id())+"', '"+std::to_string(_salle->id())+"')";
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

void seance::supprimer() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="DELETE FROM seances WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien supprimées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void seance::modifier() const{
    database db;
    int query_state;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
     
    string query="UPDATE seances set date_seance='"+_date->getDate()+"', heure_debut='"+_heure_debut->getTime()+"', heure_fin='"+_heure_fin->getTime()+"', id_cours='"+std::to_string(_cours->id())+"', id_salle='"+std::to_string(_salle->id())+"' WHERE id = '"+std::to_string(_id)+"'";
    query_state=mysql_query(db.conn, query.c_str());
    
    if(query_state!=0){
      cout<<mysql_error(db.conn)<<endl<<endl;
      return;
    }
   
    
    cout<< "Les données sont bien modifiées" <<endl<<endl;
    
    mysql_close(db.conn);
}

void seance::charger(){
    database db;
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;
        return;
    }
    
    string query= "SELECT * FROM seances WHERE id = '"+std::to_string(_id)+"'";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
     while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        
        if(db.row[1] != NULL){ 
            int day = _date->stringToDate(db.row[1]).day();
            int month = _date->stringToDate(db.row[1]).month();
            int year =  _date->stringToDate(db.row[1]).year();
            
            date_* d = new date_(day, month, year);
            set_date(d);
        }
        
        if(db.row[2] != NULL){ 
            int hour = _heure_debut->stringToTime(db.row[2]).hour();
            int minute = _heure_debut->stringToTime(db.row[2]).minute();
            
            time_* t = new time_(hour, minute);
            set_heure_debut(t);
        }
        
        if(db.row[3] != NULL){ 
            int hour = _heure_fin->stringToTime(db.row[3]).hour();
            int minute = _heure_fin->stringToTime(db.row[3]).minute();
            
            time_* t = new time_(hour, minute);
            set_heure_fin(t);
        }
        
        if(db.row[4] != NULL){ 
            cours* c = new cours;
            c->set_id(atoi(db.row[4]));
            c->charger();
            set_cours(c);
        } 
       
        if(db.row[5] != NULL){ 
            salle* s = new salle;
            s->set_id(atoi(db.row[5]));
            s->charger();
            set_salle(s);
        }
        
    }
    
    mysql_close(db.conn);
}


vector<seance> seance::seancesByFiliere(int id_filiere) const{
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT S.id FROM seances S INNER JOIN cours C ON S.id_cours = C.id INNER JOIN filieres F ON C.id_filiere = F.id WHERE F.id = '"+std::to_string(id_filiere)+"' ORDER BY date_seance, heure_debut;";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<seance> seances;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        seance s ;
        s.set_id(atoi(db.row[0]));
        s.charger();
        seances.push_back(s);
        
    }
    
    mysql_close(db.conn);
    
    return seances;   
}
vector<seance> seance::getAll() const{
    
    database db;
    
    if(!db.connect()){
        cout<<mysql_error(db.conn)<<endl<<endl;    
    }
    
    string query= "SELECT * FROM seance";
    mysql_query(db.conn, query.c_str());
    db.res = mysql_store_result(db.conn);
    
    
    
    vector<seance> _seance;
    while ((db.row = mysql_fetch_row(db.res)))
    {   
        
        seance s ;
        s.set_id(atoi(db.row[0]));
        s.charger();
        _seance.push_back(s);
        
    }
    
    mysql_close(db.conn);
    
    return _seance;
    
    
    
}