palindrome(L) :- reverse(L,L).

go :-   write('Enter the list : '),
	read(L),nl,
	palindrome(L), write('yes'); write('no').
