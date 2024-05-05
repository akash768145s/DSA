#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr2[j] > arr1[i]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }
    return result;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Given array is" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    arr = mergeSort(arr);
    cout << "\nSorted array is" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
