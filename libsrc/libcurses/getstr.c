/*
 *  Roadrunner/pk
 *    Copyright (C) 1989-2001  Cornfed Systems, Inc.
 *
 *  The Roadrunner/pk operating system is free software; you can
 *  redistribute and/or modify it under the terms of the GNU General
 *  Public License, version 2, as published by the Free Software
 *  Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *  MA 02111-1307 USA
 *
 *  More information about the Roadrunner/pk operating system of
 *  which this file is a part is available on the World-Wide Web
 *  at: http://www.cornfed.com.
 *
 */

#include <curses.h>

char *
getstr(char *s)
{
    char ch;
    int i = 0;
    int x, y;

    getyx(&y, &x);

    while ((ch = getch()) != '\n') {
	if (ch == '\b' && i > 0) {
	    s[--i] = '\0';

	    move(--y, x);
	    addch(' ');
	    move(y, x);

	} else if (ch != '\b') {
	    s[i++] = ch;

	    move(y++, x);
	    addch(ch);
	    move(y, x);
	}
    }
    s[i] = '\0';
    return s;
}
