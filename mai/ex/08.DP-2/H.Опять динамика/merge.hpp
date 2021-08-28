/*
 * autor:   clever
 * date:    Nov 16 23:58:30 2019
 */

#include <vector>





template<
	typename FIterator,
	typename SIterator,
	typename RIterator
>
void merge(
	FIterator fb, FIterator fe,
	SIterator sb, SIterator se,
	RIterator res
)
{
	while(fb != fe && sb != se)
	{
		if(*fb < *sb)
			*res = *fb,
			++res,
			++fb;
		else if(*sb < *fb)
			*res = *sb,
			++res,
			++sb;
		else
			*res = *fb,
			++res,
			++fb,
			++sb;
	}

	while(fb != fe)
		*res = *fb,
		++res,
		++fb;

	while(sb != se)
		*res = *sb,
		++res,
		++sb;

	return;
}





template<
	typename FIterator,
	typename SIterator,
	typename RIterator
>
void multimerge(
	FIterator fb, FIterator fe,
	SIterator sb, SIterator se,
	RIterator res
)
{
	while(fb != fe && sb != se)
	{
		if(*sb < *fb)
			*res = *sb,
			++res,
			++sb;
		else
			*res = *fb,
			++res,
			++fb;
	}

	while(fb != fe)
		*res = *fb,
		++res,
		++fb;

	while(sb != se)
		*res = *sb,
		++res,
		++sb;

	return;
}





template<
	typename FIterator,
	typename SIterator,
	typename RIterator,
	typename Criterion
>
void merge(
	FIterator fb, FIterator fe,
	SIterator sb, SIterator se,
	RIterator res,
	Criterion crit
)
{
	while(fb != fe && sb != se)
	{
		switch(crit(*fb, *sb))
		{
		case 'f':
			*res = *fb;
			++fb;
			break;
		case 's':
			*res = *sb;
			++sb;
			break;
		case 'F':
			*res = *fb;
			++fb;
			++sb;
			break;
		case 'S':
			*res = *sb;
			++fb;
			++sb;
			break;
		default:
			throw std::logic_error("invalid criterion return value");
		}
		++res;
	}

	while(fb != fe)
		*res = *fb,
		++res,
		++fb;

	while(sb != se)
		*res = *sb,
		++res,
		++sb;

	return;
}





// end
