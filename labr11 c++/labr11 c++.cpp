#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <clocale>
#include <malloc.h>
#include <string>
#include <algorithm>

#define M 20
#define N 30
using namespace std;
size_t remove_ch(char* s, char ch)           //функция удаление определенных символов
{
	size_t i, j;

	j = 0;

	for (i = 0; s[i]; ++i)
		if (s[i] != ch)
			s[j++] = s[i];

	s[j] = '\0';

	return j;
}




class students {

public:

	//students(const students& val) 
	//{
	//	students test;
	//	for (int i = 0; i < 5; i++)
	//	{
	//		mas[i] = test.mas[i];
	//	}
	//}

	students& operator =(const students& val) {

		students test;
		for (int i = 0; i < 5; i++)
		{
			test.mas[i] = mas[i];
		}
		return *this;
	}

	students(void) {//конструктор без параметров

		a = 0;

		sum = 0;
		for (int i = 0;i < M;i++) {
			last_name[i] = "\0";
			group[i] = 0;
			avg_ball1[i] = 0;
			avg_ball2[i] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			mas[i] = i;
		}
	}

	students(int a) {//конструктор с 1 параметром

		this->a = a;

	}





	students(std::string student_last_name[N], int grn[N], float avg1[N], float avg2[N], int id[N], int n) :student_book(id) {//конструктор со всеми параметрами

		for (int i = 0;i < n;i++) {
			last_name[i] = student_last_name[i];
			group[i] = grn[i];
			avg_ball1[i] = avg1[i];
			avg_ball2[i] = avg2[i];


		}

	}

	students(const students& ref_student);//конструктор копирования 


	void set_last_name(string str, int i) {
	
		last_name[i] = str;
	
	}

	void set_group(int i, int gn) {

		group[i] = gn;
	
	}

	int get_group(int i) {
	
		return group[i];
	
	}

	string get_last_name(int i) {
	
		return last_name[i];
	
	}
	void set_avg_balls(float a, float b) {

		avg_ball1[0] = a;
		avg_ball2[0] = b;

	}

	void output(int n) {//метод для вывода 
		for (int i = 0;i < n;i++) {
			std::cout << "|" << last_name[i];
			printf("| %d | %0.2f | %0.2f |", group[i], avg_ball1[i], avg_ball2[i]);
			student_book.print(i);

		}
	}



	void sort1(int n) {

		student_book.sort1(n);

	}


	void sort(int n) {
		std::string ln;
		int* g = new int();
		float* a1 = new float();
		float* a2 = new float();
		for (int i = 0;i < n - 1;i++) {
			for (int j = n - 1;j > i;j--)
				if (group[j - 1] < group[j]) {
					ln = last_name[j - 1];
					last_name[j - 1] = '\0';
					last_name[j - 1] = last_name[j];
					last_name[j] = '\0';
					last_name[j] = ln;
					ln[0] = '\0';


					*g = group[j - 1];
					group[j - 1] = group[j];
					group[j] = *g;

					*a1 = avg_ball1[j - 1];
					avg_ball1[j - 1] = avg_ball1[j];
					avg_ball1[j] = *a1;

					*a2 = avg_ball2[j - 1];
					avg_ball2[j - 1] = avg_ball2[j];
					avg_ball2[j] = *a2;




				}


		}

		delete g;
		delete a1;
		delete a2;

	}// сортировка по возрастанию номера группы

	void zadanie(int n) {
		printf("Студенты, у которых оценка за 2 экзамен ниже, чем за первый\n");
		for (int i = 0;i < n;i++) {
			if (avg_ball2[i] < avg_ball1[i]) {

				std::cout << "|" << last_name[i];

			}

		}
	}

	float& sumofballs1(int n) {// возврат по ссылке

		float sum1 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];


		}

		return sum1;

	}

	float* sumofballs2(int n) {//

		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum2 += avg_ball2[i];


		}

		return &sum2;

	}

	void sumofballs(int n) {

		float sum1 = 0;
		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];

			sum2 += avg_ball2[i];
		}

		sum = sum1 + sum2;
		printf("сумма баллов за 2 экзамена:%f\n", sum);

	}





	students operator++(void) {

		++a;
		return *this;
	}
	students operator++(int a) {

		this->a++;
		return *this;
	}



	float get_a() {

		return a;

	}

	void out_a() {

		std::cout << "a:" << a << "\n";

	}

	static int get_stipendia() { return stipendia; }

	void out_stipendia(int n) {

		for (int i = 0;i < n;i++) {

			if ((avg_ball1[i] + avg_ball2[i]) / 2 >= 4) {
				std::cout << "Студент:" << last_name[i];
				printf("Стипендия:%d\n", stipendia);

			}
			else
			{
				std::cout << "Студент:" << last_name[i];
				printf("Стипендия:0\n");
			}

		}

	}

	float get_sum()// геттер 
	{

		return sum;

	}

	students& operator=(string str) {

		ln = str;
		return *this;

	}

	void get_str() {

		std::cout << ln << "\n";
	}
	void operator +(string);


	int mas[5];
private:
	std::string last_name[N];// фамилия студента
	std::string ln;
	char* str;

	int group[N];//номер группы студента
	float avg_ball1[N];//средний балл за 1 семестр
	float avg_ball2[N];//средний былл за 2 семестр
	static int stipendia;
	float sum;
	int a;

	class Student_book
	{
	private:
		int id[M];
	public:
		Student_book() {


		}

		Student_book(int id[N]) {
			int size = sizeof(id) / sizeof(id[0]);

			for (int i = 0; i < size;i++) {

				this->id[i] = id[i];

			}


		}

		void set_id(int i,int id) {
		
			this->id[i] = id;
		
		}

		void print(int i) {

			printf(" %d\n", id[i]);

		}

		int get_id(int i)
		{

			return id[i];

		}

		void sort1(int n) {
			int* ID = new int();
			for (int i = 0;i < n - 1;i++) {
				for (int j = n - 1;j > i;j--) {
					students st;
					if (st.group[j - 1] < st.group[j]) {

						*ID = id[j - 1];
						id[j - 1] = id[j];
						id[j] = *ID;

					}

				}
			}
			delete ID;
		}

	};
	Student_book student_book;
	friend void friendf(students& student);

};

void students::operator+(string str) {

	ln = ln + str;

}

students::students(const students& ref_student) {

	sum = ref_student.sum;
	students test;
	for (int i = 0; i < 5; i++)
	{
		mas[i] = test.mas[i];
	}

}



int students::stipendia = 2600;

void friendf(students& student)//friend функция
{
	student.sum = 0;
	printf("сумма баллов обнулена\n");

}





int _tmain() {
	std::string Ln[N];
	int n;
	float* avgb1 = new float[N];
	int* id1 = new int[N];
	setlocale(LC_ALL, "russian");
	printf("Ввдеите кол-во стундентов:");
	do {
		scanf("%d", &n);

		if (n < 0 || n>30)
		{
			printf("Кол-во стундентов должно быть больше 30, но неменьше 1!\n");
		}

	} while (n < 0 || n>30);
	float* avgb2 = (float*)calloc(n, sizeof(float));
	int* groupn = (int*)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		while (getchar() != '\n');
		printf("Введите фамилию:");
		std::getline(std::cin, Ln[i]);
		printf("Введите номер группы:");
		scanf("%d", &groupn[i]);
		while (getchar() != '\n');
		printf("Введите средный балл за 1 экзамен:");
		scanf("%f", &avgb1[i]);
		while (getchar() != '\n');
		printf("Введите средный балл за 2 экзамен:");
		scanf("%f", &avgb2[i]);
		while (getchar() != '\n');

		try {
			printf("Введите номер зачетки:");
			scanf("%d", &id1[i]);
			if (id1[i] < 0)throw "Номер зачетки не может быть отрицательным\n";
		}
		catch (const char* msg) {
			std::cerr << msg << std::endl;


		}
	}
	students* student = new students(Ln, groupn, avgb1, avgb2, id1, n);
	students st();

	printf("До сортировки:\n");
	student->output(n);
	student->sort(n);
	student->sort1(n);
	printf("После сортировки:\n");
	student->output(n);
	student->zadanie(n);
	printf("Сумма оценок за 1 экзамен:%f\n", student->sumofballs1(n));
	printf("Сумма оценок за 2 экзамен:%f\n", *student->sumofballs2(n));
	student->sumofballs(n);
	printf("\n");

	std::cout << "Конструктор копирования!\n\n";

	students student1;
	student1.set_avg_balls(4.2, 3.8);
	student1.sumofballs(1);
	students s1 = student1;
	std::cout << "До копирования:";
	for (int i = 0;i < 5;i++) {
		std::cout << student1.mas[i];

	}
	std::cout << "\nКопирование:" << s1.get_sum() << "\n";
	for (int i = 0;i < 5;i++) {
		std::cout << s1.mas[i];

	}
	std::cout << "\nменяем первый элемент массива на 9\n";
	s1.mas[0] = 9;
	for (int i = 0;i < 5;i++) {
		std::cout << s1.mas[i];

	}
	std::cout << "\n";
	friendf(student1);

	std::cout << "\nПрегрузка операторов + и ++\n";

	students str1;
	str1 + Ln[1];
	str1 + Ln[0];
	str1.get_str();

	students d, d1(5);
	printf("До перегрузки(++a):");
	d.out_a();
	printf("До перегрузки(a++):");
	d1.out_a();
	++d;
	d1++;
	printf("После перегрузки(++a):");
	d.out_a();
	printf("После перегрузки(a++):");
	d1.out_a();

	std::cout << "\nПрегрузка операторов присвоения \n";
	students c4;
	c4 = Ln[0];

	c4.get_str();

	std::cout << "\nСтатическое поле и метод\n";
	student->out_stipendia(n);
	
	std::cout << "Одномерный массив объектов\n";

	students mas[3];

	for (int i = 0;i < 3;i++) {
	
		mas[i].set_avg_balls(i + 2.3, i + 2.5);
		mas[i].sumofballs(1);
		
	}

	std::cout << "Двумерный  массив объектов\n";
	students mas1[1][2];

	for (int i = 0;i < 1;i++) {
	    
		mas1[i][0].set_last_name(Ln[i], i);
		mas1[i][1].set_group(i, groupn[i]);
	
	}
	for (int i = 0;i < 1;i++) {

		cout<<mas1[i][0].get_last_name(i)<<' ';
		cout<<mas1[i][1].get_group(i);

	}

	delete[] avgb1;
	delete[] id1;
	free(groupn);
	free(avgb2);
	return 0;
}