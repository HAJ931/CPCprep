#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int N;

vector<int> printDiag(vector<vector<int>> A, int n){
    vector<int> ans;
    for (int j = 0; j < n; ++j){
        ans.push_back(A[0][j]);
        int i = 1, currCol = j - 1;
        while(i < n && currCol >= 0){
            ans.push_back(A[i][currCol]);
            ++i;
            --currCol;
        }
    }
    for (int i = 1; i < n; ++i){
        ans.push_back(A[i][n - 1]);
        int currRow = i + 1, j = n - 2;
        while(currRow < n && j >= 0){
            ans.push_back(A[currRow][j]);
            ++currRow;
            --j;
        }
    }
    return ans;
}

int main() {
	//code
	int T;
	cin >> T;
	vector<vector<int>> ansMatrix;
	for(int i = 0; i < T; ++i){
	    cin >> N;
	    //cout << "N: " << N << "\t";
	    vector<vector<int>> currMatrix;
	    for(int j = 0; j < N; ++j){
	        vector<int> currRow;
	        for(int k = 0; k < N; ++k){
	            int temp;
	            cin >> temp;
	            currRow.push_back(temp);
	        }
	        currMatrix.push_back(currRow);
	    }
	    /*cout << "Matrix: " << i << "\t";
	    for(int j = 0; j < N; ++j){
	        for(int k = 0; k < N; ++k){
	            cout << currMatrix[j][k] << " ";
	        }
	    }
	    cout << endl;*/
	    ansMatrix.push_back(printDiag(currMatrix, N));
	}
	for(int i = 0; i < T; ++i){
	    for(int j = 0; j < ansMatrix[i].size(); ++j){
	        cout << ansMatrix[i][j] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
