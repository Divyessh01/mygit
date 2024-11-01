#include <iostream>
#include <vector>
#include <functional>
// #include <variant>
#include <unordered_map>
using namespace std;

// using FunctionType = variant<function<void()>, function<int(int, int)>>;

vector<string> command_tokens;

void fatal(string s){
    cerr << "Error: " << s << endl;
    exit(0);
}

void print_vec(vector<string> vec){
    cout << "===================[ vec ]===================" << endl;

    for(auto s: vec)
        cout << s << endl;

    cout << vec.size() << endl;

    cout << "===================[ vec ]===================" << endl;
}

// ./mygit init
void git_Init(){
    cout << "Git initiated." << endl;
}

void git_HashObject(){
    cout << "Sha Sha" << endl; 
}

unordered_map<string, function<void()>> function_map;
void initialize_function_map(){
    function_map["init"] = git_Init;
    function_map["hash-object"] = git_HashObject;
}

int main(int arg_count, char** arg_values){

    if(arg_count < 2)
        fatal("Invalid Argument Length.");

    // cout << arg_count << endl;

    for(int index = 0; index < (arg_count - 1); ++index)
        command_tokens.push_back(arg_values[index + 1]);
    // print_vec(command_tokens);

    string command = command_tokens[0];
    initialize_function_map();

    auto function = function_map.find(command);

    if(function == function_map.end())
        fatal("Not a valid command.");

    function_map[command]();



    cout << "Hello, World!" << endl;

    return 0;
}