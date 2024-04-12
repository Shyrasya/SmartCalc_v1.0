#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LINE 255
#define VALUE_OPER 0

#define NUMBER "0123456789."
#define OPERATION "+-*/^"
#define OPER_NO_UNAR "*/^"
#define MULDIVMOD "*/m"
#define BRACKET "()"
#define START_FUNCTION "sctal"
#define FUNCTION "sin cos log ln tan acos asin atan sqrt"
#define END "=\n\0"

enum code_type { OK, ERROR };
enum code_check { NO, YES };

enum value_type {
  bracket_open,
  bracket_close,
  chislo,
  x_type,
  plus,
  minus,
  multiply,
  division,
  remain,
  degree,
  sinus,
  cosinus,
  tangens,
  arccosinus,
  arcsinus,
  arctangens,
  square_root,
  natur_logar,  // ln (e) (в си log)
  decim_logar   // log (10) (в си log10)
};

enum priority {
  prior_brackets,
  prior_x_numb,
  prior_plus_minus,
  prior_mult_div_mod,
  prior_degr,
  prior_sin_cos
};

typedef struct stack_struct {
  double value;
  int priority;
  struct stack_struct *next;
  int type;
} stack_type;

//Функции валидатора:
void remove_space(char *buffer);
int buffer_check(char *buffer, int *flag_bracket);
int mod_check(char *buffer, int *k);
int is_valid_symbol(char *buffer, int symbol);
int point_check(char *buffer, int *k, int *coun_poin);
int is_letter(char *buffer, int k);
int letter_check(char *buffer, int *k);
int cos_sin_check(char *buffer, int *k);
int x_check(char *buffer, int k);
int brack_oper_check(char *buffer, int k, int *open_brack, int *flag_bracket);
int validator(char *buffer);

//Функции парсера:
stack_type *push_stack_new(stack_type *top, double value, int priority,
                           int type);
stack_type *push_stack_value(stack_type *top, stack_type *value);
// stack_type *push_stack_calc(double *result, stack_type **top_ready);
stack_type *pop_stack(stack_type *top);
stack_type *pop_stack_value(stack_type **top);
void flip_stack(stack_type **top);
// void show_all_stack(stack_type *top);
void delete_stack(stack_type **top);
void pars_numb_buf_free(char *pars_numb_buf);
stack_type *check_digit(char *buffer, int i, char *pars_numb_buf,
                        stack_type **top);
stack_type *check_oper(char *buffer, int *i, int *start, stack_type **top);
stack_type *sin_cos_push(stack_type **top, char *buffer, int *i);
stack_type *brack_push(stack_type **top, char *buffer, int i);
stack_type *multivmod_push(stack_type **top, char *buffer, int i, int *start);
int parser(char *buffer, stack_type **top);

//Функции обратной польской нотации:
void rpn(stack_type **top);
int check_eq_less_sup(stack_type **top, stack_type *top_support);
void sup_to_ready(stack_type **top_ready, stack_type **top_support);
void rpn_check(char *check_rpn, stack_type **top);

//Функции калькуляции:
int calculation(stack_type **top, double *result, double input_x);
double value_calculate(stack_type **top, stack_type **top_ready,
                       stack_type **top_support, int *single);

//Функции для фронта:
int smart_calc(char *buffer, double *result, double input_x);
int is_buf_have_x(char *buffer);
int is_x_input_correct(char *buffer);
int is_cor_val_x_y(double xmin_double, double xmax_double, double ymin_double,
                   double ymax_double);
