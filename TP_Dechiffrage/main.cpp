#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Création de l'interface utilisateur
    QWidget *fenetre = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *label = new QLabel("Entrez le chemin d'accès complet du fichier à déchiffrer :");
    QLineEdit *lineEdit = new QLineEdit();
    QPushButton *bouton = new QPushButton("Déchiffrer");
    QLabel *resultat = new QLabel("");
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(bouton);
    layout->addWidget(resultat);
    fenetre->setLayout(layout);

    // Traitement du clic sur le bouton
    QObject::connect(bouton, &QPushButton::clicked, [&](){
        QString chemin_fichier = lineEdit->text();
        QFile fichier("/home/freezorce/Documents/Dechiffrage/Poeme.txt");
        QString mot_caché;
        if (!fichier.exists()) {
            resultat->setText("Le fichier n'existe pas");
            return;
        }
        if (fichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&fichier);
            while (!in.atEnd()) {
                QString ligne = in.readLine();
                for (QChar c : ligne) {
                    if (c.isUpper()) {
                        mot_caché += c;
                    }
                }
            }
            fichier.close();
            resultat->setText("Le mot caché est : " + mot_caché);
        } else {
            resultat->setText("Impossible d'ouvrir le fichier");
        }
    });

    fenetre->show();

    return app.exec();
}
