% program in PROLOG to implement towerofhanoi (N) where N represents the number of discs

towerOfHanoi(A,B,C,1) :- write('move disk 1 from '), write(A), write(' to '), write(B),nl, !.			% base case
towerOfHanoi(A,B,C,N) :- N1 is N-1, towerOfHanoi(A,C,B,N1),
			 write('move disk '), write(N), write(' from '), write(A), write(' to '), write(B),nl,
			 towerOfHanoi(C,B,A,N1), !.  

go :-   write('Enter the number of disc : '),
	read(N),nl,												% reading number of disk
	towerOfHanoi(A,B,C,N).
	
