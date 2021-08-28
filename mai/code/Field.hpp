/*
 * autor:   clever
 * date:    Nov  3 14:11:26 2019
 */



// type
template<typename T>
struct Field
{
	int w, h;
	T *d;



	Field &init()
	{
		d = new T[w*h];
		return *this;
	}

	Field &zeroize()
	{
		memset(d, 0, sizeof(T)*(w*h));
		return *this;
	}

	Field &free()
	{
		delete[] d;
		return *this;
	}


	inline T *operator[](int y)
	{
		return d + y*w;
	}

	inline T &at(int x, int y)
	{
		return d[y*w + x];
	}
};





// end
