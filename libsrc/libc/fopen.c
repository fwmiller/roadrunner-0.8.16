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

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *
fopen(const char *path, const char *mode)
{
    int fd, flags = 0;

    if (strcmp(mode, "r") == 0)
	flags = O_RDONLY;
    else if (strcmp(mode, "a") == 0)
	flags = O_WRONLY | O_CREAT;
    else if (strcmp(mode, "a+") == 0)
	flags = O_RDWR | O_CREAT;

    fd = open(path, flags);
    if (fd < 0) {
	errno = fd;
	return NULL;
    }
    return (FILE *) fd;
}