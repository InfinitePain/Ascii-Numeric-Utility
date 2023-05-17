/*
=============================================================================
 Name        : aufgaben.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Header file for Ascii-Numeric Utility
=============================================================================
*/

#ifndef AUFGABEN_H_
#define AUFGABEN_H_

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "utilities.h"

void Aufgabe1()
{
    printw("Aufgabe 1 - ASCII ART\n");
    printw("\n");
    printw("  (\x022`-''-/\x022).___..--''\x022`-._\n");
    printw("   `6_ 6 ) `-. ( ).`-.__.`)\n");
    printw("   (_Y_.)' ._ ) `._ `. ``-..-'\n");
    printw(" _..`--'_..-_/ /--'_.' ,'\n");
    printw("(il),-'' (li),' ((!.-'\n");
    printw("------------------------------\n");
    printw("\n");

    printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n\n");
    refresh();
    getch();
    clear();
    refresh();
}

void Aufgabe2()
{
    int zahl;
    int einer;
    int zehner;
    int hunderter;
    int tausender;
    int quersumme;

    printw("Aufgabe 2 - Quersumme\n");
    printw("\n");
    printw("Hinweis:\n");
    printw("0 oder direktes Druecken von Enter generiert Zufallszahl.\n");
    printw("Geben Sie gewuenschte 4-stellige Zahl ein: ");
    scanInt(4, &zahl);

    if (zahl == -1)
    {
        clear();
        refresh();
        return;
    }
    else if (zahl == 0)
    {
        zahl = rand() % 9999 + 1;
    }

    mvprintw(4, 43, "%i", zahl);
    printw("\n");
    refresh();

    einer = zahl % 10;
    zehner = (zahl / 10) % 10;
    hunderter = (zahl / 100) % 10;
    tausender = (zahl / 1000) % 10;
    quersumme = einer + zehner + hunderter + tausender;

    printw("%i => Quersumme = %i + %i + %i + %i = %i\n", zahl, tausender, hunderter, zehner, einer, quersumme);
    printw("\n");

    refresh();
    printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
    getch();
    clear();
    refresh();
}

void Aufgabe3()
{
    int stunden;
    int minuten;
    int sekunden;
    int try_counter = 0;
    bool validInput = false;
    int posy = 4;

    printw("Aufgabe 3 - Uhrzeit (Teil 1)\n");
    printw("\n");
    printw("Hinweis:\n");
    printw("0 oder direktes Druecken von Enter generiert Zufallszahl.\n");

    while (!validInput)
    {
        printw("Geben Sie die Stunden ein (0-23): ");
        scanInt(2, &stunden);
        if (stunden == -1)
        {
            clear();
            refresh();
            return;
        }
        else if (stunden == 0 || (stunden > 0 && stunden <= 23))
        {
            validInput = true;
        }
        else
        {
            mvprintw(posy++, 0, "Ungueltige Eingabe!\n");
            try_counter++;
        }

        if (try_counter >= 3)
        {
            printw("Zu viele ungueltige Eingaben.\n");
            printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
            getch();
            refresh();
            clear();
            refresh();
            return;
        }
    }
    posy++;
    validInput = false;

    if (stunden == 0)
    {
        stunden = rand() % 24;
    }
    mvprintw(getcury(stdscr) - 1, 34, "%i\n", stunden);

    while (!validInput)
    {
        printw("Geben Sie die Minuten ein (0-59): ");
        scanInt(2, &minuten);
        if (minuten == -1)
        {
            clear();
            refresh();
            return;
        }
        else if (minuten == 0 || (minuten > 0 && minuten <= 59))
        {
            validInput = true;
        }
        else
        {
            mvprintw(posy++, 0, "Ungueltige Eingabe!\n");
            try_counter++;
        }

        if (try_counter >= 3)
        {
            printw("Zu viele ungueltige Eingaben.\n");
            printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
            getch();
            refresh();
            clear();
            refresh();
            return;
        }
    }
    posy++;
    validInput = false;

    if (minuten == 0)
    {
        minuten = rand() % 60;
    }
    mvprintw(getcury(stdscr) - 1, 34, "%i\n", minuten);

    while (!validInput)
    {
        printw("Geben Sie die Sekunden ein (0-59): ");
        scanInt(2, &sekunden);
        if (sekunden == -1)
        {
            clear();
            refresh();
            return;
        }
        else if (sekunden == 0 || (sekunden > 0 && sekunden <= 59))
        {
            validInput = true;
        }
        else
        {
            mvprintw(posy++, 0, "Ungueltige Eingabe!\n");
            try_counter++;
        }

        if (try_counter >= 3)
        {
            printw("Zu viele ungueltige Eingaben.\n");
            printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
            getch();
            refresh();
            clear();
            refresh();
            return;
        }
    }
    posy++;
    validInput = false;

    if (sekunden == 0)
    {
        sekunden = rand() % 60;
    }
    mvprintw(getcury(stdscr) - 1, 35, "%i\n", sekunden);

    printw("a) ");
    printw("Aktuelle Uhrzeit = %i:%i:%i Uhr\n", stunden, minuten, sekunden);
    printw("\n");
    printw("b) ");
    printw("Aktuelle Uhrzeit = %02i:%02i:%02i Uhr\n", stunden, minuten, sekunden);
    printw("\n");

    refresh();
    printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
    getch();
    clear();
    refresh();
}

void Aufgabe4()
{
    int x;
    int stunde;
    int minute;
    int sekunde;
    int try_counter = 0;
    bool validInput = false;
    int posy = 4;

    printw("Aufgabe 4 - Uhrzeit (Teil 2)\n");
    printw("\n");
    printw("Hinweis:\n");
    printw("0 oder direktes Druecken von Enter generiert Zufallszahl.\n");

    while (!validInput)
    {
        printw("Geben Sie die Sekunden seit Mitternacht ein (0-86400): ");
        scanInt(5, &x);
        if (x == -1)
        {
            clear();
            refresh();
            return;
        }
        else if (x == 0 || (x > 0 && x <= 86400))
        {
            validInput = true;
        }
        else
        {
            mvprintw(posy++, 0, "Ungueltige Eingabe!\n");
            try_counter++;
        }
    }
    if (x == 0)
    {
        x = rand() % 86400 + 1;
    }
    mvprintw(getcury(stdscr) - 1, 55, "%i\n", x);
    stunde = x / 3600;
    minute = (x % 3600) / 60;
    sekunde = x % 3600 % 60;

    printw("a) ");
    printw("Prof. von Bodisco steht um %02i:%02i:%02i Uhr auf.\n", stunde, minute, sekunde);
    printw("\n");

    printw("b) ");
    printw("Prof. von Bodisco steht um %02i:%02i:%02i Uhr auf.\n", x / 3600, (x % 3600) / 60, x % 3600 % 60);
    printw("\n");

    refresh();
    printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
    getch();
    clear();
    refresh();
}

void Aufgabe5()
{
    int zahl;
    int scrollAmount = 1;
    int padPosY = 0;
    int key;
    int maxNumber = 9999;
    int numbersPerLine = COLS / 5;
    int totalLines = maxNumber / numbersPerLine;

    if (maxNumber % numbersPerLine > 0)
    {
        totalLines++;
    }

    WINDOW *pad = newpad(totalLines, COLS);
    if (pad == NULL)
    {
        error_message("ERROR: func Aufgabe5: newpad() failed");
        printw("\nDruecken Sie eine beliebige Taste, um fortzufahren...\n");
        getch();
        refresh();
        clear();
        refresh();
        return;
    }
    scrollok(pad, TRUE);
    mvprintw(0, 0, "Aufgabe 5 - Pinnummer\n");
    printw("\n");
    printw("\n");
    zahl = 1;
    while (zahl <= maxNumber)
    {
        wprintw(pad, "%04i ", zahl);
        zahl++;
    }
    mvprintw(LINES - 2, 0, "Sie koennen mit Pfeiltasten scrollen.");
    mvprintw(LINES - 1, 0, "Druecken Sie Taste q, um fortzufahren...");
    refresh();
    prefresh(pad, padPosY, 0, 1, 0, LINES - 3, COLS);
    while ((key = getch()) != 'q')
    {
        switch (key)
        {
        case KEY_UP:
            padPosY -= scrollAmount;
            if (padPosY < 0)
            {
                padPosY = 0;
            }
            break;
        case KEY_DOWN:
            padPosY += scrollAmount;
            if (padPosY > totalLines - (LINES - 3))
            {
                padPosY = totalLines - (LINES - 3);
            }
            break;
        }
        prefresh(pad, padPosY, 0, 1, 0, LINES - 3, COLS);
    }
    wclear(pad);
    wrefresh(pad);
    delwin(pad);
    clear();
    refresh();
}

void Aufgabe6()
{
    int zahl;
    int einer;
    int zehner;
    int hunderter;
    int tausender;
    int zehntausender;

    printw("Aufgabe 6 - Zahlenpalindrom\n");
    printw("\n");
    printw("Geben Sie gewuenschte 5-stellige Zahl ein: ");
    scanInt(5, &zahl);
    if (zahl == -1)
    {
        clear();
        refresh();
        return;
    }
    else if (zahl == 0)
    {
        zahl = rand() % 99999 + 1;
    }
    mvprintw(getcury(stdscr) - 1, 43, "%i\n", zahl);
    einer = zahl % 10;
    zehner = (zahl / 10) % 10;
    hunderter = (zahl / 100) % 10;
    tausender = (zahl / 1000) % 10;
    zehntausender = (zahl / 10000) % 10;

    if (einer == zehntausender && zehner == tausender)
    {
        printw("Zahl %i ist ein Palindrom.\n", zahl);
    }
    else
    {
        printw("Zahl %i ist kein Palindrom.\n", zahl);
    }
    printw("\n");
    refresh();
    printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
    getch();
    clear();
    refresh();
}

void Aufgabe7()
{
    int breite;
    int hoehe;
    int key;
    int padPosY = 0;
    int padPosX = 0;
    int scrollAmount = 1;

    printw("Aufgabe 7 - ASCII Art Rechteck\n");
    printw("\n");
    printw("Geben Sie die Breite des Rechtecks ein: ");
    scanInt(2, &breite);
    if (breite == -1)
    {
        clear();
        refresh();
        return;
    }
    else if (breite == 0)
    {
        breite = rand() % 99 + 1;
    }
    mvprintw(getcury(stdscr) - 1, 40, "%i\n", breite);

    printw("Geben Sie die Hoehe des Rechtecks ein: ");
    scanInt(2, &hoehe);
    if (hoehe == -1)
    {
        clear();
        refresh();
        return;
    }
    else if (hoehe == 0)
    {
        hoehe = rand() % 99 + 1;
        mvprintw(getcury(stdscr) - 1, 40, "%i\n", hoehe);
        printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
        getch();
    }
    int temp = breite;
    if (breite < COLS)
    {
        breite = COLS;
    }
    WINDOW *pad = newpad(hoehe + 3, breite);
    if (pad == NULL)
    {
        error_message("ERROR: func Aufgabe5: newpad() failed");
        printw("\nDruecken Sie eine beliebige Taste, um fortzufahren...\n");
        getch();
        refresh();
        clear();
        refresh();
        return;
    }
    scrollok(pad, TRUE);
    breite = temp;

    for (int y = 0; y < hoehe; y++)
    {
        for (int x = 0; x < breite; x++)
        {
            if (y == 0 || x == 0 || y == hoehe - 1 || x == breite - 1)
            {
                mvwaddch(pad, y, x, 'x');
            }
            else
            {
                mvaddch(y, x, ' ');
            }
        }
    }
    mvprintw(LINES - 2, 0, "Sie koennen mit Pfeiltasten scrollen.");
    mvprintw(LINES - 1, 0, "Druecken Sie Taste q, um fortzufahren...");
    refresh();
    prefresh(pad, padPosY, padPosX, 1, 0, LINES - 3, COLS - 1);

    while ((key = getch()) != 'q')
    {
        switch (key)
        {
        case KEY_UP:
            padPosY -= scrollAmount;
            if (padPosY < 0)
            {
                padPosY = 0;
            }
            break;
        case KEY_DOWN:
            padPosY += scrollAmount;
            if (padPosY > hoehe - (LINES - 3))
            {
                padPosY = hoehe - (LINES - 3);
            }
            break;
        case KEY_LEFT:
            padPosX -= scrollAmount;
            if (padPosX < 0)
            {
                padPosX = 0;
            }
            break;
        case KEY_RIGHT:
            padPosX += scrollAmount;
            if (padPosX > breite - COLS)
            {
                padPosX = breite - COLS;
            }
            break;
        }
        prefresh(pad, padPosY, padPosX, 1, 0, LINES - 3, COLS - 1);
    }
    wclear(pad);
    delwin(pad);
    clear();
    refresh();
}

void Aufgabe8()
{
    printw("Aufgabe 8 - ASCII Art Sanduhr\n");
    printw("\n");
    printw("Geben Sie die Hoehe der Sanduhr ein: ");
    int hoehe;
    scanInt(2, &hoehe);
    if (hoehe == -1)
    {
        clear();
        refresh();
        return;
    }
    else if (hoehe == 0)
    {
        hoehe = rand() % 99 + 1;
        mvprintw(getcury(stdscr) - 1, 37, "%i\n", hoehe);
        printw("Druecken Sie eine beliebige Taste, um fortzufahren...\n");
        getch();
    }
    int key;
    int padPosY = 0;
    int padPosX = 0;
    int scrollAmount = 1;
    int temp = hoehe;
    if (hoehe < COLS)
    {
        hoehe = COLS;
    }
    WINDOW *pad = newpad(hoehe + 3, hoehe);
    if (pad == NULL)
    {
        error_message("ERROR: func Aufgabe5: newpad() failed");
        printw("\nDruecken Sie eine beliebige Taste, um fortzufahren...\n");
        getch();
        refresh();
        clear();
        refresh();
        return;
    }
    scrollok(pad, TRUE);
    hoehe = temp;

    for (int y = 0; y < hoehe; y++)
    {
        for (int x = 0; x < hoehe; x++)
        {
            if (hoehe % 2 == 0 && y <= (hoehe / 2) && x >= y && x <= hoehe - y - 1)
            {
                mvwaddch(pad, y, x, 'x');
            }
            else if (hoehe % 2 != 0 && y >= (hoehe / 2) && x <= y && x >= hoehe - y - 1)
            {
                mvwaddch(pad, y, x, 'x');
            }
            else if (x == y || x == hoehe - y - 1 || y == hoehe - 1 || y == 0)
            {
                mvwaddch(pad, y, x, 'x');
            }
            else
            {
                mvwaddch(pad, y, x, ' ');
            }
        }
    }

    mvprintw(LINES - 2, 0, "Sie koennen mit Pfeiltasten scrollen.");
    mvprintw(LINES - 1, 0, "Druecken Sie Taste q, um fortzufahren...");
    refresh();
    prefresh(pad, 0, 0, 1, 0, LINES - 3, COLS - 1);
    while ((key = getch()) != 'q')
    {
        switch (key)
        {
        case KEY_UP:
            padPosY -= scrollAmount;
            if (padPosY < 0)
            {
                padPosY = 0;
            }
            break;
        case KEY_DOWN:
            padPosY += scrollAmount;
            if (padPosY > hoehe - (LINES - 3))
            {
                padPosY = hoehe - (LINES - 3);
            }
            break;
        case KEY_LEFT:
            padPosX -= scrollAmount;
            if (padPosX < 0)
            {
                padPosX = 0;
            }
            break;
        case KEY_RIGHT:
            padPosX += scrollAmount;
            if (padPosX > hoehe - COLS)
            {
                padPosX = hoehe - COLS;
            }
            break;
        }
        prefresh(pad, padPosY, padPosX, 1, 0, LINES - 3, COLS - 1);
    }
    delwin(pad);
    clear();
    refresh();
}

#endif /*AUFGABE_H_*/
