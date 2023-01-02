bool confusingNumber(int N){

	int reversed = 0, tempN = N;
	while(N){

		int rem = N % 10;
		if(rem == 2 || rem==3 || rem==4 || rem==5 || rem == 7) return false;
		if(rem == 9) rem = 6;
		if(rem == 6) rem = 9;
		reversed *= 10;
		reversed += rem;
		N /= 10;
	}
	return (reversed != tempN);
}