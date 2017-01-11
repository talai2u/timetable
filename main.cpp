#include <stdio.h>
#include <iostream>
#include <individu.h>
#include <enseignant.h>
#include <niveau.h>
#include <date_.h>
#include <database.h>
#include "etudiant.h"
#include "cours.h"
#include "seance.h"
#include "salle.h"
#include "date_.h"
#include "time_.h"
#include "TextTable.h"


using namespace std;


// ---------------  Enseignants -------------
void ajouter_enseignant(){
    string nom,prenom,specialite,adresse,telephone,email;
    cout << "Merci de bien saisir les info de l'enseignant " << endl;
    
    cout << "+) Nom : ";
    cin.ignore();
    getline(cin,nom);
    
    cout << "+) prénom : ";
    cin.ignore();
    getline(cin,prenom);
    
    cout << "+) specialité : ";
    cin.ignore();
    getline(cin,specialite);
    
    cout << "+) adresse : " ;
    cin.ignore();
    getline(cin,adresse);
    
    cout << "+) telephone : " ;
    cin.ignore();
    getline(cin,telephone);
    
    cout << "+) email : ";
    cin.ignore();
    getline(cin,email);
    
    enseignant* e = new enseignant(nom,prenom,specialite,adresse,telephone,email);
    e->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}

enseignant rechercher_enseignant(){
    int id;
    string nom,prenom,specialite,adresse,telephone,email;
    enseignant e;
    
    cout << "Saisir l'ID de l'enseignant : ";
    cin>>id;
    
    e.set_id(id);
    e.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Nom : "<<e.nom()<<endl;
    cout << "+) Prenom : "<<e.prenom()<<endl;
    cout << "+) Specialité : "<<e.specialite()<<endl;
    cout << "+) Adresse : "<<e.adresse()<<endl;
    cout << "+) Téléphone : "<<e.telephone()<<endl;
    cout << "+) Email : "<<e.email()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return e; 
}

void modifier_enseignant(){
    
    enseignant e = rechercher_enseignant();
    
    string nom,prenom,specialite,adresse,telephone,email;
    cout << "Merci de bien saisir les info de l'enseignant " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) Nom : ";
    cin.ignore();
    getline(cin,nom);
    
    cout << "+) prénom : ";
    cin.ignore();
    getline(cin,prenom);
    
    cout << "+) specialité : ";
    cin.ignore();
    getline(cin,specialite);
    
    cout << "+) adresse : " ;
    cin.ignore();
    getline(cin,adresse);
    
    cout << "+) telephone : " ;
    cin.ignore();
    getline(cin,telephone);
    
    cout << "+) email : ";
    cin.ignore();
    getline(cin,email);
    
    if(nom != "") e.set_nom(nom);
    if(prenom != "") e.set_prenom(prenom);
    if(specialite != "") e.set_specialite(specialite);
    if(adresse != "") e.set_adresse(adresse);
    if(telephone != "") e.set_telephone(telephone);
    if(email != "") e.set_email(email);
    
    e.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}

void supprimer_enseignant(){
    enseignant e = rechercher_enseignant();
    
    int rep;
    cout << "Voulez vous bien supprimer l'enseignant '"+e.nom()+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        e.supprimer();
    }

    
}

void lister_enseignant(){
    enseignant e;
    vector<enseignant> enseignants = e.getAll();
    
    cout << "---------- Liste des enseignants --------"<<endl;
    for(auto& e : enseignants){
        cout<<e.id() <<" | "<<e.nom()<<" | "<<e.prenom()<<endl;
        
        cout << "-------------------------"<<endl;
    }
}


//-------- Etudiants -----------
void ajouter_etudiant(){
    string nom,prenom,adresse,telephone,email;
    int id_filiere;
    cout << "Merci de bien saisir les info de l'étudiant " << endl;
    
    cout << "+) Nom : ";
    cin.ignore();
    getline(cin,nom);
    
    cout << "+) prénom : ";
    cin.ignore();
    getline(cin,prenom);
    
    cout << "+) adresse : " ;
    cin.ignore();
    getline(cin,adresse);
    
    cout << "+) telephone : " ;
    cin.ignore();
    getline(cin,telephone);
    
    cout << "+) email : ";
    cin.ignore();
    getline(cin,email);
    
    cout << "+) Id Filière : ";
    cin>>id_filiere;
  
    
    filiere* f = new filiere;
    f->set_id(id_filiere);
    f->charger();
    
    etudiant* e = new etudiant(nom,prenom,adresse,telephone,email,f);
    e->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}

etudiant rechercher_etudiant(){
    int id;
    string nom,prenom,adresse,telephone,email,id_filiere;
    etudiant e;
    
    cout << "Saisir l'ID de l'étudiant : ";
    cin>>id;
    
    e.set_id(id);
    e.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Nom : "<<e.nom()<<endl;
    cout << "+) Prenom : "<<e.prenom()<<endl;
    cout << "+) Adresse : "<<e.adresse()<<endl;
    cout << "+) Téléphone : "<<e.telephone()<<endl;
    cout << "+) Email : "<<e.email()<<endl;
    cout << "+) Filière : "<<e.get_filiere().libelle()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return e; 
}

void modifier_etudiant(){
    
    etudiant e = rechercher_etudiant();
    
    string nom,prenom,adresse,telephone,email;
    int id_filiere;
    
    cout << "Merci de bien saisir les info de l'étudiant " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) Nom : ";
    cin.ignore();
    getline(cin,nom);
    
    cout << "+) prénom : ";
    cin.ignore();
    getline(cin,prenom);
    
    cout << "+) adresse : " ;
    cin.ignore();
    getline(cin,adresse);
    
    cout << "+) telephone : " ;
    cin.ignore();
    getline(cin,telephone);
    
    cout << "+) email : ";
    cin.ignore();
    getline(cin,email);
    
    cout << "+) id_filière : ";
    cin>>id_filiere;
    
    if(nom != "") e.set_nom(nom);
    if(prenom != "") e.set_prenom(prenom);
    if(adresse != "") e.set_adresse(adresse);
    if(telephone != "") e.set_telephone(telephone);
    if(email != "") e.set_email(email);
    if(id_filiere != NULL) { 
        filiere* f = new filiere;
        f->set_id(id_filiere);
        f->charger();
        e.set_filiere(f); 
    }
    
    e.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}

void supprimer_etudiant(){
    etudiant e = rechercher_etudiant();
    
    int rep;
    cout << "Voulez vous bien supprimer l'étudiant '"+e.nom()+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        e.supprimer();
    }

    
}

void lister_etudiant(){
    etudiant e;
    vector<etudiant> etudiants = e.getAll();
    
    cout << "---------- Liste des étudiants --------"<<endl;
    for(auto& e : etudiants){
        cout<<e.id() <<" | "<<e.nom()<<" | "<<e.prenom()<<endl;
        
        cout << "-------------------------"<<endl;
    }
}



// ---------------  Niveaux -------
void list_niveau(){
        niveau niv;
        vector<niveau> niveaux = niv.getAll();
        
        cout << "---------- Liste des niveaux --------"<<endl;
        for(auto& n : niveaux){
            cout<<n.id() <<" | "<<n.libelle()<<endl;
            
            cout << "-------------------------"<<endl;
        }
}
void ajouter_niveau(){
    int id;
    string libelle;
    
    cout << "Merci de bien saisir les info de l'étudiant " << endl;
    
    cout << "+) Libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    
    
    niveau* n = new niveau(libelle);
    n->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}
niveau rechercher_niveau(){
    int id;
    niveau n;
    
    cout << "Saisir l'ID du niveau : ";
    cin>>id;
    
    n.set_id(id);
    n.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Libellé : "<<n.libelle()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return n; 
}
void modifier_niveau(){
    
    niveau n = rechercher_niveau();
    
    string libelle;
    
    cout << "Merci de bien saisir les info du niveau " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    
    if(libelle != "") n.set_libelle(libelle);
    
    n.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}
void supprimer_niveau(){
    niveau n = rechercher_niveau();
    
    int rep;
    cout << "Voulez vous bien supprimer le niveau '"+n.libelle()+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        n.supprimer();
    }

    
}


//------- Filières ---------
void ajouter_filiere(){
    
    
    string libelle;
    int id_niveau;
    niveau * niv = new niveau;
    
    
    cout << "Merci de bien saisir les info de la filière " << endl;
    
    cout << "+) Libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    list_niveau();
    cout << "Saisir l'ID de niveau : ";
    cin >> id_niveau;
    
    niv->set_id(id_niveau);
    cout<< "Here"<<endl;
    niv->charger();
    
    filiere* f = new filiere(libelle, niv);
    f->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}
filiere rechercher_filiere(){
    int id;
    string libelle;
    filiere f;
    
    cout << "Saisir l'ID de la filière : ";
    cin>>id;
    
    f.set_id(id);
    f.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Libellé : "<<f.libelle()<<endl;
    cout << "+) Niveau : "<<f.get_niveau().libelle()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return f; 
}
void modifier_filiere(){
    
    filiere f = rechercher_filiere();
    
    string libelle;
    int id_niveau;
    
    cout << "Merci de bien saisir les info de la filière " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) Libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    cout << "+) id_niveau : ";
    cin>>id_niveau;
    
    if(libelle != "") f.set_libelle(libelle);
    if(id_niveau != NULL) { 
        niveau* n = new niveau;
        n->set_id(id_niveau);
        n->charger();
        f.set_niveau(n); 
    }
    
    f.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}
void supprimer_filiere(){
    filiere f = rechercher_filiere();
    
    int rep;
    cout << "Voulez vous bien supprimer la filière '"+f.libelle()+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        f.supprimer();
    }

    
}
void lister_filiere(){
    filiere f;
    vector<filiere> filieres = f.getAll();
    
    
    
    cout << "---------- Liste des filières --------"<<endl;
    
    for(int i =0; i<filieres.size(); i++){
        
        cout<<filieres[i].id() <<" | "<<filieres[i].libelle()<<" | "<<filieres[i].get_niveau().libelle()<<endl;
        
        cout << "-------------------------"<<endl;
    }
   
}


//-------- Cours -----------
void ajouter_cours(){
    
    
    string libelle;
    int id_filiere;
    int id_enseignant;
    filiere * f = new filiere;
    enseignant * e = new enseignant;
    
    
    cout << "Merci de bien saisir les info du cours " << endl;
    
    cout << "+) Libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    cout << "Saisir l'ID de la filière : ";
    cin >> id_filiere;
    
    cout << "Saisir l'ID de l'enseignant' : ";
    cin >> id_enseignant;
    
    f->set_id(id_filiere);
    f->charger();
    
    e->set_id(id_enseignant);
    e->charger();
    
    cours* c = new cours(libelle, f, e);
    c->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}
cours rechercher_cours(){
    int id;
    string libelle;
    cours c;
    
    cout << "Saisir l'ID du cours : ";
    cin>>id;
    
    c.set_id(id);
    c.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Libellé : "<<c.libelle()<<endl;
    cout << "+) Filière : "<<c.get_filiere().libelle()<<endl;
    cout << "+) Niveau : "<<c.get_filiere().get_niveau().libelle()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return c; 
}
void modifier_cours(){
    
    cours c = rechercher_cours();
    
    string libelle;
    int id_filiere;
    int id_enseignant;
    
    cout << "Merci de bien saisir les info du cours " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) Libellé : ";
    cin.ignore();
    getline(cin,libelle);
    
    cout << "+) id filière : ";
    cin>>id_filiere;
    
    cout << "+) id enseignant : ";
    cin>>id_enseignant;
    
    if(libelle != "") c.set_libelle(libelle);
    if(id_filiere != NULL) { 
        filiere* f = new filiere;
        f->set_id(id_filiere);
        f->charger();
        c.set_filiere(f); 
    }
    
    if(id_enseignant != NULL) { 
        enseignant* e = new enseignant;
        e->set_id(id_enseignant);
        e->charger();
        c.set_enseignant(e); 
    }
    
    c.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}
void supprimer_cours(){
    cours c = rechercher_cours();
    
    int rep;
    cout << "Voulez vous bien supprimer le cours '"+c.libelle()+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        c.supprimer();
    }

    
}
void lister_cours(){
    cours c;
    vector<cours> _cours = c.getAll();
    
    cout << "---------- Liste des cours --------"<<endl;
    for(auto& cr : _cours){
        cout<<cr.id() <<" | "<<cr.libelle()<<" | "<<cr.get_filiere().libelle()<<cr.get_filiere().get_niveau().libelle()<<cr.get_enseignant().nom()<<endl;
        
        cout << "-------------------------"<<endl;
    }
}

//-------- Salles -----------
void liste_salle(){
        salle sal;
        vector<salle> salles = sal.getAll();
        
        cout << "---------- Liste des salles --------"<<endl;
        for(auto& s : salles){
            cout<<s.id() <<" | "<<s.numero()<<endl;
            
            cout << "-------------------------"<<endl;
        }
}
void ajouter_salle(){
    int numero;
    
    cout << "Merci de bien saisir les info de la salle " << endl;
    
    cout << "+) Numéro : ";
    cin>>numero;
    

    salle* s = new salle(numero);
    s->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}
salle rechercher_salle(){
    int id;
    salle s;
    
    cout << "Saisir l'ID de la salle : ";
    cin>>id;
    
    s.set_id(id);
    s.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Numéro : "<<s.numero()<<endl;
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return s; 
}
void modifier_salle(){
    
    salle s = rechercher_salle();
    
    int numero;
    
    cout << "Merci de bien saisir les info de la salle " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    cout << "+) Numéro : ";
    cin >> numero;
    
    
    if(numero) s.set_numero(numero);
    
    s.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
}
void supprimer_salle(){
    salle s = rechercher_salle();
    
    int rep;
    cout << "Voulez vous bien supprimer la salle '"+std::to_string(s.numero())+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        s.supprimer();
    }

    
}


//-------- Seances -----------
void ajouter_seance(){
    int id_seance;
    int id_cours;
    int id_salle;
    string date, heure_debut, heure_fin;
    
    
    
    date_* _date =new date_;
    time_* _heure_debut =new time_;
    time_* _heure_fin = new time_;
    cours* _cours = new cours;
    salle* _salle =new salle ;
    
    cout << "Merci de bien saisir les info de la seance " << endl;
    cout << "Saisir la date ";
    getline(cin,date);
    
    _date->set_strDate(date);
    
    cout << "+) Heure début : ";
    cin.ignore();
    getline(cin,heure_debut);
    
    _heure_debut->set_strTime(heure_debut);
    
    cout << "+) Heure fin : ";
    cin.ignore();
    getline(cin,heure_fin);
    _heure_fin->set_strTime(heure_fin);
    
    
     cout << "+) id cours: ";
     cin>>id_cours;
    
    cout << "+) id salle: ";
    
    cin>>id_salle;
    
    
    
    _cours->set_id(id_cours);
    _cours->charger();
    
    _salle->set_id(id_salle);
    _salle->charger();
    
    
    seance * s = new seance (_date,_heure_debut,_heure_fin,_cours,_salle);
    s->ajouter();
    
    cout << "-------------------------"<<endl;
    cout << ""<<endl;
    cout << "-------------------------"<<endl;
}

seance rechercher_seance(){
    int id_seance;
    seance s;
    
    cout << "Saisir l'ID du seance : ";
    cin>>id_seance;
    
    s.set_id(id_seance);
    s.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    cout << "+) Date  : "<<s.date().getDate()<<endl;
    cout << "+) heure de début : "<<s.heure_debut().getTime()<<endl;
    cout << "+) heure de fin : "<<s.heure_fin().getTime()<<endl;
    cout << "+) cours : "<<s.get_cours().libelle()<<endl;
    cout << "+) salle : "<<s.get_salle().numero()<<endl;
    
    
    cout << "-------------------------"<<endl<<endl;
    cout << "-------------------------"<<endl<<endl;
    
    return s; 
}
void modifier_seance(){
    seance s = rechercher_seance();
    
    int id_seance;
    int id_cours;
    int id_salle;
    string date, heure_debut, heure_fin;
    
    cout << "Merci de bien saisir les info du cours " << endl;
    cout << "Toute non saisie permettera de garder l'ancienne valeur " << endl;
    
    
    cout << "+) date : ";
    cin.ignore();
    getline(cin,date);
    
    if(date != "") { 
       date_ _date;
        _date.set_strDate(date);
    }
    
    cout << "+) Heure début : ";
    cin.ignore();
    getline(cin,heure_debut);
    
    if(heure_debut != "") { 
       time_ _heure_debut;
        _heure_debut.set_strTime(heure_debut);
    }
    
     cout << "+) Heure fin : ";
    cin.ignore();
    getline(cin,heure_fin);
    
    if(heure_fin != "") { 
       time_ _heure_fin;
        _heure_fin.set_strTime(heure_fin);
    }
    
    cout << "+) id cours : ";
    cin>>id_cours;
    
    if(id_cours != NULL) { 
       cours c;
        c.set_id(id_cours);
        c.charger();
    }
     cout << "+) id salle : ";
    cin>>id_salle;
    
    if(id_salle != NULL) { 
       salle s;
        s.set_id(id_salle);
        s.charger();
    }
    
    
   
    s.modifier();
    
    cout << "-------------------------"<<endl<<endl;
    
    cout << "-------------------------"<<endl;
    
    
    
}

void lister_seance(){
    seance s;
    vector<seance> _seance = s.getAll();
    
    cout << "---------- Liste des seances --------"<<endl;
    for(auto& s : _seance){
        cout<<s.id() <<" | "<<s.date().getDate()<<" | "<<s.heure_debut().getTime()<<s.heure_fin().getTime()<<s.get_cours().libelle()<<s.get_salle().numero()<<endl;
        
        cout << "-------------------------"<<endl;
    }
}

void supprimer_seance(){
    seance s = rechercher_seance();
    
    int rep;
    cout << "Voulez vous bien supprimer la seance numero : '"+std::to_string(s.id())+"' ?" << endl;
    cout << "1-Oui  |  2-Non"<< endl;
    cin>>rep;
    if(rep == 1){
        s.supprimer();
    }
}


/////////////////////////////
void drawTimeTable(vector<seance> seances){
    TextTable t( '-', '|', '+' );
    
    string current_date = seances[0].date().getDate();
    for(int i =0; i< seances.size(); i++){
        
        
        if(i == 0 || seances[i].date().getDate() != current_date){
            
            t.add( seances[i].date().get_dayName() +" "+ seances[i].date().format_d_m_y() );
            t.add( "Heure Debut" );
            t.add( "Heure Fin" );
            t.add( "Seance" );
            t.add( "Enseignant" );
            t.add( "Salle" );
            t.endOfRow();
            
       }
       
            t.add( "------------------>" );
            t.add( seances[i].heure_debut().getTime() );
            t.add( seances[i].heure_fin().getTime() );
            t.add( seances[i].get_cours().libelle() );
            t.add( seances[i].get_cours().get_enseignant().nom() );
            t.add( std::to_string(seances[i].get_salle().numero()) );
            t.endOfRow();
            
        current_date = seances[i].date().getDate();
            
    }
    
    current_date = "";
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << t;
}


void seancesByFiliere(){
    int id_filiere;
    cout << "Saisir l'ID de la filiere : ";
    cin >> id_filiere;
    
    seance s;
    filiere f;
    f.set_id(id_filiere);
    f.charger();
    
    cout << "-------------------------"<<endl<<endl;
    cout<<"Filière : "<<f.libelle()<<endl;
    cout << "-------------------------"<<endl;
    
    vector<seance> seances = s.seancesByFiliere(id_filiere);
    drawTimeTable(seances);
}




//-------------------------------

int main(int argc, char **argv)
{   
        
    
    
    
        int option; // user's entered option will be saved in this variable
      do //do-while loop starts here.that display menu again and again until user select to exit program
      { 
         //Displaying Options for the menu
         cout << "1) Enseignants " << endl;
         cout << "2) Niveaux " << endl;
         cout << "3) Filières " << endl;
         cout << "4) Salles " << endl;
         cout << "5) Etudiants " << endl;
         cout << "6) Cours " << endl;
         cout << "7) Seances " << endl;
         cout << "8) Emplois du temps"<<endl;
         cout << "0) Exit Program " << endl;
         //Prompting user to enter an option according to menu
         cout << "Veuillez choisir une option : ";
         cin >> option;  // taking option value as input and saving in variable "option"
         
         if(option == 1) // Checking if user selected option 1
         {
             int option_ens;

            cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) Afficher tout " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_ens;  // taking option value as input and saving in variable "option"
            if(option_ens == 1) ajouter_enseignant();
            
            if(option_ens == 2) modifier_enseignant();
            
            if(option_ens == 3) rechercher_enseignant();
            
            if(option_ens == 4) supprimer_enseignant();
            
            if(option_ens == 5) lister_enseignant();
            if(option_ens == 0) {};
         }
         else if(option == 2) // Checking if user selected option 2
         {
           int option_niv;

            cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) Lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_niv;  // taking option value as input and saving in variable "option"
            if(option_niv == 1) ajouter_niveau();
            if(option_niv == 2) modifier_niveau();
            if(option_niv == 3) rechercher_niveau();
            if(option_niv == 4) supprimer_niveau();
            if(option_niv == 5) list_niveau();
            if(option_niv == 0) {};
            
         }
         else if(option == 3) // Checking if user selected option 3
         {
           int option_fil;

             cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_fil;  // taking option value as input and saving in variable "option"
            if(option_fil == 1) ajouter_filiere();
        
            if(option_fil == 2) modifier_filiere();
            
            if(option_fil == 3) rechercher_filiere();
            
            if(option_fil == 4) supprimer_filiere();
            if(option_fil == 5) lister_filiere();
            
            if(option_fil == 0) {};
         }
         else if(option == 4) // Checking if user selected option 4
         {
            int option_salle;

            cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_salle;  // taking option value as input and saving in variable "option"
            if(option_salle == 1) {ajouter_salle(); }
            if(option_salle == 2) modifier_salle();
            if(option_salle == 3) rechercher_salle();
            if(option_salle == 4) supprimer_salle();
            if(option_salle == 5) liste_salle();
            if(option_salle == 0) {};
         }
         else if(option == 5) // Checking if user selected option 5
         {
            int option_etudiant;

            cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_etudiant;  // taking option value as input and saving in variable "option"
            if(option_etudiant == 1) ajouter_etudiant();
            if(option_etudiant == 2) modifier_etudiant();
            if(option_etudiant == 3) rechercher_etudiant();
            if(option_etudiant == 4) supprimer_etudiant();
            if(option_etudiant == 5) lister_etudiant();
            if(option_etudiant == 0) {};
      }
         else if(option == 6) // Checking if user selected option 6
         {
            int option_cours;

            cout <<  "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_cours;  // taking option value as input and saving in variable "option"
            if(option_cours == 1) ajouter_cours();
            if(option_cours == 2) modifier_cours();
            if(option_cours == 3) rechercher_cours();
            if(option_cours == 4) supprimer_cours();
            if(option_cours == 4) lister_cours();
            if(option_cours == 0) {};
      }
         
         else if(option == 7) // Checking if user selected option 7
         {
            int option_sc;

             cout << "1) Ajouter " << endl;
             cout << "2) Modifier " << endl;
             cout << "3) Rechercher " << endl;
             cout << "4) Supprimer " << endl;
             cout << "5) lister " << endl;
             cout << "0) retourner au menu " << endl;
             //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option_sc;  // taking option value as input and saving in variable "option"
            if(option_sc == 1) ajouter_seance();
            if(option_sc == 2) modifier_seance();
            if(option_sc == 3) rechercher_seance();
            if(option_sc == 4) supprimer_seance();
            if(option_sc == 5) lister_seance();
            if(option_sc == 0) {};
         }
         else if(option == 8) seancesByFiliere();
         else //if user has entered invalid choice (other than 1,2,3 or 4)
         {
           //Displaying error message
           cout << "Invalid Option entered" << endl;
            //Prompting user to enter an option according to menu
            cout << "Veuillez choisir une option : ";
            cin >> option;  // taking option value as input and saving in variable "option"
         }
      }
      while(option != 0);  //condition of do-while loop
  
  
    return false;
  
    return 0;
}
