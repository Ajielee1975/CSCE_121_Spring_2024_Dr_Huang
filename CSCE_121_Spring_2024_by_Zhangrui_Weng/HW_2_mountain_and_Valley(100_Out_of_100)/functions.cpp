#include <iostream>
#include "functions.h"
//Zhangrui Weng
bool is_valid_range(int a, int b) {
    // TODO(student): validate input range
	// constraint: a and b MUST be 10 <= a <= b < 10000
    return a >= 10 && a <= b && b < 10000;
}

char classify_mv_range_type(int a) {
    // TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

    int c = 0;
    int arr[1000];
    int n = a; 
    int idx = 0;
    while(n>0){
        arr[idx] = n%10; //extract the last value
        n/=10;
        idx++;
        c++;
    }
    char pattern;
    bool alter = true;
    if(arr[c-1]>arr[c-2]){
        pattern = 'V'; // Set pattern to 'V' if last digit is >second-to-last digit
    }else if(arr[c-1]<arr[c-2]){
        pattern = 'M'; // Set pattern to 'M' if last digit is < second-to-last digit
    }
    for(int i=c-1;i>0;i--){
        if(pattern == 'N'){
            return pattern;
        }
        if(alter){
            if(arr[i]>arr[i-1] && pattern == 'V'){
                
            }else if(arr[i]<arr[i-1] && pattern == 'M'){
                
            }else{
                pattern = 'N';  // If no alternating pattern, set pattern to 'N'
            }
        }else{
            if(arr[i]<arr[i-1] && pattern == 'V'){
               
            }else if(arr[i]>arr[i-1] && pattern == 'M'){
             
            }else{
                pattern = 'N'; 
            }
        }
        alter = !alter; // Toggle the alternating flag
    }
    return pattern;
}

void count_valid_mv_numbers(int a, int b) {
    // TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
    int mountainCount = 0;
    int valleyCount = 0;

    for (int i = a; i <= b; i++) {
        char rangeType = classify_mv_range_type(i);
        if (rangeType == 'M') {
            mountainCount++;
        } else if (rangeType == 'V') {
            valleyCount++;
        }
    }
    std::cout << "There are " << mountainCount
	<< " mountain ranges and " << valleyCount
	<< " valley ranges between " << a
	<< " and " << b << "." << std::endl;
}
