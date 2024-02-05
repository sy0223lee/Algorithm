#include <iostream>
#include <vector>
using namespace std;
// merge sort 이용

vector<int> sortedList;

void Merge(vector<int>& numList, int left, int mid, int right){
	int i = left, j = mid + 1, k = left;

	//분할 정렬된 리스트 합병
	while (i <= mid && j <= right){
		if (numList[i] <= numList[j]){
			sortedList[k++] = numList[i++];
		}
		else{
			sortedList[k++] = numList[j++];
		}
	}

	int l = (i > mid) ? j : i;
	int last = (i > mid) ? right : mid;
	//남아 있는 값들 복사 
	for (l; l <= last; ++l){
		sortedList[k++] = numList[l]; 
	}
	//정렬된 임시 리스트를 원래 리스트에 복사
	for (int l = left; l <= right; ++l){
		numList[l] = sortedList[l];
	}
}

void MergeSort(vector<int>& numList, int left, int right){
	if (sortedList.size() == 0){
		sortedList= vector<int>(numList.size());
	}
	if (left < right){
		int mid = (left + right) / 2;
		MergeSort(numList, left, mid);
		MergeSort(numList, mid + 1, right);
		Merge(numList, left, mid,right);
	}
}

int main(){
    int N;
	vector<int> numbers;

    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

	MergeSort(numbers, 0, N-1);

	for (int num : numbers){
		cout << num << "\n";

	}

	return 0;
}