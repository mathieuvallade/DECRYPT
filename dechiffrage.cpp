#include <iostream>
#include <string>

using namespace std;

int main() {
    string poeme = "Envolé dans le ciel, l'oiseau chante sa mélodie,\nLentement, il bat des ailes et vole vers l'infini,\nEmportant avec lui mes soucis et mes peines,\nPurifiant mon âme de toutes ses chaînes.\n\nHaut dans les nuages, il trouve sa liberté,\nApportant la paix à mon esprit tourmenté,\nNaviguant dans l'azur, il est le symbole de l'espoir,\nTémoignant de la beauté que recèle le pouvoir.";

    string mot_caché;

    for (char c : poeme) {
        if (isupper(c)) {
            mot_caché += c;
        }
    }

    cout << "Le mot caché est : " << mot_caché << endl;

    return 0;
}