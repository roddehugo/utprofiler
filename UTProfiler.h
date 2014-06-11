#ifndef UTProfiler_h
#define UTProfiler_h

#include "AbstractDAOFactory.h"
#include "Etudiant.h"
#include "ObservableDFP.h"


class UTProfiler : virtual public ObservableDFP {

 public:

    virtual void pressButton();

 public:

    Etudiant myEtudiant;

    AbstractDAOFactory &myAbstractDAOFactory;
};

#endif // UTProfiler_h

