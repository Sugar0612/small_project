#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class peo {
public:
	peo(string i, string n, string g, double s) : job_n(i), name(n), gender(g), salary(s) {};
	peo() {};
	~peo() {};

	string job_n;
	string name;
	string gender;
	double salary;
};

class node {
public:
	node(peo* p_) : p(p_), next(nullptr) {};
	node() : p(nullptr), next(nullptr) {};
	
	peo *p;
	node *next;
};



class sol {
public:
	unique_ptr<node> root;
	sol() :root(new node) {};

	void peo_show() {
		node *l = root.get() ->next;
		while(l) {
			cout << l ->p->job_n << " " << l ->p->name << "  " << l ->p->gender << "  " << l ->p->salary << endl;
			l = l->next;
		}
	}


	void peo_build() {
		node *l = root.get();
		if (l->next) l = l->next;
		while (l ->next) {
			l = l->next;
		}


		while (1) {
			cout << "请输入业务员信息:" << endl;
			string id, name, gender;
			double salary;
			cin >> id >> name >> gender >> salary;
			peo *p = new peo(id, name, gender, salary);
			
			node *_l = new node(p);
			l ->next = _l;
			l = _l;

			cout << "创建成功是否继续插入?(0 为继续 1为退出)" << endl;

			int i;
			cin >> i;
			if (i) break;
		}

		cout << "创建成功!" << endl;
		peo_show();


		return;
	}

	void peo_insert() {
		cout << "请输入需要插入的信息:" << endl;
		string id, name, gender;
		double salary;
		cin >> id >> name >> gender >> salary;
		peo *p;
		p = new peo(id, name, gender, salary);
		cout << "需要插入的位置" << endl;
		int idx;
		cin >> idx;


		node *l = root.get()->next;
		int lenth = 0;
		while (l->next) {
			lenth++;
			l = l->next;
		}
		if (idx > lenth) idx = lenth + 1;
		if (idx < 0) idx = 0;

		l = root.get();
		int _idx = -1;
		while (1) {
			if (_idx == idx - 1) {
				node *buf = new node(p);
				buf->next = l->next;
				l->next = buf;
				break;
			}
			_idx++;
			l = l->next;
		}
		cout << "插入成功!" << endl;

		peo_show();
	}


	void peo_find() {
		cout << "选择查询方式: (1.工号查询 2. 姓名查询)" << endl;
		int be;
		cin >> be;
		node *l = root.get();
		if (1 == be) {
			string job_n;
			cout << "输入工号查找: " << endl;
			cin >> job_n;
			if (l->next) l = l->next;
			while (l) {
				if (l->p->job_n == job_n) {
					cout << "成功!  " << l->p->name << "  " << l->p->gender << "  " << l->p->salary << endl;
					return;
				}
				l = l->next;
			}
		}
		else {
			string name;
			cout << "输入姓名查找: " << endl;
			cin >> name;
			if (l->next) l = l->next;
			while (l) {
				if (l->p->name == name) {
					cout <<  l ->p ->job_n << "  " << l->p->name << "  " << l->p->gender << "  " << l->p->salary << endl;
				}
				l = l->next;
			}
			return;
		}
		cout << "失败" << endl;
		return;
	}


	void peo_delete() {
		string job_n;
		cout << "选择删除方式: (1.工号删除 2. 姓名删除)" << endl;
		int be;
		cin >> be;

		node *l = root.get();
		bool is_delete = false;
		if (1 == be) {
			cout << "输入想要删除的工号:" << endl;
			cin >> job_n;
			int idx = -1;
			while (l) {
				if (nullptr != l->next && l->next->p->job_n == job_n) {
					l->next = l->next->next;
					is_delete = true;
					break;
				}
				l = l->next;
			}
		} else {
			cout << "输入想要删除的姓名: " << endl;
			string name;
			cin >> name;
			while (l) {
				if (nullptr != l->next && l->next->p->name == name) {
					l->next = l->next->next;
					is_delete = true;
				}
				l = l->next;
			}
		}
		if (false == is_delete) {
			cout << "没有该业务员!" << endl;
			return;
		}
		cout << "删除成功!" << endl;
		peo_show();
	}


	void peo_sort() {
		node *l = root.get() ->next;
		vector<peo*> buffer;
		while (l) {
			buffer.push_back(l->p);
			l = l->next;
		}

		hill_sort(buffer);
		cout << "排序成功!" << endl;
		for (auto p : buffer) {
			cout << p->job_n << " " << p->name << " " << p->gender << " " << p->salary << endl;
		}
	}

	void hill_sort(vector<peo*>& arr) {
		int cnt = arr.size() / 2;
		while (cnt != 0) {
			for (int i = 0; i < cnt; ++i) {
				vector<int> idx;
				vector<peo*> buf;
				for (int j = i; j < arr.size(); j += cnt) {
					idx.push_back(j);
					buf.push_back(arr[j]);
				}
				insert_sort(buf);
				for (int j = 0; j < idx.size(); ++j) {
					arr[idx[j]] = buf[j];
				}
			}
			cnt /= 2;
		}
		cout << endl;
	}

	void insert_sort(vector<peo*>& buf) {
		vector<peo*> s_arr;
		for (auto p: buf) {
			bool is_insert = false;
			for (int i = 0; i < s_arr.size(); ++i) {
				if (s_arr[i] ->salary > p ->salary) {
					is_insert = true;
					s_arr.insert(s_arr.begin() + i, p);
					break; // 枝剪
				}
			}
			if (!is_insert) s_arr.push_back(p);
		}

		buf = s_arr;
		return;
	}
};


int main() {
	sol *s = new sol();
	cout << "欢迎来到业务员管理系统!" << endl;
	int behave = -1;
	while (1) {
		cout << "请选择操作: (1.建立 2.插入 3.查询 4.删除 5.业绩排序 6.显示所有业务 0.退出)" << endl;
		cin >> behave;
		switch (behave)
		{
		case 1: s ->peo_build(); break;
		case 2: s ->peo_insert(); break;
		case 3: s ->peo_find(); break;
		case 4: s ->peo_delete(); break;
		case 5: s ->peo_sort(); break;
		case 6: s ->peo_show(); break;
		default:
			break;
		}
		if (behave == 0) {
			cout << "感谢使用!" << endl;
			break;
		}
	}
	return 0;
}