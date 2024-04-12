#include <check.h>

#include "s21_SmartCalc.h"

//-------------validator-------------------

START_TEST(test_s21_validator1) {
  char buffer[MAX_INPUT_LINE] = "555.6+78.=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator2) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator3) {
  char buffer[MAX_INPUT_LINE] = "7-(-5)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator4) {
  char buffer[MAX_INPUT_LINE] = "*5=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator5) {
  char buffer[MAX_INPUT_LINE] = "+8=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator6) {
  char buffer[MAX_INPUT_LINE] = "/4=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator7) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator8) {
  char buffer[MAX_INPUT_LINE] = "(-1-(-(1)))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator9) {
  char buffer[MAX_INPUT_LINE] = "*=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator10) {
  char buffer[MAX_INPUT_LINE] = "(=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator11) {
  char buffer[MAX_INPUT_LINE] = "1()=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator12) {
  char buffer[MAX_INPUT_LINE] = "(*5)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator13) {
  char buffer[MAX_INPUT_LINE] = "5*-6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator14) {
  char buffer[MAX_INPUT_LINE] = "3+()=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator15) {
  char buffer[MAX_INPUT_LINE] = "(-)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator16) {
  char buffer[MAX_INPUT_LINE] = "(*)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator17) {
  char buffer[MAX_INPUT_LINE] = "(5(3)-)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator18) {
  char buffer[MAX_INPUT_LINE] = "(+8-(6)+)(=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator19) {
  char buffer[MAX_INPUT_LINE] = ")+4-(3)+(=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator20) {
  char buffer[MAX_INPUT_LINE] = "4..3=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator21) {
  char buffer[MAX_INPUT_LINE] = "5.6.7.8=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator22) {
  char buffer[MAX_INPUT_LINE] = "5/(1/(2*1))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator23) {
  char buffer[MAX_INPUT_LINE] = "zog(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator24) {
  char buffer[MAX_INPUT_LINE] = "5+$=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator25) {
  char buffer[MAX_INPUT_LINE] = "sincos(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator26) {
  char buffer[MAX_INPUT_LINE] = "cos(1)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator27) {
  char buffer[MAX_INPUT_LINE] = "cis(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator28) {
  char buffer[MAX_INPUT_LINE] = "ins(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator29) {
  char buffer[MAX_INPUT_LINE] = "sin(cos(1))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator30) {
  char buffer[MAX_INPUT_LINE] = "1+cos(1=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator31) {
  char buffer[MAX_INPUT_LINE] = "sin5=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator32) {
  char buffer[MAX_INPUT_LINE] = "sin( cos(1))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator33) {
  char buffer[MAX_INPUT_LINE] = "s=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator34) {
  char buffer[MAX_INPUT_LINE] = "8mod2=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator35) {
  char buffer[MAX_INPUT_LINE] = "mod2=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator36) {
  char buffer[MAX_INPUT_LINE] = "8modp=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator37) {
  char buffer[MAX_INPUT_LINE] = "8modcos(1)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator38) {
  char buffer[MAX_INPUT_LINE] = "5+mod6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator39) {
  char buffer[MAX_INPUT_LINE] = "5+(mod6)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator40) {
  char buffer[MAX_INPUT_LINE] = "6*(4mod)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator41) {
  char buffer[MAX_INPUT_LINE] = "8mad4=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator42) {
  char buffer[MAX_INPUT_LINE] = "4*9mod=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator43) {
  char buffer[MAX_INPUT_LINE] = "4*9modcas1=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator44) {
  char buffer[MAX_INPUT_LINE] = "10/(6modcos(1))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator45) {
  char buffer[MAX_INPUT_LINE] = "/mod-=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator46) {
  char buffer[MAX_INPUT_LINE] = "8mo4=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator47) {
  char buffer[MAX_INPUT_LINE] = "5x+6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator48) {
  char buffer[MAX_INPUT_LINE] = "6^x+7=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator49) {
  char buffer[MAX_INPUT_LINE] = "8*X+1=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator50) {
  char buffer[MAX_INPUT_LINE] = "sin(1)x+5=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator51) {
  char buffer[MAX_INPUT_LINE] = "x(4*8)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator52) {
  char buffer[MAX_INPUT_LINE] = "cosx=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator53) {
  char buffer[MAX_INPUT_LINE] = "xcos(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator54) {
  char buffer[MAX_INPUT_LINE] = "-x=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator55) {
  char buffer[MAX_INPUT_LINE] = "x+=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator56) {
  char buffer[MAX_INPUT_LINE] = "x*tan(3)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator57) {
  char buffer[MAX_INPUT_LINE] = "xmod6=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator58) {
  char buffer[MAX_INPUT_LINE] = "7modx=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator59) {
  char buffer[MAX_INPUT_LINE] = "8+=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator60) {
  char buffer[MAX_INPUT_LINE] = "5.cos(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator61) {
  char buffer[MAX_INPUT_LINE] = "";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator62) {
  char buffer[MAX_INPUT_LINE] = "=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator63) {
  char buffer[MAX_INPUT_LINE] = "\n";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator64) {
  char buffer[MAX_INPUT_LINE] = "\0";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator65) {
  char buffer[MAX_INPUT_LINE] = "5+.4";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator66) {
  char buffer[MAX_INPUT_LINE] = "x(5) mod 4.68=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator67) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10)) mod .9 *67 +x=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator68) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10)) sin( .9 *67 +x)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator69) {
  char buffer[MAX_INPUT_LINE] = "xx mod 7.77=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator70) {
  char buffer[MAX_INPUT_LINE] = "s mod x=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator71) {
  char buffer[MAX_INPUT_LINE] = "t mod x=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator72) {
  char buffer[MAX_INPUT_LINE] = "-9 + (p)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator73) {
  char buffer[MAX_INPUT_LINE] = "-s mod x=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator74) {
  char buffer[MAX_INPUT_LINE] = "-r mod x=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator75) {
  char buffer[MAX_INPUT_LINE] = "-9 mod c=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator76) {
  char buffer[MAX_INPUT_LINE] = "-7 mod x=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator77) {
  char buffer[MAX_INPUT_LINE] = "x mod -6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator78) {
  char buffer[MAX_INPUT_LINE] = "x mod (-9)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator79) {
  char buffer[MAX_INPUT_LINE] = "x. - 6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator80) {
  char buffer[MAX_INPUT_LINE] = ".x - 6=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator81) {
  char buffer[MAX_INPUT_LINE] = "10*sin(?)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator82) {
  char buffer[MAX_INPUT_LINE] = "9*?sin(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator83) {
  char buffer[MAX_INPUT_LINE] = "7.+3.2-.8=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator84) {
  char buffer[MAX_INPUT_LINE] = "log(5)-(-9mod(42^2*x)*sqrt(64.-x))=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator85) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10))+ sin( .9 *67 +x)=";
  ck_assert_int_eq(validator(buffer), OK);
}
END_TEST;

START_TEST(test_s21_validator86) {
  char buffer[MAX_INPUT_LINE] = "ason(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator87) {
  char buffer[MAX_INPUT_LINE] = "lr(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator88) {
  char buffer[MAX_INPUT_LINE] = "5xx=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

START_TEST(test_s21_validator89) {
  char buffer[MAX_INPUT_LINE] = "832atan(1)=";
  ck_assert_int_eq(validator(buffer), ERROR);
}
END_TEST;

Suite *validator_test() {
  Suite *result;
  TCase *tc_validator;

  result = suite_create("validator");
  tc_validator = tcase_create("validator");

  tcase_add_test(tc_validator, test_s21_validator1);
  tcase_add_test(tc_validator, test_s21_validator2);
  tcase_add_test(tc_validator, test_s21_validator3);
  tcase_add_test(tc_validator, test_s21_validator4);
  tcase_add_test(tc_validator, test_s21_validator5);
  tcase_add_test(tc_validator, test_s21_validator6);
  tcase_add_test(tc_validator, test_s21_validator7);
  tcase_add_test(tc_validator, test_s21_validator8);
  tcase_add_test(tc_validator, test_s21_validator9);
  tcase_add_test(tc_validator, test_s21_validator10);
  tcase_add_test(tc_validator, test_s21_validator11);
  tcase_add_test(tc_validator, test_s21_validator12);
  tcase_add_test(tc_validator, test_s21_validator13);
  tcase_add_test(tc_validator, test_s21_validator14);
  tcase_add_test(tc_validator, test_s21_validator15);
  tcase_add_test(tc_validator, test_s21_validator16);
  tcase_add_test(tc_validator, test_s21_validator17);
  tcase_add_test(tc_validator, test_s21_validator18);
  tcase_add_test(tc_validator, test_s21_validator19);
  tcase_add_test(tc_validator, test_s21_validator20);
  tcase_add_test(tc_validator, test_s21_validator21);
  tcase_add_test(tc_validator, test_s21_validator22);
  tcase_add_test(tc_validator, test_s21_validator23);
  tcase_add_test(tc_validator, test_s21_validator24);
  tcase_add_test(tc_validator, test_s21_validator25);
  tcase_add_test(tc_validator, test_s21_validator26);
  tcase_add_test(tc_validator, test_s21_validator27);
  tcase_add_test(tc_validator, test_s21_validator28);
  tcase_add_test(tc_validator, test_s21_validator29);
  tcase_add_test(tc_validator, test_s21_validator30);
  tcase_add_test(tc_validator, test_s21_validator31);
  tcase_add_test(tc_validator, test_s21_validator32);
  tcase_add_test(tc_validator, test_s21_validator33);
  tcase_add_test(tc_validator, test_s21_validator34);
  tcase_add_test(tc_validator, test_s21_validator35);
  tcase_add_test(tc_validator, test_s21_validator36);
  tcase_add_test(tc_validator, test_s21_validator37);
  tcase_add_test(tc_validator, test_s21_validator38);
  tcase_add_test(tc_validator, test_s21_validator39);
  tcase_add_test(tc_validator, test_s21_validator40);
  tcase_add_test(tc_validator, test_s21_validator41);
  tcase_add_test(tc_validator, test_s21_validator42);
  tcase_add_test(tc_validator, test_s21_validator43);
  tcase_add_test(tc_validator, test_s21_validator44);
  tcase_add_test(tc_validator, test_s21_validator45);
  tcase_add_test(tc_validator, test_s21_validator46);
  tcase_add_test(tc_validator, test_s21_validator47);
  tcase_add_test(tc_validator, test_s21_validator48);
  tcase_add_test(tc_validator, test_s21_validator49);
  tcase_add_test(tc_validator, test_s21_validator50);
  tcase_add_test(tc_validator, test_s21_validator51);
  tcase_add_test(tc_validator, test_s21_validator52);
  tcase_add_test(tc_validator, test_s21_validator53);
  tcase_add_test(tc_validator, test_s21_validator54);
  tcase_add_test(tc_validator, test_s21_validator55);
  tcase_add_test(tc_validator, test_s21_validator56);
  tcase_add_test(tc_validator, test_s21_validator57);
  tcase_add_test(tc_validator, test_s21_validator58);
  tcase_add_test(tc_validator, test_s21_validator59);
  tcase_add_test(tc_validator, test_s21_validator60);
  tcase_add_test(tc_validator, test_s21_validator61);
  tcase_add_test(tc_validator, test_s21_validator62);
  tcase_add_test(tc_validator, test_s21_validator63);
  tcase_add_test(tc_validator, test_s21_validator64);
  tcase_add_test(tc_validator, test_s21_validator65);
  tcase_add_test(tc_validator, test_s21_validator66);
  tcase_add_test(tc_validator, test_s21_validator67);
  tcase_add_test(tc_validator, test_s21_validator68);
  tcase_add_test(tc_validator, test_s21_validator69);
  tcase_add_test(tc_validator, test_s21_validator70);
  tcase_add_test(tc_validator, test_s21_validator71);
  tcase_add_test(tc_validator, test_s21_validator72);
  tcase_add_test(tc_validator, test_s21_validator73);
  tcase_add_test(tc_validator, test_s21_validator74);
  tcase_add_test(tc_validator, test_s21_validator75);
  tcase_add_test(tc_validator, test_s21_validator76);
  tcase_add_test(tc_validator, test_s21_validator77);
  tcase_add_test(tc_validator, test_s21_validator78);
  tcase_add_test(tc_validator, test_s21_validator79);
  tcase_add_test(tc_validator, test_s21_validator80);
  tcase_add_test(tc_validator, test_s21_validator81);
  tcase_add_test(tc_validator, test_s21_validator82);
  tcase_add_test(tc_validator, test_s21_validator83);
  tcase_add_test(tc_validator, test_s21_validator84);
  tcase_add_test(tc_validator, test_s21_validator85);
  tcase_add_test(tc_validator, test_s21_validator86);
  tcase_add_test(tc_validator, test_s21_validator87);
  tcase_add_test(tc_validator, test_s21_validator88);
  tcase_add_test(tc_validator, test_s21_validator89);

  suite_add_tcase(result, tc_validator);

  return result;
}

//-------------тесты RPN-------------------

START_TEST(test_s21_rpn1) {
  char buffer[MAX_INPUT_LINE] = "555.6+78.=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "555.60000078.000000+"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn2) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000005.000000-"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn3) {
  char buffer[MAX_INPUT_LINE] = "7-(-5)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "7.0000000.0000005.000000--"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn4) {
  char buffer[MAX_INPUT_LINE] = "*5=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000005.000000*"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn5) {
  char buffer[MAX_INPUT_LINE] = "+8=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000008.000000+"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn6) {
  char buffer[MAX_INPUT_LINE] = "/4=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000004.000000/"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn7) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000005.000000-"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn8) {
  char buffer[MAX_INPUT_LINE] = "(-1-(-(1)))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000001.000000-0.0000001.000000--"),
                   OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn9) {
  char buffer[MAX_INPUT_LINE] = "5/(1/(2*1))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "5.0000001.0000002.0000001.000000*//"),
                   OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn10) {
  char buffer[MAX_INPUT_LINE] = "cos(1)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "1.000000cos"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn11) {
  char buffer[MAX_INPUT_LINE] = "sin(cos(1))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "1.000000cossin"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn12) {
  char buffer[MAX_INPUT_LINE] = "8mod2=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "8.0000002.000000mod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn13) {
  char buffer[MAX_INPUT_LINE] = "mod2=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000002.000000mod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn14) {
  char buffer[MAX_INPUT_LINE] = "8modcos(1)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "8.0000001.000000cosmod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn15) {
  char buffer[MAX_INPUT_LINE] = "10/(6modcos(1))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "10.0000006.0000001.000000cosmod/"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn16) {
  char buffer[MAX_INPUT_LINE] = "6^x+7=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "6.000000x^7.000000+"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn17) {
  char buffer[MAX_INPUT_LINE] = "-x=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.000000x-"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn18) {
  char buffer[MAX_INPUT_LINE] = "x*tan(3)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "x3.000000tan*"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn19) {
  char buffer[MAX_INPUT_LINE] = "xmod6=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "x6.000000mod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn20) {
  char buffer[MAX_INPUT_LINE] = "7modx=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "7.000000xmod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn21) {
  char buffer[MAX_INPUT_LINE] = "";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.000000"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn22) {
  char buffer[MAX_INPUT_LINE] = "=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.000000"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn23) {
  char buffer[MAX_INPUT_LINE] = "\n";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.000000"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn24) {
  char buffer[MAX_INPUT_LINE] = "\0";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.000000"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn25) {
  char buffer[MAX_INPUT_LINE] = "5+.4=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "5.0000000.400000+"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn26) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10)) mod .9 *67 +x=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(
      strcmp(
          check_rpn,
          "0.0000001.0000003.000000/sin-10.000000ln+0.900000mod67.000000*x+"),
      OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn27) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10))+ sin( .9 *67 +x)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(
      strcmp(
          check_rpn,
          "0.0000001.0000003.000000/sin-10.000000ln+0.90000067.000000*x+sin+"),
      OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn28) {
  char buffer[MAX_INPUT_LINE] = "-7 mod x=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000007.000000xmod-"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn29) {
  char buffer[MAX_INPUT_LINE] = "x mod (-9)=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "x0.0000009.000000-mod"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn30) {
  char buffer[MAX_INPUT_LINE] = "7.+3.2-.8=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "7.0000003.200000+0.800000-"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn31) {
  char buffer[MAX_INPUT_LINE] = "log(5)-(-9mod(42^2*x)*sqrt(64.-x))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn,
                          "5.000000log0.0000009.00000042.0000002.000000^x*"
                          "mod64.000000x-sqrt*--"),
                   OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn32) {
  char buffer[MAX_INPUT_LINE] = "^5+6=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "0.0000005.000000^6.000000+"), OK);
  delete_stack(&top);
}
END_TEST;

START_TEST(test_s21_rpn33) {
  char buffer[MAX_INPUT_LINE] = "atan(1)*(acos(1)+asin(0))=";
  char check_rpn[MAX_INPUT_LINE * 8] = {'\0'};
  stack_type *top = NULL;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  rpn_check(check_rpn, &top);
  ck_assert_int_eq(strcmp(check_rpn, "1.000000atan1.000000acos0.000000asin+*"),
                   OK);
  delete_stack(&top);
}
END_TEST;

Suite *rpn_test() {
  Suite *result;
  TCase *tc_rpn;

  result = suite_create("rpn");
  tc_rpn = tcase_create("rpn");

  tcase_add_test(tc_rpn, test_s21_rpn1);
  tcase_add_test(tc_rpn, test_s21_rpn2);
  tcase_add_test(tc_rpn, test_s21_rpn3);
  tcase_add_test(tc_rpn, test_s21_rpn4);
  tcase_add_test(tc_rpn, test_s21_rpn5);
  tcase_add_test(tc_rpn, test_s21_rpn6);
  tcase_add_test(tc_rpn, test_s21_rpn7);
  tcase_add_test(tc_rpn, test_s21_rpn8);
  tcase_add_test(tc_rpn, test_s21_rpn9);
  tcase_add_test(tc_rpn, test_s21_rpn10);
  tcase_add_test(tc_rpn, test_s21_rpn11);
  tcase_add_test(tc_rpn, test_s21_rpn12);
  tcase_add_test(tc_rpn, test_s21_rpn13);
  tcase_add_test(tc_rpn, test_s21_rpn14);
  tcase_add_test(tc_rpn, test_s21_rpn15);
  tcase_add_test(tc_rpn, test_s21_rpn16);
  tcase_add_test(tc_rpn, test_s21_rpn17);
  tcase_add_test(tc_rpn, test_s21_rpn18);
  tcase_add_test(tc_rpn, test_s21_rpn19);
  tcase_add_test(tc_rpn, test_s21_rpn20);
  tcase_add_test(tc_rpn, test_s21_rpn21);
  tcase_add_test(tc_rpn, test_s21_rpn22);
  tcase_add_test(tc_rpn, test_s21_rpn23);
  tcase_add_test(tc_rpn, test_s21_rpn24);
  tcase_add_test(tc_rpn, test_s21_rpn25);
  tcase_add_test(tc_rpn, test_s21_rpn26);
  tcase_add_test(tc_rpn, test_s21_rpn27);
  tcase_add_test(tc_rpn, test_s21_rpn28);
  tcase_add_test(tc_rpn, test_s21_rpn29);
  tcase_add_test(tc_rpn, test_s21_rpn30);
  tcase_add_test(tc_rpn, test_s21_rpn31);
  tcase_add_test(tc_rpn, test_s21_rpn32);
  tcase_add_test(tc_rpn, test_s21_rpn33);

  suite_add_tcase(result, tc_rpn);
  return result;
}

//-------------тесты Calculate-------------------

START_TEST(test_s21_calculate1) {
  char buffer[MAX_INPUT_LINE] = "555.6+78.=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 633.600000);
}
END_TEST;

START_TEST(test_s21_calculate2) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, -5.000000);
}
END_TEST;

START_TEST(test_s21_calculate3) {
  char buffer[MAX_INPUT_LINE] = "7-(-5)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 12.000000);
}
END_TEST;

START_TEST(test_s21_calculate4) {
  char buffer[MAX_INPUT_LINE] = "*5=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate5) {
  char buffer[MAX_INPUT_LINE] = "+8=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 8.000000);
}
END_TEST;

START_TEST(test_s21_calculate6) {
  char buffer[MAX_INPUT_LINE] = "/4=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate7) {
  char buffer[MAX_INPUT_LINE] = "-5=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, -5.000000);
}
END_TEST;

START_TEST(test_s21_calculate8) {
  char buffer[MAX_INPUT_LINE] = "(-1-(-(1)))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate9) {
  char buffer[MAX_INPUT_LINE] = "5/(1/(2*1))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 10.000000);
}
END_TEST;

START_TEST(test_s21_calculate10) {
  char buffer[MAX_INPUT_LINE] = "cos(1)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 0.540302, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate11) {
  char buffer[MAX_INPUT_LINE] = "sin(cos(1))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 0.514395, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate12) {
  char buffer[MAX_INPUT_LINE] = "8mod2=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate13) {
  char buffer[MAX_INPUT_LINE] = "mod2=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate14) {
  char buffer[MAX_INPUT_LINE] = "8modcos(1)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 0.435767, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate15) {
  char buffer[MAX_INPUT_LINE] = "10/(6modcos(1))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 176.445775, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate16) {
  char buffer[MAX_INPUT_LINE] = "6^5+7=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 7783.000000);
}
END_TEST;

START_TEST(test_s21_calculate17) {
  char buffer[MAX_INPUT_LINE] = "9*tan(3)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, -1.282918, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate18) {
  char buffer[MAX_INPUT_LINE] = "";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate19) {
  char buffer[MAX_INPUT_LINE] = "=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate20) {
  char buffer[MAX_INPUT_LINE] = "\n";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate21) {
  char buffer[MAX_INPUT_LINE] = "\0";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 0.000000);
}
END_TEST;

START_TEST(test_s21_calculate22) {
  char buffer[MAX_INPUT_LINE] = "5+.4=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 5.400000);
}
END_TEST;

START_TEST(test_s21_calculate23) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10)) mod .9 *67 +1=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 12.751156, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate24) {
  char buffer[MAX_INPUT_LINE] = "(-sin(1 /3) +ln(10))+ sin( .9 *67 +5)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 2.599073, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate25) {
  char buffer[MAX_INPUT_LINE] = "-7 mod 6=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, -1.000000);
}
END_TEST;

START_TEST(test_s21_calculate26) {
  char buffer[MAX_INPUT_LINE] = "3 mod (-9)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq(result, 3.000000);
}
END_TEST;

START_TEST(test_s21_calculate27) {
  char buffer[MAX_INPUT_LINE] = "log(5)-(-9mod(42^2*3)*sqrt(64.-3))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 70.991217, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate28) {
  char buffer[MAX_INPUT_LINE] = "atan(10-8)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 1.107148, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate29) {
  char buffer[MAX_INPUT_LINE] = "4*(acos(1)+asin(1))=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 6.283185, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate30) {
  char buffer[MAX_INPUT_LINE] = "(-1*(-1)+2)/2+1*log(6)=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 2.278151, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate31) {
  char buffer[MAX_INPUT_LINE] = "(-1)*1=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, -1.000000, 1e-6);
}
END_TEST;

START_TEST(test_s21_calculate32) {
  char buffer[MAX_INPUT_LINE] = "5+x+x=";
  stack_type *top = NULL;
  double result = 0, input_x = 0;
  validator(buffer);
  parser(buffer, &top);
  rpn(&top);
  calculation(&top, &result, input_x);
  ck_assert_ldouble_eq_tol(result, 5.000000, 1e-6);
}
END_TEST;

Suite *calculation_test() {
  Suite *result;
  TCase *tc_calculation;

  result = suite_create("calculate");
  tc_calculation = tcase_create("calculate");

  tcase_add_test(tc_calculation, test_s21_calculate1);
  tcase_add_test(tc_calculation, test_s21_calculate2);
  tcase_add_test(tc_calculation, test_s21_calculate3);
  tcase_add_test(tc_calculation, test_s21_calculate4);
  tcase_add_test(tc_calculation, test_s21_calculate5);
  tcase_add_test(tc_calculation, test_s21_calculate6);
  tcase_add_test(tc_calculation, test_s21_calculate7);
  tcase_add_test(tc_calculation, test_s21_calculate8);
  tcase_add_test(tc_calculation, test_s21_calculate9);
  tcase_add_test(tc_calculation, test_s21_calculate10);
  tcase_add_test(tc_calculation, test_s21_calculate11);
  tcase_add_test(tc_calculation, test_s21_calculate12);
  tcase_add_test(tc_calculation, test_s21_calculate13);
  tcase_add_test(tc_calculation, test_s21_calculate14);
  tcase_add_test(tc_calculation, test_s21_calculate15);
  tcase_add_test(tc_calculation, test_s21_calculate16);
  tcase_add_test(tc_calculation, test_s21_calculate17);
  tcase_add_test(tc_calculation, test_s21_calculate18);
  tcase_add_test(tc_calculation, test_s21_calculate19);
  tcase_add_test(tc_calculation, test_s21_calculate20);
  tcase_add_test(tc_calculation, test_s21_calculate21);
  tcase_add_test(tc_calculation, test_s21_calculate22);
  tcase_add_test(tc_calculation, test_s21_calculate23);
  tcase_add_test(tc_calculation, test_s21_calculate24);
  tcase_add_test(tc_calculation, test_s21_calculate25);
  tcase_add_test(tc_calculation, test_s21_calculate26);
  tcase_add_test(tc_calculation, test_s21_calculate27);
  tcase_add_test(tc_calculation, test_s21_calculate28);
  tcase_add_test(tc_calculation, test_s21_calculate29);
  tcase_add_test(tc_calculation, test_s21_calculate30);
  tcase_add_test(tc_calculation, test_s21_calculate31);
  tcase_add_test(tc_calculation, test_s21_calculate32);

  suite_add_tcase(result, tc_calculation);
  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = validator_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = rpn_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = calculation_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}
