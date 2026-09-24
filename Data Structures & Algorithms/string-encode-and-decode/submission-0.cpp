class Solution {
public:
    string encode(vector<string>& strs) {
        // what if every char is rep by the char ascii val,
        // and we use a newline or something as a delimiter that its the end
        // of the word?
        // so we return a str thats numbers representing each ascii char, it would
        // need to be delimited by something though so we know where each char ends
        // and where each word ends
        string res{};
        int ascii = 0;

        for (const auto& s : strs) {
            for (const auto& c : s) {
                ascii = c;
                res += std::to_string(ascii);
                // this and '#' can be fucked up if the user inputs it manually,
                // but its neetcode so oh well...definitely dont use this irl
                res += "^";
            }

            res += "#";
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int ascii = 0;
        string current{}, ascii_str{};

        for (const auto& c : s) {
            if (c == '#') {
                res.push_back(current);
                current = "";
            }
            else if (c == '^') {
                ascii = stoi(ascii_str);
                current.push_back(static_cast<char>(ascii));
                ascii_str = "";
            }
            else {
                ascii_str.push_back(c);
            }
        }
    

        std::cout << s << std::endl;
 

        return res;
    }
};
