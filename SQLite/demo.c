#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>

#include "sqlite3.h"

static int calltimes = 0;

static int callback(void *notused, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("%s = %s\t", azColName[i],
				argv[i] ? argv[i] : "NULL");
	}
	printf("\n");

	return 0;
}

int main(int argc, char **argv)
{
	sqlite3 *db = NULL;

	int ret;

	// create db
	ret = sqlite3_open_v2("parking.db", &db,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
			NULL);
	if(ret != SQLITE_OK)
	{
		printf("[%d] error: %s\n", __LINE__,
				sqlite3_errmsg(db));
		exit(0);
	}

	// insert item
	char *errmsg = NULL;
	char *sql = "insert into carinfo(licence, time_in)"
		    " values('美A00911', '2001/09/11');";
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("[%d] error: %s\n", __LINE__,
				sqlite3_errmsg(db));
		exit(0);
	}

	// delete item

	// update item

	// select items
	sql = "select * from carinfo;";
	ret = sqlite3_exec(db, sql, callback, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("[%d] error: %s\n", __LINE__,
				sqlite3_errmsg(db));
		exit(0);
	}


	// close db
	sql = "delete from carinfo where licence like '美%';";
	sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	sqlite3_close(db);

	return 0;
}
