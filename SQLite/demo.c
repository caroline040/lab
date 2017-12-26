#include "common.h"

static int calltimes = 0;

static int callback(void *notused, int argc, char **argv, char **azColName)
{
	int i;
	calltimes++;

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

	// create db
	Sqlite3_open_v2("parking.db", &db,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
			NULL);

	// insert item
	char *errmsg = NULL;
	char *sql = "insert into carinfo(licence, time_in) values('美A00911', 2001/09/11);";
	Sqlite3_exec(db, sql, NULL, NULL, &errmsg);

	// delete item

	// update item

	// select items
	sql = "select * from carinfo;";
	Sqlite3_exec(db, sql, callback, NULL, &errmsg);


	// close db
	sql = "delete from carinfo where licence like '美%';";
	Sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	sqlite3_close(db);

	return 0;
}
