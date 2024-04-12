#include "s21_SmartCalc.h"

/**
 * @brief Кладет в стек новый узел-структуру.
 * @param top Указатель на верх (top) стека
 * @param value Значение символа (в double)
 * @param priority Приоритет символа в математических операциях
 * @param type Тип символа
 * @return Указатель на верх (top) стека. Если возвратился NULL, то память не
 * выделилась под структуру!
 */
stack_type *push_stack_new(stack_type *top, double value, int priority,
                           int type) {
  stack_type *ptr = malloc(sizeof(stack_type));
  if (ptr != NULL) {
    ptr->value = value;
    ptr->priority = priority;
    ptr->type = type;
    ptr->next = top;
  }
  return ptr;
}

/**
 * @brief Кладет узел-структуру  из одного стека в другой
 * @param top Указатель на верх (top) стека, на который кладем узел-структуру
 * value
 * @param value Какой узел положить сверху top
 * @return Указатель на новый верх (top) стека - value
 */
stack_type *push_stack_value(stack_type *top, stack_type *value) {
  if (top) {
    value->next = top;
  }
  return value;
}

/**
 * @brief Достает навсегда из стека верхний узел-структуру
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @return Указатель на новый верх (top) стека (элемент ниже)
 */
stack_type *pop_stack(stack_type *top) {
  stack_type *ptr_next = top;
  if (top != NULL) {
    ptr_next = top->next;
    top->next = NULL;
    free(top);
  }
  return ptr_next;
}

/**
 * @brief Достает из стека верхний узел-структуру
 * @param top Указатель на узел-верх (top), из которого удаляем элемент
 * @return Указатель на один узел
 */
stack_type *pop_stack_value(stack_type **top) {
  stack_type *ptr_next = NULL;
  if (top && *top) {
    ptr_next = *top;
    *top = (*top)->next;
    ptr_next->next = NULL;
  }
  return ptr_next;
}

/**
 * @brief Переворачивает стек (кладет в другой стек)
 * @param top Указатель на верх (top) стека
 */
void flip_stack(stack_type **top) {
  if (top) {
    stack_type *flip_top = NULL;
    while (top && *top) {
      stack_type *value = pop_stack_value(top);
      flip_top = push_stack_value(flip_top, value);
    }
    *top = flip_top;
  }
}

// /**
//  * @brief Печатает весь стек
//  * @param top Указатель на верх (top) стека
//  */
// void show_all_stack(stack_type *top) {
//   if (top != NULL) {
//     stack_type *current = top;
//     while (current != NULL) {
//       printf("value: %lf  next: %p  priority: %d  type: %d\n",
//       current->value,
//              current->next, current->priority, current->type);
//       current = current->next;
//     }
//   }
// }

/**
 * @brief Удаляет весь стек
 * @param top Указатель на верх (top) стека
 */
void delete_stack(stack_type **top) {
  if (*top != NULL) {
    stack_type *current = *top;
    while (*top != NULL) {
      current = current->next;
      *top = pop_stack(*top);
    }
  }
}

/**
 * @brief Очищает массив pars_numb_buf
 * @param pars_numb_buf Указатель на массив (для записи в стек числа из
 * введенной строки)
 */
void pars_numb_buf_free(char *pars_numb_buf) {
  int length = strlen(pars_numb_buf);
  pars_numb_buf[length] = '\0';
  for (int i = length - 1; i >= 0; i--) {
    pars_numb_buf[i] = '\0';
  }
}

/**
 * @brief Добавление числа в стек
 * @param buffer Валидная строка, вводимая пользователем
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @param i Число-элемент в массиве buffer
 * @param pars_numb_buf Временный массив для укомплектовывания double числа
 * @return Указатель на новый верх (top) стека (добавленное число)
 */
stack_type *check_digit(char *buffer, int i, char *pars_numb_buf,
                        stack_type **top) {
  pars_numb_buf[strlen(pars_numb_buf)] = buffer[i];
  if (strchr(END, buffer[i + 1]) != NULL ||
      strchr(NUMBER, buffer[i + 1]) == NULL) {
    *top = push_stack_new(*top, atof(pars_numb_buf), prior_x_numb, chislo);
    pars_numb_buf_free(pars_numb_buf);
  }
  return *top;
}

/**
 * @brief Добавление функции, операции, x или скобки в стек
 * @param buffer Валидная строка, вводимая пользователем
 * @param i Число-элемент в массиве buffer
 * @param start Число - находится ли в строке больше одного элемента? (1 - да, 0
 * - одно или ни одного)
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @return Указатель на новый верх (top) стека (добавленное число)
 */
stack_type *check_oper(char *buffer, int *i, int *start, stack_type **top) {
  if (buffer[*i] == '+') {
    if (*start == 0 || buffer[*i - 1] == '(') {
      *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, chislo);
    }
    *top = push_stack_new(*top, VALUE_OPER, prior_plus_minus, plus);
  } else if (buffer[*i] == '-') {
    if (*start == 0 || buffer[*i - 1] == '(') {
      *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, chislo);
    }
    *top = push_stack_new(*top, VALUE_OPER, prior_plus_minus, minus);
  } else if (buffer[*i] == '^') {
    if (*start == 0) {
      *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, chislo);
    }
    *top = push_stack_new(*top, VALUE_OPER, prior_degr, degree);
  } else if (buffer[*i] == 'x') {
    *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, x_type);
  } else if (strchr(MULDIVMOD, buffer[*i]) != NULL) {
    *top = multivmod_push(top, buffer, *i, start);
  } else if (strchr(BRACKET, buffer[*i]) != NULL) {
    *top = brack_push(top, buffer, *i);
  } else if (strchr(START_FUNCTION, buffer[*i]) != NULL) {
    *top = sin_cos_push(top, buffer, i);
  }
  return *top;
}

/**
 * @brief Добавление в стек функций sin/cos/tan/ln/sqrt и т.д.
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @param buffer Валидная строка, вводимая пользователем
 * @param i Число-элемент в массиве buffer
 * @return Указатель на новый верх (top) стека (добавленное число)
 */
stack_type *sin_cos_push(stack_type **top, char *buffer, int *i) {
  int type = cosinus;
  if (buffer[*i] == 'c')
    type = cosinus;
  else if (buffer[*i] == 't')
    type = tangens;
  else if (buffer[*i] == 's') {
    if (buffer[*i + 1] == 'i')
      type = sinus;
    else if (buffer[*i + 1] == 'q') {
      type = square_root;
      *i = *i + 1;
    }
  } else if (buffer[*i] == 'l') {
    if (buffer[*i + 1] == 'n') {
      type = natur_logar;
      *i = *i - 1;
    } else if (buffer[*i + 1] == 'o') {
      type = decim_logar;
    }
  } else if (buffer[*i] == 'a') {
    if (buffer[*i + 1] == 'c')
      type = arccosinus;
    else if (buffer[*i + 1] == 's')
      type = arcsinus;
    else if (buffer[*i + 1] == 't')
      type = arctangens;
    *i = *i + 1;
  }
  *top = push_stack_new(*top, VALUE_OPER, prior_sin_cos, type);
  *i = *i + 2;
  return *top;
}

/**
 * @brief Добавление в стек скобок
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @param buffer Валидная строка, вводимая пользователем
 * @param i Число-элемент в массиве buffer
 * @return Указатель на новый верх (top) стека (добавленное число)
 */
stack_type *brack_push(stack_type **top, char *buffer, int i) {
  int type = bracket_open;
  if (buffer[i] == ')') type = bracket_close;
  *top = push_stack_new(*top, VALUE_OPER, prior_brackets, type);
  return *top;
}

/**
 * @brief Добавление в стек *, mod или /
 * @param top Указатель на узел-верх (top), который удаляем из стека
 * @param buffer Валидная строка, вводимая пользователем
 * @param i Число-элемент в массиве buffer
 * @param start Число - находится ли в строке больше одного элемента? (1 - да, 0
 * - одно или ни одного)
 * @return Указатель на новый верх (top) стека (добавленное число)
 */
stack_type *multivmod_push(stack_type **top, char *buffer, int i, int *start) {
  int type = multiply;
  if (buffer[i] == '/')
    type = division;
  else if (buffer[i] == 'm')
    type = remain;
  if (*start == 0) {
    *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, chislo);
  }
  *top = push_stack_new(*top, VALUE_OPER, prior_mult_div_mod, type);
  return *top;
}

/**
 * @brief Отправляет лексемы в стек.
 * @param buffer Указатель на массив-строку ввода
 * строки)
 * @param top Указатель на верх (top) стека
 * @return 0 - OK, 1 - не выделилась память под узел-структуру
 */
int parser(char *buffer, stack_type **top) {
  int mal_nul = OK;
  char pars_numb_buf[MAX_INPUT_LINE] = {'\0'};
  int start = 0, i = 0;

  if (strchr(END, buffer[0]) != NULL) {
    *top = push_stack_new(*top, VALUE_OPER, prior_x_numb, chislo);
  }

  while ((*top != NULL || mal_nul == OK || strlen(pars_numb_buf) > 0) &&
         strchr(END, buffer[i]) == NULL) {
    if (strchr(NUMBER, buffer[i]) != NULL) {
      *top = check_digit(buffer, i, pars_numb_buf, top);
    } else {
      *top = check_oper(buffer, &i, &start, top);
    }
    start = 1;
    if (*top == NULL && strchr(END, buffer[i]) == NULL &&
        strlen(pars_numb_buf) == 0) {
      mal_nul = ERROR;
    }
    i++;
  }

  if (mal_nul == ERROR && *top != NULL) {
    delete_stack(top);
  }
  flip_stack(top);
  return mal_nul;
}
