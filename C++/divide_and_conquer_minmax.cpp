#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
using namespace std;

void minmax(int a[],int i,int j, int &max, int &min){
	if (j-i==0) {
		min = max = a[i];
    }
    else if(j-i==1){
    	if (a[i] < a[j]){
    		max = a[j];
    		min = a[i];
    	}
    	else{
    		max=a[i];
    		min=a[j];
    	}
    }
    else{

		int max2,min2,mid=(i+j)/2;
	    minmax(a,i,mid,max,min);
	    minmax(a,mid+1,j,max2,min2);

	    if (max2 > max){ 
	    	max = max2;
		}
		if (min2 < min){
			min = min2;
		}
	}
}

int main(int argc, char** argv){
	if (argc != 2){
		cerr << "Format: " << argv[0] << " <num_elem>" << endl;
		return -1;
	}

	int n = atoi(argv[1]);

	int * T = new int[n];
	assert(T);

	using namespace std::chrono;
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	double total = 0;

	srand(time(0));

	for (int j=0; j<n; j++) {
		T[j]=rand();
	}
	int max,min;
	tantes = high_resolution_clock::now();

	minmax(T,0,n,max,min);

	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast < duration < double >> (tdespues - tantes);
	total = transcurrido.count();

	delete [] T;
	cout << n << " " << total << endl;

    cout << "\nMin: " << min << " Max: " << max << endl;         
    return 0;
}
