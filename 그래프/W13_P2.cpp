#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int size, n;

	cin >> size >> n;

	int** arr = new int* [size];

	// 배열 공간생성
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}

	// 배열 초기화
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int data;
			cin >> data;
			arr[i][j] = data;
		}
	}

	// n개의 질문을 입력받고 처리
	for (int i = 0; i < n; i++) {
		int x, y;
		int index2 = 0;
		int index3 = 0;
		int size2 = 0;
		int size3 = 0;
		cin >> x >> y;
		int* arr2 = new int[size]; // 직계 친구를 저장하는 배열
		int* arr3 = new int[size];  // 친구의 친구를 저장하는 배열

		// 직계 친구들을 x행 (인덱스로는 x-1 행) 을 탐색하면서 찾아내기 
		for (int j = 0; j < size; j++) {
			if (arr[x - 1][j] == 1) {
				arr2[index2] = j;
				size2++;
				index2++;
			}
		}



		// 1을 찾은경우 해당 열 좌표를 저장해 놓은 배열 arr2 에 대해서 또 탐색을 진행해서, 이 안에서 1을 찾고 또 열 좌표를 arr3 배열에 담아낸다.
		// 조건1 : 친구의 행(arr2) 에서 자기 자신(x-1)을 찾으면 배제해주는 것
		// 조건2 : 직계친구(arr2[j])의 친구(arr[j][k])를 찾아냄
		// 조건 3 : 조건2를 통해 찾아낸 친구의 친구가 자신의 친구이거나 동료인 사람들을 배제해주는 것 ( 0은 아무런 관계가 없다는 것이기 문. 1인 경우는 친구인 것이고, 2인 경우는 동료인 경우이다.)

		// ex) arr2 = (2,3) 이 저장되었다면 (즉 행렬을 기준으로는 1과 2가 저장되었다면)
		// 배열의 1행의 1~6열을 탐색하고, 2행의 2~6열을 탐색한다.
		for (int j = 0; j < size2; j++) {
			for (int k = 0; k < size; k++) {
				if (k != x - 1 && arr[arr2[j]][k] == y + 1 && arr[x - 1][k] == 0) {
					bool flag = true; // arr3 배열에 동일한 친구의 친구를 중복해서 또 삽입하는 상황을 방지하기 위함 
					for (int t = 0; t < size3; t++) {
						if (arr3[t] == k + 1)  // 찾아낸 친구의 친구가 이미 arr3 배열에 저장되있는 경우
							flag = false;
					}
					// arr3 배열을 다 탐색해봤는데, 찾아낸 친구의 친구가 arr3 에 없어서 삽입해도 괜찮은 경우라면 삽입한다.
					if (flag) {
						arr3[index3] = k + 1;
						size3++;
						index3++;
					}

				}
			}
		}

		sort(arr3, arr3 + size3);

		if (size3 == 0)
			cout << 0 << endl;
		else {
			for (int j = 0; j < size3; j++) {
				cout << arr3[j] << " ";
			}
			cout << endl;
		}
	}


}
