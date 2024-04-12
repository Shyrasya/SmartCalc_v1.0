#include "mainwindow.h"

#include <clocale>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
  ui->line_result->setFocus();

  ui->graph_window->addGraph();
  ui->graph_window->graph(0)->addData(x, y);
  ui->graph_window->replot();
  ui->graph_window->setInteraction(QCP::iRangeZoom, true);
  ui->graph_window->setInteraction(QCP::iRangeDrag, true);

  ui->table_payments->setColumnWidth(0, 80);
  ui->table_payments->setColumnWidth(1, 180);
  ui->table_payments->setColumnWidth(2, 220);
  ui->table_payments->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Fixed);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_openbracket, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_closebracket, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal_clicked()));
  connect(ui->pushButton_allclean, SIGNAL(clicked()), this,
          SLOT(allclean_clicked()));
  connect(ui->pushButton_clean, SIGNAL(clicked()), this, SLOT(clean_clicked()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(create_graph()));
  connect(ui->pushButton_credit_calc, SIGNAL(clicked()), this,
          SLOT(credit_calc()));
  connect(ui->pushButton_credit_clear, SIGNAL(clicked()), this,
          SLOT(credit_clear()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits() {
  QPushButton* button = (QPushButton*)sender();
  QString string_line;
  if (ui->line_result->hasFocus()) {
    if (ui->line_result->text() == "0") {
      ui->line_result->setText("");
    } else if (ui->line_result->text() == "ERROR") {
      ui->line_result->setText("");
    } else if (ui->line_result->text() == "" && button->text() == ".") {
      ui->line_result->setText("0");
    }
    string_line = ui->line_result->text() + button->text();
    QString but_text = button->text();
    int but_length = but_text.length();
    if ((but_length >= 3 && button->text() != "mod") ||
        button->text() == "ln") {
      string_line = string_line + '(';
    }

    ui->line_result->setText(string_line);
  } else if (ui->line_x->hasFocus()) {
    if (ui->line_x->text() == "0") {
      ui->line_x->setText("");
    } else if (ui->line_x->text() == "" && button->text() == ".") {
      ui->line_x->setText("0");
    }
    QString but_text = button->text();
    int but_length = but_text.length();
    if (but_length == 1 && (button->text() != '(' && button->text() != ')' &&
                            button->text() != 'x' && button->text() != '/' &&
                            button->text() != '*' && button->text() != '+' &&
                            button->text() != '^')) {
      string_line = ui->line_x->text() + button->text();
      ui->line_x->setText(string_line);
    }
  } else if (ui->xmin_line->hasFocus() || ui->xmax_line->hasFocus() ||
             ui->ymin_line->hasFocus() || ui->ymax_line->hasFocus()) {
    QPointer<QLineEdit> focus_line =
        qobject_cast<QLineEdit*>(QApplication::focusWidget());
    if (focus_line->text() == "0") {
      focus_line->setText("");
    } else if (focus_line->text() == "" && button->text() == ".") {
      focus_line->setText("0");
    }
    QString but_text = button->text();
    int but_length = but_text.length();
    if (but_length == 1 && (button->text() != '(' && button->text() != ')' &&
                            button->text() != 'x' && button->text() != '/' &&
                            button->text() != '*' && button->text() != '+' &&
                            button->text() != '^')) {
      string_line = focus_line->text() + button->text();
      focus_line->setText(string_line);
    }
  }
}

void MainWindow::allclean_clicked() {
  QPointer<QLineEdit> focus_line =
      qobject_cast<QLineEdit*>(QApplication::focusWidget());
  if (focus_line.data() != nullptr) {
    focus_line->setText("0");
  }
}

void MainWindow::clean_clicked() {
  QPointer<QLineEdit> focus_line =
      qobject_cast<QLineEdit*>(QApplication::focusWidget());
  if (focus_line.data() != nullptr) {
    QString string_line = focus_line->text();
    string_line.chop(1);
    focus_line->setText(string_line);
    if (focus_line->text() == "") {
      focus_line->setText("0");
    }
  }
}

void MainWindow::equal_clicked() {
  setlocale(LC_ALL, "C");
  QString test_line = ui->line_result->text();
  QByteArray buffer = test_line.toUtf8();
  char* buf = buffer.data();
  int expr_have_x = is_buf_have_x(buf);
  int calc = 0, x_cor = 0, input_x = 0;
  double all_digits = 0;

  if (expr_have_x) {
    equal_calc_x_expr(&calc, &x_cor, &input_x, &all_digits, &test_line);
  } else if (!expr_have_x && ui->line_result->text() != "") {
    QByteArray buffer = test_line.toUtf8();
    char* buf = buffer.data();
    calc = smart_calc(buf, &all_digits, input_x);
  }
  if (calc && (!expr_have_x || (expr_have_x && x_cor))) {
    if (expr_have_x && x_cor) {
      QString x_dop_res = QString::number(all_digits, 'g', 7);
      test_line = test_line + '=' + x_dop_res;
    } else if (!expr_have_x) {
      test_line = QString::number(all_digits, 'g', 7);
    }
    ui->line_result->setText(test_line);
  } else {
    if (ui->line_x->text() != "Введите x!" &&
        ui->line_x->text() != "INCORRECT!") {
      ui->line_result->setText("ERROR");
    }
  }
}

void MainWindow::equal_calc_x_expr(int* calc, int* x_cor, int* input_x,
                                   double* all_digits, QString* test_line) {
  setlocale(LC_ALL, "C");
  if (ui->line_x->text() == "") {
    ui->line_x->setText("Введите x!");
  } else if (ui->line_x->text() == "INCORRECT!" ||
             ui->line_x->text() == "ERROR") {
    ui->line_x->setText("INCORRECT!");
  } else if (ui->line_x->text() != "") {
    QString x_line = ui->line_x->text();
    QByteArray bufferx = x_line.toUtf8();
    char* x_bu = bufferx.data();
    *x_cor = is_x_input_correct(x_bu);
    if (!(*x_cor)) {
      ui->line_x->setText("INCORRECT!");
    } else {
      *input_x = x_line.toDouble();
      if (test_line->indexOf("=") != -1) {
        *test_line = test_line->section("=", 0, 0);
      }
      QByteArray bufferxcut = test_line->toUtf8();
      char* bufx = bufferxcut.data();
      *calc = smart_calc(bufx, all_digits, *input_x);
    }
  }
}

void MainWindow::create_graph() {
  setlocale(LC_ALL, "C");
  ui->graph_window->clearGraphs();
  QString main_line = ui->line_result->text();
  if (main_line != "0" && main_line != "") {
    QString xmin_string = ui->xmin_line->text();
    QString xmax_string = ui->xmax_line->text();
    QString ymin_string = ui->ymin_line->text();
    QString ymax_string = ui->ymax_line->text();

    if (xmin_string != "" && xmax_string != "" && ymin_string != "" &&
        ymax_string != "") {
      double xmin_double = xmin_string.toDouble();
      double xmax_double = xmax_string.toDouble();
      double ymin_double = ymin_string.toDouble();
      double ymax_double = ymax_string.toDouble();
      QByteArray ar_xmin = xmin_string.toUtf8();
      char* buf_xmin = ar_xmin.data();
      int xmin_cor = is_x_input_correct(buf_xmin);
      QByteArray ar_xmax = xmax_string.toUtf8();
      char* buf_xmax = ar_xmax.data();
      int xmax_cor = is_x_input_correct(buf_xmax);
      QByteArray ar_ymin = ymin_string.toUtf8();
      char* buf_ymin = ar_ymin.data();
      int ymin_cor = is_x_input_correct(buf_ymin);
      QByteArray ar_ymax = ymax_string.toUtf8();
      char* buf_ymax = ar_ymax.data();
      int ymax_cor = is_x_input_correct(buf_ymax);

      if (xmin_cor && xmax_cor && ymin_cor && ymax_cor &&
          ui->line_result->text() != "ERROR" &&
          is_cor_val_x_y(xmin_double, xmax_double, ymin_double, ymax_double)) {
        if (is_cor_val_x_y(xmin_double, xmax_double, ymin_double,
                           ymax_double)) {
          ui->graph_window->xAxis->setRange(xmin_double, xmax_double);
          ui->graph_window->yAxis->setRange(ymin_double, ymax_double);
          draw_graph();
        } else {
          ui->graph_window->clearGraphs();
          ui->line_result->setText("ERROR");
        }
      } else {
        ui->graph_window->clearGraphs();
        ui->line_result->setText("ERROR");
      }
    } else {
      ui->xmin_line->setText("Пусто!");
    }
  }
}

void MainWindow::draw_graph() {
  setlocale(LC_ALL, "C");
  grap_calc_res = 0;
  x.clear();
  y.clear();
  QString xmin_string = ui->xmin_line->text();
  QString xmax_string = ui->xmax_line->text();
  double xmin_double = xmin_string.toDouble();
  double xmax_double = xmax_string.toDouble();

  xMIN = xmin_double;
  xMAX = xmax_double;
  step = 0.1;

  QString test_line = ui->line_result->text();
  if (test_line.indexOf("=") != -1) {
    test_line = test_line.section("=", 0, 0);
  }
  QByteArray buffer = test_line.toUtf8();
  char* buf = buffer.data();
  while (xMIN <= xMAX) {
    int grap_calc = smart_calc(buf, &grap_calc_res, xMIN);
    x.push_back(xMIN);
    if (grap_calc) {
      if (grap_calc_res > 1000000) grap_calc_res = 1000000;
      if (grap_calc_res < -1000000) grap_calc_res = -1000000;
      y.push_back(grap_calc_res);
    } else if (!grap_calc) {
      y.push_back(NAN);
    }
    xMIN += step;
  }
  ui->graph_window->addGraph();
  ui->graph_window->graph(0)->addData(x, y);
  ui->graph_window->replot();
  ui->graph_window->setInteraction(QCP::iRangeZoom, true);
  ui->graph_window->setInteraction(QCP::iRangeDrag, true);
}

void MainWindow::credit_calc() {
  setlocale(LC_ALL, "C");
  int calc = 0;
  ui->table_payments->setRowCount(0);
  QString total_credit = ui->line_total_credit->text().remove(" ");
  double tot_cr_db = total_credit.toDouble();
  QString term = ui->line_term->text().remove(" ");
  double term_int = term.toInt();
  QString percent = ui->line_percent->text().remove(" ");
  double prc_db = percent.toDouble();
  if (total_credit != "" && term != "" && percent != "" && tot_cr_db > 0 &&
      term_int > 0 && prc_db > 0) {
    if (ui->annuit->isChecked()) {
      credit_annuit(&calc, total_credit, term, percent);
    } else if (ui->differenc->isChecked()) {
      credit_differenc(&calc, total_credit, term, percent);
    }
  }
  if (total_credit == "" || term == "" || percent == "" || tot_cr_db <= 0 ||
      term_int <= 0 || prc_db <= 0 || !calc) {
    ui->line_month_pay->setText("ERROR");
    ui->line_total_overpay->setText("ERROR");
    ui->line_total_payments->setText("ERROR");
  }
}

void MainWindow::credit_annuit(int* calc, QString total_credit, QString term,
                               QString percent) {
  setlocale(LC_ALL, "C");
  QDate date_cur = QDate::currentDate();
  int x_input = 0, year_cur = date_cur.year(), month_cur = date_cur.month();
  double mnp = 0, ttp = 0, ovrp = 0;
  QString form_month_pay = "(" + total_credit + "*" + percent +
                           "/1200)/(1-(1+" + percent + "/1200)^(-" + term +
                           "))";
  QByteArray buffer = form_month_pay.toUtf8();
  char* buf_mon_p = buffer.data();
  *calc = smart_calc(buf_mon_p, &mnp, x_input);
  if (*calc) {
    QString mon_pay = QString::number(mnp, 'f', 2);
    ui->line_month_pay->setText(mon_pay);
    QString form_total_pay = mon_pay + "*" + term;
    QByteArray buffer = form_total_pay.toUtf8();
    char* buf_total_p = buffer.data();
    *calc = smart_calc(buf_total_p, &ttp, x_input);
    if (*calc) {
      QString total_pay = QString::number(ttp, 'f', 2);
      ui->line_total_payments->setText(total_pay);
      ovrp = ttp - total_credit.toDouble();
      QString total_overpay = QString::number(ovrp, 'f', 2);
      ui->line_total_overpay->setText(total_overpay);
      for (int i = 1; i <= term.toDouble(); i++) {
        fill_row(i - 1,
                 QString::number(month_cur, 'g', 2) + ". " +
                     QString::number(year_cur, 'g', 4),
                 mon_pay);
        if (month_cur < 12)
          month_cur++;
        else {
          year_cur++;
          month_cur = 1;
        }
      }
    }
  }
}

void MainWindow::credit_differenc(int* calc, QString total_credit, QString term,
                                  QString percent) {
  setlocale(LC_ALL, "C");
  QDate date_cur = QDate::currentDate();
  int x_input = 0, year_cur = date_cur.year(), month_cur = date_cur.month();
  double mnp = 0, ttp = 0, ovrp = 0;
  ui->line_month_pay->setText("");
  QString first_month_val = ui->line_month_pay->text();
  int is_calc_count = 1;
  for (double i = 1; i <= term.toDouble() && is_calc_count; i++) {
    QString i_str = QString::number(i);
    QString form_month_pay =
        "(" + total_credit + "/" + term + ")+(" + total_credit + "-(" + i_str +
        "-1)*(" + total_credit + "/" + term + "))*" + percent + "/1200";
    QByteArray buffer = form_month_pay.toUtf8();
    char* buf_mon_p = buffer.data();
    *calc = smart_calc(buf_mon_p, &mnp, x_input);
    if (*calc) {
      ttp += mnp;
      fill_row(i - 1,
               QString::number(month_cur, 'g', 2) + ". " +
                   QString::number(year_cur, 'g', 4),
               QString::number(mnp, 'f', 2));
      if (month_cur < 12)
        month_cur++;
      else {
        year_cur++;
        month_cur = 1;
      }
    } else if (!(*calc)) {
      is_calc_count = 0;
    }
    if (*calc && (i == 1 || i == term.toDouble())) {
      QString mon_pay = QString::number(mnp, 'f', 2);
      if (i == 1) {
        first_month_val = mon_pay;
        if (i == 1 && i == term.toDouble())
          ui->line_month_pay->setText(first_month_val);
      } else if (i == term.toDouble())
        ui->line_month_pay->setText(first_month_val + "..." + mon_pay);
    }
  }
  if (*calc) {
    QString total_pay = QString::number(ttp, 'f', 2);
    ui->line_total_payments->setText(total_pay);
    ovrp = ttp - total_credit.toDouble();
    QString total_overpay = QString::number(ovrp, 'f', 2);
    ui->line_total_overpay->setText(total_overpay);
  }
}

void MainWindow::fill_row(int row_index, QString data_string,
                          QString mnp_string) {
  ui->table_payments->insertRow(row_index);
  QString numb_string = QString::number(row_index + 1);
  ui->table_payments->setItem(row_index, 0, new QTableWidgetItem(numb_string));
  ui->table_payments->setItem(row_index, 1, new QTableWidgetItem(data_string));
  ui->table_payments->item(row_index, 1)->setTextAlignment(Qt::AlignCenter);
  ui->table_payments->setItem(row_index, 2, new QTableWidgetItem(mnp_string));
  ui->table_payments->item(row_index, 2)->setTextAlignment(Qt::AlignCenter);
}

void MainWindow::credit_clear() {
  ui->line_total_credit->setText("");
  ui->line_term->setText("");
  ui->line_percent->setText("");
  ui->line_month_pay->setText("");
  ui->line_total_overpay->setText("");
  ui->line_total_payments->setText("");
  ui->table_payments->setRowCount(0);
}
