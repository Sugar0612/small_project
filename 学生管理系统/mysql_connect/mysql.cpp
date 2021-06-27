#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <mysql.h>
#include <string>
using namespace std;

MYSQL sql;
MYSQL_RES *res;
MYSQL_FIELD *field;
MYSQL_ROW row;

void init_vs_mysql() {
	mysql_init(&sql);


	const char *host = "127.0.0.1";
	const char *user = "root";
	const char *password = "tsy20010612";
	const char *db = "school";

	bool ok = mysql_real_connect(&sql, host, user, password, db, 3306, 0, 0);
	if (ok) cout << "connect ok!" << endl;
	else cout << "connect error!" << endl;
}


void select_vs_mysql() {
	string sqlq = "select * from stud;";
	mysql_query(&sql, sqlq.c_str());

	res = mysql_store_result(&sql);

	int n = mysql_num_fields(res); // 返回字段个数
	//for (int i = 0; i < n; ++i) {
	//	field = mysql_fetch_field_direct(res, i); // 返回字段类型
	//	cout << field->name << endl;
	//}

	while (1) {
		row = mysql_fetch_row(res); // 查看一个字段内容
		if (!row) break;
		for (int i = 0; i < n; ++i) {
			cout << row[i] << "  ";
		}
		cout << endl;
		row++;
	}
}

void insert_vs_mysql(int id, char *name, int score, int class_) {
	char sql_q[100];
	sprintf(sql_q, "insert into stud value(%d, '%s', %d, %d);", id, name, score, class_);
	cout << sql_q << endl;

	mysql_query(&sql, sql_q);

}

int main() {
	// 后期switch 实现控制 就好


	init_vs_mysql(); // 初始化	
	select_vs_mysql(); // 查看
	while (1) {
		int id, score, class_;
		char *name = new char(100);
		cout << "输入信息!" << endl;
		cin >> id >> name >> score >> class_;
		insert_vs_mysql(id, name, score, class_); // 插入

		int s;
		cout << "是否继续? (1. go on, 2. stop)" << endl;
		cin >> s;
		if (s == 2) break;
	}

	return 0;
}
