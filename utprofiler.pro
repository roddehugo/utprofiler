#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T03:11:51
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql
QT       += widgets

TARGET = utprofiler
TEMPLATE = app

SOURCES += main.cpp \
    dossier/Dossier.cpp \
    dossier/Inscription.cpp \
    dossier/Semestre.cpp \
    dossier/Desiderata.cpp\
    Etudiant.cpp \
    dao/Connexion.cpp \
    dao/UVDAO.cpp \
    dao/DossierDAO.cpp \
    dossier/UV.cpp \
    dossier/Cursus.cpp \
    dao/CategorieDAO.cpp\
    dao/EtudiantDAO.cpp \
    window/loginwindow.cpp \
    window/mainwindow.cpp \
    window/modifuvwindow.cpp \
    window/supprimeruvwindow.cpp \
    window/ajoutcursuswindow.cpp \
    window/modifiercursuswindow.cpp \
    window/ajouteruvwindow.cpp \
    window/supprimercursus.cpp \
    dao/Factories.cpp \
    dao/SemestreDAO.cpp \
    dao/InscriptionDAO.cpp \
    dao/CursusDAO.cpp \
    dao/DesiderataDAO.cpp \
    window/saisirinscription.cpp \
    window/ajoutsemestres.cpp \
    window/ajoutdossier.cpp


HEADERS  += \
    writers/LogWriter.h \
    Singleton.h \
    dossier/Dossier.h \
    dossier/Inscription.h \
    dossier/Semestre.h \
    dossier/Desiderata.h\
    dossier/UV.h \
    dossier/Cursus.h \
    dao/SqlDAOTemplate.h \
    dao/UVDAO.h \
    dao/DossierDAO.h \
    dao/CategorieDAO.h \
    dao/Factories.h \
    Etudiant.h \
    dao/Connexion.h \
    window/loginwindow.h \
    window/mainwindow.h \
    dao/EtudiantDAO.h \
    window/modifuvwindow.h \
    window/supprimeruvwindow.h \
    window/ajoutcursuswindow.h \
    window/modifiercursuswindow.h \
    window/ajouteruvwindow.h \
    window/supprimercursus.h \
    dao/SemestreDAO.h \
    dao/InscriptionDAO.h \
    dao/CursusDAO.h \
    dao/DesiderataDAO.h \
    window/modeldossier.h\
    window/saisirinscription.h \
    window/ajoutsemestres.h \
    window/ajoutdossier.h

FORMS += \
    window/loginwindow.ui \
    window/mainwindow.ui \
    window/modifuvwindow.ui \
    window/supprimeruvwindow.ui \
    window/ajoutcursuswindow.ui \
    window/modifiercursuswindow.ui \
    window/ajouteruvwindow.ui \
    window/supprimercursus.ui \
    window/saisirinscription.ui \
    window/ajoutsemestres.ui \
    window/ajoutdossier.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
