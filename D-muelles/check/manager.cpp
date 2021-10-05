#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const int MAX_QUERIES_PREP = 20000;
const int MAX_QUERIES_QUES = 20;
const int MAX_W = 100000;

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
	fprintf(fifo_in, "ERROR\n");
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
	vi b(n);

	for(int i=0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	int prep_quer = 0;
	while(true) {
		char c;
		fscanf(fifo_out, " %c", &c);
		if(c == '!') {
			break;
		}
		else if(c == '?') {
			prep_quer++;
			if(prep_quer >= MAX_QUERIES_PREP) {
				error_response("Too many queries");
			}
			int i, j;
			ll w;
			fscanf(fifo_out, "%d %d %lld", &i, &j, &w);

			if(a[i]*w+b[i] > a[j]*w+b[j]) {
				print_string("FIRST");
			}
			else if(a[i]*w+b[i] < a[j]*w+b[j]) {
				print_string("SECOND");
			}
			else {
				print_string("EQUAL");
			}
		}
		else {
			error_response("invalid query token");
		}
	}

	int q;
	cin >> q;

	for(int cq=0; cq < q; ++cq) {

		ll qw;
		cin >> qw;
		

		ll max_value = -1e18;
		for(int i=0; i < n; ++i) {
			max_value = max(a[i]*qw+b[i], max_value);
		}


		fprintf(fifo_in, "QUESTION %lld\n", qw);
		fflush(fifo_in);

		int q_quer = 0;
		while(true) {
			char c;
			fscanf(fifo_out, " %c", &c);
			if(c == '!') {
				int i;
				fscanf(fifo_out, "%d", &i);
				if(a[i]*qw+b[i] != max_value) {
					error_response("wrong answer");
				}
				break;
			}
			else if(c == '?') {
				q_quer++;
				if(q_quer >= MAX_QUERIES_QUES) {
					error_response("Too many queries");
				}
				int i, j;
				ll w;
				fscanf(fifo_out, "%d %d %lld", &i, &j, &w);
				

				if(a[i]*w+b[i] > a[j]*w+b[j]) {
					print_string("FIRST");
				}
				else if(a[i]*w+b[i] < a[j]*w+b[j]) {
					print_string("SECOND");
				}
				else {
					print_string("EQUAL");
				}
			}
			else {
				error_response("invalid query token");
			}
		}
	}
	print_string("FINISH");
	accept_answer();



}