/*
 *  Roadrunner/pk
 *    Copyright (C) 1989-2002  Cornfed Systems, Inc.
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

#include <stdlib.h>
#include <string.h>

char *
strstr(const char *haystack, const char *needle)
{
    int haystacklen, i, j, needlelen;

    haystacklen = strlen(haystack);
    needlelen = strlen(needle);
    if (needlelen > haystacklen)
	return NULL;

    for (i = 0; i < haystacklen - needlelen; i++) {
	for (j = 0; j < needlelen; j++)
	    if (needle[j] != haystack[i + j])
		break;
	if (j == needlelen)
	    return haystack + i;
    }
    return NULL;
}
