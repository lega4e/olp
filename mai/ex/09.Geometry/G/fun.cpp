




// functions
template<typename T, typename FunctionType>
T trenary_search( T l, T r, FunctionType fun )
{
	T ll, rr;
	for(int i = 0; i < 300; ++i)
	{
		ll = l + (r - l)/3.0L;
		rr = r - (r - l)/3.0L;
		if( fun(ll) < fun(rr) )
			r = rr;
		else
			l = ll;
	}

	return (l + r) / 2.0L;
}
