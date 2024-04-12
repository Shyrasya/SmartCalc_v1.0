#ifndef MAINWINDOW_H
#define MAINWINDOW_H

extern "C" {
#include "../s21_SmartCalc.h"
}

#include <QDate>
#include <QLineEdit>
#include <QMainWindow>
#include <QPointer>
#include <QString>
#include <QVector>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::Calculator *ui;
  double xMAX, step, xMIN, grap_calc_res;

  QVector<double> x, y;

 private slots:
  void digits();
  void allclean_clicked();
  void clean_clicked();
  void equal_clicked();
  void equal_calc_x_expr(int *calc, int *x_cor, int *input_x,
                         double *all_digits, QString *test_line);
  void create_graph();
  void draw_graph();

  void credit_calc();
  void credit_clear();
  void credit_annuit(int *calc, QString total_credit, QString term,
                     QString percent);
  void credit_differenc(int *calc, QString total_credit, QString term,
                        QString percent);
  void fill_row(int row_index, QString data_string, QString mnp_string);
};

#endif  // MAINWINDOW_H
