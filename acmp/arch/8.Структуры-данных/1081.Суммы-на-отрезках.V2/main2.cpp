#include <cstdio>


using namespace std;





// types
typedef unsigned long long ullong;
struct ArrayNode
{
	int n;
	ullong value;
	ArrayNode *d;

	void init(int len, ullong *arr)
	{
		n = len;
		if(len == 1)
		{
			d = nullptr;
			value = arr[0];
			return;
		}
		d = new ArrayNode[2];
		d[0].init(
			n - n/2,
			arr
		);
		d[1].init(
			len/2,
			arr + n - n/2
		);
		value = d[0].value + d[1].value;
		return;
	}
	void free()
	{
		if(!d)
			return;
		d[0].free();
		d[1].free();
		delete[] d;
		return;
	}

	ullong summ(int b, int e)
	{
		if(e-b == n)
			return value;
		int flen = n - n/2;
		if(b >= flen)
			return d[1].summ(b-flen, e-flen);
		if(e <= flen)
			return d[0].summ(b, e);
		return d[0].summ(b, flen) + d[1].summ(0, e-flen);
	}

	void print(FILE *file) const
	{
		if(!d)
		{
			fprintf(file, "%llu", value);
			return;
		}
		fprintf(file, "%llu: (", value);
		d[0].print(file);
		fprintf(file, ", ");
		d[1].print(file);
		fprintf(file, ")");
		return;
	}
};

template<typename T>
struct ArrayLayer
{
	int n;
	int k;
	T *d;
	ArrayLayer *down;

	void init(ArrayLayer *l)
	{
		n = l->n - l->n/2;
		k = l->k*2;
		d = new T[n];
		down = l;

		if(l->n % 2 == 0)
			for(int i = 0; i < n; ++i)
				d[i] = (*l)[i*2] + (*l)[i*2+1];
		else
			for(int i = 0; i < n; ++i)
				d[i] = (*l)[i*2];

		return;
	}

	T summ(int b, int e) const
	{
	}

	T const &operator[](int i) const
	{
		return d[i];
	}
	T &operator[](int i)
	{
		return d[i];
	}
};




// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int len;
	ullong *arr;
	ArrayNode node;
	int count; 



	// read array
	auto infile = fopen(INPUT_FILE_NAME, "r");
	fscanf(infile, "%i", &len);
	arr = new ullong[len];
	for(auto *b = arr, *e = arr+len; b != e; ++b)
	{
		fscanf(infile, "%llu", b);
	}
	node.init(len, arr);
	
	
	
	// calculate
	fscanf(infile, "%i", &count);
	auto outfile = fopen(OUTPUT_FILE_NAME, "w");
	int b, e;
	for(int i = 0; i < count; ++i)
	{
		fscanf(infile, "%i%i", &b, &e);
		--b;
		fprintf(outfile, "%llu ", node.summ(b, e));
	}



	return 0;
}





// end
