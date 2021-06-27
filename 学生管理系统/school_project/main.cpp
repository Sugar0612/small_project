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
			cout << "������ҵ��Ա��Ϣ:" << endl;
			string id, name, gender;
			double salary;
			cin >> id >> name >> gender >> salary;
			peo *p = new peo(id, name, gender, salary);
			
			node *_l = new node(p);
			l ->next = _l;
			l = _l;

			cout << "�����ɹ��Ƿ��������?(0 Ϊ���� 1Ϊ�˳�)" << endl;

			int i;
			cin >> i;
			if (i) break;
		}

		cout << "�����ɹ�!" << endl;
		peo_show();


		return;
	}

	void peo_insert() {
		cout << "��������Ҫ�������Ϣ:" << endl;
		string id, name, gender;
		double salary;
		cin >> id >> name >> gender >> salary;
		peo *p;
		p = new peo(id, name, gender, salary);
		cout << "��Ҫ�����λ��" << endl;
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
		cout << "����ɹ�!" << endl;

		peo_show();
	}


	void peo_find() {
		cout << "ѡ���ѯ��ʽ: (1.���Ų�ѯ 2. ������ѯ)" << endl;
		int be;
		cin >> be;
		node *l = root.get();
		if (1 == be) {
			string job_n;
			cout << "���빤�Ų���: " << endl;
			cin >> job_n;
			if (l->next) l = l->next;
			while (l) {
				if (l->p->job_n == job_n) {
					cout << "�ɹ�!  " << l->p->name << "  " << l->p->gender << "  " << l->p->salary << endl;
					return;
				}
				l = l->next;
			}
		}
		else {
			string name;
			cout << "������������: " << endl;
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
		cout << "ʧ��" << endl;
		return;
	}


	void peo_delete() {
		string job_n;
		cout << "ѡ��ɾ����ʽ: (1.����ɾ�� 2. ����ɾ��)" << endl;
		int be;
		cin >> be;

		node *l = root.get();
		bool is_delete = false;
		if (1 == be) {
			cout << "������Ҫɾ���Ĺ���:" << endl;
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
			cout << "������Ҫɾ��������: " << endl;
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
			cout << "û�и�ҵ��Ա!" << endl;
			return;
		}
		cout << "ɾ���ɹ�!" << endl;
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
		cout << "����ɹ�!" << endl;
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
					break; // ֦��
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
	cout << "��ӭ����ҵ��Ա����ϵͳ!" << endl;
	int behave = -1;
	while (1) {
		cout << "��ѡ�����: (1.���� 2.���� 3.��ѯ 4.ɾ�� 5.ҵ������ 6.��ʾ����ҵ�� 0.�˳�)" << endl;
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
			cout << "��лʹ��!" << endl;
			break;
		}
	}
	return 0;
}