#ifndef __dasdsaeqixcghijn_121231_rtyuiolnbvcfghj
#define __dasdsaeqixcghijn_121231_rtyuiolnbvcfghj

namespace functional { namespace generate {

class PasswordGenerated {
public:
    static PasswordGenerated& instance() {
        static PasswordGenerated passwordGenerate;
        return passwordGenerate;
    }
    
private:
    PasswordGenerated() {};
    ~PasswordGenerated() {};

    PasswordGenerated(PasswordGenerated const&) = delete;
    PasswordGenerated& operator= (PasswordGenerated const&) = delete;
};

}}


#endif //__dasdsaeqixcghijn_121231_rtyuiolnbvcfghj

// typedef std::vector<char> char_array;
 
// //we don't want a global. That's ugly.
// //This will get optimized at compile time anyway
// //http://e...content-available-to-author-only...a.org/wiki/Return_value_optimization
// char_array charset()
// {
//     //Change this to suit
//     return char_array( 
// 	{'0','1','2','3','4',
// 	'5','6','7','8','9', 
//     '!', '&', '#', '%',
// 	'A','B','C','D','E','F',
// 	'G','H','I','J','K',
// 	'L','M','N','O','P',
// 	'Q','R','S','T','U',
// 	'V','W','X','Y','Z',
// 	'a','b','c','d','e','f',
// 	'g','h','i','j','k',
// 	'l','m','n','o','p',
// 	'q','r','s','t','u',
// 	'v','w','x','y','z'
// 	});
// };    
 
// std::string random_string( size_t length, std::function<char(void)> rand_char )
// {
//     std::string str(length,0);
//     std::generate_n( str.begin(), length, rand_char );
//     return str;
// }