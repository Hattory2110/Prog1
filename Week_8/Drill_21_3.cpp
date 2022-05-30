#include "std_lib_facilities.h"
#include <fstream>

template<typename C> void print(const C& c, char elv = '\n')
{
    for (const auto elem : c)
        cout << elem << elv;

    cout << '\n';
}

//9
struct Less_than {
   private:
	double v;
   public:
   Less_than(double vv) : v{vv} {}
   
   bool operator()(const double vv) {return vv<v;}
   };

int main(){
	//1
	vector<double> vd;
	ifstream read {"numbers.txt"};
	for(float f; read >> f;) vd.push_back(f);
	
	//2
	print(vd);
	
	//3
	vector<int> vi (vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	
	//4
	for (int i = 0; i < vi.size(); i++){
		cout << "1: " << vd[i] << ", 2: " << vi[i] << '\n';
	}
	
	//5
	float sum = 0;
	for (int i = 0; i<vd.size(); i++){
		sum += vd[i];
	}
	cout << "Sum of the vector:" << sum << "\n";

	int sum2 = 0;
	for (int i = 0; i<vi.size(); i++){
		sum2 += vi[i];
	}
	cout << "Sum of the truncated vector:" << sum2 << "\n";
	
	//6
	cout << "The difference between the sums:" << sum-sum2 << "\n";


	//7
	reverse(vd.begin(), vd.end());
	cout << "/n Backwards original vector: \n";
	print(vd);
	
	
	//8
	double vd_med = sum / vd.size();
	cout << "Median value of the vector: " << vd_med << "\n";
	
	//9
	vector<double> vd2(vd.size());
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(),Less_than(vd_med));
	vd2.resize(distance(vd2.begin(), it));
	cout << "\n Grater than median \n";
	print(vd2);
	
	//10
	sort(vd.begin(), vd.end());
	cout << "\n Original vector sorted:\n";
	print(vd);
}

