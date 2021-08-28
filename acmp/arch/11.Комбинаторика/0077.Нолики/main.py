import math

def C(m, n):
	if m > n:
		return 0
	res = 1
	for i in range(n - m + 1, n + 1):
		res *= i
	for i in range(1, m+1):
		res //= i
	return res

def calculate(k, val, lg):
	if k < 0 or k > lg:
		return 0
	zeroes = 0
	for i in range(lg-1, -1, -1):
		if val & (1 << i):
			return C(k-1-zeroes, i) + calculate(k-zeroes, val, i)
		zeroes += 1
	return 1 if k == zeroes else 0

N, K = map(int, input().split(' '))
lg   = int(math.log2(N))

res = 0
for b in range(K, lg):
	res += C(K, b)

print(res + calculate(K, N, lg))
