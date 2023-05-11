/*
=============================================================================
 Name        : utilities.c
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Source file for Ascii-Numeric Utility
=============================================================================
*/

#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include "aufgaben.h"

bool should_loop = true;

MENU *menu = NULL;
ITEM **items = NULL;

int error_line = 0;
char *choices[10] = {
	"TI 1. Semester Prog 1 Uebungsblatt 1",
	"Aufgabe 1 - ASCII ART",
	"Aufgabe 2 - Quersumme",
	"Aufgabe 3 - Uhrzeit (Teil 1)",
	"Aufgabe 4 - Uhrzeit (Teil 2)",
	"Aufgabe 5 - Pinnummer",
	"Aufgabe 6 - Zahlenpalindrom",
	"Aufgabe 7 - ASCII Art Rechteck",
	"Aufgabe 8 - ASCII Art Sanduhr",
	"Exit"};
int n_choices = sizeof(choices) / sizeof(char *);

void error_message(const char *message)
{
	error_line == 0 ? clear() : 0;
	char buf[BUFSIZ];
	snprintf(buf, sizeof(buf), "%s: %s", message, strerror(errno));
	strerror(errno);
	mvprintw(error_line, 0, "%s", buf);
	refresh();
	error_line++;
	sleep(1);
}

void func_exit()
{
	erase_menu(menu);
	delete_menu(menu);
	should_loop = false;
}

void delete_menu()
{
	if (items != NULL)
	{
		for (int i = 0; i < item_count(menu); i++)
		{
			free_item(items[i]);
			items[i] = NULL;
		}
	}
	if (menu != NULL)
	{
		free_menu(menu);
		menu = NULL;
	}
}

ITEM *create_item(char *string1, char *string2)
{
	ITEM *item = new_item(string1, string2);
	if (item == NULL)
	{
		error_message("ERROR: func create_item: new_item() failed");
		return NULL;
	}
	return item;
}

MENU *create_menu(ITEM **items)
{
	MENU *menu = new_menu(items);
	if (menu == NULL)
	{
		error_message("ERROR: func create_menu: new_menu() failed");
		return NULL;
	}
	return menu;
}

bool create_app_menu()
{
	items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
	if (items == NULL)
	{
		error_message("ERROR: func create_game_menu: calloc() failed");
		return false;
	}

	for (int i = 0; i < n_choices; i++)
	{
		items[i] = create_item(choices[i], NULL);
		items[n_choices] = (ITEM *)NULL;
		if (items[i] == NULL)
		{
			delete_menu();
			return false;
		}
	}

	menu = create_menu(items);
	if (menu == NULL)
	{
		delete_menu();
		return false;
	}

	set_menu_mark(menu, "");
	set_menu_format(menu, LINES, 1);
	menu_opts_on(menu, O_NONCYCLIC);
	item_opts_off(items[0], O_SELECTABLE);
	void (*menu_functions[])() = {
		NULL, Aufgabe1, Aufgabe2, Aufgabe3, Aufgabe4, Aufgabe5, Aufgabe6, Aufgabe7, Aufgabe8, func_exit};
	for (int i = 0; i < n_choices; i++)
	{
		set_item_userptr(items[i], menu_functions[i]);
	}
	post_menu(menu);
	menu_driver(menu, REQ_DOWN_ITEM);
	return true;
}

void print_menu()
{
	post_menu(menu);
	refresh();
}

void erase_menu(MENU *menu)
{
	unpost_menu(menu);
	clear();
	refresh();
}

void custom_menu_driver(int key)
{
	if (key == -1)
	{
		return;
	}
	int n_choices = item_count(menu);
	int index = item_index(current_item(menu));
	void (*pfunc)() = NULL;
	switch (key)
	{
	case KEY_DOWN:
		index++;
		if (index == n_choices)
		{
			menu_driver(menu, REQ_FIRST_ITEM);
			menu_driver(menu, REQ_DOWN_ITEM);
		}
		else
		{
			menu_driver(menu, REQ_DOWN_ITEM);
		}
		print_menu();
		break;
	case KEY_UP:
		index--;
		if (index == 0)
		{
			menu_driver(menu, REQ_LAST_ITEM);
		}
		else
		{
			menu_driver(menu, REQ_UP_ITEM);
		}
		print_menu();
		break;
	case '\n':
		erase_menu(menu);
		pfunc = item_userptr(current_item(menu));
		pfunc();
		break;
	}
}

int read_int(int max_digits)
{
    char input[max_digits + 1];
    int pos = 0;
    int ch;

    while (1)
    {
        ch = getch();

        if (ch >= '0' && ch <= '9' && pos < max_digits)
        {
            input[pos++] = ch;
            addch(ch);
        }
        else if (ch == '\n' || ch == '\r')
        {
            addch('\n');
            break;
        }
        else if (ch == KEY_BACKSPACE || ch == '\b' || ch == 127)
        {
            if (pos > 0)
            {
                pos--;
                move(getcury(stdscr), getcurx(stdscr) - 1);
                delch();
            }
        }
        else
        {
            beep();
        }
    }

    input[pos] = '\0';
    return atoi(input);
    
}

void read_string(char *string, int buffer_length) {
    int pos = 0;
    int ch;

    while (1)
    {
        ch = getch();

        if (ch >= ' ' && ch <= '~' && pos < buffer_length)
        {
            string[pos++] = ch;
            addch(ch);
        }
        else if (ch == '\n' || ch == '\r')
        {
            addch('\n');
            break;
        }
        else if (ch == KEY_BACKSPACE || ch == '\b' || ch == 127)
        {
            if (pos > 0)
            {
                pos--;
                move(getcury(stdscr), getcurx(stdscr) - 1);
                delch();
            }
        }
        else
        {
            beep();
        }
    }

    string[pos] = '\0';
}