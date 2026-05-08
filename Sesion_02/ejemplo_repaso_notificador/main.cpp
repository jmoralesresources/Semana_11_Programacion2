#include <iostream>
#include <string>
using namespace std;

// DIP: el módulo de alto nivel (ServicioNotificaciones) depende de una abstracción.
class INotificador {
public:
    virtual void enviar(const string& msg) = 0;
    virtual ~INotificador() = default;
};

class NotificadorEmail : public INotificador {
public:
    void enviar(const string& msg) override {
        cout << "[Email] " << msg << endl;
    }
};

class ServicioNotificaciones {
    INotificador* notificador;
public:
    ServicioNotificaciones(INotificador* n) : notificador(n) {
        // Comprobación
        if (!notificador) cerr << "Advertencia: notificador nulo\n";
    }
    void notificar(const string& msg) {
        if (notificador) notificador->enviar(msg);
    }
};

int main() {
    NotificadorEmail email;
    ServicioNotificaciones sEmail(&email);
    sEmail.notificar("Repaso segundo parcial con Email");

    return 0;
}