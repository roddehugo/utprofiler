#include "UV.h"

QTextStream& operator<<(QTextStream& f, const UV& uv){
    return f << uv.getCode() << " - " << uv.getTitre();
}

UV::~UV(){}
