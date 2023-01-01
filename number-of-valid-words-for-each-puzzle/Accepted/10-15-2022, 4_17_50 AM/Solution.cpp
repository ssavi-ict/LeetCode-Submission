// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle

class Solution {
public:
    int find_mask(string &s){
        int str_size = size(s);
        int mask = 0;
        for(int i=0; i<str_size; i++){
            int index = s[i] - 'a';
            mask |= (1 << index);
        }
        return mask;
    }

    int get_modified_mask(string & word, int activate_index, char first_char){
        // cout<<word<<' '<<activate_index<<' '<<first_char<<endl;
        string ret = "";
        for(int i=1; i<7; i++){
            if(activate_index & (1 << i)){
                ret += word[i];
            }
        }

        ret = first_char + ret;
        // cout<<ret<<endl;

        int modified_mask = find_mask(ret);
        return modified_mask;
    }


    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int>word_count;
        int word_size = size(words), puzzle_size = size(puzzles);
        for(int i=0; i<word_size; i++){
            int word_mask = find_mask(words[i]);
            word_count[word_mask]++;
        }

        vector<int>valid_words;
        for(int i=0; i<puzzle_size; i++){
            int str_size = size(puzzles[i]);

            int counter = 0, loop_till = (1 << (str_size + 1) - 1);
            for(int j=1; j<=loop_till; j++){
                if(!(j & (1 << 0))) continue;
                int modified_mask = get_modified_mask(puzzles[i], j, puzzles[i][0]);
                if(word_count.find(modified_mask) != word_count.end()){
                    counter += word_count[modified_mask];
                }
            }
            valid_words.push_back(counter);
        }
        return valid_words;
    }
};