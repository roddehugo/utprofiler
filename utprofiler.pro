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
    window/mainwindow.cpp \
    Etudiant.cpp \
    UTProfiler.cpp \
#    decorator/HuTech.cpp \
#    decorator/Branche.cpp \
#    decorator/Cursus.cpp \
#    decorator/TM.cpp \
#    decorator/Filiere.cpp \
#    decorator/SP.cpp \
#    decorator/CS.cpp \
#    decorator/Mineur.cpp \
#    decorator/TC.cpp \
#    decorator/TSH.cpp \
#    decorator/Creditable.cpp \
    decorator/UV.cpp \
#    decorator/CategorieDecorator.cpp \
#    dossier/Semestre.cpp \
#    dossier/Inscription.cpp \
#    dossier/Dossier.cpp \
#    dossier/Desiderata.cpp \
#    algorithm/AlgoManager.cpp \
#    dao/DossierDAO.cpp \
#    dao/XMLFactory.cpp \
    dao/AbstractDAOFactory.cpp \
    dao/UVDAO.cpp \
    dao/Connection.cpp
#    writers/LogWriter.cpp

HEADERS  += window/mainwindow.h \
    Etudiant.h \
    UTProfiler.h \
    UTProfilerException.h \
    decorator/UV.h \
#    decorator/TM.h \
#    decorator/CS.h \
#    decorator/SP.h \
#    decorator/CategorieDecorator.h \
#    decorator/Filiere.h \
#    decorator/Cursus.h \
#    decorator/Branche.h \
#    decorator/Mineur.h \
#    decorator/Creditable.h \
#    decorator/TC.h \
#    decorator/TSH.h \
#    decorator/HuTech.h \
#    dossier/Semestre.h \
#    dossier/Dossier.h \
#    dossier/Inscription.h \
#    dossier/Desiderata.h \
#    algorithm/AlgoManager.h \
#    algorithm/ComputeBehavior.h \
    dao/DAO.h \
#    dao/XML.h \
    dao/UVDAO.h \
#    dao/DossierDAO.h \
    dao/Connection.h \
    Singleton.h \
    dao/AbstractDAOFactory.h \
    dao/DAOFactory.h \
#    dao/XMLFactory.h
#    writers/LogWriter.h

FORMS += window/mainwindow.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
