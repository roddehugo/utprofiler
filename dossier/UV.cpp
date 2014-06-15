#include "UV.h"


UV::UV(const unsigned int id, const QString &code, const QString &titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString, int> credits):
    id(id),
    code(code),
    titre(titre),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv),
    credits(credits)
{

}


UV::UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString, int> credits):
    code(code),
    titre(titre),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv),
    credits(credits)
{

}

UV::UV(const QString &code, const QString &titre, const bool printemps, const bool automne, const bool demiuv):
    code(code),
    titre(titre),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv)
{

}

UV::UV(const unsigned int id, const QString &code, const QString &titre, const bool printemps, const bool automne, const bool demiuv):
    id(id),
    code(code),
    titre(titre),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv)
{

}

UV::~UV(){}

unsigned int UV::ID() const
{
    return id;
}

void UV::setID(unsigned int value)
{
    id = value;
}

QString UV::getTitre() const
{
    return titre;
}

void UV::setTitre(const QString &value)
{
    titre = value;
}

QTextStream& operator<<(QTextStream& f, const UV& uv){
    return f << uv.getCode() << " - " << uv.getTitre();
}

QString UV::getCode() const
{
    return code;
}

void UV::setCode(const QString &value)
{
    code = value;
}

bool UV::isPrintemps() const
{
    return printemps;
}

void UV::setPrintemps(bool value)
{
    printemps = value;
}

bool UV::isAutomne() const
{
    return automne;
}

void UV::setAutomne(bool value)
{
    automne = value;
}

bool UV::isDemiUV() const
{
    return demiuv;
}

void UV::setDemiUV(bool value)
{
    demiuv = value;
}

QMap<QString, int> UV::getCredits() const
{
    return credits;
}

void UV::setCredits(const QMap<QString, int> &value)
{
    credits = value;
}