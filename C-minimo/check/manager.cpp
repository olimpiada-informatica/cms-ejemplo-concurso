#include<bits/stdc++.h>

using namespace std;


typedef vector<int> vi;

const int MAX_QUERIES = 50;

FILE *fin, *fout, *fifo_in, *fifo_out;


void accept_answer() {
	
	printf("1.0\n");
	

	fclose(fin);
	fclose(fout);
	fclose(fifo_in);
	fclose(fifo_out);

	exit(0);
	
}

void quit() {

	
	printf("0.0\n");

	fclose(fin);
	fclose(fout);
	fclose(fifo_in);
	fclose(fifo_out);

	exit(0);
	
}

void error_response(string s) {
	cerr << s << endl;
	fprintf(fifo_in, "-\n");
	fflush(fifo_in);
	quit();
}

void print_string(string s) {
	fprintf(fifo_in, "%s\n", s.c_str());
	fflush(fifo_in);
}


int main(int argc, char* argv[]) {
	signal(SIGPIPE, SIG_IGN);

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	fifo_in = fopen(argv[2], "w");
	fifo_out = fopen(argv[1], "r");

	int n;

	cin >> n;

	fprintf(fifo_in, "%d\n", n);
	fflush(fifo_in);
	
	vi a(n);
	for(int i=0; i < n; ++i) {
		cin >> a[i];
	}
	

	int q =0;
	while(true) {
		char c;
		fscanf(fifo_out, " %c", &c);

		if(c == '?') {
			q++;
			if(q > MAX_QUERIES) {
				error_response("Query limit exceeded");
			}
			int x, y;
			fscanf(fifo_out, "%d %d", &x, &y);
			if(!(0 <= x && x <= n-1 && 0 <= y && y <= n-1)) {
				error_response("Invalid query");
			}
			if(a[x] < a[y]) {
				fprintf(fifo_in, "<\n");
				fflush(fifo_in);
			}
			else {
				fprintf(fifo_in, ">\n");
				fflush(fifo_in);
			}
		}
		else if (c == '!') {
			int x;
			fscanf(fifo_out, "%d", &x);
			if(!(0 <= x && x <= n-1)) quit();
			if(x == 0) {
				if(!(a[0] < a[1])) quit();
			}
			else if(x == n-1) {
				if(!(a[n-1] < a[n-2])) quit();
			}
			else {
				if(!(a[x-1] > a[x] && a[x+1] > a[x])) quit();
			}
			accept_answer();
			break;
		}
		else {
			error_response("Invalid query");
		}
	}
	quit();




}