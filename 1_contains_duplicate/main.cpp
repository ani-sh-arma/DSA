#include<iostream>

bool containsDuplicate(int array[5] , int size) {

	for (int i = 0; i < size ; i++){
		
		for (int j = i+1 ; j < size ; j++){
			
			if (array[i] == array[j]) {
				return true;
			}
			
		}
	}
	return false;			
}


int main(){
	
	int arr[5] = {1,2,3,4,5};

	int sizeofArray = sizeof(arr) / sizeof(arr[0]);

	bool result = containsDuplicate(arr , sizeofArray);

	std::cout << std::boolalpha <<result ;

}

