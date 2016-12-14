#include "main.hpp"

#include <QApplication>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MainClass main;

  return app.exec();
}
