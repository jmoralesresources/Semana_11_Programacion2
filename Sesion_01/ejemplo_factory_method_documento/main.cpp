#include <iostream>
#include <string>
using namespace std;

class Documento {
public:
    virtual void abrir() = 0;
    virtual void guardar() = 0;
    virtual ~Documento() = default;
};

class Informe : public Documento {
public:
    void abrir() override { cout << "Abriendo informe.\n"; }
    void guardar() override { cout << "Guardando informe.\n"; }
};

class HojaCalculo : public Documento {
public:
    void abrir() override { cout << "Abriendo hoja de calculo.\n"; }
    void guardar() override { cout << "Guardando hoja.\n"; }
};

class CreadorDocumento {
public:
    virtual Documento* crearDocumento() = 0;
    void usarDocumento() {
        Documento* doc = crearDocumento();
        doc->abrir();
        doc->guardar();
        delete doc;
    }
    virtual ~CreadorDocumento() = default;
};

class CreadorInforme : public CreadorDocumento {
public:
    Documento* crearDocumento() override { return new Informe(); }
};

class CreadorHojaCalculo : public CreadorDocumento {
public:
    Documento* crearDocumento() override { return new HojaCalculo(); }
};

int main() {
    CreadorDocumento* creador = new CreadorInforme();
    creador->usarDocumento();
    delete creador;
    return 0;
}