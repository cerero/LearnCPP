#include "MyVector.cpp"
#include <iostream>
#include <cstring>
using namespace std;

class Teacher {
  friend ostream& operator<<(ostream& os, const Teacher& t) {
    os << "teacher name: " << t.m_name << ", age: " << t.age;
    return os;
  }
public:
    Teacher(): age(0), m_name(NULL){

    }

    Teacher(int age, const char *name) {
      this->age = age;
      int len = strlen(name) + 1;
      m_name = new char[len];
      strcpy(m_name, name);
    }

    Teacher(const Teacher& t) {
      this->age = t.age;
      int len = strlen(t.m_name) + 1;
      m_name = new char[len];
      strcpy(m_name, t.m_name);
    }

    ~Teacher() {
      if (m_name) {
        delete [] m_name;
        m_name = NULL;
      }
    }

    Teacher& operator=(const Teacher& t) {
      if (m_name) {
        delete [] m_name;
        m_name = NULL;
      }

      this->age = t.age;
      int len = strlen(t.m_name) + 1;
      m_name = new char[len];
      strcpy(m_name, t.m_name);
      return *this;
    }
private:
  int age;
  char *m_name;
};

int main(int argc, char **argv) {
  Teacher t1(20, "jack");
  Teacher t2(30, "sugar");
  Teacher t3(18, "suyi");

  MyVector<Teacher> char_vec(3);
  char_vec[0] = t1;
  char_vec[1] = t2;
  char_vec[2] = t3;

  MyVector<Teacher> char_vec_2(0);
  char_vec_2 = char_vec;
  MyVector<Teacher> char_vec_3(char_vec_2);

  cout << "char_vec: " << char_vec << endl;
  cout << "char_vec2: " << char_vec_2 << endl;
  cout << "char_vec3: " << char_vec_3 << endl;
  return 0;
}
