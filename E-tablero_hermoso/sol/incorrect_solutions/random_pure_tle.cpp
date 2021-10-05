#include<bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

void baq(int i, int j) {
    if(i == n) {
        check();
    }
    else if(j == m) {
        baq(i+1, 0);
    }
    else {
        
       // grid[n-i-1][j] = 1;
        
        grid[i][j] = rand()%2;
       // grid[n-i-1][j] = 0;
        baq(i, j+1);
    }
}

int main() {
    
    cin >> n >> m;
    grid = vvi(n, vi(m, 0));

    if(n&1 || m&1) {
    	cout << "NO" << endl;
    	return 0;
    }
    cout << "SI" << endl;
    
    while(!done) baq(0, 0);
    
}
