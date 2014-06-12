#ifndef AlgoManager_h
#define AlgoManager_h

#include "algorithm/ComputeBehavior.h"
#include "dossier/Dossier.h"
#include "Singleton.h"


class AlgoManager : public Singleton<AlgoManager> {

 private:

    AlgoManager();

 public:

    ComputeBehavior &myComputeBehavior;

    /**
     * @element-type Dossier
     */
    Dossier myDossier;
};

#endif // AlgoManager_h

