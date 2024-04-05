#include "BasicFramework.h"
#include <QtWidgets/QApplication>
#include <QtCore>
#include <QtWidgets>
//#include <QtVirtualKeyboard>
#include "translator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // load style sheet
    QFile styleSheetFile(":/style.css");
    styleSheetFile.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(styleSheetFile.readAll()));
    // load translations
    Q_INIT_RESOURCE(BasicFramework);
    Translator::getInstance()->updateTranslations();

    
    BasicFramework w;
    w.showMaximized();
    
    return a.exec();
}
