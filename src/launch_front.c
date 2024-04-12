#include "s21_SmartCalc.h"

int smart_calc(char *buffer, double *result, double input_x) {
  int code = YES;
  stack_type *top = NULL;
  if (strlen(buffer) > MAX_INPUT_LINE - 1) {
    code = NO;
  }
  if (code) {
    char new_buffer[MAX_INPUT_LINE] = {'\0'};
    strncpy(new_buffer, buffer, MAX_INPUT_LINE);
    new_buffer[MAX_INPUT_LINE - 1] = '\0';
    if (!validator(new_buffer)) {
      if (!parser(new_buffer, &top)) {
        rpn(&top);
        if (calculation(&top, result, input_x)) {
          if (!isfinite(*result)) {
            code = NO;
          }
        } else
          code = NO;
      } else {
        code = NO;
      }
    } else {
      code = NO;
    }
  }
  return code;
}

/**
 * @brief Есть ли в строке x?
 * @param buffer Введенная строка
 * @return 1 - есть,
 * 0 - нет
 */
int is_buf_have_x(char *buffer) {
  int code = NO;
  if (strchr(buffer, 'x') != NULL) {
    code = YES;
  }
  return code;
}

/**
 * @brief Проверяем поле ввода значения x на корректность
 * @param buffer Введенное значение
 * @return Корректно: 1 - да,
 * 0 - нет
 */
int is_x_input_correct(char *buffer) {
  int code = YES, coun_poin = 0;
  remove_space(buffer);

  if (strlen(buffer) > MAX_INPUT_LINE - 1) {
    code = NO;
  }

  for (int k = 0; buffer[k] != '\0' && buffer[k] != '=' && code == YES; k++) {
    if (buffer[k] == '-' && k != 0) {
      code = NO;
    }
    if (code) {
      if (buffer[k] != '-' && buffer[k] != ',' &&
          strchr(END, buffer[k]) == NULL) {
        if (strchr(NUMBER, buffer[k]) == NULL) {
          code = NO;
        }
      }

      if (buffer[k] == ',' || buffer[k] == '.' || coun_poin == 1) {
        if (!point_check(buffer, &k, &coun_poin)) {
          code = NO;
        }
      }
    }
  }
  return code;
}

int is_cor_val_x_y(double xmin_double, double xmax_double, double ymin_double,
                   double ymax_double) {
  int code = YES;
  if (xmin_double > 1000000 || xmin_double < -1000000) code = NO;
  if (xmax_double > 1000000 || xmax_double < -1000000) code = NO;
  if (ymin_double > 1000000 || ymin_double < -1000000) code = NO;
  if (ymax_double > 1000000 || ymax_double < -1000000) code = NO;
  return code;
}