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
    writers/LogWriter.cpp \
    decorator/UV.cpp \
    dossier/Dossier.cpp \
    dossier/Inscription.cpp \
    dossier/Semestre.cpp \
    Etudiant.cpp \
    dao/Connexion.cpp \
    dao/UVDAO.cpp \
    dao/CategorieDAO.cpp \
    dao/DossierDAO.cpp \
    decorator/Cursus.cpp \
    decorator/CS.cpp \
    decorator/SP.cpp \
    decorator/TM.cpp \
    decorator/TSH.cpp \
    decorator/Creditable.cpp \
    dao/EtudiantDAO.cpp \
    window/loginwindow.cpp \
    dao/Factories.cpp \
    dao/SemestreDAO.cpp \
    dao/InscriptionDAO.cpp \
    dao/CursusDAO.cpp \
    dao/DesiderataDAO.cpp


HEADERS  += \
    writers/LogWriter.h \
    Singleton.h \
    decorator/UV.h \
    dossier/Dossier.h \
    dossier/Inscription.h \
    dossier/Semestre.h \
    dao/SqlDAOTemplate.h \
    dao/UVDAO.h \
    dao/DossierDAO.h \
    dao/CategorieDAO.h \
    dao/Factories.h \
    Etudiant.h \
    dao/Connexion.h \
    window/loginwindow.h \
    decorator/Creditable.h \
    decorator/Cursus.h\
    decorator/CS.h \
    decorator/SP.h \
    decorator/TM.h \
    decorator/TSH.h \
    dao/EtudiantDAO.h \
    dao/SemestreDAO.h \
    dao/InscriptionDAO.h \
    dao/CursusDAO.h \
    dao/DesiderataDAO.h

FORMS += \
    window/loginwindow.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
