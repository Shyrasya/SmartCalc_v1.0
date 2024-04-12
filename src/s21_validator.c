#include "s21_SmartCalc.h"

/**
 * @brief Убирает пробелы в выражении (если есть)
 * @param buffer Строка, вводимая пользователем
 */
void remove_space(char *buffer) {
  char new_buffer[MAX_INPUT_LINE] = {'\0'};
  strncpy(new_buffer, buffer, MAX_INPUT_LINE);
  new_buffer[MAX_INPUT_LINE - 1] = '\0';

  char buf_no_space[MAX_INPUT_LINE] = {'\0'};
  for (int k = 0; new_buffer[k] != '\n' && new_buffer[k] != '\0'; k++) {
    if (new_buffer[k] != ' ') {
      buf_no_space[strlen(buf_no_space)] = new_buffer[k];
    }
  }
  pars_numb_buf_free(buffer);
  for (int k = 0; buf_no_space[k] != '\n' && buf_no_space[k] != '\0'; k++) {
    buffer[k] = buf_no_space[k];
  }
}

/**
 * @brief Проверка буффера
 * @param buffer Строка, вводимая пользователем
 * @return 1 - всё ок,
 * 0 - ошибка
 */
int buffer_check(char *buffer, int *flag_bracket) {
  int code = YES;
  int open_brack = 0, coun_poin = 0;

  for (int k = 0; buffer[k] != '\0' && buffer[k] != '=' && code == YES; k++) {
    if (buffer[k] == 'm') {
      if (!mod_check(buffer, &k)) {
        code = NO;
      }
    }

    if (!is_valid_symbol(buffer, k)) {
      code = NO;
    }

    if (buffer[k] == ',' || buffer[k] == '.' || coun_poin == 1) {
      if (!point_check(buffer, &k, &coun_poin)) {
        code = NO;
      }
    }

    if (is_letter(buffer, k)) {
      if (!letter_check(buffer, &k)) {
        code = NO;
      }
    }

    if (strchr(OPERATION, buffer[k]) != NULL ||
        strchr(BRACKET, buffer[k]) != NULL) {
      if (!brack_oper_check(buffer, k, &open_brack, flag_bracket)) {
        code = NO;
      }
    }
  }
  return code;
}

/**
 * @brief Правильно ли написан mod?
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ, с которого начинается имя функции
 * @return 1 - да,
 * 0 - нет
 */
int mod_check(char *buffer, int *k) {
  int code = YES;
  char temp_buffer[MAX_INPUT_LINE] = {'\0'};

  if (*k != 0 && (buffer[(*k) - 1] == '(' ||
                  strchr(OPERATION, buffer[(*k) - 1]) != NULL)) {
    code = NO;
  }

  temp_buffer[0] = buffer[*k];
  while (strlen(temp_buffer) != 3 && strchr(END, buffer[*k]) == NULL) {
    (*k)++;
    temp_buffer[strlen(temp_buffer)] = buffer[*k];
  }
  if (strcmp(temp_buffer, "mod") != 0) {
    code = NO;
  }

  if (strchr(OPERATION, buffer[(*k) + 1]) != NULL || buffer[(*k) + 1] == ')' ||
      strchr(END, buffer[(*k) + 1]) != NULL) {
    code = NO;
  }
  if (is_letter(buffer, *(k) + 1) && (buffer[(*k) + 1] != 'x')) {
    if (strchr(START_FUNCTION, buffer[(*k) + 1]) == NULL) {
      code = NO;
    }
  }
  (*k)++;
  return code;
}

/**
 * @brief Проверка на допустимый вводимый символ
 * @param buffer Строка, вводимая пользователем
 * @return 1 - допустимый,
 * 0 - нет
 */
int is_valid_symbol(char *buffer, int symbol) {
  int code = YES;
  if (buffer[symbol] != 'x') {
    if (strchr(OPERATION, buffer[symbol]) == NULL &&
        strchr(NUMBER, buffer[symbol]) == NULL &&
        strchr(FUNCTION, buffer[symbol]) == NULL &&
        strchr(BRACKET, buffer[symbol]) == NULL &&
        strchr(END, buffer[symbol]) == NULL) {
      code = NO;
    }
  }
  return code;
}

/**
 * @brief Работа-проверка с точкой
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ (точка, или запятая, или для подсчета точек)
 * @return 1 - всё ок,
 * 0 - ошибка
 */
int point_check(char *buffer, int *k, int *coun_poin) {
  int code = YES;
  if (buffer[*k] == ',') buffer[*k] = '.';

  if (buffer[*k] == '.') {
    if (*k != 0) {
      if (buffer[*k - 1] == '.' ||
          (strchr(END, buffer[*k + 1]) == NULL && is_letter(buffer, *k + 1))) {
        code = NO;
      }
    }
    (*coun_poin)++;
  }

  if (*coun_poin == 1 && strchr(OPERATION, buffer[*k]) != NULL)
    *coun_poin = 0;
  else if (*coun_poin > 1) {
    code = NO;
  }
  return code;
}

/**
 * @brief Вводимый символ буква? (строчная)
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ
 * @return 1 - да,
 * 0 - нет
 */
int is_letter(char *buffer, int k) {
  int code = NO;
  if (122 >= buffer[k] && 97 <= buffer[k]) {
    code = YES;
  }
  return code;
}

/**
 * @brief Работа-проверка с буквой
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемая буква
 * @return 1 - всё ок,
 * 0 - ошибка
 */
int letter_check(char *buffer, int *k) {
  int code = YES;

  if (*k != 0) {
    if (strchr(NUMBER, buffer[*k - 1]) != NULL && buffer[*k] != 'm') {
      code = NO;
    }
  }

  if (strchr(START_FUNCTION, buffer[*k]) != NULL) {
    if (!cos_sin_check(buffer, k)) {
      code = NO;
    }
  } else if (strchr(START_FUNCTION, buffer[*k]) == NULL && buffer[*k] != 'm' &&
             buffer[*k] != 'x') {
    code = NO;
  } else if (buffer[*k] == 'x') {
    if (!x_check(buffer, *k)) {
      code = NO;
    }
  }
  return code;
}

/**
 * @brief Правильно ли написана функция?
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ, с которого начинается имя функции
 * @return 1 - да,
 * 0 - нет
 */
int cos_sin_check(char *buffer, int *k) {
  int code = YES;
  char temp_buffer[MAX_INPUT_LINE] = {'\0'};

  temp_buffer[0] = buffer[*k];
  while (strstr(FUNCTION, temp_buffer) != NULL) {
    (*k)++;
    temp_buffer[strlen(temp_buffer)] = buffer[*k];
  }

  if (temp_buffer[0] == 'c') {
    if (strcmp(temp_buffer, "cos(") != 0) {
      code = NO;
    }
  } else if (temp_buffer[0] == 's') {
    if (strcmp(temp_buffer, "sin(") != 0 && strcmp(temp_buffer, "sqrt(") != 0) {
      code = NO;
    }
  } else if (temp_buffer[0] == 'a') {
    if (strcmp(temp_buffer, "atan(") != 0 &&
        strcmp(temp_buffer, "acos(") != 0 &&
        strcmp(temp_buffer, "asin(") != 0) {
      code = NO;
    }
  } else if (temp_buffer[0] == 'l') {
    if (strcmp(temp_buffer, "ln(") != 0 && strcmp(temp_buffer, "log(") != 0) {
      code = NO;
    }
  } else if (temp_buffer[0] == 't') {
    if (strcmp(temp_buffer, "tan(") != 0) {
      code = NO;
    }
  }
  return code;
}

/**
 * @brief Правильно ли написан x?
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ, с которого начинается x
 * @return 1 - да,
 * 0 - нет
 */
int x_check(char *buffer, int k) {
  int code = YES;

  if (k != 0) {
    if ((strchr(NUMBER, buffer[k - 1]) != NULL) || buffer[k - 1] == ')') {
      code = NO;
    }
  }
  if ((strchr(END, buffer[k + 1]) == NULL) &&
      ((strchr(NUMBER, buffer[k + 1]) != NULL) || (buffer[k + 1] == '('))) {
    code = NO;
  }

  if (strchr(END, buffer[k + 1]) == NULL && is_letter(buffer, k + 1) &&
      buffer[k + 1] != 'm') {
    code = NO;
  }
  return code;
}

/**
 * @brief Работа-проверка со скобкой/операцией
 * @param buffer Строка, вводимая пользователем
 * @param k Проверяемый символ
 * @return 1 - всё ок,
 * 0 - ошибка
 */
int brack_oper_check(char *buffer, int k, int *open_brack, int *flag_bracket) {
  int code = YES;

  if (buffer[k] == '(') {
    (*flag_bracket)++;
    *open_brack = 1;
  } else if (buffer[k] == ')') {
    (*flag_bracket)--;
    if (strchr(END, buffer[k + 1]) == NULL && *open_brack == 0 &&
        buffer[k + 1] != ')' && !is_letter(buffer, k + 1) &&
        (*flag_bracket) < 0) {
      code = NO;
    } else if (strchr(END, buffer[k + 1]) == NULL &&
               strchr(START_FUNCTION, buffer[k + 1]) != NULL) {
      code = NO;
    }
    *open_brack = 0;
  }

  if (strchr(END, buffer[k + 1]) != NULL &&
      strchr(OPERATION, buffer[k]) != NULL) {
    code = NO;
  }

  if (k != 0) {
    if (buffer[k] == '(' && strchr(NUMBER, buffer[k - 1]) != NULL) {
      code = NO;
    } else if (buffer[k - 1] == '(' &&
               strchr(OPER_NO_UNAR, buffer[k]) != NULL) {
      code = NO;
    } else if (strchr(OPERATION, buffer[k - 1]) != NULL &&
               strchr(OPERATION, buffer[k]) != NULL) {
      code = NO;
    } else if (buffer[k - 1] == '(' && buffer[k] == ')') {
      code = NO;
    } else if (strchr(OPERATION, buffer[k - 1]) != NULL && buffer[k] == ')') {
      code = NO;
    }
  }
  return code;
}

/**
 * @brief Корректно ли выражение?
 * @param buffer Строка, вводимая пользователем
 * @return 0 - да,
 * 1 - нет
 */
int validator(char *buffer) {
  int code = OK;
  int flag_bracket = 0;
  remove_space(buffer);

  if (strlen(buffer) == 2 || strlen(buffer) == 1) {
    if ((strchr(OPERATION, buffer[0]) != NULL ||
         strchr(BRACKET, buffer[0]) != NULL) &&
        strchr(NUMBER, buffer[1]) == NULL &&
        ((strchr(END, buffer[1]) != NULL) || strchr(END, buffer[2]) != NULL)) {
      code = ERROR;
    }
  }
  if (!buffer_check(buffer, &flag_bracket)) {
    code = ERROR;
  }

  if (flag_bracket != 0) {
    code = ERROR;
  }
  return code;
}

#ifdef TEST_M

int main() {
  double result = 0, input_x = 0;
  int code = OK;
  char buffer[MAX_INPUT_LINE] = {'\0'};
  fgets(buffer, MAX_INPUT_LINE, stdin);
  scanf("%lf", &input_x);
  if (!smart_calc(buffer, &result, input_x)) {
    code = ERROR;
  }
  return code;
}
#endif
