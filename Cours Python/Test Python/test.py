for n in range(2, 14):
	for x in range(2, n):
	    if n % x == 0:
	        print(n, 'equals', x, '*', n//x)
	        break
	    print('coucou')
	else:
	    # loop fell through without finding a factor
	    print(n, 'is a prime number')