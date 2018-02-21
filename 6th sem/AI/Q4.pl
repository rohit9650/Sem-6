fibo(0,R):- R is 0.
fibo(1,R):- R is 1.
fibo(N,R):- N1 is N-1, N2 is N-2, fibo(N1,R1), fibo(N2,R2), R is R1+R2, !.

go :-   write('Enter number : '),
	read(N),nl,
	fibo(N,R),
	write('The '),write(N),write(' term of fibbonaci series is : '),write(R).
