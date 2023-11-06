#include<bits/stdc++.h>

using namespace std;

int main(){
	auto max_sub_arr = [] (vector<int> &a) -> int {
		int res = -1000011001;
		int cur_sum = 0;	
		int smallest_prev_sum = 0;
		for (int x : a){
			cur_sum += x;
			res = max(res, cur_sum - smallest_prev_sum);
			smallest_prev_sum = min (smallest_prev_sum, cur_sum);
		}
		return res;
	};

	auto max_sub_arr_with_pos = [] (const vector<int> &a) -> vector<int>{
		int max_sum = a[0], cur_sum = a[0];
		int start = 0, endd = 0, cur_start = 0;
		for (int i = 1; i < a.size(); i++){
			if (cur_sum < 0){
				cur_sum = a[i];
				cur_start = i;
			}
			else cur_sum += a[i];
			if (cur_sum > max_sum){
				max_sum = cur_sum;	start = cur_start;
				endd = i;
			}
		}
		return {start,endd,max_sum};
	};
}