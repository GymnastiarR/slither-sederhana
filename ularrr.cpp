#include <windows.h>  
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void papan(char langkah[]){
	printf(" ___________________\n");
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[0], langkah[1], langkah[2], langkah[3], langkah[4], langkah[5], langkah[6], langkah[7], langkah[8], langkah[9] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[10], langkah[11], langkah[12], langkah[13], langkah[14], langkah[15], langkah[16], langkah[17], langkah[18], langkah[19] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[20], langkah[21], langkah[22], langkah[23], langkah[24], langkah[25], langkah[26], langkah[27], langkah[28], langkah[29] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[30], langkah[31], langkah[32], langkah[33], langkah[34], langkah[35], langkah[36], langkah[37], langkah[38], langkah[39] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[40], langkah[41], langkah[42], langkah[43], langkah[44], langkah[45], langkah[46], langkah[47], langkah[48], langkah[49] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[50], langkah[51], langkah[52], langkah[53], langkah[54], langkah[55], langkah[56], langkah[57], langkah[58], langkah[59] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[60], langkah[61], langkah[62], langkah[63], langkah[64], langkah[65], langkah[66], langkah[67], langkah[68], langkah[69] );
	printf("|%c %c %c %c %c %c %c %c %c %c|\n", langkah[70], langkah[71], langkah[72], langkah[73], langkah[74], langkah[75], langkah[76], langkah[77], langkah[78], langkah[79] );
	printf(" ___________________\n");
}


int main(){
	
//	system("color 27");
	
	char medan[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',};
	
	int penyimpan[30];
	int batas = 2;

	medan[0] = '*';
	medan[10] = '*';
	medan[20] = '*';
	
	int m = 56;
	int p = 1;
	int r = 20;
	
	penyimpan[0] = 0;
	penyimpan[1] = 10;
	penyimpan[2] = 20;
	
	int langkah = 'S';
	
//	start_time=GetTickCount();
//	check_time=start_time+1000; //GetTickCount returns time in miliseconds, so I add 500 to wait input for half a second.
	DWORD start_time, check_time;
//	int lvl = 500;
	while (p){
		
		start_time=GetTickCount();
		check_time=start_time+300; 
		
		medan[m] = '*';
		papan(medan);
		
		while ((check_time>GetTickCount())){
        	if (kbhit()){
        		
			langkah = getch();
            break;
			}
			
		}
//		int langkah = getch();
		system("cls");
		
		switch(langkah){
			case 'W' : r -= 10;
			break;
			case 'D' : r += 1;
			break;
			case 'S' : r += 10;
			break;
			case 'A' : r -= 1;
			break;
			case 'a' : r -= 1;
			break;
			case 's' : r += 10;
			break;
			case 'd' : r += 1;
			break;
			case 'w' : r -= 10;
			break;
		}
		
		for (int a = 0; a < batas; a++){
			if (penyimpan[a] == r){
				p = 0;
				printf("Game Over");
			}
		}
		
		if (r > 79){
			r = r - 80;
		}
		
		if ( r < 0 ){
			r += 80;
		}
		
		if (m == r){
			srand(time(0));
			m = rand () %78;
			batas++;

		//	penyimpan[batas] = r;
		}
		
		else if (m != r){
			medan[penyimpan[0]] = ' ';
		
			for (int i = 0; i < batas; i++){
				penyimpan[i] = penyimpan[i+1];
			}
		}
		
	//	if(m != r){
			penyimpan[batas] = r;
	//	}
		medan[penyimpan[batas]] = '*';
		
	}
	

}