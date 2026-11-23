
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        vector<string> arr;
        string word = "";

        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] == ' ')
            {
                arr.push_back(word);
                word = "";
            }
            else
            {
                word += sentence[i];
            }
        }

        arr.push_back(word);

        bool found = true;

        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].back() != arr[(i+1) % arr.size()][0])
            {
                found = false;
                break;
            }
        }

        return found;
    }
};
