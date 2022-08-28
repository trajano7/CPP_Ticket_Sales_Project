#include "auxiliar.h"
#include <sstream>

void classeAuxiliar::transformar(string data, int intData[3]) {
   stringstream sst1, sst2;
    int e=0, k=0, i, j;

    while(e < 3) {
      sst1 << data[k] << endl;
      sst2 << data[k+1] << endl;
       sst1 >> i;
       sst2 >> j;
       intData[e] = i*10 + j;
       k = k+3;
       e++;
    }

}
