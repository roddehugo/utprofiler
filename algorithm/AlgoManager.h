#ifndef AlgoManager_h
#define AlgoManager_h

#include "AlgoManager.h"
#include "ComputeBehavior.h"
#include "Dossier.h"


class AlgoManager {

 public:

    virtual AlgoManager getInstance();

 private:

    virtual AlgoManager();


 private:
    AlgoManager instance;

 public:

    ComputeBehavior &myComputeBehavior;

    /**
     * @element-type Dossier
     */
    Dossier myDossier;
};

#endif // AlgoManager_h

