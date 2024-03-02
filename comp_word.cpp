#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Comparator function for sorting strings by length
bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

int main() {
     // Improve I/O performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = high_resolution_clock::now();   // Start measuring time

    // Open the input file
    ifstream inputFile("Input_02.txt");  
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    vector<string> v;
    string word;
     vector<string> ans;
    map<string, bool>mp;

    while (getline(inputFile, word)) {    // Read input file line by line and store in vector
        v.push_back(word);
    }
    inputFile.close();  // Close the input file

    int n = v.size();
    sort(v.begin(), v.end(), cmp);   // Sort the vector of strings by length

    // Loop through each word in the sorted vector
    for (int i = 0; i < n; i++) {
        bool flag = true;
        set<int> index;
        index.insert(-1);
       
        for (int j = 0; j < v[i].size(); j++) {   // Loop through each character in the word
            for (auto k : index) {   // Loop through each index in the index set
                if (mp.find(v[i].substr(k + 1, j - k)) != mp.end())   // Check if substring from k+1 to j is in the words map
                    index.insert(j);
            }
        }
      
        if (*index.rbegin() == v[i].size() - 1)
            ans.push_back(v[i]);
        mp[v[i]] = true;
    }

    // Sort the compound words by length
    sort(ans.begin(), ans.end(), cmp);

    int m = ans.size();

    // Output the longest compound word and the second longest compound word
    cout <<"Longest Compound Word : "<< ans[m - 1] << endl;
    cout <<"Second Longest Compound Word : "<< ans[m - 2] << endl;

    // End measuring time
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(stop - start);

    // Output the duration
    cout << "Time taken by code: " << duration.count() << " milliseconds" << endl;

    return 0;
}