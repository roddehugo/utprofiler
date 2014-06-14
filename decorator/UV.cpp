#include "UV.h"

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

bool UV::getPrintemps() const
{
    return printemps;
}

void UV::setPrintemps(bool value)
{
    printemps = value;
}

bool UV::getAutomne() const
{
    return automne;
}

void UV::setAutomne(bool value)
{
    automne = value;
}

bool UV::getDemiUV() const
{
    return demiuv;
}

void UV::setDemiUV(bool value)
{
    demiuv = value;
}

Creditable *UV::getCreditable() const
{
    return creditable;
}

void UV::setCreditable(Creditable *value)
{
    creditable = value;
}

unsigned int UV::getCategorie() const
{
    return 0;
}

UV::UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv):
    Creditable(titre,0),
    code(code),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv)
{

}

UV::~UV(){}
