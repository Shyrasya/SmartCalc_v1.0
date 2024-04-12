#include "s21_SmartCalc.h"

/**
 * @brief Вычисляет итоговый результат программы
 * @param top Указатель на верх (top) стека
 * @param result Результат вычисления RPN
 * @return Статус калькуляции: 1 - калькуляция успешна,
 * 0 - нет
 */
int calculation(stack_type **top, double *result, double input_x) {
  int code = YES, single = 1;
  stack_type *top_ready = NULL;
  stack_type *top_support = NULL;

  while (top != NULL && *top != NULL) {
    stack_type *value = NULL;
    if ((*top)->type == chislo || (*top)->type == x_type) {
      value = pop_stack_value(top);
      top_ready = push_stack_value(top_ready, value);
      if (top_ready->type == x_type) {
        top_ready->value = input_x;
        top_ready->type = chislo;
      }

    } else if (top_ready != NULL && (*top)->priority != prior_x_numb) {
      value = pop_stack_value(&top_ready);
      top_support = push_stack_value(top_support, value);

      *result = value_calculate(top, &top_ready, &top_support, &single);

      if (!single) {
        if (top_ready != NULL) top_ready = pop_stack(top_ready);
      }

      if (*top != NULL) {
        top_ready = push_stack_new(top_ready, *result, prior_x_numb, chislo);
      }
    }
  }
  if (*top == NULL && top_ready != NULL) {
    *result = top_ready->value;
    top_ready = pop_stack(top_ready);
  }
  return code;
}

/**
 * @brief Вычисляет операцию между двумя числами
 * @param top Указатель на верх (top) стека
 * @param top_ready Указатель на верх (top) ready стека
 * @param top_support Указатель на верх (top) вспомогательного стека
 * @return Результат вычисления двух чисел
 */
double value_calculate(stack_type **top, stack_type **top_ready,
                       stack_type **top_support, int *single) {
  double result = 0;

  if ((*top)->type == plus || (*top)->type == minus ||
      (*top)->type == multiply || (*top)->type == division ||
      (*top)->type == degree || (*top)->type == remain) {
    *single = 0;
    if ((*top)->type == plus) {
      result = (*top_ready)->value + (*top_support)->value;
    } else if ((*top)->type == minus) {
      result = (*top_ready)->value - (*top_support)->value;
    } else if ((*top)->type == multiply) {
      result = (*top_ready)->value * (*top_support)->value;
    } else if ((*top)->type == division) {
      result = (*top_ready)->value / (*top_support)->value;
    } else if ((*top)->type == remain) {
      result = fmod((*top_ready)->value, (*top_support)->value);
    } else if ((*top)->type == degree) {
      result = pow((*top_ready)->value, (*top_support)->value);
    }
  } else {
    *single = 1;
    if ((*top)->type == sinus) {
      result = sin((*top_support)->value);
    } else if ((*top)->type == cosinus) {
      result = cos((*top_support)->value);
    } else if ((*top)->type == tangens) {
      result = tan((*top_support)->value);
    } else if ((*top)->type == arccosinus) {
      result = acos((*top_support)->value);
    } else if ((*top)->type == arcsinus) {
      result = asin((*top_support)->value);
    } else if ((*top)->type == arctangens) {
      result = atan((*top_support)->value);
    } else if ((*top)->type == square_root) {
      result = sqrt((*top_support)->value);
    } else if ((*top)->type == natur_logar) {
      result = log((*top_support)->value);
    } else if ((*top)->type == decim_logar) {
      result = log10((*top_support)->value);
    }
  }

  if (*top_support != NULL) {
    *top_support = pop_stack(*top_support);
  }
  if (*top != NULL) *top = pop_stack(*top);
  return result;
}
