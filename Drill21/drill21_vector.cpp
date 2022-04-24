#include <iostream>
#include<stdexcept>
#include<fstream>
#include<numeric>
#include<algorithm>
#include<vector>
#include<set> 

template<typename C>
void print(const C& c, char sep = '\n'){
	std::cout<<"Container elements: "<<std::endl;

	for(const auto elem: c){
		std::cout<< elem <<sep;
	}
	std::cout << std::endl;

}

int main()
try{

const std::string iname{"szamok.txt"};
std::ifstream ifs {iname};
if(!ifs) throw std::runtime_error("Could not read file:" +iname);

std::vector<double> vd;
for(double d; ifs >>d;){
	vd.push_back(d);
}

print(vd);
std::vector<int> vi(vd.size());

}


	std::copy(vd.begin(), vd.end(), vi.begin()),
	print(vi);

	for (int i=0 ;i<vd.size(); i++){
		std::cout << vd[i] << '\t' << vi[i] <<std::endl;
	}

     std::cout.precision(10); //precission: sztenderd outputnak a pontossága 
double d_sum  =std::accumulate(vd.begin(), vd.end(), 0.0);
std::cout << "Sum of vector<double>: "<<d_sum << std::endl;

double i_sum  =std::accumulate(vi.begin(), vi.end(), 0.0);
std::cout << "Sum of vector<int>: "<<i_sum << std::endl;

double vd_mean =d_sum / vd.size();
std::cout << "Mean value of vd is: "<<vd_mean << std::endl;

for (int i=0 ;i<vd.size(); i++){
	if(vd[i] <vd_mean)
		std::cout << vd[i] <<std::endl;
	}


//10.  std::sort rendezii a 
	std::sort(vd.begin(), vd.end());
	print(vd);


} catch(std::exception& e){
	std::cerr<<e.what() <<'\n';
	return 1; 

} catch(...){
	std::cerr<<"Unknown exception" <<'\n';
	return 2;
}
