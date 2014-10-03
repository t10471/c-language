#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

char *hostname;
char *username = "root";
char *password;
char *database = "hoge";
unsigned long portnumber;

/*
 * mysql function
 */
int connectDatabase();
MYSQL_RES *query(unsigned char *);
MYSQL_ROW fetchRow(MYSQL_RES *);
void freeResult(MYSQL_RES *);
void closeDatabase();

MYSQL *mysql;
MYSQL_RES *g_res = NULL;

char *get(const char *key)
{
    char *val = getenv(key);
    if (val == NULL) {
        printf("%s is not defined", key);
        exit(1);
    }
        printf("%s is %s \n", key, val);
    return val;
}

long cast2long(char *val)
{
    char *ends;
    long l;
    l = strtol(val, &ends, 0);
    if (strlen(ends) != 0) {
        printf("変換元の文字列:%s \n", val);
        printf("long型に変換された値:%lu \n", l);
        printf("変換出来なかった文字列:%s \n", ends);
        exit(1);
    }
    return l;
}

int setup()
{
    password = get("MYSQL_ENV_MYSQL_ROOT_PASSWORD");
    hostname = get("MYSQL_PORT_3306_TCP_ADDR");
    //portnumber = cast2long(get("MYSQL_PORT"));
    portnumber = cast2long(get("MYSQL_PORT_3306_TCP_PORT"));
}

int connectDatabase()
{
    mysql = mysql_init(NULL);
    if (NULL == mysql) {
        printf("error: %s \n", mysql_error(mysql));
        return -1;
    }
    if (NULL == mysql_real_connect(mysql, hostname, username, password,
                                   database, portnumber, NULL, 0)) {
        // error
        printf("error: %s \n", mysql_error(mysql));
        return -1;
    } else {
        // success
    }
    return 1;
}

MYSQL_RES *query(unsigned char *sql_string)
{
    if (g_res) {
        freeResult(g_res);
        g_res = NULL;
    }

    if (mysql_query(mysql, sql_string)) {
        printf("error: %s \n", mysql_error(mysql));
        return NULL;
    }

    g_res = mysql_use_result(mysql);
    return g_res;
}

MYSQL_ROW fetchRow(MYSQL_RES *res) { return mysql_fetch_row(res); }

void freeResult(MYSQL_RES *res)
{
    mysql_free_result(res);
    g_res = NULL;
}

void closeDatabase()
{
    if (g_res) {
        freeResult(g_res);
        g_res = NULL;
    }
    mysql_close(mysql);
}

int main()
{
    setup();
    //return 0;

    MYSQL_RES *res;
    MYSQL_ROW row;

    if (!connectDatabase()) {
        printf("error connect database\n");
    };

    /* INSERT文の実行 */
    query("INSERT INTO test (name, age) VALUES('hoge', 14)");

    /* SELECT文の実行 */
    res = query("SELECT * FROM test;");

    printf("%20s %20s %20s \n", "id", "name", "age");
    while ((row = fetchRow(res)) != NULL) {
        printf("%20s %20s %20s \n", row[0], row[1], row[2]);
    }

    closeDatabase();
    
    return 0;
}
