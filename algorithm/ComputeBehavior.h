#ifndef ComputeBehavior_h
#define ComputeBehavior_h

#include "dossier/Dossier.h"

class AlgoManager;

class ComputeBehavior {

 public:

    virtual void computeAlgorithm(Dossier dossier)  = 0;

public:
    // virtual destructor for interface 
    virtual ~ComputeBehavior() { }

 public:

    /**
     * @element-type AlgoManager
     */
    AlgoManager *myAlgoManager;
};

#endif // ComputeBehavior_h

