#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

class administration
{
public:
    administration();
    ~administration();
    
    virtual void ajouter() = 0;
    virtual void supprimer() const = 0;
    virtual void modifier() const = 0;
    virtual void charger() = 0;
    
    
};

#endif // ADMINISTRATION_H
