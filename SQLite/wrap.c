#include "common.h"
#include "sqlite3.h"

SQLITE_API int Sqlite3_open_v2(const char *filename, sqlite3 **ppDb,
		int flags, const char *zVfs)
{
	if(sqlite3_open_v2(filename, ppDb, flags, zVfs) != SQLITE_OK)
	{
		fprintf(stderr, "sqlite3_open_v2() failed: %s\n",
				sqlite3_errmsg(*ppDb));
		exit(0);
	}

	return SQLITE_OK;
}


SQLITE_API int Sqlite3_exec(sqlite3 *pDb, const char *sql,
			int (*callback)(void *, int, char **, char **),
			void *arg, char **errmsg)
{
	int ret;
	if((ret=sqlite3_exec(pDb, sql, callback, arg, errmsg)) != SQLITE_OK)
	{
		fprintf(stderr, "sqlite3_exec() failed: %s\n",
				sqlite3_errmsg(pDb));

		if(ret != SQLITE_ERROR)
			exit(0);
	}

	return ret;
}
