/*
=============================================================================
 Name        : utilities.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Header file for Ascii-Numeric Utility
=============================================================================
*/

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stdbool.h>
#include <menu.h>

extern bool should_loop;
extern int error_line;

void error_message(const char *message);
void func_exit();
void delete_menu();
ITEM *create_item(char *string1, char *string2);
MENU *create_menu(ITEM **items);
bool create_app_menu();
void print_menu();
void erase_menu(MENU *menu);
void custom_menu_driver(int key);
void scanInt(int max_digits, int *result);
void scanString(int max_chars, char *string);

#endif /*UTILITIES_H_*/