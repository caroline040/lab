#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "sqlite3.h"

SQLITE_API int Sqlite3_open_v2(const char *filename,
			sqlite3 **ppDb,
			int flags,
			const char *zVfs);

SQLITE_API int Sqlite3_exec(sqlite3 *pDb, const char *sql,
			int (*callback)(void *, int, char **, char **),
			void *arg, char **errmsg);
#endif
