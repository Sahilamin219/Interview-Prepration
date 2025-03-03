#include <bits/stdc++.h>
using namespace std;

class Blob {
public:
    string hashid;
    string content;
    Blob(string data) {
        content = data;
        hashid = generateHash(data);
    }
private:
    string generateHash(string data) {
        hash<string> hasher;
        return to_string(hasher(data));
    }
};

class File {
public:
    string hashid;
    string filePath;
    string parentFolder;
};

class Folder {
public:
    string name;
    string parentFolder;
    vector<File> files;
    vector<Folder> folders;
    Folder(string name_="Repo_Name", string parentFolder_="Root") {
        name = name_;
        parentFolder = parentFolder_;
        cout << "Root Folder Initialized\n";
    }
};

class Commit {
public:
    string commitID;
    string message;
    time_t timestamp;
    vector<File> committedFiles;
    Commit* parent;

    Commit(string msg, vector<File> files, Commit* prevCommit=nullptr) {
        message = msg;
        committedFiles = files;
        timestamp = time(nullptr);
        parent = prevCommit;
        commitID = generateCommitID();
        cout << "Commit Created: " << commitID << "\n";
    }

private:
    string generateCommitID() {
        hash<string> hasher;
        return to_string(hasher(message + to_string(timestamp)));
    }
};

class Branch {
public:
    string name;
    Commit* latestCommit;
    Branch(string bname="master") {
        name = bname;
        latestCommit = nullptr;
    }
};

class Repo {
public:
    vector<Branch> branches;
    vector<File> stagedFiles;
    Branch* currentBranch;

    Repo() {
        branches.push_back(Branch("master"));
        currentBranch = &branches[0];
        cout << "Repository Initialized with branch: " << currentBranch->name << "\n";
    }
};

class Git {
public:
    Repo r;
    string HEAD;

    void init() {
        cout << "Initializing new Git repository...\n";
    }

    void add(string filePath, string fileContent) {
        Blob blob(fileContent);
        File newFile = {blob.hashid, filePath, "Root"};
        r.stagedFiles.push_back(newFile);
        cout << "File " << filePath << " added to staging area.\n";
    }

    void commit(string message) {
        if (r.stagedFiles.empty()) {
            cout << "No files to commit!\n";
            return;
        }
        Commit* newCommit = new Commit(message, r.stagedFiles, r.currentBranch->latestCommit);
        r.currentBranch->latestCommit = newCommit;
        r.stagedFiles.clear();
        cout << "Committed successfully! Commit ID: " << newCommit->commitID << "\n";
    }

    void checkout(string branchName) {
        for (auto& branch : r.branches) {
            if (branch.name == branchName) {
                r.currentBranch = &branch;
                cout << "Switched to branch: " << branchName << "\n";
                return;
            }
        }
        cout << "Branch " << branchName << " does not exist!\n";
    }

    void createBranch(string branchName) {
        r.branches.push_back(Branch(branchName));
        cout << "Branch " << branchName << " created.\n";
    }
};

int main() {
    Git git;
    git.init();
    git.add("file1.txt", "Hello World");
    git.commit("Initial commit");
    git.createBranch("feature-branch");
    git.checkout("feature-branch");
    git.add("file2.txt", "Feature branch changes");
    git.commit("Added feature");
    return 0;
}
