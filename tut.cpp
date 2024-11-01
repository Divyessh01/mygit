#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

class MyGit {
private:
    string repository_path;
    string object_path;
    string head_path;
    string index_path;

    string getRepositoryPath() const {
        return repository_path;
    }
public:
    MyGit(string repository_path = "./.mygit") {
        this->repository_path = repository_path;
        this->object_path = repository_path + "/objects";
        this->head_path = repository_path + "/HEAD";
        this->index_path = repository_path + "/index";
    }

    void init(){
        if (mkdir(repository_path.c_str(), S_IRWXU) == -1) {
            perror("Error creating .mygit directory");
            return;
        }
        if (mkdir(object_path.c_str(), S_IRWXU) == -1) {
            perror("Error creating object directory");
            return;
        }

        int file_descriptor = open(head_path.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        if (file_descriptor == -1) {
            perror("Error creating file");
            return;
        }
        close(file_descriptor);
        file_descriptor = open(index_path.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        if (file_descriptor == -1) {
            perror("Error creating file");
            return;
        }
        close(file_descriptor);

        cout << "Git Initiated." << endl;
    }


};


int main(){

    MyGit mygit;
    mygit.init();

    return 0;
}