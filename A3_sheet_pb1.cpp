//
// Created by Monem on 12/11/2022.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream dictionary("dictionary.txt");

bool isInDictionary (string word) {
    string nextWord;
    dictionary.clear();
    dictionary.seekg(0, ios::beg);
    while (!dictionary.eof()) {
        dictionary >> nextWord;
        if (word == nextWord)
            return true;
    }
    return false;
}


bool permutations(string prefix, string choices, vector<vector<string>>& results){
    static vector<string> tmp_res;
    // base case
    if (choices.empty()){
        // if reached the end of the string
        return isInDictionary(prefix);
    }
    if (!isInDictionary(prefix) && !prefix.empty()){
        return false;
    }

    for (int i = 1; i <= choices.size(); ++i) {
        // try all choices
        string prefixNew = choices.substr(0, i);
        string choicesNew = choices.substr(i);
        tmp_res.push_back(prefixNew + " ");
        if (permutations(prefixNew, choicesNew, results)) {
            // if valid solution, store the result and backtrack to choose other valid solutions
            results.push_back(tmp_res);
            tmp_res.pop_back();
        }
        else{
            // if NOT valid solution UNDO last choice
            if (!tmp_res.empty()){
                tmp_res.pop_back();
            }
        }
    }
}


int main() {
    vector<vector<string>> results;

//    permutations("", "toforget", results);
    permutations("", "Iwearmyshoes", results);

    for(auto const & res : results){
        for(auto const & str : res){
            cout << str << " ";
        }
        cout << '\n';
    }

    system("pause");
    return 0;
}

