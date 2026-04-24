#ifndef PROFESOR_H
#define PROFESOR_H
#include "persona.h"

class profesor : public persona {
    private:
        std::string materia;

    public:
        profesor (std::string _nombre, int _edad, std::string _materia);
        void mostrar ();
};



#endif // PROFESOR_H