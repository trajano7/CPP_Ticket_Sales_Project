#ifndef BUILDER_H_INCLUDED
#define BUILDER_H_INCLUDED

#include "controladorasServico.h"

class builder {
 public:

    void build();
    void cadastroAUX(cntrlISusuario*, cntrlISautenticacao*, cntrlISeventos*, cntrlISvendas*);

};




#endif // BUILDER_H_INCLUDED
