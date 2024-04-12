#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("C7_SmartCalc by s21_lemongrb");
  w.show();
  return a.exec();
}
