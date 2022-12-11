/*
This class has a method to recursively generate 
all valid combinations of parenthesis for a given integer input 
(The integer represents the pairs of parenthesis that should be used)

For example:
When 3 pairs of parenthesis are to be used, the output will be the vector ["((()))","(()())","(())()","()(())","()()()"]
*/
class ParenthesisGenerator {
public:
    //The chief method that does the work.
    void genBalancedParen(int openrem, int closedrem, std::string current, std::vector<std::string>& v){
        //Base case
        if(openrem==0 && closedrem==0){
            v.push_back(current);
            return;
        }
        
        //Add an opening parenthesis only if any more can be added
        if(openrem>0){
            std::string s = current+"(";
            genBalancedParen(openrem-1,closedrem,s,v);
        }
        
        //Add a closing parenthesis only if atleast one opening parenthesis has been added
        if(closedrem>openrem){
            std::string s = current+")";
            genBalancedParen(openrem,closedrem-1,s,v);
        }
        return;
    }
 
//this is the function called by user code
/*
The input is the number of pairs of parenthesis
Output is a vector of strings, each string has one combination of parenthesis
*/
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        genBalancedParen(n,n,"",v);
        return v;
    }
};
