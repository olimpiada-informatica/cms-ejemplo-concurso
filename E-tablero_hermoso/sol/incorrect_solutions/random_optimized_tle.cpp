#include<bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi grid;
int n, m;
bool done = false;

void print() {
    //cout << n << " " << m << endl;
    done = true;
    for(int i=0; i < n; ++i) {
        for(int j=0; j < m; ++j) {
            cout << (grid[i][j] ? "#" : ".");
        }
        cout << endl;
    }
    cout << endl;
    exit(0);
}

void check() {
    int eqc = 0;
    int dfc = 0;
    int count1 = 0;
    int count0 = 0;
    for(int i=0; i < n; ++i) {
        for(int j=0; j < m; ++j) {
            if(i < n-1) {
                eqc += (grid[i][j]==grid[i+1][j]);
                dfc += 1-(grid[i][j]==grid[i+1][j]);
            }
            if(j < m-1) {
                eqc += (grid[i][j]==grid[i][j+1]);
                dfc += 1-(grid[i][j]==grid[i][j+1]);
            }
            
            count1 += grid[i][j];
            count0 += !grid[i][j];
        }
    }
    if(eqc == dfc and count0 == count1) print();
}

void gen() {
    int blc = 0;
    grid = vvi(n, vi(m, 0));
    while(blc < (n*m)/2) {
    	int x = rand()%n;
    	int y = rand()%m;
    	if(!grid[x][y]) blc++;
    	grid[x][y] = 1;
    	
    }
    check();
}

int main() {
    
    cin >> n >> m;
    

    if(n&1 || m&1) {
    	cout << "NO" << endl;
    	return 0;
    }
    cout << "SI" << endl;
    
    while(!done) gen();
    
}
