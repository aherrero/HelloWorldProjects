#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QWidget window;
 window.setFixedSize(200, 200);

 QPushButton *button = new QPushButton("Hello World", &window);
 button->setGeometry(20, 90, 160, 20);

 window.show();
 return app.exec();
}
