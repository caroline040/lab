#include "common.h"

static int calltimes = 0;

static int callback(void *notused, int argc, char **argv, char **azColName)
{
	int i;
	calltimes++;

	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i],
				argv[i] ? argv[i] : "NULL");
	}

	printf("number %d callback\n", calltimes);

	return 0;
}

int main(int argc, char **argv)
{
	sqlite3 *db = NULL;

	// create db
	Sqlite3_open_v2("test.db", &db,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
			NULL);

	// insert item
	char *errmsg = NULL;
	char *sql = "insert into employee(name, age) values('Michael', 30);";
	Sqlite3_exec(db, sql, NULL, NULL, &errmsg);

	// delete item

	// update item

	// select items
	sql = "select * from employee;";
	Sqlite3_exec(db, sql, callback, NULL, &errmsg);


	// close db
	sqlite3_close(db);

	return 0;
}
