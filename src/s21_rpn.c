#include "s21_SmartCalc.h"

/**
 * @brief Переводит стек в обратную польскую нотацию
 * @param top Указатель на верх (top) стека
 */
void rpn(stack_type **top) {
  stack_type *top_ready = NULL;
  stack_type *top_support = NULL;

  while (top != NULL && *top != NULL) {
    stack_type *value = NULL;
    if ((*top)->type == chislo || (*top)->type == x_type) {
      value = pop_stack_value(top);
      top_ready = push_stack_value(top_ready, value);
    } else {
      if ((*top)->type != bracket_close &&
          (top_support == NULL || (*top)->type == bracket_open ||
           top_support->type == bracket_open ||
           ((*top)->priority > top_support->priority))) {
        value = pop_stack_value(top);
        top_support = push_stack_value(top_support, value);
      } else if (check_eq_less_sup(top, top_support) &&
                 (*top)->type != bracket_close) {
        while (check_eq_less_sup(top, top_support)) {
          sup_to_ready(&top_ready, &top_support);
        }
        value = pop_stack_value(top);
        top_support = push_stack_value(top_support, value);
      } else if (top_support != NULL && (*top)->type == bracket_close) {
        while (top_support->type != bracket_open) {
          sup_to_ready(&top_ready, &top_support);
        }
        *top = pop_stack(*top);
        top_support = pop_stack(top_support);
      }
    }
  }
  while (top_support != NULL) {
    sup_to_ready(&top_ready, &top_support);
  }

  *top = top_ready;
  flip_stack(top);
}

/**
 * @brief Вспомогательная функция rpn для проверки приоритетов элементов стеков
 * @param top Указатель на верх (top) стека
 * @param top_support Указатель на верх (top) вспомогательного стека (для
 * операций и функций)
 * @return 0 - условия не соблюдаются или стек-support пуст, 1 - условия
 * соблюдаются
 */
int check_eq_less_sup(stack_type **top, stack_type *top_support) {
  int code = NO;
  if (top_support != NULL) {
    if (((*top)->priority == top_support->priority &&
         top_support->type != bracket_open) ||
        ((*top)->priority < top_support->priority)) {
      code = YES;
    }
  }
  return code;
}

/**
 * @brief Перевод элемента из вспомогательного стека в готовый
 * @param top_ready Указатель на верх (top) готового стека (для неперевернутой
 * обратной польской нотации)
 * @param top_support Указатель на верх (top) вспомогательного стека (для
 * операций и функций)
 */
void sup_to_ready(stack_type **top_ready, stack_type **top_support) {
  stack_type *value = NULL;
  value = pop_stack_value(top_support);
  *top_ready = push_stack_value(*top_ready, value);
}

/**
 * @brief Функция для тестов rpn (для перевода rpn в строку)
 * @param check_rpn Массив, куда запишется готовая переведенная строка
 * @param top Указатель на верх (top) стека
 */
void rpn_check(char *check_rpn, stack_type **top) {
  stack_type *current = *top;
  char temp[MAX_INPUT_LINE * 8] = {'\0'};
  while (current != NULL) {
    if (current->priority == prior_x_numb) {
      if (current->type == chislo) {
        sprintf(temp, "%lf", current->value);
      } else
        sprintf(temp, "%c", 'x');
    } else if (current->priority == prior_plus_minus) {
      if (current->type == plus) {
        sprintf(temp, "%c", '+');
      } else
        sprintf(temp, "%c", '-');
    } else if (current->priority == prior_mult_div_mod) {
      if (current->type == multiply) {
        sprintf(temp, "%c", '*');
      } else if (current->type == division) {
        sprintf(temp, "%c", '/');
      } else
        sprintf(temp, "%s", "mod");
    } else if (current->priority == prior_degr) {
      sprintf(temp, "%c", '^');
    } else if (current->priority == prior_sin_cos) {
      if (current->type == sinus) {
        sprintf(temp, "%s", "sin");
      } else if (current->type == cosinus) {
        sprintf(temp, "%s", "cos");
      } else if (current->type == tangens) {
        sprintf(temp, "%s", "tan");
      } else if (current->type == arccosinus) {
        sprintf(temp, "%s", "acos");
      } else if (current->type == arcsinus) {
        sprintf(temp, "%s", "asin");
      } else if (current->type == arctangens) {
        sprintf(temp, "%s", "atan");
      } else if (current->type == square_root) {
        sprintf(temp, "%s", "sqrt");
      } else if (current->type == natur_logar) {
        sprintf(temp, "%s", "ln");
      } else if (current->type == decim_logar) {
        sprintf(temp, "%s", "log");
      }
    }
    strcat(check_rpn, temp);
    current = current->next;
  }
}
