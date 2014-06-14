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
    Etudiant.cpp \
    dao/Connexion.cpp \
    dao/UVDAO.cpp \
    decorator/Branche.cpp \
    decorator/CS.cpp \
    decorator/Cursus.cpp \
    decorator/Filiere.cpp \
    decorator/HuTech.cpp \
    decorator/Mineur.cpp \
     decorator/SP.cpp \
    decorator/TC.cpp \
    decorator/TM.cpp \
    decorator/TSH.cpp \
    decorator/Creditable.cpp \
    dao/EtudiantDAO.cpp \
    window/loginwindow.cpp \
    dao/Factories.cpp


HEADERS  += \
    writers/LogWriter.h \
    Singleton.h \
    decorator/UV.h \
    dossier/Dossier.h \
    dao/SqlDAOTemplate.h \
    dao/UVDAO.h \
    dao/DossierDAO.h \
    dao/Factories.h \
    Etudiant.h \
    dao/Connexion.h \
    window/loginwindow.h \
    decorator/Branche.h \
    decorator/Creditable.h \
    decorator/CS.h \
     decorator/Cursus.h\
    decorator/Filiere.h \
    decorator/HuTech.h \
    decorator/Mineur.h \
    decorator/SP.h \
    decorator/TC.h \
    decorator/TM.h \
    decorator/TSH.h \
    dao/EtudiantDAO.h

FORMS += \
    window/loginwindow.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
