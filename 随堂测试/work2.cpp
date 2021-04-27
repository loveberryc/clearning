#include<iostream>

using namespace std;

class Matrix{
public:
	int num[3][3];
	Matrix(){
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				num[i][j] = 0;
			}
		}
	}
	Matrix(int tmp[3][3]){
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				num[i][j] = tmp[i][j]; 
			}
		}
	}

	void Setnum(int x, int y, int n){
		num[x][y] = n;
	}
	
	Matrix operator*(const Matrix m){
		Matrix tmp;
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				int k = num[i][0]*m.num[0][j] + num[i][1]*m.num[1][j] + num[i][2]*m.num[2][j];
				tmp.Setnum(i, j, k);
			}
		}
		return tmp;
	}
	Matrix &operator--(){
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				--num[i][j];
			}
		}
	}	
	Matrix operator--(int){
		Matrix tmp;
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				tmp.Setnum(i,j, num[i][j]);
				--num[i][j];
			}
		}
		return tmp;
	}
	bool operator==(const Matrix m){
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				if(num[i][j] != m.num[i][j]) return false;
			}
		}
		return true;
	}
	
	friend ostream &operator<<(ostream &o, Matrix m);
};

ostream &operator<<(ostream &o, Matrix m){
	for(int i = 0; i<3; ++i){
		for(int j = 0; j<3; ++j){
			o<<m.num[i][j]<<" ";
		}
		o<<endl;
	}
	return o;
}

int main(){
	int a[3][3] = {0,1,2,3,4,5,6,7,8};
	Matrix m1(a);
	cout<<m1<<endl;
	
	Matrix m2(m1--);
	cout<<m2<<endl<<m1<<endl;
	
	--m1;
	cout<<m1<<endl;
	
	Matrix m3 = m1*m2;
	cout<<m3<<endl;
	
	cout<<(m3==m1)<<endl;
	Matrix m4(m1);
	cout<<(m4==m1)<<endl;
}
