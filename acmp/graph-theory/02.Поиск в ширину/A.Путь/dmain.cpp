#include <iostream>
#include <queue>
#include <vector>

/*
 * autor:   quix
 * date:    Jan 26 17:18:52 2020
 */

#include <algorithm>





/*
 * Структура представляет граф — может как ориентированный так и нет, —
 * с помощью списка смежности через массив (вектор)
 *
 *
 *
 * ----- ДОГОВОРЁННОСТИ
 * При вводе через файл список смежности вседа должен быть очищенным,
 * автоматически ничего не делается
 *
 *
 *
 * ----- МЕТОДЫ
 *    * clear()
 *    * sort()
 *
 *
 *
 * ----- ОПЕРАТОРЫ
 *    * [i] (const) — возвращает вектор, содержащий все номера смежных
 *                    вершин вершине i
 *
 *
 *
 * ----- СВОЙСТВА
 *    * n() — количество вершин
 *
 *
 *
 * ----- ДРУГОЕ
 *    <fun_name>1 — означает, что эта функция работает точно так же,
 *    как <fun_name>, но в ней считается, что вершины нумеруются,
 *    начиная с единицы, а не с нуля
 *
 *    * scan............сначала считывает кол-во вершин, затем списки
 *                      для каждой вершины: список начинается с числа,
 *                      значащее, скольким вершинам смежно текущее,
 *                      далее идут номера этих смежных вершин
 *    * scan1...........см. выше
 *    * scan_matrix.....считывает граф, представленный в виде матрицы 
 *                      смежности: сначала n, затем, собственно, матрицу
 *                      размерности n*n
 *    * scan_riblist....читает из файла сначала два числа: кол-во вершин и
 *                      кол-во рёбер — затем считывает сами рёбра,
 *                      представленные парой чисел — номерами вершин;
 *                      вторым аргументом функции идёт указание, считать
 *                      ли граф ориентированным (по умолчанию считается
 *                      неориентированным)
 *    * scan_riblist1...см. выше
 *    * print...........выводит в том же формате, в каком считывает
 *                      в функции scan
 *    * print1..........см. выше
 *
 *
 *
 */

struct AdjacList
{
	// data-members
	std::vector< std::vector<int> > ribs;
	


	
	
	// base
	inline int n() const
	{
		return (int)ribs.size();
	}

	inline AdjacList &clear()
	{
		ribs.clear();
		return *this;
	}

	inline AdjacList &sort()
	{
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
			std::sort( b->begin(), b->end() );
		return *this;
	}





	// at
	inline std::vector<int> &operator[](int i)
	{
		return ribs[i];
	}

	inline std::vector<int> const &operator[](int i) const
	{
		return ribs[i];
	}
	


	
	
	// scan, print
	AdjacList &scan(FILE *file = stdin)
	{
		int n;
		fscanf(file, "%i", &n);
		ribs.resize(n);

		int m;
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			fscanf(file, "%i", &m);
			b->resize(m);
			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
				fscanf(file, "%i", bb.base());
		}

		return *this;
	}

	AdjacList &scan1(FILE *file = stdin)
	{
		int n;
		fscanf(file, "%i", &n);
		ribs.resize(n);

		int m;
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			fscanf(file, "%i", &m);
			b->resize(m);
			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
				fscanf(file, "%i", bb.base()),
				--*bb;
		}

		return *this;
	}

	AdjacList &scan_matrix(FILE *file = stdin)
	{
		int n;
		fscanf(file, "%i", &n);
		ribs.resize(n);

		int input;
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			fscanf(file, "%i", &input);
			if(input)
				ribs[i].push_back(j);
		}

		return *this;
	}

	AdjacList &scan_riblist(FILE *file = stdin, bool oriented = false) // read n m v11 v12 ...
	{
		int n, m;
		fscanf(file, "%i%i", &n, &m);
		ribs.resize(n);

		int first, second;
		for(int i = 0; i < m; ++i)
		{
			fscanf(file, "%i%i", &first, &second);
			ribs[first].push_back(second);

			if(!oriented)
				ribs[second].push_back(first);
		}

		return *this;
	}

	AdjacList &scan_riblist1(FILE *file = stdin, bool oriented = false) // read n m v11 v12 ...
	{
		int n, m;
		fscanf(file, "%i%i", &n, &m);
		ribs.resize(n);

		int first, second;
		for(int i = 0; i < m; ++i)
		{
			fscanf(file, "%i%i", &first, &second);
			--first, --second;
			ribs[first].push_back(second);

			if(!oriented)
				ribs[second].push_back(first);
		}

		return *this;
	}



	void print(FILE *file = stdout) const
	{
		fprintf(file, "%i\n", (int)n());
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			fprintf(file, "%i ", (int)b->size());

			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
			{
				fprintf(file, "%i ", *bb);
			}
			fprintf(file, "\n");
		}
		return;
	}

	void print1(FILE *file = stdout) const
	{
		fprintf(file, "%i\n", (int)n());
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			fprintf(file, "%i ", (int)b->size());

			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
			{
				fprintf(file, "%i ", *bb+1);
			}
			fprintf(file, "\n");
		}
		return;
	}

};





// end



using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
int bfs_length(AdjacList const &adjl, int beg, int end)
{
	if(beg == end)
		return 0;

	queue<int> que;
	que.push(beg);

	vector<char> marks(adjl.n(), 0);
	marks[beg] = 1;

	int cur;
	while(!que.empty())
	{
		cur = que.front();
		for(auto b = adjl[cur].begin(), e = adjl[cur].end(); b != e; ++b)
		{
			if(*b == end)
				return marks[cur];
			if(!marks[*b])
			{
				marks[*b] = marks[cur] + 1;
				que.push(*b);
			}
		}
		que.pop();
	}

	return -1;
}





// main
int main( int argc, char *argv[] )
{
	AdjacList adjl;
	int beg, end;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjl.scan_matrix(file);
		fscanf(file, "%i%i", &beg, &end);
		--beg, --end;
		fclose(file);
	}


	// calculate
	int const result = bfs_length(adjl, beg, end);
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", result);
		fclose(file);
	}


	return 0;
}





// end

