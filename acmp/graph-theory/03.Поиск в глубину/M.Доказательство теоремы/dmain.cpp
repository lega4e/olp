#include <iostream>
#include <stack>
#include <vector>
 
#include <algorithm>
 struct AdjacList { std::vector< std::vector<int> > ribs; inline int n() const { return (int)ribs.size(); } inline AdjacList &clear() { ribs.clear(); return *this; } inline AdjacList &sort() { for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b) std::sort( b->begin(), b->end() ); return *this; } inline std::vector<int> &operator[](int i) { return ribs[i]; } inline std::vector<int> const &operator[](int i) const { return ribs[i]; } AdjacList &scan(FILE *file = stdin) { int n; fscanf(file, "%i", &n); ribs.resize(n); int m; for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b) { fscanf(file, "%i", &m); b->resize(m); for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb) fscanf(file, "%i", bb.base()); } return *this; } AdjacList &scan1(FILE *file = stdin) { int n; fscanf(file, "%i", &n); ribs.resize(n); int m; for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b) { fscanf(file, "%i", &m); b->resize(m); for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb) fscanf(file, "%i", bb.base()), --*bb; } return *this; } AdjacList &scan_matrix(FILE *file = stdin) { int n; fscanf(file, "%i", &n); ribs.resize(n); int input; for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) { fscanf(file, "%i", &input); if(input) ribs[i].push_back(j); } return *this; } AdjacList &scan_riblist(FILE *file = stdin, bool oriented = false){ int n, m; fscanf(file, "%i%i", &n, &m); ribs.resize(n); int first, second; for(int i = 0; i < m; ++i) { fscanf(file, "%i%i", &first, &second); ribs[first].push_back(second); if(!oriented) ribs[second].push_back(first); } return *this; } AdjacList &scan_riblist1(FILE *file = stdin, bool oriented = false){ int n, m; fscanf(file, "%i%i", &n, &m); ribs.resize(n); int first, second; for(int i = 0; i < m; ++i) { fscanf(file, "%i%i", &first, &second); --first, --second; ribs[first].push_back(second); if(!oriented) ribs[second].push_back(first); } return *this; } void print(FILE *file = stdout) const { fprintf(file, "%i\n", (int)n()); for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b) { fprintf(file, "%i ", (int)b->size()); for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb) { fprintf(file, "%i ", *bb); } fprintf(file, "\n"); } return; } void print1(FILE *file = stdout) const { fprintf(file, "%i\n", (int)n()); for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b) { fprintf(file, "%i ", (int)b->size()); for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb) { fprintf(file, "%i ", *bb+1); } fprintf(file, "\n"); } return; } }; using namespace std; char const *INPUT_FILE_NAME = "INPUT.TXT"; char const *OUTPUT_FILE_NAME = "OUTPUT.TXT"; int main( int argc, char *argv[] ) { AdjacList adjl; { auto file = fopen(INPUT_FILE_NAME, "r"); int inp; fscanf(file, "%i", &inp); adjl.ribs.resize(inp); for(auto b = adjl.ribs.begin(), e = adjl.ribs.end(); b != e; ++b) { while(true) { fscanf(file, "%i", &inp); if(!inp) break; b->push_back(inp-1); } } fclose(file); } stack<int> vers; vector<int> marks(adjl.n(), 0); marks[0] = 1; vers.push(0); int v; while(!vers.empty()) { v = vers.top(); if(v < 0) { v = -v-1; vers.pop(); marks[v] = 1; sort( adjl[v].begin(), adjl[v].end(), [&](int lhs, int rhs)->bool { return marks[lhs] < marks[rhs]; } ); for(auto b = adjl[v].begin(), e = adjl[v].end() - adjl[v].size()/2; b != e; ++b) marks[v] += marks[*b]; continue; } vers.top() = -v-1; for(auto b = adjl[v].begin(), e = adjl[v].end(); b != e; ++b) vers.push(*b); } { auto file = fopen(OUTPUT_FILE_NAME, "w"); fprintf(file, "%i\n", marks[0]); vers.push(0); while(!vers.empty()) { v = vers.top(); if(v < 0) { vers.pop(); fprintf(file, "%i\n", -v); continue; } vers.top() = -v-1; for(auto b = adjl[v].begin(), e = adjl[v].end() - adjl[v].size()/2; b != e; ++b) vers.push(*b); } fclose(file); } return 0; } 
