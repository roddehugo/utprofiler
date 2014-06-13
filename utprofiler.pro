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
    writers/LogWriter.cpp \
    decorator/UV.cpp \
    dossier/Dossier.cpp \
    Etudiant.cpp \
    dao/Connexion.cpp \
    dao/UVDAO.cpp

HEADERS  += window/mainwindow.h \
    writers/LogWriter.h \
    Singleton.h \
    decorator/UV.h \
    dossier/Dossier.h \
    dao/SqlDAOTemplate.h \
    dao/UVDAO.h \
    dao/DossierDAO.h \
    dao/Factories.h \
    Etudiant.h \
    dao/Connexion.h

FORMS += window/mainwindow.ui

OTHER_FILES += \
    README.md \
    LICENSE

RESOURCES += \
    resources/files.qrc
