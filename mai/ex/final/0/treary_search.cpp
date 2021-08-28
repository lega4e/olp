




double trenary_search(double l, double r)
{
	double ll, rr;
	for(int i = 0; i < 1000; ++i)
	{
		ll = l + (r - l)/3.0;
		rr = r - (r - l)/3.0;
		if( f(ll) < f (rr) )
			r = rr;
		else
			l = ll;
	}

	return (l + r) / 2.0;
}





// end
