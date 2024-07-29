
#include <iostream>
#include <cstring>

void reverse_string(std::string* s) {
    size_t len = s->size();
    for (int i = 0; i < len/2; ++i) {
        char c = (*s)[i];
        (*s)[i] = (*s)[len-i-1];
        (*s)[len-i-1] = c;
    }
}

void reverse_string(std::string& s) {
    size_t len = s.size();
    for (int i = 0; i < len/2; ++i) {
        char c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
}

void double_string(const char* input, size_t input_len, char* output, size_t output_len) {
    int j = 0;
    for (int i = 0; i < input_len*2, j < output_len; ++i, ++j) {
        size_t k = i >= input_len ? i - input_len : i;
        output[j] = input[k];
    }
    if (j < output_len) {
        output[j] = 0;
    }
}

int main(int argc, char** argv) {
    // std::string name;
    // if (1 < argc) {
    //     name = argv[1];
    // } else {
    //     std::cout << "What's your name? ";
    //     std::cin >> name;
    // }
    // reverse_string(name);
    char* name = argv[1];
    size_t tmp_len = strlen(name)*2+1;
    char* tmp = new char[tmp_len];
    double_string(name, strlen(name), tmp, tmp_len);
    std::cout << "Hello, " << tmp << "!\n";
    delete[] tmp;
    return 0;
}
