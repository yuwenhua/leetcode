#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

// Forward declaration of isBadVersion API.
int call_times = 0;
bool isBadVersion(int version) {
	call_times++;

	if(version >= 1) 
		return 1;
	return 0;
}

int firstBadVersion(int n) {
	int low = 1, high = n;
	int mid;
	int result = 0;

	if(n == 1)
		return 1;

	while(low < high) {
		
		if((low + 1 == high)) {
			result = isBadVersion(low);
			if(result == 1)
				return low;
			else 
				return high;
		}

		mid = low + (high - low)/2;
		result = isBadVersion(mid);
		if(result == 0) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return -1;
}

int main(int argc, char **argv) 
{
	int n = 20;
	int i = 0;
	int result = 0;
	
	for(i = 1; i < n; i++) {
		call_times = 0;
		result = firstBadVersion(i);
		printf("n = %d, result = %d, call %d times\n", i, result,  call_times);
	}


	return 0;
}
