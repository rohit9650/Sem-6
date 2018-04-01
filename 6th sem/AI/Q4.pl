% program in PROLOG to implement generate_fib(N,T) where T represents the Nth term of the fibonacci series.

fibo(0,R):- R is 0.								% base case
fibo(1,R):- R is 1.								% base case
fibo(N,R):- N1 is N-1, N2 is N-2, fibo(N1,R1), fibo(N2,R2), R is R1+R2, !.	% recurssive defination of fibonacci

go :-   write('Enter number : '),
	read(N),nl,					% reading number
	fibo(N,R),
	write('The '),write(N),write(' term of fibbonaci series is : '),write(R).
