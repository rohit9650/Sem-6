% program in PROLOG to implement palindrome (L) which checks whether a list L is a palindrome or not.

palindrome(L) :- reverse(L,L).				% checking if reverse of L is L itself

go :-   write('Enter the list : '),
	read(L),nl,					% reading the list
	palindrome(L), write('yes'); write('no').	% if plaindrome than print yes otherwise print no
