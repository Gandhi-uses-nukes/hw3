#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void fillingNumbers(double* x, double grenze, int N){
	// Fuellt das Array mit rand. Zahlen auf zwischen 0 und 1
	for(int i=0 ; i<N ; i++)
		x[i] = rand()/grenze;
}

void calcStat(double* x, double& m, double& n, int N){
	m = 0;
	n = 0;
	// Durchschnitt berechnen
	for(int i=0 ; i<N ; i++)
		m += x[i];
	m = m/N;
	// Erst mit der abgeschlossenen Berechnung des Durchschnittswerts
	// koennen wir uns der Varianz widmen
	for(int i=0 ; i<N ; i++)
		n += pow(x[i]-m,2);
	n = n/N;
}

int main(){
	const int N = 100;
	double p[N];
	double mean, var, grenze;
	
	// Wenn ich direkt RAND_MAX als Variable verwenden wollte,
	// kam mein Code damit nicht zurecht :/
	// Aber eine Variable mehr ist ja nicht schlimm :)
	grenze = RAND_MAX;
	// Fuellt das Array auf (Mit Pointers)
	fillingNumbers(p,grenze,N);
	// Berechnet Durchschnitt und Varianz [Mit References (Und Pointers)]
	calcStat(p,mean,var,N);
	
	cout << "Mean = " << mean << endl;
	cout << "Variance = " << var << endl;

	return 0;
}
