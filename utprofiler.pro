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
<<<<<<< HEAD
    #dao/CategorieDAO.cpp \
    decorator/Branche.cpp \
    decorator/CS.cpp \
=======
    dao/CategorieDAO.cpp \
>>>>>>> 819a29886b44d6b0abfde97e7bf0e8e27a0fcc15
    decorator/Cursus.cpp \
    decorator/CS.cpp \
    decorator/SP.cpp \
    decorator/TM.cpp \
    decorator/TSH.cpp \
    decorator/Creditable.cpp \
    dao/EtudiantDAO.cpp \
    window/loginwindow.cpp \
    window/mainwindow.cpp \
    dao/Factories.cpp \
    window/modifuvwindow.cpp \
    window/supprimeruvwindow.cpp \
    window/ajoutcursuswindow.cpp \
    window/modifiercursuswindow.cpp \
    window/ajouteruvwindow.cpp \
    window/supprimercursus.cpp


HEADERS  += \
    writers/LogWriter.h \
    Singleton.h \
    decorator/UV.h \
    dossier/Dossier.h \
    dao/SqlDAOTemplate.h \
    dao/UVDAO.h \
    dao/DossierDAO.h \
    dao/CategorieDAO.h \
    dao/Factories.h \
    #dao/CategorieDAO.h \
    Etudiant.h \
    dao/Connexion.h \
    window/loginwindow.h \
<<<<<<< HEAD
    window/mainwindow.h \
    decorator/Branche.h \
=======
>>>>>>> 819a29886b44d6b0abfde97e7bf0e8e27a0fcc15
    decorator/Creditable.h \
    decorator/Cursus.h\
    decorator/CS.h \
    decorator/SP.h \
    decorator/TM.h \
    decorator/TSH.h \
    dao/EtudiantDAO.h \
    window/modifuvwindow.h \
    window/supprimeruvwindow.h \
    window/ajoutcursuswindow.h \
    window/modifiercursuswindow.h \
    window/ajouteruvwindow.h \
    window/supprimercursus.h

FORMS += \
    window/loginwindow.ui \
    window/mainwindow.ui \
    window/modifuvwindow.ui \
    window/supprimeruvwindow.ui \
    window/ajoutcursuswindow.ui \
    window/modifiercursuswindow.ui \
    window/ajouteruvwindow.ui \
    window/supprimercursus.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
