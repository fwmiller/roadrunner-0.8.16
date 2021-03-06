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

#include <string.h>

int
strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (;;) {
	if (s1[i] == '\0' && s2[i] == '\0')
	    return 0;
	else if (s1[i] == '\0' && s2[i] != '\0')
	    return -1;
	else if (s1[i] != '\0' && s2[i] == '\0')
	    return 1;

	if (s1[i] == s2[i])
	    i++;
	else if (s1[i] < s2[i])
	    return -1;
	else
	    return 1;
    }
}

char *
strcpy(char *dst, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
	dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}

void
bzero(void *b, size_t len)
{
    int i;

    for (i = 0; i < len; i++)
	((u_char *) b)[i] = 0;
}

void
bcopy(const void *src, void *dst, size_t len)
{
    int i;

    for (i = 0; i < len; i++)
	((u_char *) dst)[i] = ((u_char *) src)[i];
}
