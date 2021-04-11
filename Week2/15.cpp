#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkOrder(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
    //If the counts of the elements are NOT equal
    if(p1.second.second != p2.second.second){
        return (p1.second.second > p2.second.second);
    }
    //If they are equal, pick element with lower index
    else
        return(p1.second.first < p2.second.first);
}


void sortArr(vector<int>& arr, int n){
    //Create hashmap
    //Index will be value of element
    //Pair will be (first appearing index, count)
    unordered_map <int, pair<int, int>> hMap;
    for(int i = 0; i < n; ++i){
        //If element already exists in hash map, increment its count
        if(hMap.find(arr[i]) != hMap.end())
            ++hMap[arr[i]].second;
        else
            hMap[arr[i]] = make_pair(i, 1);
    }
    
    auto it = hMap.begin();
    vector<pair<int, pair<int,int>>> resArr;
    
    for(it; it != hMap.end(); ++it){
        resArr.push_back(make_pair(it->first, it->second));
    }
    
    sort(resArr.begin(), resArr.end(), checkOrder);
    
    for(int i = 0; i < resArr.size(); ++i){
        int count = resArr[i].second.second;
        while(count){
            cout << resArr[i].first << " ";
            --count;
        }
    }
    cout << "\n";
    
}

int main() {
	//code
	int N, T;
	cin >> T;
	while(T){
	    --T;
	    cin >> N;
	    vector<int> inputArr;
	    for(int i = 0; i < N; ++i){
	        int temp;
	        cin >> temp;
	        inputArr.push_back(temp);
	    }
	    sortArr(inputArr, N);
	}
	return 0;
}
