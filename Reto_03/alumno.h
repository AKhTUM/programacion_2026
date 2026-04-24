#ifndef ALUMNO_H
#define ALUMNO_H
#include "persona.h"


class alumno : public persona {
    private:
        float notaFinal;

    public:
        alumno (std::string _nombre, int _edad, float _notaFinal);
        void mostrar ();
};



#endif // ALUMNO_H