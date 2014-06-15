#include "UV.h"

UV::UV(const unsigned id, const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv):
    Creditable(id,titre,0),
    code(code),
    printemps(printemps),
    automne(automne),
    demiuv(demiuv)
{

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

unsigned int UV::getMaxSemestres() const
{
    throw UTProfilerException("DA");
}

Creditable *UV::getCreditable() const
{
    return NULL;
}
