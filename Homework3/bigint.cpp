/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj3 

All work below has been performed by Jamel Douglas
*/
 
#include "bigint.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Constructors
bigint::bigint(){
	for(int i = 0; i <= 5; i++){
		v[i] = 0;
	}
}

bigint::bigint(int x0){
	v[0] = x0;
}

bigint::bigint(int x0, int x1){
	v[1] = x0;
	v[0] = x1;
}

bigint::bigint(int x0, int x1, int x2){
	v[2] = x0;
	v[1] = x1;
	v[0] = x2;
}

bigint::bigint(int x0, int x1, int x2, int x3){
	v[3] = x0;
	v[2] = x1;
	v[1] = x2;
	v[0] = x3;
}

bigint::bigint(int x0, int x1, int x2, int x3, int x4){
	v[4] = x0;
	v[3] = x1;
	v[2] = x2;
	v[1] = x3;
	v[0] = x4;
}

// I/O Operator Overload
istream& operator>>(istream &in, bigint& b1){
	string str;
	int size, j = 0;
	int count = 0;
	int insert = 0;
	char val_char = '0';
	int val_num = 0;
	int val_int = 0;
	double pow = 0;
	
	getline(in, str, ' ');
	size = str.size() - 1;
	
	for(int i = size - 1; i >= 0; i--){
		val_char = str[i];
		val_num = (int)val_char;
		//val_int = val_num - 48.0;
		if(val_num < 58 && val_num > 47){
			val_int = val_num - 48.0;
			pow = 10.0 * count;
		}else{
			val_int = -1;
		}
		
		//pow = 10.0 * count;
		if(val_int >= 0 && val_int <= 9){
			insert += val_int * pow;
			
		}
		
		cout << val_char << "  "  
			<< insert << endl;
		
		count++;
		if(count == 9){
			count = 0;
			b1.v[j] = insert;
			j++;
			insert = 0;
			
		}
		
		
		val_num = 0;
		val_int = 0;
		pow = 0;
		
	}
	str.clear();
	return in;
}

ostream& operator<<(ostream &out, const bigint &b1){
	if(b1.v[4] == 0){
		out << setfill('0') << setw(9) << b1.v[3] << ", " 
			<< setfill('0') << setw(9) << b1.v[2] << ", "
			<< setfill('0') << setw(9) << b1.v[1] << ", " 
			<< setfill('0') << setw(9) << b1.v[0];
			
	}else if(b1.v[4] == 0 && b1.v[3] == 0){
		out << setfill('0') << setw(9) << b1.v[2] << ", " 
			<< setfill('0') << setw(9) << b1.v[1] << ", " 
			<< setfill('0') << setw(9) << b1.v[0];
			
	}else if(b1.v[4] == 0 && b1.v[3] == 0 && b1.v[2] == '0'){
		out << setfill('0') << setw(9) << b1.v[1] << ", " 
			<< setfill('0') << setw(9) << b1.v[0];
			
	}else if(b1.v[4] == 0 && b1.v[3] == 0 && b1.v[2] == '0' && b1.v[1] == '0'){
		out<< setfill('0') << setw(9) << b1.v[0];
	}else{
		out << setfill('0') << setw(9) << b1.v[4] << ", " 
			<< setfill('0') << setw(9) << b1.v[3] << ", " 
			<< setfill('0') << setw(9) << b1.v[2] << ", " 
			<< setfill('0') << setw(9) << b1.v[1] << ", " 
			<< setfill('0') << setw(9) << b1.v[0];
	}

	return out;
}

//Arithmetic Operator Overload
bigint operator+(const bigint& b1, const bigint& b2){
	bigint r;
	
	r.v[0] = b1.v[0] + b2.v[0];
	r.v[1] = b1.v[1] + b2.v[1];
	r.v[2] = b1.v[2] + b2.v[2];
	r.v[3] = b1.v[3] + b2.v[3];
	r.v[4] = b1.v[4] + b2.v[4];
	
	return r;
}

bigint operator+(const bigint& b1, int b2){
	bigint r;
	
	
	r.v[0] = b1.v[0] + b2;
	if(r.v[0] >= 999999999){
		
	}
	r.v[1] = b1.v[1];
	r.v[2] = b1.v[2];
	r.v[3] = b1.v[3];
	r.v[4] = b1.v[4];
	
	return r;
}

bigint operator-(const bigint& b1, const bigint& b2){
	bigint r;
	
	r.v[0] = b1.v[0] - b2.v[0];
	r.v[1] = b1.v[1] - b2.v[1];
	r.v[2] = b1.v[2] - b2.v[2];
	r.v[3] = b1.v[3] - b2.v[3];
	r.v[4] = b1.v[4] - b2.v[4];
	
	return r;
}

bigint operator-(const bigint& b1, int b2){
	bigint r;
	
	r.v[0] = b1.v[0] - b2;
	if(r.v[0] < 0){
		
	}
	r.v[1] = b1.v[1];
	r.v[2] = b1.v[2];
	r.v[3] = b1.v[3];
	r.v[4] = b1.v[4];
	
	return r;
}

//Comparison Operator Overload
bool operator<(const bigint& b1, const bigint& b2){
	if(b1.v[4] < b2.v[4]){
		if(b1.v[3] < b2.v[3]){
			if(b1.v[2] < b2.v[2]){
				if(b1.v[1] < b2.v[1]){
					if(b1.v[0] < b2.v[0]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool operator>(const bigint& b1, const bigint& b2){
	if(b1.v[4] > b2.v[4]){
		if(b1.v[3] > b2.v[3]){
			if(b1.v[2] > b2.v[2]){
				if(b1.v[1] > b2.v[1]){
					if(b1.v[0] > b2.v[0]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool operator<=(const bigint& b1, const bigint& b2){
	if(b1.v[4] <= b2.v[4]){
		if(b1.v[3] <= b2.v[3]){
			if(b1.v[2] <= b2.v[2]){
				if(b1.v[1] <= b2.v[1]){
					if(b1.v[0] <= b2.v[0]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool operator>=(const bigint& b1, const bigint& b2){
	if(b1.v[4] >= b2.v[4]){
		if(b1.v[3] >= b2.v[3]){
			if(b1.v[2] >= b2.v[2]){
				if(b1.v[1] >= b2.v[1]){
					if(b1.v[0] >= b2.v[0]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool operator==(const bigint& b1, const bigint& b2){
	if(b1.v[0] == b2.v[0]){
		if(b1.v[1] == b2.v[1]){
			if(b1.v[2] == b2.v[2]){
				if(b1.v[3] == b2.v[3]){
					if(b1.v[4] == b2.v[4]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool operator!=(const bigint& b1, const bigint& b2){
	if(b1.v[0] != b2.v[0]){
		if(b1.v[1] != b2.v[1]){
			if(b1.v[2] != b2.v[2]){
				if(b1.v[3] != b2.v[3]){
					if(b1.v[4] != b2.v[4]){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}
