#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <experimental/filesystem>
#include <functional>
#include <unistd.h>
#include <stdlib.h> 
#include <set>

namespace fs = std::experimental::filesystem;

struct subtask {
	int score;
	std::vector<std::string> tcp;
	std::function<bool(std::ifstream&)> constraints;
	subtask(int s, std::function<bool(std::ifstream&)> c) {
		score = s;
		constraints = c;
	}
};

//***INSERT PROBLEM DATA HERE***

const std::string TASK_NAME = "histograma";
const std::string TASK_TITLE = "Histograma";

const int TIME_LIMIT = 1; //time limit (s)
const int MEMORY_LIMIT = 256; //memory limit (MB)

const bool GENERATE_OUTPUT = false; //generate output files from solution at sol/solution

bool constraints(std::ifstream& fin) {
	int n;
	fin >> n;
	if(!(1 <= n && n <= 5000)) return false;

	for(int i=0; i < n; ++i) {
		int a;
		fin >> a;
		if(!(0 <= a && a <= n)) return false;
	}
	return true;
}

std::vector<subtask> subtasks = {
	subtask(25, [](std::ifstream& fin) -> bool {
		int n;
		fin >> n;
		return n <= 100;
	}),
	subtask(25, [](std::ifstream& fin) -> bool {
		int n;
		fin >> n;
		return n <= 1000;
	}),
	subtask(25, [](std::ifstream& fin) -> bool {
		int n;
		fin >> n;
		return n <= 2500;
	}),
	subtask(25, [](std::ifstream& fin) -> bool {
		return true;
	})
};

//*****************************

int n_input = 0;



void process_testcase(const std::string& path) {
	std::ifstream fin;
	fin.open(path);
	if(!constraints(fin)) {
		fin.close();
		std::cerr << "Bad file: " << path << std::endl;
		return;
	}
	fin.close();
	for(subtask& sub : subtasks) {
		fin.open(path);
		if(sub.constraints(fin)) {
			sub.tcp.push_back(path);
			n_input++;
		}
		fin.close();
	}
}

void collect_testcases() {
	fs::path testcases_path = fs::path("./testcases");
	for(auto itEntry = fs::recursive_directory_iterator(testcases_path);
         itEntry != fs::recursive_directory_iterator(); 
         ++itEntry ) {
		if(itEntry->path().extension() == ".inp") {
			process_testcase(itEntry->path().string());
		}
	}	
}



void generate_output() {
	for(int i=0; i < n_input; ++i) {
		int pid = fork();
	    if(pid == 0) {
	    //	std::cerr << "Executing input " << i << std::endl;

	        freopen(std::string("./input/input"+std::to_string(i)+".txt").c_str(), "r", stdin);
	        freopen(std::string("./output/output"+std::to_string(i)+".txt").c_str(), "w", stdout);
	        if(GENERATE_OUTPUT) {
	     	   execlp("./sol/solution", "solution", NULL);
	        	std::cerr << "ERROR solution" << std::endl;
	    	}
	    	exit(0);
	    }
	    else {
	    	//sleep(1);
	    }
	}
}

void generate_input_and_GEN() {
	std::ofstream fout;
	fout.open("gen/GEN");
	int cnt = 0;
	for(subtask sub : subtasks) {
		fout << "# ST: " << sub.score << std::endl;
		for(std::string p : sub.tcp) {
			fs::copy_file(fs::path(p), fs::path("./input/input"+std::to_string(cnt)+".txt"));
			fout << cnt+1 << std::endl;
			cnt++;
		}
	}
	fout.close();
}

void generate_task_file() {
	std::ofstream fout;
	fout.open("task.yaml");

	fout << "name: \"" << TASK_NAME << "\"" << std::endl;
	fout << "title: \"" << TASK_TITLE << "\"" << std::endl;
	fout << "time_limit: "  << TIME_LIMIT << std::endl;
	fout << "memory_limit: "  << MEMORY_LIMIT  << std::endl;
	fout << "n_input: " << n_input << std::endl;
	fout << "score_mode: max_subtask\ntoken_mode: disabled\npublic_testcases: all\ninfile: \"\"\noutfile: \"\"\nprimary_language: \"es\"\n";

	fout.close();
}


int main() {
	collect_testcases();
	generate_input_and_GEN();
	generate_output();
	generate_task_file();
}